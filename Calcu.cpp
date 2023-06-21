#include <iostream>
#include <string>
#include <cctype>
using namespace std;

const int MAX_HISTORY_SIZE = 100;  // Maximum number of equations to store in history

struct Equation {
    string* equation;
    string* answer;
};

int ans;
int addition(int num1, int num2);
int subtraction(int num1, int num2);
int multiplication(int num1, int num2);
int division(int num1, int num2);
void displayHistory(Equation* equationHistory, int count);

int main() {
    char back;

    do {
        int num1;
        int num2;
        char opt;

        Equation equationHistory[MAX_HISTORY_SIZE];  // Array to store equations and answers as structs
        int count = 0;                               // Count of equations in history

        do {
                system("CLS");
                cout << "Enter the equation: ";
                if (!(cin >> num1 >> opt >> num2)) {
                    cout << "Invalid input. Please enter numeric values." << endl;
                    cin.clear();
                    break;
                }

            string equation = to_string(num1) + " " + opt + " " + to_string(num2);

            if (opt == '+') {
                ans = addition(num1, num2);
            } else if (opt == '-') {
                ans = subtraction(num1, num2);
            } else if (opt == '*') {
                ans = multiplication(num1, num2);
            } else if (opt == '/') {
                if (num2 == 0) {
                    cout << "Division by zero is not allowed." << endl;
                    continue;
                }
                ans = division(num1, num2);
            } else {
                cout << "Invalid operator" << endl;
                continue;
            }

            string answer = to_string(ans);

            equationHistory[count].equation = new string(equation);
            equationHistory[count].answer = new string(answer);
            count++;

            cout << "Answer: " << answer << endl << endl;

            displayHistory(equationHistory, count);  // Display the history

            cout << "Continue solving problems? [Y/N] ";
            cin >> back;
            if(back != 'Y' || 'y' || 'N' || 'n'){
                cout<< " Invalid Choice";
            }else{
                continue;
            }
            cout << endl << endl;

        } while (back == 'y' || back == 'Y');

        cout << "Do you want to view the history of all problems solved? [Y/N] ";
        cin >> back;
        cout << endl;

        if (back == 'y' || back == 'Y') {
            displayHistory(equationHistory, count);
        }

        cout << "Continue with a new set of problems? [Y/N] ";
        cin >> back;
        cout << endl << endl;

    } while (back == 'y' || back == 'Y');

    return 0;
}

int addition(int num1, int num2) {
    ans = num1 + num2;
    return ans;
}

int subtraction(int num1, int num2) {
    ans = num1 - num2;
    return ans;
}

int multiplication(int num1, int num2) {
    ans = num1 * num2;
    return ans;
}

int division
(int num1, int num2) {
    if (num2 == 0) {
        cout << "Division by zero is not allowed." << endl;
        return 0;
    } else {
        ans = num1 / num2;
        return ans;
    }
}

void displayHistory(Equation* equationHistory, int count) {
    cout << "History:" << endl;
    for (int i = 0; i < count; i++) {
        cout << *equationHistory[i].equation << " = " << *equationHistory[i].answer << " (" << &equationHistory[i] << ")" << endl;
    }
    cout << endl;
}
