#include "day04.hpp"
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

TEST_CASE("Single roll", "[day04pt2]") {
  const std::vector<std::string> input = {"@"};
  REQUIRE(day04::part2(input) == 1);
}
