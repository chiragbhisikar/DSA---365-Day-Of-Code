#include <iostream>
using namespace std;

void reverseArray(int arr[], int size)
{
    int start = 0, end = size - 1;
    for (int i = 0; i < size / 2; i++)
    {
        // int temp = arr[start];
        // arr[start] = arr[end];
        // arr[end] = temp;

        swap(arr[start], arr[end]);

        start++;
        end--;
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}
int main()
{
    int arr[5] = {13, 15, 17, 18, 20};
    reverseArray(arr, 5);

    int arr2[6] = {13, 15, 17, 18, 20, 22};
    reverseArray(arr2, 6);

    return 0;
}