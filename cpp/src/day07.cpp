#include "day07.hpp"
#include <iostream>
#include <string>
#include <vector>

namespace day07 {
int part1(const std::vector<std::string> &diag_orig) {
  std::vector<std::string> diag = diag_orig;
  int count = 0;

  int ROWS = diag.size();
  int COLS = diag[0].size();

  int S_pos = diag[0].find('S');
  diag[1][S_pos] = '|';

  for (int row = 1; row < ROWS - 1; row++) {
    for (int col = diag[row].find('|'); col != std::string::npos;
         col = diag[row].find('|', col + 1)) {
      if (diag[row + 1][col] == '^') {
        count++;
        if (col > 0) {
          diag[row + 1][col - 1] = '|';
        }
        if (col < COLS - 1) {
          diag[row + 1][col + 1] = '|';
        }
      } else {
        diag[row + 1][col] = '|';
      }
    }
  }

  return count;
};

size_t bt(int row, int col, const std::vector<std::string> &diag,
          std::vector<std::vector<size_t>> &dp) {
  int ROWS = diag.size();
  int COLS = diag[0].size();

  if (col < 0 || col >= COLS || row >= ROWS - 1) {
    return 1;
  }

  if (dp[row][col] != -1) {
    return dp[row][col];
  }

  size_t count = 0;
  if (diag[row + 1][col] == '^') {
    count += bt(row + 1, col - 1, diag, dp);
    count += bt(row + 1, col + 1, diag, dp);
  } else {
    count += bt(row + 1, col, diag, dp);
  }
  dp[row][col] = count;
  return count;
}

size_t part2(const std::vector<std::string> &diag) {
  auto dp = std::vector<std::vector<size_t>>(
      diag.size(), std::vector<size_t>(diag[0].size(), -1));
  int S_pos = diag[0].find('S');
  return bt(1, S_pos, diag, dp);
}
} // namespace day07
