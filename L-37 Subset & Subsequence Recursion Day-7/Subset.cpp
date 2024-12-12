
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void solve(vector<int> nums, vector<int> output, int index,
           vector<vector<int>> &ans)
{
    if (index >= nums.size())
    {
        ans.push_back(output);
        return;
    }
    // exclude
    solve(nums, output, index + 1, ans);

    // include
    int element = nums[index];
    output.push_back(element);
    solve(nums, output, index + 1, ans);
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;

    solve(nums, output, index, ans);

    return ans;
}

// vector<vector<int>> powerSet;
// for (int i = 0; i < pow(2, nums.size()); i++) {
//     int n = i;
//     vector<int> subset;
//     int index = nums.size() - 1;

//     while (n != 0) {
//         if (n & 1) {
//             subset.push_back(nums[index]);
//         }
//         n = n >> 1;
//         index--;
//     }
//     powerSet.push_back(subset);
// }
// return powerSet;


int main(){
    	
    return 0;
}