#include <bits/stdc++.h>

using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = -1;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
    }

    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

class Queue
{
public:
    Node *queue_front;
    Node *queue_rear;

    Queue()
    {
        queue_front = NULL;
        queue_rear = NULL;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty()
    {
        if (queue_front == NULL && queue_rear == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(int data)
    {
        // intial stage
        if (isEmpty())
        {
            Node *newNode = new Node(data);
            queue_front = newNode;
            queue_rear = newNode;

            return;
        }

        Node *newNode = new Node(data);
        queue_rear->next = newNode;
        queue_rear = queue_rear->next;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            return -1;
        }

        int element = queue_front->data;

        Node *temp = queue_front;
        queue_front = queue_front->next;
        delete temp;

        if (queue_front == NULL)
        {
            queue_rear = NULL;
        }

        return element;
    }

    int front()
    {
        if (isEmpty())
        {
            cout << "Queue Is Empty !" << endl;
            return -1;
        }

        return queue_front->data;
    }
};

int main()
{

    Queue *q = new Queue();
    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);
    q->enqueue(4);
    q->enqueue(5);
    q->enqueue(6);

    cout << "q->front = " << q->front() << " && q->dequeu() = " << q->dequeue() << endl;
    cout << "q->front = " << q->front() << " && q->dequeu() = " << q->dequeue() << endl;
    cout << "q->front = " << q->front() << " && q->dequeu() = " << q->dequeue() << endl;
    cout << "q->front = " << q->front() << " && q->dequeu() = " << q->dequeue() << endl;
    cout << "q->front = " << q->front() << " && q->dequeu() = " << q->dequeue() << endl;
    cout << "q->front = " << q->front() << " && q->dequeu() = " << q->dequeue() << endl;
    cout << "q->front = " << q->front() << " && q->dequeu() = " << q->dequeue() << endl;

    return 0;
}