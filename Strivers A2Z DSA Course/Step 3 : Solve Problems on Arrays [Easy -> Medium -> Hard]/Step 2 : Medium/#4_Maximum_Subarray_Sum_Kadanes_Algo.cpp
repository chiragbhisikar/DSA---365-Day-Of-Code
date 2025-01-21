#include <bits/stdc++.h>

using namespace std;

void print(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
// Coding Ninjas If Negative Maxi Then Return 0
int maxSubarraySum(vector<int> arr, int n)
{
    int maxi = INT_MIN;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];

        if (sum < 0)
        {
            sum = 0;
        }

        if (sum > maxi)
        {
            maxi = sum;
        }
    }
    return maxi;
}

// Leetcode If Negative Maxi Then Return Maxi
int maxSubArray(vector<int> &nums)
{
    int maxi = INT_MIN;
    int sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (sum < 0)
        {
            sum = 0;
        }

        sum = sum + nums[i];
        maxi = max(sum, maxi);
    }

    return maxi;
}
int main()
{
    vector<int> v;
    v.push_back(-2);
    v.push_back(1);
    v.push_back(-3);
    v.push_back(4);
    v.push_back(-1);
    v.push_back(2);
    v.push_back(1);
    v.push_back(-5);
    v.push_back(4);
    print(v);
    cout << "Maximum Subarray Sum Is " << maxSubarraySum(v, v.size()) << endl;
    cout << "Maximum Subarray Sum Is " << maxSubArray(v) << endl;

    v.clear();
    v.push_back(-3);
    v.push_back(-5);
    v.push_back(-6);
    print(v);
    cout << "Maximum Subarray Sum Is " << maxSubarraySum(v, v.size()) << endl;
    cout << "Maximum Subarray Sum Is " << maxSubArray(v) << endl;
    return 0;
}