#include <bits/stdc++.h>

using namespace std;

int sumOfDivisors(int n)
{
    int finalAns = 0;
    for (int i = 1; i <= n; i++)
    {
        int ans = 0;
        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0)
            {
                ans = ans + j;
            }
        }
        finalAns = finalAns + ans;
    }

    return finalAns;
}
int main()
{
    int n = 4;
    cout << sumOfDivisors(n) << endl;
    return 0;
}