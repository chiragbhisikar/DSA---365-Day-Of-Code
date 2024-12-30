#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int consecutiveOnes(vector<int> &arr)
{
    int maxConsecutiveOnes = 0;
    int tempConsecutiveOnes = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 1)
        {
            tempConsecutiveOnes++;
            maxConsecutiveOnes = max(maxConsecutiveOnes, tempConsecutiveOnes);
        }
        else
        {
            tempConsecutiveOnes = 0;
        }
    }

    return maxConsecutiveOnes;
}

int main()
{
    vector<int> arr;
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(0);
    cout << consecutiveOnes(arr) << endl;

    return 0;
}