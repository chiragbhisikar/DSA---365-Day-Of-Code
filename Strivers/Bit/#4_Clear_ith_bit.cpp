// #4_Clear_ith_bit.cpp
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int number = 13;
    int checkSetIndex = 2;
    int ans = ~(1 << checkSetIndex);
    ans = ans & number;

    cout << ans << endl;
    return 0;
}
