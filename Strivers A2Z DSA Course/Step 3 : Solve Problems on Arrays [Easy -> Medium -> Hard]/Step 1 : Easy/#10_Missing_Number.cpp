#include <bits/stdc++.h>

using namespace std;

int missingNumber(vector<int> &a, int N)
{
    // int ans = (N*(N+1))/2;
    // for(int i = 0; i < a.size(); i++){
    //     ans -= a[i];
    // }

    // return ans;

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
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(5);

    int missing = missingNumber(arr, arr.size() + 1);
    cout << "missing number is " << missing << endl;
    return 0;
}