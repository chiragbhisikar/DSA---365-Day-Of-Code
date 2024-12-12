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

void moveZeros(int n, vector<int> arr)
{
    int zeroIndex = -1, elementIndex = -1;
    // Find First Non Zero Element
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            zeroIndex = i;
            break;
        }
    }

    for (int i = zeroIndex + 1; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[zeroIndex], arr[i]);
            zeroIndex++;
        }
        printArray(arr);
    }
}

int main()
{
    vector<int> arr;
    arr.push_back(0);
    arr.push_back(0);
    arr.push_back(74);
    arr.push_back(13);
    arr.push_back(95);
    arr.push_back(36);
    arr.push_back(79);

    // arr.push_back(4);
    // arr.push_back(0);
    // arr.push_back(3);
    // arr.push_back(2);
    // arr.push_back(5);
    moveZeros(arr.size(), arr);

    return 0;
}