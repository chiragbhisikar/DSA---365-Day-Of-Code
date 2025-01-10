// start = 10 goal = 7 => ans = 3
// 1 0 1 0
// 0 1 1 1
// -------
// 1 1 0 1 => Number Of Set Bit Is Answer
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int minBitFlips(int start, int goal)
{
    // Checking Which Bits To Be Different In Both Numbers
    int n = start ^ goal;
    int ans = 0;

    // Counting Number Of Set Bits
    while (n != 0)
    {
        if (n & 1)
        {
            ans++;
        }
        n = n >> 1;
    }

    return ans;
}

int main()
{
    // int start = 10, goal = 7;
    // int start = 3, goal = 4;
    int start = 16, goal = 8;
    cout << minBitFlips(start, goal) << endl;
    return 0;
}
