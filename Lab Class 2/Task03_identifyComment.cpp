#include <iostream>
#include <string>
using namespace std;

bool isSingleLineComment(string line) {
    if (line.size() >= 2 && line[0] == '/' && line[1] == '/')
        return true;
    return false;
}

bool isMultiLineComment(string line) {
    int len = line.size();
    if (len >= 4 && line[0] == '/' && line[1] == '*' && line[len - 2] == '*' && line[len - 1] == '/')
        return true;
    return false;
}

int main() {
    string input;
    cout << "Enter a line: ";
    cin >> input;

    if (isSingleLineComment(input)) {
        cout << "The given input is a single-line comment." << endl;
    } else if (isMultiLineComment(input)) {
        cout << "The given input is a multi-line comment." << endl;
    } else {
        cout << "The given input is not a comment." << endl;
    }

    return 0;
}
