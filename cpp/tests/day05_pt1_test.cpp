#include "day05.hpp"
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

TEST_CASE("Part 1 Example", "[day05pt1] AOC") {
  const std::vector<std::string> input = {
      "3-5", "10-14", "16-20", "12-18", "", "1", "5", "8", "11", "17", "32",
  };
  REQUIRE(day05::part1(input) == 3);
}
