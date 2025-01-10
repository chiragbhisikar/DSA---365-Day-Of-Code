#include <bits/stdc++.h>

using namespace std;
int gcd(int a, int b)
{
    if (a > b)
    {
        return gcd(a - b, b);
    }
    else if (b > a)
    {
        return gcd(b - a, a);
    }
    return a;
}

int main()
{
    int a = 20, b = 5;
    cout << gcd(a, b) << endl;
    return 0;
}