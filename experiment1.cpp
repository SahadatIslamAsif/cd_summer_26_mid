
#include <iostream>
#include <string>
using namespace std;

bool isNumericConstant(const string &token) {
    if (token.empty())
        return false;

    int i = 0;

    // allow an optional sign at the start
    if (token[0] == '+' || token[0] == '-')
        i = 1;

    // if the token was only a sign, it's not a number
    if (i == (int)token.length())
        return false;

    for (; i < (int)token.length(); i++) {
        if (!isdigit((unsigned char)token[i]))
            return false;
    }
    return true;
}

int main() {
    string input;

    cout << "Enter an input token: ";
    cin >> input;

    if (isNumericConstant(input))
        cout << "\"" << input << "\" is a numeric constant." << endl;
    else
        cout << "\"" << input << "\" is not numeric." << endl;

    return 0;
}
