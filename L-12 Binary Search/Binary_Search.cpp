#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key)
{
    int start = 0, end = size - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        int currentElement = arr[mid];

        if (currentElement == key)
        {
            return mid;
        }
        else if (currentElement > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = 6;
    int key = 2;
    // cout << binarySearch(enveArray, 6, 6) << endl;

    int start = 0, end = size - 1;
    int mid = (start + end) / 2;

    while (start <= end)
    {
        mid = (start + end) / 2;
        int currentElement = arr[mid];

        if (currentElement == key)
        {
            return mid;
        }
        else if (currentElement > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    int oddArray[] = {1, 2, 3, 4, 5};
    // cout << binarySearch(enveArray, 5, 12) << endl;
    return 0;
}