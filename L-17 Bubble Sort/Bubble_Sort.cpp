#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

void sort(int arr[], int size)
{
    for (int i = 1; i <= size - 1; i++)
    {
        bool isSorted = true;
        for (int j = 1; j < size - i; j++)
        {
            if (arr[j - 1] >= arr[j])
            {
                swap(arr[j - 1], arr[j]);
                isSorted = false;
            }
        }
        if (isSorted)
        {
            break;
        }
    }

    printArray(arr, size);
}

int main()
{
    // int arr[] = {5, 4, 3, 2, 1};
    int arr[] = {5, 4, 30, 20, 1};
    sort(arr, 5);
    return 0;
}