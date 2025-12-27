#include "day09.hpp"
#include <algorithm>
#include <charconv>
#include <cstdlib>
#include <iterator>
#include <string>
#include <vector>

namespace day09 {

struct Coord {
  int64_t x;
  int64_t y;

  Coord(int64_t x, int64_t y) : x(x), y(y) {}

  static Coord from(const std::string &line) {
    int64_t x;
    int64_t y;
    auto comma_pos = line.find(',');
    std::from_chars(line.data(), line.data() + comma_pos, x);
    std::from_chars(line.data() + comma_pos + 1, line.data() + line.size(), y);
    return Coord{x, y};
  }
};

size_t part1(const std::vector<std::string> &lines) {
  std::vector<Coord> coords;
  coords.reserve(lines.size());
  std::transform(lines.begin(), lines.end(), std::back_inserter(coords),
                 [](const std::string &line) { return Coord::from(line); });

  size_t max_area = 0;

  for (int i = 0; i < coords.size(); i++) {
    for (int j = i + 1; j < coords.size(); j++) {
      Coord coord1 = coords[i];
      Coord coord2 = coords[j];
      size_t area =
          std::abs((coord1.x - coord2.x + 1) * (coord1.y - coord2.y + 1));
      max_area = std::max(max_area, area);
    }
  }

  return max_area;
}
size_t part2(const std::vector<std::string> &lines);
} // namespace day09
