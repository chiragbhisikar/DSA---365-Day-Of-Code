#include <bits/stdc++.h>

using namespace std;

class Queue
{
private:
    int *arr;
    int size;
    int queue_rear;
    int queue_front;

public:
    Queue()
    {
        this->size = 100;
        this->arr = new int[size];
        this->queue_rear = 0;
        this->queue_front = 0;
    }

    Queue(int size)
    {
        this->size = size;
        this->arr = new int[size];
        this->queue_rear = 0;
        this->queue_front = 0;
    }
    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty()
    {
        if (queue_front == queue_rear)
        {
            cout << "Queue Is Empty !" << endl;
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isFull()
    {
        if (queue_rear == size)
        {
            cout << "Queue Is Full !" << endl;
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(int data)
    {
        if (isFull())
        {
            return;
        }
        else
        {
            arr[queue_rear] = data;
            queue_rear++;
        }
    }

    int dequeue()
    {
        if (isEmpty())
        {
            return -1;
        }

        int element = arr[queue_front];
        queue_front++;

        if (queue_front == queue_rear)
        {
            queue_front = 0;
            queue_rear = 0;
        }

        return element;
    }

    int front()
    {
        if (isEmpty())
        {
            return -1;
        }

        return arr[queue_front];
    }
};

int main()
{
    Queue *q = new Queue(5);
    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);
    q->enqueue(4);
    q->enqueue(5);
    q->enqueue(6);

    cout << "q->front = " << q->front() << endl;
    q->dequeue();
    cout << "q->front = " << q->front() << endl;
    q->dequeue();
    cout << "q->front = " << q->front() << endl;
    q->dequeue();
    cout << "q->front = " << q->front() << endl;
    q->dequeue();
    cout << "q->front = " << q->front() << endl;
    q->dequeue();

    return 0;
}