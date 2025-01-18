#include <bits/stdc++.h>

using namespace std;
string read(vector<int> arr, int target)
{
    // Brute Force O(n^2)

    /*
        for (int i = 0; i < arr.size(); i++)
        {
            for (int k = i + 1; k < arr.size(); k++)
            {
                int sum = arr[i] + arr[k];
                if (sum == target)
                {
                    cout << "YES (" << arr[i] << " + " << arr[k] << ")";
                    return "YES";
                }
            }
        }
        return "NO";
    */

    //    Better Approach O(N ^ 2)
    /*
    unordered_map<int, int> mapp;
    for (int i = 0; i < arr.size(); i++)
    {
        int currentElement = arr[i];
        int needsMore = target - arr[i];
        if (mapp.find(needsMore) != mapp.end())
        {
            return "YES";
        }
        mapp[currentElement] = i;
    }
    return "NO";
    */

    //    Optimal Approach O(N log N)
    sort(arr.begin(), arr.end());
    int front = 0, back = arr.size() - 1;
    while (front < back)
    {
        int sum = arr[front] + arr[back];
        if (sum == target)
        {
            return "YES";
        }
        else if (sum < target)
        {
            front++;
        }
        else if (sum > target)
        {
            back--;
        }
    }
    return "NO";
}

int main()
{
    vector<int> arr;
    int sum = 5;
    arr.push_back(4);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(1);

    cout << "Sum With Two Element 5 Is " << (read(arr, sum) == "YES" ? "Exist" : "Not Exists") << endl;
    return 0;
}