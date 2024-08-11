// 1207. Unique Number of Occurrences
/*
Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
Input: arr = [1,2]
Output: false

Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true

Constraints:
1 <= arr.length <= 1000
-1000 <= arr[i] <= 1000
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
    // sort(arr.begin(), arr.end());
    // vector<int> occurence;

    // int count = 0;

    // for (int i = 0; i < arr.size(); i++)
    // {
    //     if (arr[i] != arr[i + 1])
    //     {
    //         occurence.push_back(count);
    //         count = 0;
    //     }
    //     else
    //     {
    //         count++;
    //     }
    // }

    // sort(occurence.begin(), occurence.end());
    // printArray(occurence);

    // count = 0;
    // for (int i = 0; i < occurence.size(); i++)
    // {
    //     if (arr[i] == arr[i + 1])
    //     {
    //         return false;
    //     }
    // }

    // return true;

    sort(arr.begin(), arr.end());
    vector<int> occurence;

    int count = 1;

    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] != arr[i + 1])
        {
            occurence.push_back(count);
            count = 1;
        }
        else
        {
            count++;
        }
    }
    occurence.push_back(count);

    sort(occurence.begin(), occurence.end());
    printArray(occurence);

    for (int i = 0; i < occurence.size(); i++)
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
    vector<int> arr;
    // [1,2,2,1,1,3]
    // arr.push_back(1);
    // arr.push_back(2);
    // arr.push_back(2);
    // arr.push_back(1);
    // arr.push_back(1);
    // arr.push_back(3);

    // [-3,0,1,-3,1,1,1,-3,10,0]
    // arr.push_back(-3);
    // arr.push_back(0);
    // arr.push_back(1);
    // arr.push_back(-3);
    // arr.push_back(1);
    // arr.push_back(1);
    // arr.push_back(1);
    // arr.push_back(-3);
    // arr.push_back(10);
    // arr.push_back(0);

    // [1,1,1,2,2,2]
    // arr.push_back(1);
    // arr.push_back(1);
    // arr.push_back(1);
    // arr.push_back(2);
    // arr.push_back(2);
    // arr.push_back(2);

    // [-4,3,3]
    // arr.push_back(-4);
    // arr.push_back(3);
    // arr.push_back(3);

    // [1,2]
    arr.push_back(1);
    arr.push_back(2);

    sort(arr.begin(), arr.end());
    printArray(arr);
    cout << (uniqueOccurrences(arr) ? "true" : "false") << endl;
    return 0;
}