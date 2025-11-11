#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ---------- Task 1: Check if a string is numeric ----------
bool isNumeric(const string& s) {
    if (s.empty()) return false;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] < '0' || s[i] > '9') {
            return false;
        }
    }
    return true;
}

// ---------- Task 2: Check for arithmetic operators ----------
void checkOperators() {
    string expr;
    cout << "Enter an expression: ";
    cin >> expr;

    string ops = "+-*/%=";
    int count = 0;

    for (int i = 0; i < expr.length(); i++) {
        for (int j = 0; j < ops.length(); j++) {
            if (expr[i] == ops[j]) {
                count++;
                cout << "Operator " << count << ": " << expr[i] << endl;
            }
        }
    }

    if (count == 0)
        cout << "No arithmetic operators found.\n";
}

// ---------- Task 3: Check for comments ----------
void checkComment() {
    string line;
    cout << "Enter a line of code: ";
    getline(cin, line);

    if (line.length() >= 2 && line[0] == '/' && line[1] == '/')
        cout << "This is a single-line comment.\n";
    else if (line.find("/*") != string::npos && line.find("*/") != string::npos)
        cout << "This is a multi-line comment.\n";
    else
        cout << "This is not a comment.\n";
}

// ---------- Task 4: Check valid identifier ----------
bool isIdentifier(const string& word) {
    if (word.empty()) return false;

    if (!(isalpha(word[0]) || word[0] == '_'))
        return false;

    for (int i = 1; i < word.length(); i++) {
        if (!(isalnum(word[i]) || word[i] == '_'))
            return false;
    }
    return true;
}

void checkIdentifier() {
    string word;
    cout << "Enter a word: ";
    cin >> word;

    if (isIdentifier(word))
        cout << word << " is a VALID Identifier.\n";
    else
        cout << word << " is NOT a VALID Identifier.\n";
}

// ---------- Task 5: Calculate average ----------
void calculateAverage() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of elements!\n";
        return;
    }

    vector<int> nums(n);
    int sum = 0;

    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        sum += nums[i];
    }

    cout << "Average: " << (float)sum / n << endl;
}

// ---------- Task 6: Find min and max ----------
void findMinMax() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of elements!\n";
        return;
    }

    vector<int> nums(n);
    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int minVal = nums[0];
    int maxVal = nums[0];

    for (int i = 1; i < n; i++) {
        if (nums[i] < minVal)
            minVal = nums[i];
        if (nums[i] > maxVal)
            maxVal = nums[i];
    }

    cout << "Minimum: " << minVal << endl;
    cout << "Maximum: " << maxVal << endl;
}

// ---------- Task 7: Concatenate names ----------
void concatName() {
    string first, last;
    cout << "Enter first name: ";
    cin >> first;
    cout << "Enter last name: ";
    cin >> last;
    cout << "Full name: " << first + " " + last << endl;
}

// ---------- Menu ----------
void showMenu() {
    cout << "\n=========== MENU ===========\n";
    cout << "1. Check Numeric\n";
    cout << "2. Check Operators\n";
    cout << "3. Check Comment Line\n";
    cout << "4. Check Identifier\n";
    cout << "5. Find Average\n";
    cout << "6. Find Min & Max\n";
    cout << "7. Concatenate Name\n";
    cout << "0. Exit\n";
    cout << "============================\n";
}

int main() {
    int choice;

    while (true) {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear newline

        if (choice == 0) {
            cout << "Exiting... Goodbye!\n";
            break;
        }

        switch (choice) {
            case 1: {
                string s;
                cout << "Enter a string: ";
                cin >> s;
                cout << (isNumeric(s) ? "Numeric string.\n" : "Not numeric.\n");
                break;
            }
            case 2:
                checkOperators();
                break;
            case 3:
                checkComment();
                break;
            case 4:
                checkIdentifier();
                break;
            case 5:
                calculateAverage();
                break;
            case 6:
                findMinMax();
                break;
            case 7:
                concatName();
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }

        cout << "------------------------------------\n";
    }

    return 0;
}
