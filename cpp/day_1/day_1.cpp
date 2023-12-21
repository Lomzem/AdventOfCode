#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string line;
    ifstream MyReadFile("input");
    int sum = 0;

    while (getline(MyReadFile, line)) {
        vector<char> lineDigits;
        for (int i = 0; i < line.length(); i++) {
            if (isdigit(line[i])) {
                lineDigits.push_back(line[i]);
            }
        }
        string lineNumStr =
            string(1, lineDigits.at(0)) + string(1, lineDigits.back());
        // int lineNumInt = stoi(lineNumStr);
        sum += stoi(lineNumStr);
    }
    cout << sum << "\n";
    return sum;
}
