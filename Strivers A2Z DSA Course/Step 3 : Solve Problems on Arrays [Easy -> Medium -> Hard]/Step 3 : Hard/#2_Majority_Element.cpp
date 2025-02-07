#include <bits/stdc++.h>

using namespace std;

void print(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Better Approach => T.C -> O(n) & S.C -> O(N)
/*
vector<int> majorityElement(vector<int> nums) {
   int atMinimum = nums.size() / 3;
        map<int, int> counting;

        for (int i = 0; i < nums.size(); i++) {
            counting[nums[i]] = counting[nums[i]] + 1;
        }

        vector<int> ans;
        for (auto it : counting) {
            if (it.second > atMinimum) {
                ans.push_back(it.first);
            }
        }
        return ans;
}
*/

// Optimal Approach => T.C -> O(n) & S.C -> O(1)
vector<int> majorityElement(vector<int> nums)
{
    int cnt1 = 0, elementOne = INT_MIN;
    int cnt2 = 0, elementTwo = INT_MIN;

    for (int i = 0; i < nums.size(); i++)
    {
        if (cnt1 == 0 && nums[i] != elementTwo)
        {
            cnt1 = 1;
            elementOne = nums[i];
        }
        else if (cnt2 == 0 && nums[i] != elementOne)
        {
            cnt2 = 1;
            elementTwo = nums[i];
        }
        else if (elementOne == nums[i])
        {
            cnt1++;
        }
        else if (elementTwo == nums[i])
        {
            cnt2++;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }

    cnt1 = 0;
    cnt2 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (elementOne == nums[i])
        {
            cnt1++;
        }
        if (elementTwo == nums[i])
        {
            cnt2++;
        }
    }

    int minimumCount = nums.size() / 3;
    vector<int> ans;
    if (cnt1 > minimumCount)
    {
        ans.push_back(elementOne);
    }
    if (cnt2 > minimumCount)
    {
        ans.push_back(elementTwo);
    }

    return ans;
}

int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(2);
    v.push_back(1);
    v.push_back(3);
    v.push_back(1);
    v.push_back(1);
    v.push_back(3);
    v.push_back(1);
    v.push_back(1);

    v = majorityElement(v);
    print(v);
    return 0;
}