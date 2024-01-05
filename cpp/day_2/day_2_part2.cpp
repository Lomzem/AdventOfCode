#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::unordered_map;
using std::vector;

class DiceGame {
  public:
    string text;
    vector<unordered_map<string, int>> roundsColors;

    DiceGame(string gameText) {
        text = gameText;
        parse_game(text);
        getColorMaxes();
    }

    unordered_map<string, int> getColorMaxes() {
        unordered_map<string, int> colorMaxes;
        for (unordered_map<string, int> roundColor : roundsColors) {
            for (auto const &[key, val] : roundColor) {
                if (colorMaxes.find(key) == colorMaxes.end() ||
                    colorMaxes.at(key) < val) {
                    colorMaxes[key] = val;
                }
            }
        }
        return colorMaxes;
    }

  private:
    void parse_game(string gameText) {
        // vector<unordered_map<string, int>> roundsColors;
        string roundInfo = gameText.substr(gameText.find(":") + 1);

        size_t pos = 0;
        string roundDelim = ";";

        while ((pos = roundInfo.find(roundDelim)) != string::npos) {
            string round = roundInfo.substr(1, pos - 1);
            roundsColors.push_back(parse_round(round));
            roundInfo.erase(0, pos + roundDelim.length());
        }
        string round = roundInfo.substr(1, pos - 1);
        roundsColors.push_back(parse_round(round));
    }

    unordered_map<string, int> parse_round(string roundText) {
        unordered_map<string, int> colorMap;

        size_t pos = 0;
        string roundDelim = ", ";
        while ((pos = roundText.find(roundDelim)) != string::npos) {
            string round = roundText.substr(0, pos);
            int count = std::stoi(round.substr(0, round.find(" ")));
            string color = round.substr(round.find(" ") + 1);

            colorMap.insert({color, count});
            roundText.erase(0, pos + roundDelim.length());
        }

        string round = roundText.substr(0, pos);
        int count = std::stoi(round.substr(0, round.find(" ")));
        string color = round.substr(round.find(" ") + 1);

        colorMap.insert({color, count});
        return colorMap;
    }
};

int part_2(string filename) {
    string line;
    std::ifstream file(filename);
    int sum = 0;

    while (std::getline(file, line)) {
        DiceGame lineGame(line);
        unordered_map<string, int> colorMaxes = lineGame.getColorMaxes();
        int power = 1;
        for (auto i : colorMaxes) {
            power *= i.second;
        }
        sum += power;
    }
    std::cout << sum << "\n";
    return sum;
}

int main() {
    part_2("./part2");
}
