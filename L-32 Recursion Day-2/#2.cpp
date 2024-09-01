#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int fibonacciSeries(int n)
{
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    int ans = fibonacciSeries(n - 1) + fibonacciSeries(n - 2);

    return ans;
}

int main()
{
    int n = 8;
    cout << fibonacciSeries(n) << endl;
    return 0;
}