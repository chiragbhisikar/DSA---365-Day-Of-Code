// 448. Find All Numbers Disappeared in an Array
// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/

/**
 * Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]
Input: nums = [1,1]
Output: [2]

Constraints:
n == nums.length
1 <= n <= 105
1 <= nums[i] <= n
*/

#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

vector<int> findDisappearedNumbers(vector<int> &arr)
{
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        int temp = abs(arr[i]);
        if (arr[temp - 1] > 0)
        {
            arr[temp - 1] *= (-1);
        }
    }
    printArray(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > 0)
        {
            ans.push_back(i + 1);
        }
    }
    printArray(ans);
    return ans;
}

int main()
{
    vector<int> nums;
    // nums = [4,3,2,7,8,2,3,1];
    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(8);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);

    // printArray(nums);

    // nums.push_back(1);
    // nums.push_back(1);
    // nums.push_back(2);
    // nums.push_back(2);
    findDisappearedNumbers(nums);

    // nums.clear();
    // nums.push_back(1);
    // nums.push_back(1);

    // printArray(nums);
    // findDisappearedNumbers(nums);
    return 0;
}