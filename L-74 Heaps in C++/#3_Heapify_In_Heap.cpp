#include <bits/stdc++.h>

using namespace std;

void heapify(int arr[], int n, int index)
{
    int largest = index;
    int leftChildIndex = 2 * index;
    int rightChildIndex = 2 * index + 1;

    if (leftChildIndex <= n && arr[largest] < arr[leftChildIndex])
    {
        largest = leftChildIndex;
    }
    if (rightChildIndex <= n && arr[largest] < arr[rightChildIndex])
    {
        largest = rightChildIndex;
    }

    // update hua he
    if (largest != index)
    {
        swap(arr[largest], arr[index]);
        heapify(arr, n, largest);
    }
}

int main()
{
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    // build max heap
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}