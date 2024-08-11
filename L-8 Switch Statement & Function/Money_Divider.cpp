// Calculator
#include <iostream>
using namespace std;

int main()
{
    int amount, notes;

    cout << "Enter Amount \n=> ";
    cin >> amount;

    switch (1)
    {
    case 1:
        notes = amount / 100;
        cout << "We Need 100 Rs " << notes << " Notes" << endl;
        amount = amount % 100;
        // amount = amount - (int)((amount / 100) * 100);
    case 2:
        notes = amount / 50;
        cout << "We Need 50 Rs " << notes << " Notes" << endl;
        amount = amount % 50;
        // amount = amount - (int)((amount / 50) * 50);
    case 3:
        notes = amount / 20;
        cout << "We Need 20 Rs " << notes << " Notes" << endl;
        amount = amount % 20;
    case 4:
        notes = amount / 1;
        cout << "We Need 1 Rs " << notes << " Notes" << endl;
        amount = amount % 20;
    }

    return 0;
}