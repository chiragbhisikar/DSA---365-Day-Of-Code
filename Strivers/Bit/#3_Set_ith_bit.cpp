// Set ith bit

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int number = 5;
    int checkSetIndex = 1;
    int ans = 1 << checkSetIndex;
    ans = ans | number;
    cout << ans << endl;
    return 0;
}