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
void reverseArray(vector<int> &arr, int m)
{
    int start = m + 1, end = arr.size() - 1;
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
    printArray(arr);
}

int main()
{
    vector<int> arr;
    // arr.push_back(1);
    // arr.push_back(4);
    // arr.push_back(5);
    // arr.push_back(6);
    // arr.push_back(6);
    // arr.push_back(7);
    // arr.push_back(7);

    // 10 4 5 2 3 6 1 3 6
    arr.push_back(10);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(6);
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(6);

    reverseArray(arr, 3);
    return 0;
}