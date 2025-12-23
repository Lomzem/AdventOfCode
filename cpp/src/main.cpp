#include "day02.hpp"
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  int day = 0;

  if (argc > 1) {
    day = std::stoi(argv[1]);
  }

  std::string filename = "./inputs/day" + std::string(day < 10 ? "0" : "") +
                         std::to_string(day) + ".txt";

  switch (day) {
  case 1:
    break;
  case 2:
    std::cout << "Day 2\n";
    std::cout << "Part 1: ";
    std::ifstream file(filename);
    if (!file.is_open()) {
      std::cerr << "Error: Could not open file " << filename << '\n';
      exit(1);
    }
    size_t total = 0;
    for (std::string range; std::getline(file, range, ',');) {
      total += day02::part1(range);
    }
    std::cout << total << '\n';
    break;
  }

  return 0;
}
