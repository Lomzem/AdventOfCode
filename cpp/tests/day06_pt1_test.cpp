#include "day06.hpp"
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

TEST_CASE("One Col Multiply", "[day06pt1]") {
  const std::vector<std::vector<std::string>> input = {
      {"123"},
      {"45"},
      {"6"},
      {"*"},
  };
  REQUIRE(day06::part1(input) == 33210);
}

TEST_CASE("One Col Add", "[day06pt1]") {
  const std::vector<std::vector<std::string>> input = {
      {"328"},
      {"64"},
      {"98"},
      {"+"},
  };
  REQUIRE(day06::part1(input) == 490);
}

TEST_CASE("Part 1 Example", "[day06pt1]") {
  const std::vector<std::vector<std::string>> input = {
      {"123", "328", "51", "64"},
      {"45", "64", "387", "23"},
      {"6", "98", "215", "314"},
      {"*", "+", "*", "+"},
  };
  REQUIRE(day06::part1(input) == 4277556);
}
