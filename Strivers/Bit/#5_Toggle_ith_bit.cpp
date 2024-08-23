// Toggle ith Bit
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int number = 13;
    int checkSetIndex = 2;
    // 1 1 0 1
    // ans = 1 0 0 1
    int ans = (1 << checkSetIndex) ^ number;
    cout << ans << endl;
    return 0;
}