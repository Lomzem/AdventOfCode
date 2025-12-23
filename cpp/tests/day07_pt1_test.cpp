#include "day07.hpp"
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

TEST_CASE("One Split", "[day07pt1]") {
  const std::vector<std::string> input = {
      ".......S.......",
      "...............",
      ".......^.......",
      "...............",
  };
  REQUIRE(day07::part1(input) == 1);
}

TEST_CASE("Part 1 Example", "[day07pt1]") {
  const std::vector<std::string> input = {
      ".......S.......", "...............", ".......^.......",
      "...............", "......^.^......", "...............",
      ".....^.^.^.....", "...............", "....^.^...^....",
      "...............", "...^.^...^.^...", "...............",
      "..^...^.....^..", "...............", ".^.^.^.^.^...^.",
      "...............",
  };
  REQUIRE(day07::part1(input) == 21);
}
