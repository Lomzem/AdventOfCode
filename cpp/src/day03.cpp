#include "day03.hpp"
#include <climits>
#include <string>
#include <utility>

namespace day03 {
int part1(const std::string &bank) {
  int max_first = 0;
  int max_first_idx;
  int max_second = 0;

  // Get largest first digit
  for (int i = 0; i < bank.size() - 1; i++) {
    if (bank[i] > max_first) {
      max_first = bank[i];
      max_first_idx = i;
    }
  }

  // Get largest second digit
  for (int i = max_first_idx + 1; i < bank.size(); i++) {
    if (bank[i] > max_second) {
      max_second = bank[i];
    }
  }

  max_first -= '0';
  max_second -= '0';
  return 10 * max_first + max_second;
};

size_t part2(const std::string &bank) {
  char best[12] = {0};
  int offset = 0;
  for (int i = 0; i < 12; i++) {
    for (int j = offset; j <= bank.size() - (12 - i); j++) {
      if (bank[j] > best[i]) {
        best[i] = bank[j];
        offset = j + 1;
      }
      if (bank[j] == '9')
        break;
    }
  }
  return std::stoul(best);
}

} // namespace day03
