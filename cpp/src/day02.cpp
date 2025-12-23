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

int part2(const std::vector<std::string> &input) { return 0; }

} // namespace day02
