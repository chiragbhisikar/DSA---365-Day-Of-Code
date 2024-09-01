#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int missingNumber(vector<int> &a, int N)
{
    // Optimal 1
    // int ans = (N * (N + 1)) / 2;
    // for (int i = 0; i < a.size(); i++)
    // {
    //     ans -= a[i];
    // }

    // return ans;

    // Optimal 2
    int xor1 = 0, xor2 = 0;

    for (int i = 0; i < N - 1; i++)
    {
        xor2 = xor2 ^ a[i];    // XOR of array elements
        xor1 = xor1 ^ (i + 1); // XOR up to [1...N-1]
    }
    xor1 = xor1 ^ N; // XOR up to [1...N]

    return (xor1 ^ xor2);
}

int main()
{
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_back(6);
    a.push_back(7);
    a.push_back(8);
    a.push_back(10);
    cout << missingNumber(a, 10) << endl;
    return 0;
}