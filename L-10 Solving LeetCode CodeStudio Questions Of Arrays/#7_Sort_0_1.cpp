#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}
void sortZeroesAndOne(int arr[], int size)
{
    int front = 0, back = size - 1;

    while (front <= back)
    {
        if (arr[front] == 0)
        {
            front++;
        }
        else if (arr[back] == 1)
        {
            back--;
        }
        else if (arr[front] == 1)
        {
            swap(arr[front], arr[back]);
            back--;
        }
        else if (arr[back] == 0)
        {
            swap(arr[front], arr[back]);
            front++;
        }
        // cout << front << "  " << back << endl;
    }
    printArray(arr, size);
}
int main()
{
    // int arr1[] = {0, 1, 1, 0, 1, 0, 1};
    // sortZeroesAndOne(arr1, sizeof(arr1) / sizeof(int));
    // int arr2[] = {1, 0, 1, 1, 0, 1, 0, 1};
    // sortZeroesAndOne(arr2, sizeof(arr2) / sizeof(int));
    // int arr3[] = {0, 0, 1, 0, 1, 0};
    // sortZeroesAndOne(arr3, sizeof(arr3) / sizeof(int));
    // int arr4[] = {1, 1, 0, 0, 1, 0};
    // sortZeroesAndOne(arr4, sizeof(arr4) / sizeof(int));

    int arr5[] = {1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1};
    sortZeroesAndOne(arr5, sizeof(arr5) / sizeof(int));

    return 0;
}
