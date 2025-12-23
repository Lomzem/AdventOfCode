#include "day02.hpp"
#include "day03.hpp"
#include "day04.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

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
  case 2: {
    std::cout << "Day 2\n";
    std::ifstream file(filename);
    std::vector<std::string> inputs;
    for (std::string range; std::getline(file, range, ',');) {
      inputs.push_back(range);
    }

    size_t total = 0;
    std::cout << "Part 1: ";
    for (const std::string &input : inputs) {
      total += day02::part1(input);
    }
    std::cout << total << '\n';

    total = 0;
    std::cout << "Part 2: ";
    for (const std::string &input : inputs) {
      total += day02::part2(input);
    }
    std::cout << total << '\n';
    break;
  }
  case 3: {
    std::cout << "Day 3\n";
    std::ifstream file(filename);
    std::vector<std::string> inputs;
    for (std::string range; std::getline(file, range);) {
      inputs.push_back(range);
    }

    size_t total = 0;
    std::cout << "Part 1: ";
    for (const std::string &input : inputs) {
      total += day03::part1(input);
    }
    std::cout << total << '\n';

    total = 0;
    std::cout << "Part 2: ";
    for (const std::string &input : inputs) {
      total += day03::part2(input);
    }
    std::cout << total << '\n';
    break;
  }

  case 4: {
    std::cout << "Day 4\n";
    std::ifstream file(filename);
    std::vector<std::string> input;
    for (std::string range; std::getline(file, range);) {
      input.push_back(range);
    }
    std::cout << "Part 1: ";
    int total = day04::part1(input);
    std::cout << total << '\n';
    std::cout << "Part 2: ";
    total = day04::part2(input);
    std::cout << total << '\n';
    break;
  }
  }

  return 0;
}
