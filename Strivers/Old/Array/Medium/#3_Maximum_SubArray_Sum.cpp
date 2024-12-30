#include <iostream>
#include <bits/stdc++.h>

using namespace std;
long long maxSubarraySum(vector<int> arr, int n)
{
    long long maximumSum = INT_MIN;
    long long sum = 0;

    int start = 0;
    int start_index = -1, end_index = -1;

    for (int i = 0; i < n; i++)
    {
        if (sum == 0)
        {
            start = i;
        }

        sum = sum + arr[i];

        if (maximumSum < sum)
        {
            maximumSum = sum;
            start_index = start;
            end_index = i;
        }

        if (sum < 0)
        {
            sum = 0;
        }
    }

    for (int i = start_index; i <= end_index; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;

    return maximumSum;
}
int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(7);
    arr.push_back(-4);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(-10);
    arr.push_back(9);
    arr.push_back(1);
    cout << maxSubarraySum(arr, arr.size()) << endl;
    return 0;
}