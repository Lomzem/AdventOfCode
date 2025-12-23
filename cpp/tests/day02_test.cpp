#include "day02.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Palindrome", "[day02pt1]") {
  const char *input = "101-101";
  REQUIRE(day02::part1(input) == 0);
}

TEST_CASE("Repeat Single Char", "[day02pt1]") {
  const char *input = "55-55";
  REQUIRE(day02::part1(input) == 55);
}

TEST_CASE("Two Repeat Single Char", "[day02pt1]") {
  const char *input = "11-22";
  REQUIRE(day02::part1(input) == (11 + 22));
}

TEST_CASE("Repeat Double Char", "[day02pt1]") {
  const char *input = "998-1012";
  REQUIRE(day02::part1(input) == 1010);
}

TEST_CASE("Repeat 5-Digit Char", "[day02pt1]") {
  const char *input = "1188511880-1188511890";
  REQUIRE(day02::part1(input) == 1188511885);
}

TEST_CASE("Full AOC Example", "[day02pt1]") {
  int total = 0;
  const char *inputs[] = {
      "11-22",         "95-115",
      "998-1012",      "1188511880-1188511890",
      "222220-222224", "1698522-1698528",
      "446443-446449", "38593856-38593862",
  };
  for (const char *input : inputs) {
    total += day02::part1(input);
  }
  REQUIRE(total == 1227775554);
}
