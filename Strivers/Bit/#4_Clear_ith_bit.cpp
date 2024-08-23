// #4_Clear_ith_bit.cpp
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int number = 7;
    int checkSetIndex = 1;
    int ans = 0;
    ans = ~(1 << checkSetIndex);
    ans = ans & number;

    cout << ans << endl;
    return 0;
}
