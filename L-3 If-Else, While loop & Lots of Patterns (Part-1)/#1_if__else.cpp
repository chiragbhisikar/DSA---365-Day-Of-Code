#include <iostream>
using namespace std;

int main()
{
    // int n;
    // cout << "Enter N : ";
    // // cin >> n;
    // n = cin.get();
    // cout << "Value Of N is " << n << endl;

    // if (n > 0)
    // {
    //     cout << "+ve";
    // }
    // else
    // {
    //     cout << "-ve";
    // }

    int a, b;

    cout << "Enter A : ";
    cin >> a;

    cout << "Enter B : ";
    cin >> b;

    if (a > b)
    {
        cout << "A Is Greater" << endl;
    }
    else
    {
        cout << "B Is Greater" << endl;
    }
    return 0;
}