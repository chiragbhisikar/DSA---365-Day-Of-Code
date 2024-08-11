// 50. Pow(x, n)
/*
    Input: x = 2.00000, n = 10
    Output: 1024.00000

    Input: x = 2.10000, n = 3
    Output: 9.26100

    Input: x = 2.00000, n = -2
    Output: 0.25000
    Explanation: 2-2 = 1/22 = 1/4 = 0.25
*/

#include <iostream>
using namespace std;

double myPow(double x, int n)
{
    int i = 0;
    double ans = x;
    int nop = n;

    if (n < 0)
    {
        n = n * (-1);
    }

    while (i != (n - 1))
    {
        ans = ans * x;
        i++;
    }

    if (nop < 0)
    {
        return (1 / ans);
    }

    return ans;
}

int main()
{
    cout << myPow(0.44528, 0);
    return 0;
}