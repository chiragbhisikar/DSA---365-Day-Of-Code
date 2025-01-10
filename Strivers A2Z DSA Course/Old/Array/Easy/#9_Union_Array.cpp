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

void sortedArray(vector<int> a, vector<int> b)
{
    vector<int> ans;
    int firstPointer = 0, secondPointer = 0, currentPointer = INT_MIN;
    int firstArrayLength = a.size(), secondArrayLength = b.size();

    while (firstPointer < firstArrayLength && secondPointer < secondArrayLength)
    {
        if (currentPointer == a[firstPointer])
        {
            firstPointer++;
            continue;
        }
        else if (currentPointer == b[secondPointer])
        {
            secondPointer++;
            continue;
        }

        if (a[firstPointer] == b[secondPointer])
        {
            currentPointer = a[firstPointer];
            ans.push_back(currentPointer);
            firstPointer++;
            secondPointer++;
        }
        else if (a[firstPointer] < b[secondPointer])
        {
            currentPointer = a[firstPointer];
            ans.push_back(currentPointer);
            firstPointer++;
        }
        else
        {
            currentPointer = b[secondPointer];
            ans.push_back(currentPointer);
            secondPointer++;
        }
    }

    while (firstPointer < firstArrayLength)
    {
        if (currentPointer == a[firstPointer])
        {
            firstPointer++;
            continue;
        }
        else
        {
            currentPointer = a[firstPointer];
            ans.push_back(currentPointer);
            firstPointer++;
        }
    }

    while (secondPointer < secondArrayLength)
    {
        if (currentPointer == b[secondPointer])
        {
            secondPointer++;
            continue;
        }
        else
        {
            currentPointer = b[secondPointer];
            ans.push_back(currentPointer);
            secondPointer++;
        }
    }

    printArray(ans);
}
int main()
{
    vector<int> a;
    vector<int> b;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    // a.push_back(5);
    a.push_back(6);

    // b.push_back(2);
    b.push_back(2);
    b.push_back(3);
    b.push_back(5);

    sortedArray(a, b);
    return 0;
}