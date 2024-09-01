#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void printArray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}
void findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    vector<int> ans;
    int firstPointer = 0, secondPointer = 0;

    while (firstPointer < n && secondPointer < m)
    {
        if (arr1[firstPointer] == arr2[secondPointer])
        {
            ans.push_back(arr1[firstPointer]);
            firstPointer++;
            secondPointer++;
        }
        else if (arr1[firstPointer] < arr2[secondPointer])
        {
            firstPointer++;
        }
        else
        {
            secondPointer++;
        }
    }
    printArray(ans);
}
int main()
{
    vector<int> arr1;
    arr1.push_back(1);
    arr1.push_back(2);
    arr1.push_back(2);
    arr1.push_back(2);
    arr1.push_back(3);
    arr1.push_back(4);

    vector<int> arr2;
    arr2.push_back(2);
    arr2.push_back(2);
    arr2.push_back(3);
    arr2.push_back(3);

    findArrayIntersection(arr1, arr1.size(), arr2, arr2.size());
    return 0;
}