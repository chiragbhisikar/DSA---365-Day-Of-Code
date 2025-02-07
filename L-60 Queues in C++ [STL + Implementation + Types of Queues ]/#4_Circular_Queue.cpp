#include <bits/stdc++.h>
using namespace std;

class CircularQueue
{
private:
    // data members
    int *arr;
    int front, rear;
    int size;

public:
    // Initialize your data structure.
    CircularQueue(int n)
    {
        // Write your code here.
        this->size = n;
        this->arr = new int[this->size];
        this->front = this->rear = -1;
    }

    bool isEmpty()
    {
        if (this->front == -1)
        {
            cout << "Queue Is Empty !" << endl;
            return true;
        }

        return false;
    }

    bool isFull()
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            cout << "Queue Is FULL => ";
            return true;
        }

        return false;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack,
    // and false otherwise.
    bool enqueue(int value)
    {
        if (isFull())
        {
            return false;
        }

        if (this->front == -1) // first element to push
        {
            this->front = this->rear = 0;
        }
        else if (front != 0 && this->rear == this->size - 1)
        {
            this->rear = 0;
        }
        else
        {
            this->rear++;
        }

        this->arr[this->rear] = value;

        // cout << "enqueue => this->front -> " << this->front << " && this->rear -> " << this->rear << " => ";

        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty,
    // otherwise returns the popped element.
    int dequeue()
    {
        if (isEmpty())
        {
            return -1;
        }

        int element = arr[this->front];

        if (this->front == this->rear) // single element
        {
            this->front = this->rear = -1;
        }
        else if (this->front == this->size - 1)
        {
            this->front = 0;
        }
        else
        {
            this->front++;
        }

        cout << "dequeue => this->front -> " << this->front << " && this->rear -> " << this->rear << " => ";

        return element;
    }
};

int main()
{
    CircularQueue *cq = new CircularQueue(3);
    cout << "enqueue check : " << endl;
    cout << (cq->enqueue(1) ? "True" : "False") << endl;
    cout << (cq->enqueue(2) ? "True" : "False") << endl;
    cout << (cq->enqueue(3) ? "True" : "False") << endl;
    cout << (cq->enqueue(4) ? "True" : "False") << endl
         << endl;

    cout << "dequeue check : " << endl;
    cout << cq->dequeue() << endl;
    cout << cq->dequeue() << endl;
    cout << cq->dequeue() << endl;
    cout << cq->dequeue() << endl;
    return 0;
}