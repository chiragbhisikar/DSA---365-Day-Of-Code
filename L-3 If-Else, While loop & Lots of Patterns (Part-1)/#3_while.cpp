#include <iostream>
using namespace std;

int main()
{
    // int n = 0;
    // cout << "Enter N : ";
    // cin >> n;

    // int i = 1;
    // while (i <= n)
    // {
    //     cout << i << endl;
    //     i++;
    // }

    // int n = 0;
    // cout << "Enter N : ";
    // cin >> n;

    // int i = 1;
    // int sum = 0;
    // while (i <= n)
    // {
    //     sum = sum + i;
    //     i++;
    // }

    // cout << "Sum Of 1 To " << n << " is " << sum << endl;

    /*
       Sum Of First N Even Number
    */

    // int n = 0;
    // cout << "Enter N : ";
    // cin >> n;

    // int i = 0;
    // int sum = 0;
    // while (i <= n)
    // {
    //     sum = sum + i;
    //     i = i + 2;
    // }

    // cout << "Sum Of 1 To " << n << " is " << sum << endl;

    /*
    Prime Or Not
    */

    int n = 0;
    cout << "Enter N : ";
    cin >> n;

    bool counter = true;
    int i = 2;

    while (i < n)
    {
        if (n % i == 0)
        {
            counter = false;
        }
        i++;
    }

    if (counter)
    {
        cout << "Number Is Prime";
    }
    else
    {
        cout << "Number Is Not Prime" << endl;
    }

    return 0;
}