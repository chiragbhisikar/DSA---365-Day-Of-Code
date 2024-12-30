#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(vector<int> nums, vector<vector<int> > &ans, int index)
{
    if (index >= nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for (int j = index; j < nums.size(); j++)
    {
        swap(nums[index], nums[j]);
        solve(nums, ans, index + 1);
        // backtrack
        swap(nums[index], nums[j]);
    }
}
vector<vector<int> > permute(vector<int> &nums)
{
    vector<vector<int> > ans;
    int index = 0;
    solve(nums, ans, index);

    return ans;
}

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);

    vector<vector<int> > ans = permute(nums);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}