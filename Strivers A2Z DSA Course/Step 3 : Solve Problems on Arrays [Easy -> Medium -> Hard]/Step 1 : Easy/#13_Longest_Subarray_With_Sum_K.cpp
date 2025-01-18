// https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_6682399?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems&leftPanelTabValue=PROBLEM
#include <bits/stdc++.h>

using namespace std;

int longestSubarrayWithSumK(vector<int> arr, long long k)
{
    int left = 0, right = 0;
    long long sum = arr[0];
    int maxLen = 0;
    int n = arr.size();

    while (right < n)
    {
        while (left <= right && sum > k)
        {
            sum = sum - arr[left];
            left++;
        }

        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }

        right++;
        if (right < n)
        {
            sum = sum + arr[right];
        }
    }
    return maxLen;
}

int main()
{
    vector<int> arr;
    int k = 3;

    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(1);

    cout << "longest Subarray With Sum " << k << " is " << longestSubarrayWithSumK(arr, k) << endl;
    return 0;
}