// GCD(a,b) => GCD(a-b,b) => Euclidiam Algorithm

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int getGcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    if (b == 0)
    {
        return a;
    }

    while (a != b)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }
    return a;
}
int main()
{
    int a = 12, b = 15;
    cout << getGcd(a, b);
    return 0;
}