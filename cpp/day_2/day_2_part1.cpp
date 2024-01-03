#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using std::cout;
using std::string;
using std::unordered_map;

class DiceGame {
  public:
    string text;
    uint gameID;
    unordered_map<string, uint> maxColors{
        {"red", 12},
        {"green", 13},
        {"blue", 14},
    };

    DiceGame(string gameText) {
        text = gameText;
        parse_game_id();
    }

    bool isValidGame() {
        // text example: Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
        string colorsInfo = text.substr(text.find(":") + 1);
        // colorsInfo includes a space at the beginning
        size_t pos = 0;
        string roundDelim = ";";
        while ((pos = colorsInfo.find(roundDelim)) != string::npos) {
            string round = colorsInfo.substr(0, pos);
            if (!isValidRound(round)) {
                return false;
            }
            colorsInfo.erase(0, pos + roundDelim.length());
        }
        if (!isValidRound(colorsInfo)) {
            return false;
        }
        return true;
    }

  private:
    bool isValidColor(string colorInfo) {
        colorInfo = colorInfo.substr(1);
        int colorCount = std::stoi(colorInfo.substr(0, colorInfo.find(' ')));
        string color = colorInfo.substr(colorInfo.find(' ') + 1);
        uint maxColor = maxColors.at(color);
        return colorCount <= maxColor;
    }

    bool isValidRound(string round) {
        size_t pos = 0;
        string colorInfo;
        string colorDelim = ",";
        while ((pos = round.find(colorDelim)) != string::npos) {
            string token = round.substr(0, pos);
            if (!isValidColor(token)) {
                return false;
            }
            round.erase(0, pos + colorDelim.length());
        }

        // now "round" is just the last colorInfo
        if (!isValidColor(round)) {
            return false;
        }

        return true;
    }

    void parse_game_id() {
        size_t colonIndex = text.find(":");
        // Skip first 5 characters to skip "Game" part of text
        // Game 11: ... ...
        string gameIDstr = text.substr(5, colonIndex - 5);
        gameID = std::stoi(gameIDstr);
    }
};

int part_1(string filename) {
    string line;
    std::ifstream file(filename);
    int sum = 0;

    while (std::getline(file, line)) {
        DiceGame lineGame(line);
        cout << "Game " << lineGame.gameID << ": " << lineGame.isValidGame()
             << "\n";
        if (lineGame.isValidGame()) {
            sum += lineGame.gameID;
        }
    }
    return sum;
}

int part_2(string filename) {
    string line;
    std::ifstream file(filename);
    int sum = 0;

    while (std::getline(file, line)) {
        DiceGame lineGame(line);
    }
    return sum;
}

int main() {
    // int result = part_1("./part1");
    // cout << result << "\n";
    // return 1;
}
