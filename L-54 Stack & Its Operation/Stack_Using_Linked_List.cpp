#include <bits/stdc++.h>

using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Stack
{
public:
    Node *head;

    Stack()
    {
        head = NULL;
    }

    // insertAtHead
    void push(int data)
    {
        Node *newNode = new Node(data);
        if (this->head == NULL)
        {
            this->head = newNode;
        }
        else
        {
            // insertAtHead
            Node *oldHead = head;
            newNode->next = oldHead;
            this->head = newNode;
        }
    }

    // deleteAtHead
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Is Underflow" << endl;
        }
        else
        {
            if (head->next != NULL)
            {
                Node *oldHead = head;
                head = head->next;
                delete oldHead;
            }
            else
            {
                head = NULL;
            }
        }
    }
    bool isEmpty()
    {
        if (this->head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void print()
    {
        Node *temp = this->head;
        while (temp != NULL)
        {
            cout << temp->data << "  ";
            temp = temp->next;
        }
        cout << endl;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack Is Empty" << endl;
            return -1;
        }
        else
        {
            return this->head->data;
        }
    }
};
int main()
{
    Stack *stack = new Stack();
    stack->push(1);
    stack->push(2);
    stack->push(3);
    stack->push(4);
    stack->push(5);

    stack->print();
    cout << "stack -> top = " << stack->peek() << endl;

    stack->pop();
    stack->pop();
    stack->pop();
    stack->pop();
    stack->pop();
    stack->pop();

    stack->push(1);
    cout << "stack -> top = " << stack->peek() << endl;
    stack->print();
    return 0;
}