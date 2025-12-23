#include "day01.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Empty input", "[day01pt1]") {
  const std::vector<std::string> input = {};
  REQUIRE(day01::part1(input) == 0);
}

TEST_CASE("L49", "[day01pt1]") {
  const std::vector<std::string> input = {"L49"};
  REQUIRE(day01::part1(input) == 0);
}

TEST_CASE("L50", "[day01pt1]") {
  const std::vector<std::string> input = {"L50"};
  REQUIRE(day01::part1(input) == 1);
}

TEST_CASE("Overflow: R50", "[day01pt1]") {
  const std::vector<std::string> input = {"R50"};
  REQUIRE(day01::part1(input) == 1);
}

TEST_CASE("Double Overflow: R150", "[day01pt1]") {
  const std::vector<std::string> input = {"R150"};
  REQUIRE(day01::part1(input) == 1);
}

TEST_CASE("Underflow: L51 L99", "[day01pt1]") {
  const std::vector<std::string> input = {"L51", "L99"};
  REQUIRE(day01::part1(input) == 1);
}

TEST_CASE("Double Underflow 2 Parts", "[day01pt1]") {
  const std::vector<std::string> input = {"L50", "L1", "L99"};
  REQUIRE(day01::part1(input) == 2);
}

TEST_CASE("Double Underflow 1 Part", "[day01pt1]") {
  const std::vector<std::string> input = {"L50", "L100"};
  REQUIRE(day01::part1(input) == 2);
}

TEST_CASE("Triple Underflow 1 Part", "[day01pt1]") {
  const std::vector<std::string> input = {"L50", "L200"};
  REQUIRE(day01::part1(input) == 2);
}

TEST_CASE("AOC Example Part 1", "[day01pt1]") {
  const std::vector<std::string> input = {
      "L68", "L30", "R48", "L5", "R60", "L55", "L1", "L99", "R14", "L82",
  };
  REQUIRE(day01::part1(input) == 3);
}

TEST_CASE("AOC Underflow L51", "[day01pt2]") {
  const std::vector<std::string> input = {"L51"};
  REQUIRE(day01::part2(input) == 1);
}

TEST_CASE("AOC Example Single Cross", "[day01pt2]") {
  const std::vector<std::string> input = {"L68", "L30"};
  REQUIRE(day01::part2(input) == 1);
}

TEST_CASE("AOC Example Part 2", "[day01pt2]") {
  const std::vector<std::string> input = {
      "L68", "L30", "R48", "L5", "R60", "L55", "L1", "L99", "R14", "L82",
  };
  REQUIRE(day01::part2(input) == 6);
}

TEST_CASE("AOC Example Double Cross", "[day01pt2]") {
  const std::vector<std::string> input = {"L68", "L30", "R48"};
  REQUIRE(day01::part2(input) == 2);
}

TEST_CASE("AOC Example Before Triple Cross", "[day01pt2]") {
  const std::vector<std::string> input = {
      "L68",
      "L30",
      "R48",
      "L5",
  };
  REQUIRE(day01::part2(input) == 2);
}

TEST_CASE("AOC Example Triple Cross", "[day01pt2]") {
  const std::vector<std::string> input = {
      "L68", "L30", "R48", "L5", "R60",
  };
  REQUIRE(day01::part2(input) == 3);
}

TEST_CASE("AOC Example R1000", "[day01pt2]") {
  const std::vector<std::string> input = {"R1000"};
  REQUIRE(day01::part2(input) == 10);
}

TEST_CASE("1 Exact Left", "[day01pt2]") {
  const std::vector<std::string> input = {"L50"};
  REQUIRE(day01::part2(input) == 1);
}

TEST_CASE("2 Exact Left", "[day01pt2]") {
  const std::vector<std::string> input = {"L50", "L100"};
  REQUIRE(day01::part2(input) == 2);
}

TEST_CASE("1 Exact Right", "[day01pt2]") {
  const std::vector<std::string> input = {"R50"};
  REQUIRE(day01::part2(input) == 1);
}

TEST_CASE("2 Little Over Right", "[day01pt2]") {
  const std::vector<std::string> input = {"R51", "R101"};
  REQUIRE(day01::part2(input) == 2);
}

TEST_CASE("2 Exact Right", "[day01pt2]") {
  const std::vector<std::string> input = {"R50", "R100"};
  REQUIRE(day01::part2(input) == 2);
}

TEST_CASE("3 Exact Left", "[day01pt2]") {
  const std::vector<std::string> input = {"L250"};
  REQUIRE(day01::part2(input) == 3);
}

TEST_CASE("3 Exact Right", "[day01pt2]") {
  const std::vector<std::string> input = {"R250"};
  REQUIRE(day01::part2(input) == 3);
}
