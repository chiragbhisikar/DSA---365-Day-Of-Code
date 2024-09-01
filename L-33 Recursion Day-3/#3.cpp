#include <iostream>
#include <bits/stdc++.h>

using namespace std;
bool LinearSearch(int arr[], int size, int searchElement)
{
    if (size == 0)
    {
        return false;
    }

    if (arr[0] == searchElement)
    {
        return true;
    }
    else
    {
        bool remainingPart = LinearSearch(arr + 1, size - 1, searchElement);
        return remainingPart;
    }
}
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    cout << LinearSearch(arr, 5, 10) << endl;
    return 0;
}