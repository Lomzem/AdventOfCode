#include "day06.hpp"
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

TEST_CASE("One Col", "[day06pt1]") {
  const std::vector<std::string> input = {"123", "45", "6", "*"};
  REQUIRE(day05::part2(input) == 33210);
}
