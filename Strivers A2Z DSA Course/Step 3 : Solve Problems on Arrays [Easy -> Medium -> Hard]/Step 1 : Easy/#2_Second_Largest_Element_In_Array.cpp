#include <bits/stdc++.h>

using namespace std;

int largest(int arr[], int n)
{
    // T.C => O(n) S.C => O(1)
    int largestElement = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= largestElement)
        {
            largestElement = arr[i];
        }
    }

    return largestElement;
}
int secondLargest(int arr[], int n)
{
    int largestElement = largest(arr, n);
    int secondLargestElement = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > secondLargestElement && arr[i] != largestElement)
        {
            secondLargestElement = arr[i];
        }
    }

    return secondLargestElement;
}
int main()
{
    int arr[] = {1, 5, 4, 6, 2, 1, 7, 9, 7, 6};
    int largestElement = largest(arr, 10);
    cout << "largest element in array is " << largestElement << endl;
    int secondLargestElement = secondLargest(arr, 10);
    cout << "second largest element in array is " << secondLargestElement << endl;
    return 0;
}