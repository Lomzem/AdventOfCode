#include "day04.hpp"
#include <string>
#include <vector>

namespace day04 {
int part1(const std::vector<std::string> &grid) {
  int ROWS = grid.size();
  int COLS = grid[0].size();

  const char dirs[8][2] = {
      {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1},
  };

  int num_accessible = 0;
  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
      if (grid[row][col] != '@')
        continue;
      int total_neighbors = 0;
      for (const auto &dir : dirs) {
        int r = row + dir[0];
        int c = col + dir[1];
        if (r < 0 || r >= ROWS)
          continue;
        if (c < 0 || c >= COLS)
          continue;
        if (grid[r][c] == '@') {
          if (++total_neighbors >= 4) {
            goto next_cell;
          }
        }
      }
      num_accessible++;
    next_cell:
    }
  }
  return num_accessible;
}
int part2(const std::vector<std::string> &grid) { return 0; }
} // namespace day04
