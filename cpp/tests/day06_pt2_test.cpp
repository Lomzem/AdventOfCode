#include "day06.hpp"
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

TEST_CASE("One Col Add", "[day06pt2]") {
  const std::vector<std::vector<std::string>> input = {
      {"4"},
      {"431"},
      {"623"},
      {"+"},
  };
  REQUIRE(day06::part2(input) == 1058);
}
