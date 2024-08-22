// 137. Single Number II

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int singleNumber(vector<int> &nums)
{
    // int ans = 0;
    // for (int i = 0; i < 3; i++)
    // {
    //     int counter = 0;
    //     for (int j = 0; j < nums.size(); j++)
    //     {
    //         if (nums[j] & 1)
    //         {
    //             counter++;
    //         }
    //         nums[j] = nums[j] >> 1;
    //         cout << nums[j] << "\t";
    //     }
    //     cout << " & counter = " << counter << endl;
    //     if (counter % 3 == 1)
    //     {
    //         // ans = ans << 1;
    //         ans = ans + pow(2, i);
    //     }
    // }
    // cout << ans << endl;

    // map<int, int> ans;
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     int key = nums[i];

    //     if (ans.find(nums[i]) != ans.end())
    //     {
    //         int currentCount = ++ans[nums[i]];
    //         ans[nums[i]] = currentCount;
    //     }
    //     else
    //     {
    //         ans.insert(pair<int, int>(nums[i], 1));
    //     }
    // }

    // for (auto it : ans)
    // {
    //     if (it.second == 1)
    //     {
    //         return it.first;
    //     }
    // }

    int ones = 0, twos = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        ones = (ones ^ nums[i]) & ~twos;
        twos = (twos ^ nums[i]) & ~ones;
    }

    return ones;
}
int main()
{
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);

    cout << singleNumber(nums) << endl;
    return 0;
}