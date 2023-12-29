#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int part1(string input) {
    string line;
    ifstream file(input);
    int sum = 0;

    while (getline(file, line)) {
        string numStr = "";
        for (int i = 0; i < line.length(); i++) {
            if (isdigit(line[i])) {
                numStr.push_back(line[i]);
                break;
            }
        }

        for (int i = line.length() - 1; i >= 0; i--) {
            if (isdigit(line[i])) {
                numStr.push_back(line[i]);
                break;
            }
        }

        sum += stoi(numStr);
    }
    cout << sum << "\n";
    return sum;
}

bool startswith(string input, string starter) {
    return (input.substr(0, starter.length()) == starter);
}

int getdigits(string input) {
    string numStr = "";
    for (int i = 0; i < input.length(); i++) {
        if (isdigit(input[i])) {
            numStr.push_back(input[i]);
            break;
        }
        string rest = input.substr(i);
        if (startswith(rest, "zero")) {
            numStr.push_back('0');
            break;
        } else if (startswith(rest, "one")) {
            numStr.push_back('1');
            break;
        } else if (startswith(rest, "two")) {
            numStr.push_back('2');
            break;
        } else if (startswith(rest, "three")) {
            numStr.push_back('3');
            break;
        } else if (startswith(rest, "four")) {
            numStr.push_back('4');
            break;
        } else if (startswith(rest, "five")) {
            numStr.push_back('5');
            break;
        } else if (startswith(rest, "six")) {
            numStr.push_back('6');
            break;
        } else if (startswith(rest, "seven")) {
            numStr.push_back('7');
            break;
        } else if (startswith(rest, "eight")) {
            numStr.push_back('8');
            break;
        } else if (startswith(rest, "nine")) {
            numStr.push_back('9');
            break;
        }
    }

    for (int i = input.length(); i >= 0; i--) {
        if (isdigit(input[i])) {
            numStr.push_back(input[i]);
            break;
        }
        string rest = input.substr(i);
        if (startswith(rest, "zero")) {
            numStr.push_back('0');
            break;
        } else if (startswith(rest, "one")) {
            numStr.push_back('1');
            break;
        } else if (startswith(rest, "two")) {
            numStr.push_back('2');
            break;
        } else if (startswith(rest, "three")) {
            numStr.push_back('3');
            break;
        } else if (startswith(rest, "four")) {
            numStr.push_back('4');
            break;
        } else if (startswith(rest, "five")) {
            numStr.push_back('5');
            break;
        } else if (startswith(rest, "six")) {
            numStr.push_back('6');
            break;
        } else if (startswith(rest, "seven")) {
            numStr.push_back('7');
            break;
        } else if (startswith(rest, "eight")) {
            numStr.push_back('8');
            break;
        } else if (startswith(rest, "nine")) {
            numStr.push_back('9');
            break;
        }
    }
    return stoi(numStr);
}

int part2(string input) {
    string line;
    ifstream file(input);
    int sum = 0;

    while (getline(file, line)) {
        sum += getdigits(line);
    }
    cout << sum << "\n";
    return sum;
}

int main() {
    // part1("input1");
    part2("input2");
}
