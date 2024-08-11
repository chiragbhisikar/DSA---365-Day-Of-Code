// Calculator
#include <iostream>
using namespace std;

int main()
{
    int a, b;
    char operation;

    cout << "Enter First Number \n=> ";
    cin >> a;

    cout << "Enter Operation\n=> ";
    cin >> operation;

    cout << "Enter Second Number \n=> ";
    cin >> b;

    switch (operation)
    {
    case '+':
        cout << a << " + " << b << " = " << (a + b) << endl;
        break;
    case '-':
        cout << a << " - " << b << " = " << (a - b) << endl;
        break;
    case '*':
        cout << a << " * " << b << " = " << (a * b) << endl;
        break;
    case '/':
        cout << a << " / " << b << " = " << (a / b) << endl;
        break;
    case '%':
        cout << a << " % " << b << " = " << (a % b) << endl;
        break;
    default:
        cout << "Please Enter Valid Operation";
        break;
    }

    return 0;
}