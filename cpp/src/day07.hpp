#pragma once
#include <string>
#include <vector>

namespace day07 {
int part1(const std::vector<std::string> &diag);

size_t bt(int row, int col, const std::vector<std::string> &diag,
          std::vector<std::vector<size_t>> &dp);

size_t part2(const std::vector<std::string> &diag);
} // namespace day07
