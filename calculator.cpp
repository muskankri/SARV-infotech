#include <iostream>
using namespace std;
int main() {
    double num1, num2;
    char operation;
    cout << "Welcome in the simple calculator.\n";
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the operation (+, -, *, /) : ";
    cin >> operation;
    cout << "Enter the second number: ";
    cin >> num2;
    switch (operation) {
        case '+':
            cout << "Required sum = " << num1 << " + " << num2 << " = " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Required difference = " << num1 << " - " << num2 << " = " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Required product = " << num1 << " * " << num2 << " = " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0) {
                cout << "Required division = " << num1 << " / " << num2 << " = " << num1 / num2 << endl;
            } else {
                cout << "Error! Division by zero is not allowed." << endl;
            }
            break;
        default:
            cout << "Error! Invalid operation. Please try again." << endl;
            break;
    }
    return 0;
}
