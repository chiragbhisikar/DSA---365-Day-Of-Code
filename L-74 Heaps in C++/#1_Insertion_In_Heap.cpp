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

    return 0;
}