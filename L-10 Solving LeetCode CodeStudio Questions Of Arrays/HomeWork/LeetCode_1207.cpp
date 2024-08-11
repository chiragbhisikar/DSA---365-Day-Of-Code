// 1207. Unique Number of Occurrences
// https://leetcode.com/problems/unique-number-of-occurrences/description/

/**
 * Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
Input: arr = [1,2]
Output: false
Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true
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

bool uniqueOccurrences(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    vector<int> occurence;
    int count = 0;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] != arr[i + 1])
        {
            occurence.push_back(count);
            count = 0;
        }
        else
        {
            count++;
        }
    }
    occurence.push_back(count);
    sort(occurence.begin(), occurence.end());

    for (int i = 0; i < occurence.size() - 1; i++)
    {
        if (occurence[i] == occurence[i + 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<int> arr1;
    // arr = [1,2,2,1,1,3]
    arr1.push_back(1);
    arr1.push_back(2);
    arr1.push_back(2);
    arr1.push_back(1);
    arr1.push_back(1);
    arr1.push_back(3);

    printArray(arr1);
    cout << (uniqueOccurrences(arr1) ? "true" : "false") << endl;

    vector<int> arr2;
    // arr = [1,2]
    arr2.push_back(1);
    arr2.push_back(2);

    printArray(arr2);
    cout << (uniqueOccurrences(arr2) ? "true" : "false") << endl;

    vector<int> arr3;
    // arr = [-3,0,1,-3,1,1,1,-3,10,0]
    arr3.push_back(-3);
    arr3.push_back(0);
    arr3.push_back(1);
    arr3.push_back(-3);
    arr3.push_back(1);
    arr3.push_back(1);
    arr3.push_back(1);
    arr3.push_back(-3);
    arr3.push_back(10);
    arr3.push_back(0);

    printArray(arr3);
    cout << (uniqueOccurrences(arr3) ? "true" : "false") << endl;
    return 0;
}