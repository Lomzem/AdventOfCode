#include "day01.hpp"
#include <fstream>
#include <iostream>
#include <vector>

std::vector<std::string> read_input(const std::string &filename) {
  std::vector<std::string> lines;
  std::ifstream file(filename);

  if (!file.is_open()) {
    std::cerr << "Error: Could not open file " << filename << std::endl;
    return lines;
  }

  std::string line;
  while (std::getline(file, line)) {
    if (!line.empty()) {
      lines.push_back(line);
    }
  }

  return lines;
}

int main() {
  auto input = read_input("./inputs/day01pt1.txt");

  if (input.empty()) {
    std::cerr << "No input data found" << std::endl;
    return 1;
  }

  int result1 = day01::part1(input);
  int result2 = day01::part2(input);

  std::cout << "Part 1: " << result1 << std::endl;
  std::cout << "Part 2: " << result2 << std::endl;

  return 0;
}
