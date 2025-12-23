#include "day02.hpp"
#include <charconv>
#include <string>

namespace day02 {

size_t part1(const std::string &id_range) {
  const auto dash_pos = id_range.find('-');
  size_t start;
  size_t end;
  std::from_chars(id_range.data(), id_range.data() + dash_pos, start);
  std::from_chars(id_range.data() + dash_pos + 1,
                  id_range.data() + id_range.size(), end);

  size_t total = 0;
  for (size_t curnum = start; curnum <= end; curnum++) {
    const auto istr = std::to_string(curnum);
    if (istr.size() % 2 != 0)
      continue;
    auto left = istr.begin();
    auto right = istr.begin() + (istr.size() / 2);
    bool should_continue = false;
    while (right != istr.end()) {
      if (*left != *right) {
        should_continue = true;
        break;
      }
      left++;
      right++;
    }
    if (should_continue)
      continue;
    total += curnum;
  }

  return total;
}

size_t part2(const std::string &id_range) {
  const auto dash_pos = id_range.find('-');
  size_t start;
  size_t end;
  std::from_chars(id_range.data(), id_range.data() + dash_pos, start);
  std::from_chars(id_range.data() + dash_pos + 1,
                  id_range.data() + id_range.size(), end);

  size_t total = 0;

  // Prime numbers for ways to divide
  // Fine to go up to 64-bit
  const int dividers[] = {2,  3,  5,  7,  11, 13, 17, 19, 23,
                          29, 31, 37, 41, 43, 47, 53, 59, 61};

  for (size_t curnum = start; curnum <= end; curnum++) {
    const std::string istr = std::to_string(curnum);
    for (const int divider : dividers) {
      if (istr.size() % divider != 0) {
        continue;
      }
      int step = istr.size() / divider;
      for (int i = 0; i < step; i++) {
        char prev = istr[i];
        for (int j = 1; j < divider; j++) {
          if (prev != istr[i + j * step]) {
            goto next_divider;
          }
          prev = istr[i + j * step];
        }
      }
      total += curnum;
      goto next_number;
    next_divider:
    }
  next_number:
  }

  return total;
}
} // namespace day02
