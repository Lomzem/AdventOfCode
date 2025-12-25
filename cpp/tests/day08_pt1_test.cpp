#include "day08.hpp"
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

TEST_CASE("Two Box", "[day08pt1]") {
  const std::vector<std::string> input = {
      "162,817,812",
      "57,618,57",
  };
  REQUIRE(day08::part1(input, 1) == 2);
}

TEST_CASE("Part 1 Example", "[day08pt1]") {
  const std::vector<std::string> input = {
      "162,817,812", "57,618,57",   "906,360,560", "592,479,940", "352,342,300",
      "466,668,158", "542,29,236",  "431,825,988", "739,650,466", "52,470,668",
      "216,146,977", "819,987,18",  "117,168,530", "805,96,715",  "346,949,466",
      "970,615,88",  "941,993,340", "862,61,35",   "984,92,344",  "425,690,689",
  };
  REQUIRE(day08::part1(input, 10) == 40);
}
