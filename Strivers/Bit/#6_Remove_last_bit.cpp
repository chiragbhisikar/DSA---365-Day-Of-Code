// Remove Last Bit Set Bit

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int number = 13;
    // 1 1 0 1
    // 1 1 0 0
    int ans = number & (number - 1);
    cout << ans << endl;
    return 0;
}
