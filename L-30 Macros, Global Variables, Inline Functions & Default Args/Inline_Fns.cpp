#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int getMax(int& a, int& b)
{
    return (a > b) ? a : b;
}
int main()
{
    int a = 10;
    int b = 20;
    int ans = getMax(a, b);
    cout << ans << endl;

    a = 30;
    b = 50;
    ans = getMax(a, b);
    cout << ans << endl;
    return 0;
}