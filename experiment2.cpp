#include <iostream>
#include <string>
using namespace std;

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' ||
            ch == '/' || ch == '%' || ch == '=');
}

int main() {
    string input;

    cout << "Enter an expression (e.g. 2+3=5): ";
    cin >> input;

    int opCount = 0;

    for (size_t i = 0; i < input.length(); i++) {
        if (isOperator(input[i])) {
            opCount++;
            cout << "operator" << opCount << ": " << input[i] << endl;
        }
    }

    if (opCount == 0)
        cout << "No operator found in the input." << endl;

    return 0;
}
