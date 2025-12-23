#include "day01.hpp"
#include <charconv>
#include <string>

#define DIAL_START (50)
#define DIAL_MIN (0)
#define DIAL_MAX (99)

namespace day01 {

int part1(const std::vector<std::string> &input) {
  int cur = DIAL_START;
  int crosses = 0;

  for (const auto &line : input) {
    // First char should be direction
    char dir = line[0];
    int count;
    std::from_chars(line.data() + 1, line.data() + line.size(), count);

    if (dir == 'L') {
      count = -1 * count;
    }
    cur += count;

    // Underflow, may cause overflow
    if (cur < 0) {
      cur = (DIAL_MAX + 1) - ((-1 * cur) % (DIAL_MAX + 1));
    }

    // Overflow
    if (cur > DIAL_MAX) {
      cur %= (DIAL_MAX + 1);
    }

    if (cur == 0) {
      crosses++;
    }
  }
  return crosses;
}

int part2(const std::vector<std::string> &input) {
  int cur = DIAL_START;
  int crosses = 0;

  for (const auto &line : input) {
    // First char should be direction
    char dir = line[0];
    int count;
    std::from_chars(line.data() + 1, line.data() + line.size(), count);

    if (dir == 'L') {
      count = -1 * count;
    }

    cur += count;

    if (cur == 0) {
      crosses++;
      continue;
    }

    // Underflow, may cause overflow
    if (cur < 0) {
      if (cur - count == 0) {
        crosses--;
      }
      crosses += (-1 * cur / (DIAL_MAX + 1)) + 1;
      cur = (DIAL_MAX + 1) - ((-1 * cur) % (DIAL_MAX + 1));
      cur %= DIAL_MAX + 1;
      continue;
    }

    // Overflow
    if (cur > DIAL_MAX) {
      crosses += cur / (DIAL_MAX + 1);
      cur %= (DIAL_MAX + 1);
    }
  }

  return crosses;
}

} // namespace day01
