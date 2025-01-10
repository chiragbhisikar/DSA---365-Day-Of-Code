#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int longestSubarrayWithSumK(vector<int> arr, long long k)
{
    // Brute Force O(N^2)
    // int largestSumOfSubArray = 0;

    // for (int i = 0; i < arr.size(); i++)
    // {
    //     long long sumOfSubArray = 0;
    //     int subArrayCount = 1;
    //     bool flag = false;

    //     for (int j = i; j < arr.size(); j++)
    //     {
    //         sumOfSubArray = sumOfSubArray + arr[j];
    //         cout << arr[j] << "\t";
    //         if (sumOfSubArray > k)
    //         {
    //             flag = true;
    //             break;
    //         }
    //         else if (sumOfSubArray < k)
    //         {
    //             subArrayCount++;
    //         }
    //         else
    //         {
    //             break;
    //         }
    //     }
    //     cout << endl;
    //     if (flag && largestSumOfSubArray <= subArrayCount)
    //     {
    //         largestSumOfSubArray = subArrayCount;
    //     }
    //     if (subArrayCount == k)
    //     {
    //         break;
    //     }
    // }

    // return largestSumOfSubArray;

    // Better => O(N log N)

    // map<long long, int> preSumMap;
    // long long sum = 0;
    // int maxLen = 0;

    // for (int i = 0; i < arr.size(); i++)
    // {
    //     sum = sum + arr[i];
    //     if (sum == k)
    //     {
    //         maxLen = max(maxLen, i + 1);
    //     }
    //     long long rem = sum - k;

    //     if (preSumMap.find(rem) != preSumMap.end())
    //     {
    //         int len = i - preSumMap[rem];
    //         maxLen = max(maxLen, len);
    //     }

    //     if (preSumMap.find(sum) == preSumMap.end())
    //     {
    //         preSumMap[sum] = i;
    //     }
    // }

    // For Understanding Only

    // for (auto i : preSumMap)
    // {
    //     cout << i.first << "\t" << i.second << endl;
    // }

    // return maxLen;

    int left = 0, right = 0;
    long long sum = arr[0];
    int longestSubArrayWithSum = 0;
    int n = arr.size();

    while (right < n)
    {
        // loop till sum is not become lesser than k
        // and take care of left does not exceed right
        while (left <= right && sum > k)
        {
            sum = sum - arr[left];
            left++;
        }

        // if sum = k, update the longestSubArrayWithSum
        if (sum == k)
        {
            longestSubArrayWithSum = max(longestSubArrayWithSum, right - left + 1);
        }

        // Move forward thw right pointer
        right++;
        if (right < n)
        {
            sum = sum + arr[right];
        }
    }

    return longestSubArrayWithSum;
}

int main()
{
    vector<int> arr;

    // arr.push_back(1);
    // arr.push_back(2);
    // arr.push_back(1);
    // arr.push_back(3);
    // int k = 2;

    // arr.push_back(8);
    // arr.push_back(15);
    // arr.push_back(17);
    // arr.push_back(0);
    // arr.push_back(11);
    // int k = 17;

    // arr.push_back(1);
    // arr.push_back(2);
    // arr.push_back(3);
    // arr.push_back(1);
    // arr.push_back(1);
    // arr.push_back(1);
    // arr.push_back(1);
    // int k = 4;

    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(1);
    arr.push_back(2);
    int k = 2;

    cout << longestSubarrayWithSumK(arr, k) << endl;
    return 0;
}