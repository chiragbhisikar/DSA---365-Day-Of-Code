#include <iostream>
using namespace std;

int main()
{
    char a = '1';

    switch (a)
    {
    case '1':
        cout << "Character 1" << endl;
        // break;
    case 1:
        cout << "Integer 1" << endl;
        break;
    default:
        cout << "Default Case" << endl;
        break;
    }

    while (1)
    {
        switch (a)
        {
        case '1':
            cout << "Character 1" << endl;
            exit(0);
            break;
        case 1:
            cout << "Integer 1" << endl;
            break;
        default:
            cout << "Default Case" << endl;
            break;
        }
    }

    cout << "Bahar Nikal Gya!" << endl;
    return 0;
}