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

vector<int> nextGreaterPermutation(vector<int> &arr)
{
    // Step 1 : Find Peak Element
    int index = -1;
    int n = arr.size();

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            index = i;
            break;
        }
    }
    cout << arr[index] << "  " << index << endl;

    // If Already Largest Permutation Than Return Smallest One
    if (index == -1)
    {
        reverse(arr.begin(), arr.end());
        return arr;
    }

    // Step 2 : Find Next bigger element than what is arr[index] element
    for (int i = n - 1; i >= index; i--)
    {
        if (arr[index] < arr[i])
        {
            swap(arr[index], arr[i]);
            break;
        }
    }

    print(arr);

    reverse(arr.begin() + index + 1, arr.end());
    return arr;
}

int main()
{
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(5);
    arr.push_back(4);
    arr.push_back(1);
    arr.push_back(0);
    arr.push_back(0);

    print(arr);
    arr = nextGreaterPermutation(arr);
    print(arr);
    return 0;
}