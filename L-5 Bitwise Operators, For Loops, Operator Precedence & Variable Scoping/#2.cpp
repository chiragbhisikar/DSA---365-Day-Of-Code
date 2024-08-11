#include <iostream>
using namespace std;

int main()
{
    int n = 5;

    for (int i = 1; i <= n; i++)
    {
        cout << i << endl;
    }

    // Sum Of N Nature Number

    int sum = 0;

    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }

    cout << "Sum Of First N Natural Number is " << sum << endl;

    int a = 0, b = 1, c = a + b;

    for (int i = 0; i <= n; i++)
    {
        cout << a << " ";

        a = b;
        b = c;
        c = a + b;
    }
    cout << endl;

    // Prime Number
    bool check = true;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            check = false;
            break;
        }
    }
    if (check)
    {
        cout << "Prime Number " << endl;
    }
    else
    {
        cout << "Not Prime Number " << endl;
    }

    return 0;
}