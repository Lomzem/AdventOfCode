#include "day07.hpp"
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

TEST_CASE("One Split", "[day07pt2]") {
  const std::vector<std::string> input = {
      ".......S.......",
      "...............",
      ".......^.......",
      "...............",
  };
  REQUIRE(day07::part2(input) == 2);
}

TEST_CASE("Two Splits", "[day07pt2]") {
  const std::vector<std::string> input = {
      ".......S.......", "...............", ".......^.......",
      "...............", "......^.^......", "...............",
  };
  REQUIRE(day07::part2(input) == 4);
}

TEST_CASE("Part 2 Example", "[day07pt2]") {
  const std::vector<std::string> input = {
      ".......S.......", "...............", ".......^.......",
      "...............", "......^.^......", "...............",
      ".....^.^.^.....", "...............", "....^.^...^....",
      "...............", "...^.^...^.^...", "...............",
      "..^...^.....^..", "...............", ".^.^.^.^.^...^.",
      "...............",
  };
  REQUIRE(day07::part2(input) == 40);
}
