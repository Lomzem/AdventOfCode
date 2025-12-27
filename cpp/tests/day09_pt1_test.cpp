#include "day09.hpp"
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

TEST_CASE("AOC Example", "[day09pt1]") {
  const std::vector<std::string> input = {
      "7,1", "11,1", "11,7", "9,7", "9,5", "2,5", "2,3", "7,3",
  };
  REQUIRE(day09::part1(input) == 50);
}
