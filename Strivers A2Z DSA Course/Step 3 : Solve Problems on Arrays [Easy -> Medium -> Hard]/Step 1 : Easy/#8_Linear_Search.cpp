#include <bits/stdc++.h>

using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

bool linearSearch(int nums[], int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == k)
        {
            return true;
        }
    }

    return false;
}
int main()
{
    int arr[] = {1, 2, 0, 4, 5};
    print(arr, 5);
    cout << (linearSearch(arr, 5, 5) ? "Yes Exist In Array" : "No Doesn't Exist In Array") << endl;
    return 0;
}