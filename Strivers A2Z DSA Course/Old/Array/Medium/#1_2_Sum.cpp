#include <iostream>
#include <bits/stdc++.h>

using namespace std;
// Variaty 1
string read(int n, vector<int> arr, int target)
{
    unordered_map<int, int> mapp;

    for (int i = 0; i < n; i++)
    {
        int currentElement = arr[i];
        int needsMore = target - currentElement;
        if (mapp.find(needsMore) != mapp.end())
        {
            return "YES";
        }
        mapp[currentElement] = i;
    }
    return "NO";
}

// Variaty 2
void twoSum(vector<int> &arr, int target)
{
    vector<int> ans;
    ans = arr;
    sort(ans.begin(), ans.end());

    int front = 0, back = arr.size() - 1;

    while (front < back)
    {
        int sum = ans[front] + ans[back];

        if (sum == target)
        {
            cout << arr[front] << "\t" << arr[back] << endl;
            front = arr[front];
            back = arr[back];
            break;
        }
        else if (sum < target)
        {
            front++;
        }
        else
        {
            back--;
        }
    }

    int first = 0, second = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == front)
        {
            first = i;
        }
        if (arr[i] == back)
        {
            second = i;
        }
    }

    cout << first << "\t" << second << endl;
}
int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(7);
    v.push_back(9);
    cout << read(v.size(), v, 8) << endl;
    twoSum(v, 8);
    return 0;
}