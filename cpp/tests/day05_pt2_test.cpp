#include "day05.hpp"
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

TEST_CASE("Part 2 Example", "[day05pt2] AOC") {
  const std::vector<std::string> input = {
      "3-5",
      "10-14",
      "16-20",
      "12-18",
  };
  REQUIRE(day05::part2(input) == 14);
}
