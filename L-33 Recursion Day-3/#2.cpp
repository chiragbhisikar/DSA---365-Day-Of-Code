#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int getSum(int arr[], int size)
{
    if (size == 1)
    {
        return arr[0];
    }

    int element = arr[0];
    int sum = element + getSum(arr + 1, size - 1);

    return sum;
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    cout << getSum(arr, 5) << endl;
    return 0;
}