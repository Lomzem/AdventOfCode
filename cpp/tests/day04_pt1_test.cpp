#include "day04.hpp"
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

TEST_CASE("Single roll", "[day04pt1]") {
  const std::vector<std::string> input = {"@"};
  REQUIRE(day04::part1(input) == 1);
}

TEST_CASE("All rolls", "[day04pt1]") {
  const std::vector<std::string> input = {
      "@@@",
      "@@@",
      "@@@",
      // x@x
      // @@@
      // x@x
  };
  REQUIRE(day04::part1(input) == 4);
}

TEST_CASE("Part 1 Example", "[day04pt1] AOC") {
  const std::vector<std::string> input = {
      "..@@.@@@@.", "@@@.@.@.@@", "@@@@@.@.@@", "@.@@@@..@.", "@@.@@@@.@@",
      ".@@@@@@@.@", ".@.@.@.@@@", "@.@@@.@@@@", ".@@@@@@@@.", "@.@.@@@.@.",
  };
  REQUIRE(day04::part1(input) == 13);
}
