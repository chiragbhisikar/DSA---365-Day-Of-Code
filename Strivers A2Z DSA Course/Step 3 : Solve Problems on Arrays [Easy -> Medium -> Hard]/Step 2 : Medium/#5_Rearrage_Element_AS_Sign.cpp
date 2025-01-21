#include <bits/stdc++.h>

using namespace std;

vector<int> rearrangeArray(vector<int> &nums)
{
    // Optimal

    vector<int> ans(nums.size());
    int positivePointer = 0;
    int negativePointer = 1;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
        {
            ans[positivePointer] = nums[i];
            positivePointer += 2;
        }
        else
        {
            ans[negativePointer] = nums[i];
            negativePointer += 2;
        }
    }
    return ans;
}
int main()
{

    return 0;
}