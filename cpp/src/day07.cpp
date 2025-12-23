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

int part2(const std::vector<std::string> &diag);
} // namespace day07
