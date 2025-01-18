#include <bits/stdc++.h>

using namespace std;

int getSingleElement(vector<int> &arr)
{
    int n = arr.size();

    // XOR all the elements:
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i];
    }

    return ans;
}
int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(4);

    int consecutive = getSingleElement(arr);
    cout << "single element is " << consecutive << endl;

    return 0;
}