#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *nextNode)
    {
        this->data = data;
        this->next = nextNode;
    }
};

void print(Node *head)
{
    Node *pointer = head;

    while (pointer != NULL)
    {
        cout << pointer->data << " -> ";
        pointer = pointer->next;
    }
    cout << endl;
}

void insertAtCorrectOrder(Node *head, Node *current, Node *next)
{
    if (current == NULL)
    {
        head = next;
        current = next;
    }
    else
    {
        current->next = next;
        current = current->next;
    }
}

Node *sortTwoLists(Node *first, Node *second)
{
    if (first == NULL)
        return second;

    if (second == NULL)
        return first;

    Node *currentFirst = first;
    Node *currentSecond = second;
    Node *current = NULL;
    Node *head = NULL;
    Node *next = NULL;

    while (currentFirst != NULL && currentSecond != NULL)
    {
        int firstData = currentFirst->data;
        int secondData = currentSecond->data;

        if (firstData >= secondData)
        {
            next = currentSecond->next;

            if (current == NULL)
            {
                head = currentSecond;
                current = currentSecond;
            }
            else
            {
                current->next = currentSecond;
                current = current->next;
            }

            currentSecond = next;
        }
        else
        {
            next = currentFirst->next;

            if (current == NULL)
            {
                head = currentFirst;
                current = currentFirst;
            }
            else
            {
                current->next = currentFirst;
                current = current->next;
            }

            currentFirst = next;
        }
    }

    while (currentFirst != NULL)
    {
        next = currentFirst->next;
        current->next = currentFirst;
        current = current->next;
        currentFirst = next;
    }

    while (currentSecond != NULL)
    {
        next = currentSecond->next;
        current->next = currentSecond;
        current = current->next;
        currentSecond = next;
    }

    return head;
}

int main()
{
    Node *n1 = new Node(1);
    Node *n2 = new Node(3);
    Node *n3 = new Node(5);
    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;

    // 1 3 6 10 - 1

    Node *n4 = new Node(1);
    Node *n5 = new Node(3);
    Node *n6 = new Node(6);
    Node *n7 = new Node(10);
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = NULL;

    Node *first = n1;
    Node *second = n4;

    print(first);
    print(second);

    Node *sortedListHead = sortTwoLists(first, second);
    print(sortedListHead);

    return 0;
}