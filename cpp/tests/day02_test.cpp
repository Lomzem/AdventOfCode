#include "day02.hpp"
#include <catch2/catch_test_macros.hpp>
#include <iostream>

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

TEST_CASE("Full AOC Example Part 1", "[day02pt1]") {
  size_t total = 0;
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

TEST_CASE("3 Repeats", "[day02pt2]") {
  const char *input = "123123123-123123123";
  REQUIRE(day02::part2(input) == 123123123);
}

TEST_CASE("100 Valid", "[day02pt2]") {
  const char *input = "100-100";
  REQUIRE(day02::part2(input) == 0);
}

TEST_CASE("Single Char 3 Repeats", "[day02pt2]") {
  const char *input = "99-111";
  REQUIRE(day02::part2(input) == (99 + 111));
}

TEST_CASE("Double Char 3 Repeats", "[day02pt2]") {
  const char *input = "565653-565659";
  REQUIRE(day02::part2(input) == (565656));
}

TEST_CASE("Triple Char 3 Repeats", "[day02pt2]") {
  const char *input = "824824821-824824827";
  REQUIRE(day02::part2(input) == (824824824));
}

TEST_CASE("Double Char 4 Repeats", "[day02pt2]") {
  const char *input = "2121212118-2121212124";
  REQUIRE(day02::part2(input) == (2121212121));
}

TEST_CASE("Single Char 7 Repeats", "[day02pt2]") {
  const char *input = "1111111-1111111";
  REQUIRE(day02::part2(input) == (1111111));
}

TEST_CASE("Quad Char 2 Repeats", "[day02pt2]") {
  const char *input = "12341234-12341234";
  REQUIRE(day02::part2(input) == (12341234));
}

TEST_CASE("Double Char 5 Repeats", "[day02pt2]") {
  const char *input = "1212121212-1212121212";
  REQUIRE(day02::part2(input) == (1212121212));
}

TEST_CASE("Repeat 5-Digit Char", "[day02pt2]") {
  const char *input = "1188511880-1188511890";
  REQUIRE(day02::part2(input) == 1188511885);
}

TEST_CASE("3 Single, 2 Double", "[day02pt2]") {
  const char *input = "998-1012";
  REQUIRE(day02::part2(input) == (999 + 1010));
}

TEST_CASE("11-22", "[day02pt2]") {
  const char *input = "11-22";
  REQUIRE(day02::part2(input) == (11 + 22));
}

TEST_CASE("95-115", "[day02pt2]") {
  const char *input = "95-115";
  REQUIRE(day02::part2(input) == (99 + 111));
}

TEST_CASE("222220-222224", "[day02pt2]") {
  const char *input = "222220-222224";
  REQUIRE(day02::part2(input) == (222222));
}

TEST_CASE("AOC No invalid", "[day02pt2]") {
  const char *input = "1698522-1698528";
  REQUIRE(day02::part2(input) == (0));
}

TEST_CASE("446443-446449", "[day02pt2]") {
  const char *input = "446443-446449";
  REQUIRE(day02::part2(input) == (446446));
}

TEST_CASE("38593856-38593862", "[day02pt2]") {
  const char *input = "38593856-38593862";
  REQUIRE(day02::part2(input) == (38593859));
}

TEST_CASE("Full AOC Example Part 2", "[day02pt2]") {
  size_t total = 0;
  const char *inputs[] = {
      "11-22",
      "95-115",
      "998-1012",
      "1188511880-1188511890",
      "222220-222224",
      "1698522-1698528",
      "446443-446449",
      "38593856-38593862",
      "565653-565659",
      "824824821-824824827",
      "2121212118-2121212124",
  };
  for (const char *input : inputs) {
    total += day02::part2(input);
  }
  REQUIRE(total == 4174379265);
}
