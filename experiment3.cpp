 */

#include <iostream>
#include <string>
using namespace std;

int main() {
    string line, text = "";

    cout << "Enter the input (type END on its own line to finish):" << endl;

    while (getline(cin, line)) {
        if (line == "END")
            break;
        text += line + "\n";
    }

    // remove the trailing newline we added for the last real line
    if (!text.empty() && text.back() == '\n')
        text.pop_back();

    bool isComment = false;

    // Case 1: single line comment -> the text starts with //
    if (text.size() >= 2 && text[0] == '/' && text[1] == '/') {
        isComment = true;
        cout << "This is a single line comment." << endl;
    }
    // Case 2: multi line comment -> starts with /* and contains a closing */
    else if (text.size() >= 2 && text[0] == '/' && text[1] == '*') {
        size_t closePos = text.find("*/");
        if (closePos != string::npos) {
            isComment = true;
            cout << "This is a multi line comment." << endl;
        }
    }

    if (!isComment)
        cout << "This is not a comment." << endl;

    return 0;
}
