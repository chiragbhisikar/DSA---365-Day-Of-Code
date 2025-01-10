#include <bits/stdc++.h>

using namespace std;

// void reverseArray(int arr[], int size, int i = 0)
// {
//     if (i >= (size / 2))
//     {
//         return;
//     }
//     swap(arr[i], arr[size - i - 1]);
//     reverseArray(arr, size, ++i);
// }

void reverseArray(vector<int> &arr, int i = 0)
{
    int size = arr.size();
    if (i >= (size / 2))
    {
        return;
    }
    swap(arr[i], arr[size - i - 1]);
    reverseArray(arr, ++i);
}
int main()
{
    vector<int> arr;
    arr.push_back(5);
    arr.push_back(4);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(1);
    reverseArray(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << "\t";
    }
    cout << "\nsize of array: "<<arr.size() << endl;
    return 0;
}

/*
    int arr[] = {1, 2, 3, 4, 5, 5};
    int size = 5;
    reverseArray(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
 */