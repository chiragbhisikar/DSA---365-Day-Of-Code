#include <bits/stdc++.h>

using namespace std;

class Stack
{
public:
    int *arr;
    int top;
    int size;

    Stack(int size)
    {
        this->top = -1;
        this->size = size;
        this->arr = new int[size];
    }

    void push(int element)
    {
        if (isFull())
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {
            arr[++top] = element;
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow " << endl;
        }
        else
        {
            arr[top] = 0;
            top--;
        }
    }

    int peek()
    {
        if (isEmpty())
            cout << "Stack Underflow ";
        else
            return arr[top];
    }

    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if ((top + 1) == size)
            return true;
        else
            return false;
    }
};

int main()
{
    Stack *stack = new Stack(5);
    stack->push(1);
    stack->push(2);
    stack->push(3);
    stack->push(4);
    stack->push(5);
    stack->push(6);
    cout << "top element = " << stack->peek() << endl;
    stack->pop();
    stack->pop();
    stack->pop();
    stack->pop();
    stack->pop();
    stack->pop();
    cout << "top element = " << stack->peek() << endl;

    return 0;
}