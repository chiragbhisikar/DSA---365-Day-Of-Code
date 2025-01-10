// #7_Check_Number_Is_Power_Of_2.cpp

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 13;
    int ans = n - 1;
    bool finalAns = (n & ans) == 0;
    cout << finalAns << endl;
    return 0;
}