#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    map<int, int> frequency;

    for (int i = 0; i < n; i++)
    {
        frequency[arr[i]]++;
    }

    for (auto value : frequency)
    {
        cout << value.first << " => " << value.second << endl;
    }

    return 0;
}