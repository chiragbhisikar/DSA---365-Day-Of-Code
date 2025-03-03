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

void heapSort(int arr[], int n)
{
    // Step 1 : Build Heap (rearrange vector)
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    // Step 2 : Heap Sort
    int size = n;
    while (size > 1)
    {
        // step 1 : swap
        swap(arr[size], arr[1]);
        size--;

        // step 2 : heapify for root
        heapify(arr, size, 1);
    }
}

int main()
{
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    // heap sort
    heapSort(arr, n);
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}