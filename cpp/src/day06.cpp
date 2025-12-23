#include "day06.hpp"
#include <charconv>
#include <string>
#include <vector>

namespace day06 {
size_t part1(const std::vector<std::vector<std::string>> &hw) {
  size_t res = 0;

  int ROWS = hw.size();
  int COLS = hw[0].size();
  for (int col = 0; col < COLS; col++) {
    char op = hw[ROWS - 1][col][0];
    const std::string &numstr = hw[0][col];

    size_t numint;
    std::from_chars(numstr.data(), numstr.data() + numstr.size(), numint);

    size_t base = numint;

    for (int row = 1; row < ROWS - 1; row++) {
      std::from_chars(hw[row][col].data(),
                      hw[row][col].data() + hw[row][col].size(), numint);
      if (op == '*') {
        base *= numint;
      } else if (op == '+') {
        base += numint;
      }
    }
    res += base;
  }

  return res;
};

size_t part2(const std::vector<std::vector<std::string>> &input) { return 0; }
} // namespace day06
