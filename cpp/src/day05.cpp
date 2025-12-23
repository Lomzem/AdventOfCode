#include "day05.hpp"
#include <charconv>
#include <iostream>
#include <string>
#include <vector>

struct Range {
  size_t start;
  size_t end;
  Range(size_t start, size_t end) : start(start), end(end) {};
};

namespace day05 {
int part1(const std::vector<std::string> &list) {
  std::vector<Range> ranges;

  int ingredient_start_idx;
  for (int i = 0; i < list.size(); i++) {
    const std::string &line = list[i];
    if (line.empty()) {
      ingredient_start_idx = i + 1;
      break;
    }
    size_t start;
    size_t end;
    auto dash_pos = line.find('-');
    std::from_chars(line.data(), line.data() + dash_pos, start);
    std::from_chars(line.data() + dash_pos + 1, line.data() + line.size(), end);
    ranges.push_back({
        start,
        end,
    });
  }

  int total_fresh = 0;
  for (int i = ingredient_start_idx; i < list.size(); i++) {
    size_t cur_id;
    const std::string &line = list[i];
    std::from_chars(line.data(), line.data() + line.size(), cur_id);
    for (const Range &range : ranges) {
      if (range.start <= cur_id && cur_id <= range.end) {
        total_fresh++;
        break;
      }
    }
  }

  return total_fresh;
};
int part2(const std::vector<std::string> &list);
} // namespace day05
