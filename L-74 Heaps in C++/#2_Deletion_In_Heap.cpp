#include <bits/stdc++.h>

using namespace std;

// Max Heap
class MaxHeap
{
public:
    int arr[100];
    int size = 0;

    MaxHeap()
    {
        arr[0] = -1;
        size = 0;
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void insertInHeap(int data)
    {
        size = size + 1;
        int index = size;
        arr[index] = data;

        while (index > 1)
        {
            int parentIndex = index / 2;

            if (arr[parentIndex] < arr[index])
            {
                swap(arr[parentIndex], arr[index]);
                index = parentIndex;
            }
            else
            {
                return;
            }
        }
    }

    void deleteFromHeap()
    {
        if (size == 0)
        {
            cout << "Heap Is Empty!" << endl;
            return;
        }
        // step 1 : put last element at root node or last element to first index
        arr[1] = arr[size];

        // step 2 : remove last element
        size--;

        // step 3 : take root element to it's right position
        int index = 1;
        while (index < size)
        {
            int leftChildIndex = 2 * index;
            int rightChildIndex = 2 * index + 1;

            if (arr[index] < arr[leftChildIndex] && leftChildIndex < size)
            {
                swap(arr[index], arr[leftChildIndex]);
                index = leftChildIndex;
            }
            else if (arr[index] < arr[rightChildIndex] && rightChildIndex < size)
            {
                swap(arr[index], arr[rightChildIndex]);
                index = rightChildIndex;
            }
            else
            {
                return;
            }
        }
    }
};

int main()
{
    MaxHeap *maxheap = new MaxHeap();
    maxheap->insertInHeap(50);
    maxheap->insertInHeap(55);
    maxheap->insertInHeap(53);
    maxheap->insertInHeap(52);
    maxheap->insertInHeap(54);
    maxheap->print();
    maxheap->deleteFromHeap();
    maxheap->print();

    return 0;
}