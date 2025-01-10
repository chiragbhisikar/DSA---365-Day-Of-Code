#include <bits/stdc++.h>

using namespace std;

int firstNSum(int n, int sum = 0, int i = 1)
{
    if (i > n)
    {
        return sum;
    }
    sum = sum + i;
    return firstNSum(n, sum, i + 1);
}
int main()
{
    cout << firstNSum(5) << endl;
    return 0;
}