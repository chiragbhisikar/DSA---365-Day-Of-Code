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

vector<int> alternateNumbers(vector<int> &a)
{
    vector<int> ans(a.size(), 0);
    int positiveIndex = 0;
    int negativeIndex = 1;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] > 0)
        {
            ans[positiveIndex] = a[i];
            positiveIndex = positiveIndex + 2;
        }
        else
        {
            ans[negativeIndex] = a[i];
            negativeIndex = negativeIndex + 2;
        }
    }

    printArray(ans);
    return ans;
}

int main()
{
    vector<int> a;
    a.push_back(-2);
    a.push_back(-3);
    a.push_back(4);
    a.push_back(5);

    a = alternateNumbers(a);
    return 0;
}