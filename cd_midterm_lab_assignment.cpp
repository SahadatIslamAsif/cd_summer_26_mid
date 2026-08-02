/*
 * Midterm Lab Assignment - Compiler Design (Standard Version)
 *
 * Reads a source code text file and, for every line:
 *   - tokenizes it manually (character by character scan, no built-in
 *     tokenizing function like strtok/stringstream)
 *   - identifies each token as Keyword, Identifier, Number, Operator,
 *     or Symbol
 *   - prints the total number of tokens found on that line
 *
 * This version uses plain while/for loops and std::string, which is
 * the most common and easiest style to read for this kind of lab.
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// a few common keywords - just check against this small list
bool isKeyword(string word) {
    string keywords[] = {
        "int", "float", "char", "double", "void", "return",
        "if", "else", "while", "for", "cout", "cin", "main"
    };
    int count = 13;

    for (int i = 0; i < count; i++) {
        if (word == keywords[i])
            return true;
    }
    return false;
}

int main() {
    string filename;
    cout << "Enter the source code text file name: ";
    cin >> filename;

    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Could not open file." << endl;
        return 1;
    }

    string line;
    int lineNumber = 0;

    // read the file line by line
    while (getline(file, line)) {
        lineNumber++;
        cout << "\nLine " << lineNumber << ": " << line << endl;

        int count = 0;
        int i = 0;
        int len = line.length();

        // scan the line character by character
        while (i < len) {
            char ch = line[i];

            // skip spaces/tabs
            if (ch == ' ' || ch == '\t') {
                i++;
                continue;
            }

            // letters -> identifier or keyword
            if (isalpha(ch)) {
                string word = "";
                while (i < len && isalnum(line[i])) {
                    word += line[i];
                    i++;
                }
                count++;
                if (isKeyword(word))
                    cout << "  Token " << count << ": " << word << " -> Keyword" << endl;
                else
                    cout << "  Token " << count << ": " << word << " -> Identifier" << endl;
                continue;
            }

            // digits -> number
            if (isdigit(ch)) {
                string num = "";
                while (i < len && isdigit(line[i])) {
                    num += line[i];
                    i++;
                }
                count++;
                cout << "  Token " << count << ": " << num << " -> Number" << endl;
                continue;
            }

            // operators
            if (ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
                ch == '=' || ch == '<' || ch == '>') {
                count++;
                cout << "  Token " << count << ": " << ch << " -> Operator" << endl;
                i++;
                continue;
            }

            // everything else (brackets, semicolon, quotes, etc.)
            count++;
            cout << "  Token " << count << ": " << ch << " -> Symbol" << endl;
            i++;
        }

        cout << "  Total tokens in this line: " << count << endl;
    }

    file.close();
    return 0;
}
