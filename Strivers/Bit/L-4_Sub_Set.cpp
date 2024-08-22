// 78. Subsets
// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// Input: nums = [0]
// Output: [[],[0]]

// TC => O ( N * 2 ^ N)
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
void subsets(vector<int> &nums)
{
    // vector<vector<int> > powerSet;
    int size = nums.size();
    size = 1 << size;

    for (int i = 0; i < size; i++)
    {
        int n = i;
        vector<int> subset;
        int index = nums.size() - 1;

        while (n != 0)
        {
            if (n & 1)
            {
                cout << nums[index] << "\t";
                subset.push_back(nums[index]);
            }
            index--;
            n = n >> 1;
        }
        cout << endl;

        // powerSet.push_back(subset);
    }
    // return powerSet;
}

int main()
{
    vector<int> n;
    n.push_back(1);
    n.push_back(2);
    n.push_back(3);
    subsets(n);
    return 0;
}