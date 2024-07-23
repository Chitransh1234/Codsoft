#include <iostream>
using namespace std;

// Function to perform addition
double add(double a, double b)
{
    return a + b;
}

// Function to perform subtraction
double subtract(double a, double b)
{
    return a - b;
}

// Function to perform multiplication
double multiply(double a, double b)
{
    return a * b;
}

// Function to perform division
double divide(double a, double b)
{
    if (b != 0)
    {
        return a / b;
    }
    else
    {
        cout << "Error: Division by zero is not allowed." << endl;
        return 0;
    }
}

int main()
{
    double num1, num2;
    char operation;
    bool continueCalculation = true;

    while (continueCalculation)
    {
        cout << "Enter the first number: ";
        cin >> num1;
        cout << "Enter the second number: ";
        cin >> num2;

        cout << "Choose an operation (+, -, *, /): ";
        cin >> operation;

        switch (operation)
        {
        case '+':
            cout << "Result: " << add(num1, num2) << endl;
            break;
        case '-':
            cout << "Result: " << subtract(num1, num2) << endl;
            break;
        case '*':
            cout << "Result: " << multiply(num1, num2) << endl;
            break;
        case '/':
            cout << "Result: " << divide(num1, num2) << endl;
            break;
        default:
            cout << "Error: Invalid operation." << endl;
            break;
        }

        char choice;
        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> choice;
        if (choice != 'y' && choice != 'Y')
        {
            continueCalculation = false;
        }
    }

    cout << "Thank you for using the calculator!" << endl;
    return 0;
}
