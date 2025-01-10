#include <bits/stdc++.h>

using namespace std;

class LinkedListNode
{
public:
    int data;
    LinkedListNode *prev;
    LinkedListNode *next;

    LinkedListNode()
    {
        data = 0;
        next = NULL;
    }
    LinkedListNode(int data)
    {
        this->prev = NULL;
        this->data = data;
        this->next = NULL;
    }
    LinkedListNode(int data, LinkedListNode *prev, LinkedListNode *next)
    {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

void print(LinkedListNode *&head)
{
    LinkedListNode *currentNode = head;
    LinkedListNode *lastNode = head;
    cout << "next -> ";
    while (currentNode != NULL)
    {
        cout << currentNode->data << " --> ";

        if (currentNode->next == NULL)
        {
            lastNode = currentNode;
        }
        currentNode = currentNode->next;
    }
    cout << "NULL" << endl;
    cout << "prev -> ";
    while (lastNode != NULL)
    {
        cout << lastNode->data << " <-- ";
        lastNode = lastNode->prev;
    }
    cout << "NULL" << endl;
    cout << "*****" << endl;
}

// Iterative Approach
/**/
LinkedListNode *reverseLinkedList(LinkedListNode *&head)
{
    LinkedListNode *current = head;
    LinkedListNode *previous = current;
    LinkedListNode *forward = head;

    while (forward != NULL)
    {
        forward = current->next;
        previous = current->prev;
        current->next = previous;
        current->prev = forward;
        current = forward;
    }

    return previous->prev;
}

int main()
{
    LinkedListNode *n1 = new LinkedListNode(1);
    LinkedListNode *n2 = new LinkedListNode(2);
    LinkedListNode *n3 = new LinkedListNode(3);
    LinkedListNode *n4 = new LinkedListNode(4);
    LinkedListNode *n5 = new LinkedListNode(5);
    // n1
    n1->prev = NULL;
    n1->next = n2;
    // n2
    n2->prev = n1;
    n2->next = n3;
    // n3
    n3->prev = n2;
    n3->next = n4;
    // n4
    n4->prev = n3;
    n4->next = n5;
    // n4
    n5->prev = n4;
    n5->next = NULL;
    print(n1);

    LinkedListNode *head = reverseLinkedList(n1);
    print(head);

    return 0;
}