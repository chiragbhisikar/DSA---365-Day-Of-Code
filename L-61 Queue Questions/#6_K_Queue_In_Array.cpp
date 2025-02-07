#include <bits/stdc++.h>

using namespace std;

class kQueue
{
private:
    int n; // => Size Of Queue
    int k; // => Number Of Queue
    int *front;
    int *rear;
    int *arr;
    int *next;
    int freeSlot;

public:
    kQueue(int numberOfQueue, int sizeOfQueue)
    {
        n = sizeOfQueue;
        k = numberOfQueue;
        front = new int[k];
        rear = new int[k];

        for (int i = 0; i < k; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }

        next = new int[n];
        for (int i = 0; i < n; i++)
        {
            next[i] = i + 1;
        }
        next[n - 1] = -1;

        arr = new int[n];
        freeSlot = 0;
    }

    void enqueue(int qn, int data)
    {
        if (freeSlot == -1)
        {
            cout << "queue is full !" << endl;
            return;
        }

        int index = freeSlot;

        // update freeSlot
        freeSlot = next[index];

        // check whether first element
        if (front[qn - 1] == -1)
        {
            front[qn - 1] = index;
        }
        else
        {
            // link new element to previous
            next[rear[qn - 1]] = index;
        }

        // update the next
        next[index] = -1;

        // update rear
        rear[qn - 1] = index;

        // push element
        arr[index] = data;
    }

    int dequeue(int qn)
    {
        if (front[qn - 1] == -1)
        {
            cout << "queue is empty!" << endl;
            return -1;
        }

        // find index to pop
        int index = front[qn - 1];

        // getting data to return
        int element = arr[index];

        // front ko aage badhavo
        front[qn - 1] = next[index];

        // manage freeslot
        next[index] = freeSlot;
        freeSlot = index;

        return element;
    }
};
int main()
{
    kQueue *q = new kQueue(3, 10);
    q->enqueue(1, 10);
    q->enqueue(1, 20);
    q->enqueue(2, 30);
    q->enqueue(3, 40);
    cout << "poped element is " << q->dequeue(1) << endl;
    cout << "poped element is " << q->dequeue(1) << endl;
    cout << "poped element is " << q->dequeue(2) << endl;
    cout << "poped element is " << q->dequeue(3) << endl;

    return 0;
}