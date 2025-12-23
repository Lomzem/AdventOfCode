#include "day06.hpp"
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

TEST_CASE("One Col Left", "[day06pt2]") {
  const std::vector<std::string> input = {"64 ", "23 ", "314", "+  "};
  REQUIRE(day06::part2(input) == 1058);
}

TEST_CASE("Part 2 Example", "[day06pt2]") {
  const std::vector<std::string> input = {
      "123 328  51 64 ",
      " 45 64  387 23 ",
      "  6 98  215 314",
      "*   +   *   +  ",
  };
  REQUIRE(day06::part2(input) == 3263827);
}
