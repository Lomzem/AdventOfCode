#include "day03.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("987654321111111", "[day03pt2] AOC") {
  const char *input = "987654321111111";
  REQUIRE(day03::part2(input) == 987654321111);
}

TEST_CASE("811111111111119", "[day03pt2] AOC") {
  const char *input = "811111111111119";
  REQUIRE(day03::part2(input) == 811111111119);
}

TEST_CASE("234234234234278", "[day03pt2] AOC") {
  const char *input = "234234234234278";
  REQUIRE(day03::part2(input) == 434234234278);
}

TEST_CASE("818181911112111", "[day03pt2] AOC") {
  const char *input = "818181911112111";
  REQUIRE(day03::part2(input) == 888911112111);
}
