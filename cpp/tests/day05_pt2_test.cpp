#include "day05.hpp"
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

TEST_CASE("One Range", "[day05pt2] AOC") {
  const std::vector<std::string> input = {
      "3-5",
  };
  REQUIRE(day05::part2(input) == 3);
}

TEST_CASE("Two Indep Range", "[day05pt2] AOC") {
  const std::vector<std::string> input = {
      "3-5",
      "10-14",
  };
  REQUIRE(day05::part2(input) == (3 + 5));
}

TEST_CASE("Two Intersect Range", "[day05pt2] AOC") {
  const std::vector<std::string> input = {
      "3-5",
      "4-10",
  };
  REQUIRE(day05::part2(input) == 8);
}

TEST_CASE("Three Intersect Range", "[day05pt2] AOC") {
  const std::vector<std::string> input = {
      "3-5",
      "8-12",
      "4-9",
  };
  REQUIRE(day05::part2(input) == 10);
}

TEST_CASE("Part 2 Example", "[day05pt2] AOC") {
  const std::vector<std::string> input = {
      "3-5",
      "10-14",
      "16-20",
      "12-18",
  };
  REQUIRE(day05::part2(input) == 14);
}

TEST_CASE("Full Input", "[day05pt2]") {
  const std::vector<std::string> input = {
      "3-5",
      "10-14",
      "",
      "69",
  };
  REQUIRE(day05::part2(input) == 8);
}

// TEST_CASE("Large Numbers", "[day05pt2]") {
//   const std::vector<std::string> input = {
//       "284509448628766-289381261597719",
//       "417436534565209-420984393851206",
//       "124942655568155-125884357831428",
//       "",
//       "69",
//   };
//   REQUIRE(day05::part2(input) == (
//               4871812968953
//               ));
// }
