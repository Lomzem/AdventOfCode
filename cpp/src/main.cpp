#include "day02.hpp"
#include "day03.hpp"
#include "day04.hpp"
#include "day05.hpp"
#include "day06.hpp"
#include "day07.hpp"
#include "day08.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
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

  case 5: {
    std::cout << "Day 5\n";
    std::ifstream file(filename);
    std::vector<std::string> input;
    for (std::string range; std::getline(file, range);) {
      input.push_back(range);
    }
    std::cout << "Part 1: ";
    size_t total = day05::part1(input);
    std::cout << total << '\n';

    total = 0;
    std::cout << "Part 2: ";
    total = day05::part2(input);
    std::cout << total << '\n';
    break;
  }

  case 6: {
    std::cout << "Day 6\n";
    std::ifstream file(filename);
    std::vector<std::vector<std::string>> inputpt1;
    std::vector<std::string> inputpt2;

    for (std::string line; std::getline(file, line);) {
      inputpt2.push_back(line);
      std::istringstream iss(line);
      std::vector<std::string> tokens;
      std::string token;
      while (iss >> token) {
        tokens.push_back(token);
      }
      inputpt1.push_back(tokens);
    }

    std::cout << "Part 1: ";
    size_t total = day06::part1(inputpt1);
    std::cout << total << '\n';

    std::cout << "Part 2: ";
    total = day06::part2(inputpt2);
    std::cout << total << '\n';
  }

  case 7: {
    std::cout << "Day 7\n";
    std::ifstream file(filename);
    std::vector<std::string> input;

    for (std::string line; std::getline(file, line);) {
      input.push_back(line);
    }

    std::cout << "Part 1: ";
    size_t res = day07::part1(input);
    std::cout << res << '\n';

    std::cout << "Part 2: ";
    res = day07::part2(input);
    std::cout << res << '\n';
  }

  case 8: {
    std::cout << "Day 8\n";
    std::ifstream file(filename);
    std::vector<std::string> input;

    for (std::string line; std::getline(file, line);) {
      input.push_back(line);
    }

    std::cout << "Part 1: ";
    size_t res = day08::part1(input, 1000);
    std::cout << res << '\n';
  }
  }

  return 0;
}
