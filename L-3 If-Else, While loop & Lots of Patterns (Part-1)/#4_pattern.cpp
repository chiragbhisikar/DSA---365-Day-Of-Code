/*
 * * *
 * * *
 * * *
 */

#include <iostream>
using namespace std;

int main()
{
    int i = 1;
    int n = 5;

    while (i <= n)
    {
        int j = 1;
        while (j <= n)
        {
            cout << "* ";
            j++;
        }
        cout << endl;
        i++;
    }

    i = 1;
    cout << endl;
    while (i <= n)
    {
        int j = 1;
        while (j <= n)
        {
            cout << i << " ";
            j++;
        }
        cout << endl;
        i++;
    }

    return 0;
}