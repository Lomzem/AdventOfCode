#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::isdigit;
using std::min;
using std::string;
using std::vector;

class Schematic {
  public:
    string schematicText;

    Schematic(string text) {
        schematicText = text;
    }

    int extractNumSums() {
        int sum = 0;
        vector<string> lines = stringSplitLines(schematicText);

        for (int line = 0; line < lines.size(); line++) {
            string curLine = lines[line];
            size_t col = 0;
            int colStart = 0;

            while (col < curLine.length()) {
                string currentNum = "";
                if (col != 0) {
                    colStart = col - 1;
                }

                while (isdigit(curLine[col])) {
                    currentNum += curLine[col];
                    col++;
                }
                int colEnd = min(col, curLine.length() - 1);

                if (currentNum == "") {
                    col++;
                    continue;
                }

                char charStart = curLine[colStart];
                char charEnd = curLine[colEnd];

                bool startIsSymbol = colStart >= 0 && isSymbol(charStart);
                bool endIsSymbol =
                    colEnd < curLine.length() - 1 && isSymbol(charEnd);

                if (startIsSymbol || endIsSymbol) {
                    int num = std::stoi(currentNum);
                    sum += num;
                    std::cout << "found " << num << " from simple\n";
                    col++;
                    continue;
                }

                for (int i = colStart; i <= colEnd; i++) {
                    bool prevLineExists = line - 1 >= 0;
                    bool nextLineExists = line + 1 < lines.size();

                    bool prevLineIsSymbol = false;
                    bool nextLineIsSymbol = false;

                    if (prevLineExists) {
                        prevLineIsSymbol = isSymbol(lines[line - 1][i]);
                    }
                    if (nextLineExists) {
                        nextLineIsSymbol = isSymbol(lines[line + 1][i]);
                    }

                    if (prevLineIsSymbol || nextLineIsSymbol) {
                        int num = std::stoi(currentNum);
                        sum += num;
                        std::cout << "found " << num << "\n";
                        break;
                    }
                }
            }
            col++;
        }
        std::cout << "total sum: " << sum << "\n";
        return sum;
    }

  private:
    vector<string> stringSplitLines(string input) {
        vector<string> result;
        std::istringstream stream(input);
        string line;

        while (std::getline(stream, line)) {
            result.push_back(line);
        }
        return result;
    }

    bool isSymbol(char c) {
        return (!isdigit(c) && !(c == '.'));
    }
};

int part_1(string filename) {
    string line;
    std::ifstream file(filename);
    std::stringstream buffer;
    buffer << file.rdbuf();
    string fileContents = buffer.str();
    Schematic schematic(fileContents);

    return schematic.extractNumSums();
}

int main() {
    // part_1("./input1");
    part_1("./example_1");
    return 1;
}
