#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

// Numeric Constant
bool isNumericConstant(const string &token) {
    if (token.empty())
        return false;

    int i = 0;
    if (token[0] == '+' || token[0] == '-')
        i = 1;

    if (i == (int)token.length())
        return false;

    for (; i < (int)token.length(); i++) {
        if (!isdigit((unsigned char)token[i]))
            return false;
    }
    return true;
}

void question1() {
    string input;
    cout << "Enter an input token: ";
    cin >> input;

    if (isNumericConstant(input))
        cout << "\"" << input << "\" is a numeric constant." << endl;
    else
        cout << "\"" << input << "\" is not numeric." << endl;
}

// Operator
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' ||
            ch == '/' || ch == '%' || ch == '=');
}

void question2() {
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
}

// Comment
void question3() {
    string line, text = "";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flush leftover newline
    cout << "Enter the input (type END on its own line to finish):" << endl;

    while (getline(cin, line)) {
        if (line == "END")
            break;
        text += line + "\n";
    }

    if (!text.empty() && text.back() == '\n')
        text.pop_back();

    bool isComment = false;

    if (text.size() >= 2 && text[0] == '/' && text[1] == '/') {
        isComment = true;
        cout << "This is a single line comment." << endl;
    } else if (text.size() >= 2 && text[0] == '/' && text[1] == '*') {
        size_t closePos = text.find("*/");
        if (closePos != string::npos) {
            isComment = true;
            cout << "This is a multi line comment." << endl;
        }
    }

    if (!isComment)
        cout << "This is not a comment." << endl;
}

// Identifier
bool isIdentifier(const string &token) {
    if (token.empty())
        return false;

    char first = token[0];
    if (!(isalpha((unsigned char)first) || first == '_'))
        return false;

    for (size_t i = 1; i < token.length(); i++) {
        char ch = token[i];
        if (!(isalnum((unsigned char)ch) || ch == '_'))
            return false;
    }
    return true;
}

void question4() {
    string input;
    cout << "Enter an input token: ";
    cin >> input;

    if (isIdentifier(input))
        cout << "\"" << input << "\" is a valid identifier." << endl;
    else
        cout << "\"" << input << "\" is not a valid identifier." << endl;
}

// Average of array
void question5() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<double> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    double avg = (n > 0) ? sum / n : 0;
    cout << "Average = " << avg << endl;
}

// Min and Max of array
void question6() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    if (n == 0) {
        cout << "Array is empty." << endl;
        return;
    }

    int minVal = arr[0], maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) minVal = arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
    }

    cout << "Minimum = " << minVal << endl;
    cout << "Maximum = " << maxVal << endl;
}

// Concatenate first and last name
void question7() {
    string firstName, lastName;
    cout << "Enter first name: ";
    cin >> firstName;
    cout << "Enter last name: ";
    cin >> lastName;

    string fullName = firstName + " " + lastName;
    cout << "full name = \"" << fullName << "\"" << endl;
}

int main() {
    int choice;

    do {
        cout << "\n===== Compiler Design Lab Task 1 =====\n";
        cout << "1. Check Numeric Constant\n";
        cout << "2. Check Operator\n";
        cout << "3. Check Comment\n";
        cout << "4. Check Identifier\n";
        cout << "5. Average of array elements\n";
        cout << "6. Min and Max of array elements\n";
        cout << "7. Concatenate first and last name\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: question1(); break;
            case 2: question2(); break;
            case 3: question3(); break;
            case 4: question4(); break;
            case 5: question5(); break;
            case 6: question6(); break;
            case 7: question7(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
