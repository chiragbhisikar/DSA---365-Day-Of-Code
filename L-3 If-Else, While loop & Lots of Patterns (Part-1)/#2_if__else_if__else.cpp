#include <iostream>
using namespace std;

int main()
{
    // int n;
    // cout << "Enter N : ";
    // cin >> n;

    // if (n > 0)
    // {
    //     cout << "+ve";
    // }
    // else if (n < 0)
    // {
    //     cout << "-ve";
    // }
    // else
    // {
    //     cout << "0ve";
    // }

    char ch;
    cout << "Enter Character : ";
    cin >> ch;

    if (ch >= 'a' && ch <= 'z')
    {
        cout << "Small Case Character" << endl;
    }
    else if (ch >= 'A' && ch <= 'Z')
    {
        cout << "Upper Case Character" << endl;
    }
    else if (ch >= '0' && ch <= '9')
    {
        cout << "Number" << endl;
    }

    return 0;
}