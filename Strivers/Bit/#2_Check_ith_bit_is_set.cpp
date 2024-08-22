// Check ith bit is set or not
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int number = 5;
    int checkSetIndex = 2;
    // 1 1 0
    // 2 1 0

    int check = 1 << checkSetIndex;
    // 1 1 0
    // 1 0 0 
    // 1 0 0 => Not 0 If 0 That Not Set
    bool ans = (check & number) != 0;
    cout << ans << endl;
    // Or
    number = number >> checkSetIndex;
    ans = number & 1;
    cout << ans << endl;

    return 0;
}