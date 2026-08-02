#include <iostream>
#include <string>
using namespace std;

// check if a word is a recognized keyword
bool isKeyword(string word) {
    string keywords[] = {"cout", "cin", "endl", "int", "float",
                          "char", "double", "void", "return"};
    int count = 9;

    for (int i = 0; i < count; i++) {
        if (word == keywords[i])
            return true;
    }
    return false;
}

// decide what type a single token is
string classify(string token) {
    if (token.empty())
        return "Unknown";

    // string literal, e.g. "Hello"
    if (token[0] == '"')
        return "String Literal";

    // keyword
    if (isKeyword(token))
        return "Keyword";

    // operator (<<, +, -, *, /, =)
    if (token == "<<" || token == ">>" || token == "+" || token == "-" ||
        token == "*" || token == "/" || token == "=")
        return "Operator";

    // punctuation
    if (token == ";" || token == "," || token == "(" || token == ")")
        return "Punctuation";

    // number (all digits)
    bool allDigits = true;
    for (size_t i = 0; i < token.length(); i++) {
        if (!isdigit(token[i]))
            allDigits = false;
    }
    if (allDigits)
        return "Number";

    // letters/digits, not a keyword -> identifier
    if (isalpha(token[0]))
        return "Identifier";

    return "Unknown";
}

int main() {
    string expr = "cout << 60 + sum << \"Hello\" << endl ;";

    cout << "Expression: " << expr << endl << endl;

    int len = expr.length();
    int i = 0;
    int tokenNumber = 0;

    while (i < len) {
        // skip spaces between tokens
        if (expr[i] == ' ') {
            i++;
            continue;
        }

        string token = "";

        if (expr[i] == '"') {
            token += expr[i];
            i++;
            while (i < len && expr[i] != '"') {
                token += expr[i];
                i++;
            }
            if (i < len) {
                token += expr[i]; // closing quote
                i++;
            }
        } else {
            while (i < len && expr[i] != ' ') {
                token += expr[i];
                i++;
            }
        }

        tokenNumber++;
        cout << "Token " << tokenNumber << ": " << token
             << " -> " << classify(token) << endl;
    }

    cout << "\nTotal tokens: " << tokenNumber << endl;

    return 0;
}
