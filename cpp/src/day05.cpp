#include "day05.hpp"
#include <algorithm>
#include <charconv>
#include <string>
#include <vector>

struct Range {
  size_t start;
  size_t end;
  Range(size_t start, size_t end) : start(start), end(end) {};
};

Range from_line(const std::string &line) {
  size_t start;
  size_t end;
  auto dash_pos = line.find('-');
  std::from_chars(line.data(), line.data() + dash_pos, start);
  std::from_chars(line.data() + dash_pos + 1, line.data() + line.size(), end);
  return Range{start, end};
}

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
    ranges.push_back(from_line(line));
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

size_t part2(const std::vector<std::string> &list) {
  std::vector<Range> ranges;

  ranges.push_back(from_line(list[0]));
  for (int i = 1; i < list.size(); i++) {
    if (list[i].empty())
      break;
    Range line_range = from_line(list[i]);
    std::vector<Range> new_ranges;
    int j = 0;
    while (j < ranges.size() && ranges[j].end < line_range.start) {
      new_ranges.push_back(ranges[j]);
      j++;
    }
    while (j < ranges.size() && line_range.end >= ranges[j].start) {
      line_range.start = std::min(line_range.start, ranges[j].start);
      line_range.end = std::max(line_range.end, ranges[j].end);
      j++;
    }
    new_ranges.push_back(line_range);
    while (j < ranges.size()) {
      new_ranges.push_back(ranges[j]);
      j++;
    }
    ranges = std::move(new_ranges);
  }

  size_t total = 0;
  for (const Range &range : ranges) {
    total += range.end - range.start + 1;
  }
  return total;
};
} // namespace day05
