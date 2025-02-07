#include <bits/stdc++.h>

using namespace std;

void print(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}
vector<int> superiorElements(vector<int> &arr)
{
    int maxi = INT_MIN;
    vector<int> ans;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        if (maxi <= arr[i])
        {
            maxi = arr[i];
            ans.push_back(arr[i]);
        }
    }

    return ans;
}
int main()
{
    vector<int> arr;
    arr.push_back(10);
    arr.push_back(22);
    arr.push_back(12);
    arr.push_back(3);
    arr.push_back(0);
    arr.push_back(6);

    print(arr);
    arr = superiorElements(arr);
    print(arr);
    return 0;
}