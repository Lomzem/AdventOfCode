#include "day03.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("98", "[day03pt1] AOC") {
  const char *input = "987654321111111";
  REQUIRE(day03::part1(input) == 98);
}

TEST_CASE("89", "[day03pt1] AOC") {
  const char *input = "811111111111119";
  REQUIRE(day03::part1(input) == 89);
}

TEST_CASE("78", "[day03pt1] AOC") {
  const char *input = "234234234234278";
  REQUIRE(day03::part1(input) == 78);
}

TEST_CASE("818181911112111", "[day03pt1] AOC") {
  const char *input = "818181911112111";
  REQUIRE(day03::part1(input) == 92);
}
