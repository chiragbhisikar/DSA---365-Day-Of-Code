// 442. Find All Duplicates in an Array
// https://leetcode.com/problems/find-all-duplicates-in-an-array/description/

/**
 * Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each    integer appears once or twice, return an array of all the integers that appears twice.
  You must write an algorithm that runs in O(n) time and uses only constant extra space.
Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
Input: nums = [1,1,2]
Output: [1]
Input: nums = [1]
Output: []
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

void findDuplicates(vector<int> &nums)
{
    vector<int> answer;
    for (int i = 0; i < nums.size(); ++i)
    {
        int temp = abs(nums[i]);
        if (nums[temp - 1] < 0)
        {
            cout << "pushing " << temp << endl;
            answer.push_back(temp);
        }
        else
        {
            nums[temp - 1] = nums[temp - 1] * (-1);
            cout << "popping " << nums[temp - 1] << endl;
        }
    }

    printArray(nums);
    printArray(answer);
}
/**
 * vector<int> findDuplicates(vector<int>& arr) {
        vector<int> answer;
        for (int i = 0; i < arr.size(); i++) {
            int temp = abs(arr[i]);
            if (arr[temp - 1] < 0) {
                answer.push_back(temp);
            } else {
                arr[temp - 1] = arr[temp - 1] * (-1);
            }

            for (int i = 0; i < arr.size(); i++) {
                int temp = abs(arr[i]);
                if (arr[temp - 1] < 0) {
                    answer.push_back(temp);
                } else {
                    arr[temp - 1] = arr[temp - 1] * (-1);
                }
            }
        }
        return answer;
    }
 */

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

    // nums = [ 1, 1, 2 ];
    // nums.push_back(1);
    // nums.push_back(1);
    // nums.push_back(2);

    printArray(nums);
    // findDuplicates(nums);
    vector<int> answer;

    for (int i = 0; i < nums.size(); ++i)
    {
        int temp = abs(nums[i]);
        if (nums[temp - 1] < 0)
        {
            cout << "pushing " << temp << endl;
            answer.push_back(temp);
        }
        else
        {
            nums[temp - 1] = nums[temp - 1] * (-1);
            cout << "popping " << nums[temp - 1] << endl;
        }
    }

    return 0;
}

/*
 vector<int> ans;
        if(arr.size() == 1){
            return ans;
        }
        sort(arr.begin(),arr.end());
        int count = 0;
        int n = arr.size();

        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] == arr[i + 1])
            {
                arr.push_back(arr[i]);
                count++;
            }
        }
        arr.erase(arr.begin(), arr.end() - count);

        return arr;
    }
*/