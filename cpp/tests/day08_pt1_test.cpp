#include "day08.hpp"
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

TEST_CASE("Two Box", "[day08pt1]") {
  const std::vector<std::string> input = {
      "162,817,812",
      "57,618,57",
  };
  REQUIRE(day08::part1(input, 2) == 2);
}
