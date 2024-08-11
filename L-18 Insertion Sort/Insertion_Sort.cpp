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
    // for (int i = 1; i <= size - 1; i++)
    // {
    //     int currentValue = arr[i];
    //     int j = i - 1;
    //     for (; j >= 0; j--)
    //     {
    //         if (arr[j] > currentValue)
    //         {
    //             // shift
    //             arr[j + 1] = arr[j];
    //         }
    //         else
    //         {
    //             break;
    //         }
    //     }
    //     arr[j + 1] = currentValue;
    // }

    for (int i = 1; i <= size - 1; i++)
    {
        int currentValue = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > currentValue)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = currentValue;
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