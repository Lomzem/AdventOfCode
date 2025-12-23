#include "day01.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Empty input", "[day01]") {
  const std::vector<std::string> input = {};
  REQUIRE(day01::part1(input) == 0);
}

TEST_CASE("L49", "[day01]") {
  const std::vector<std::string> input = {"L49"};
  REQUIRE(day01::part1(input) == 0);
}

TEST_CASE("L50", "[day01]") {
  const std::vector<std::string> input = {"L50"};
  REQUIRE(day01::part1(input) == 1);
}

TEST_CASE("Overflow: R50", "[day01]") {
  const std::vector<std::string> input = {"R50"};
  REQUIRE(day01::part1(input) == 1);
}

TEST_CASE("Double Overflow: R150", "[day01]") {
  const std::vector<std::string> input = {"R150"};
  REQUIRE(day01::part1(input) == 1);
}

TEST_CASE("Underflow: L51 L99", "[day01]") {
  const std::vector<std::string> input = {"L51", "L99"};
  REQUIRE(day01::part1(input) == 1);
}

TEST_CASE("Double Underflow 2 Parts", "[day01]") {
  const std::vector<std::string> input = {"L50", "L1", "L99"};
  REQUIRE(day01::part1(input) == 2);
}

TEST_CASE("Double Underflow 1 Part", "[day01]") {
  const std::vector<std::string> input = {"L50", "L100"};
  REQUIRE(day01::part1(input) == 2);
}

TEST_CASE("Triple Underflow 1 Part", "[day01]") {
  const std::vector<std::string> input = {"L50", "L200"};
  REQUIRE(day01::part1(input) == 2);
}

TEST_CASE("AOC Example", "[day01]") {
  const std::vector<std::string> input = {
      "L68", "L30", "R48", "L5", "R60", "L55", "L1", "L99", "R14", "L82",
  };
  REQUIRE(day01::part1(input) == 3);
}

// TEST_CASE("Day 01 Part 2", "[day01]") {
//   std::vector<std::string> input = {"example", "input", "here"};
//   REQUIRE(day01::part2(input) == 0);
// }
