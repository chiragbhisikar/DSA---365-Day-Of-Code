#include <bits/stdc++.h>

using namespace std;

class LinkedListNode
{
public:
    int data;
    LinkedListNode *next;

    LinkedListNode()
    {
        data = 0;
        next = NULL;
    }
    LinkedListNode(int data)
    {
        this->data = data;
        next = NULL;
    }
    LinkedListNode(int data, LinkedListNode *node)
    {
        this->data = data;
        this->next = node;
    }
};

void print(LinkedListNode *&head)
{
    LinkedListNode *currentNode = head;
    while (currentNode != NULL)
    {
        cout << currentNode->data << " --> ";
        currentNode = currentNode->next;
    }
    cout << "NULL" << endl;
}

// Iterative Approach
/*
LinkedListNode *reverseLinkedList(LinkedListNode *head)
{
    LinkedListNode *previous = NULL;
    LinkedListNode *forward = NULL;
    LinkedListNode *current = head;

    while (current != NULL)
    {
        forward = current->next;
        current->next = previous;
        previous = current;
        current = forward;
    }

    return previous;
}
*/

// Recursive Approach
void reverse(LinkedListNode *&head, LinkedListNode *previous, LinkedListNode *current)
{
    if (current == NULL)
    {
        head = previous;
        return;
    }
    LinkedListNode *forward = current->next;
    reverse(head, current, forward);
    current->next = previous;
}

LinkedListNode *reverseLinkedList(LinkedListNode *head)
{
    LinkedListNode *current = head;
    LinkedListNode *previous = NULL;
    reverse(head, previous, current);

    return head;
}

int main()
{
    LinkedListNode *n1 = new LinkedListNode(1);
    LinkedListNode *n2 = new LinkedListNode(2);
    LinkedListNode *n3 = new LinkedListNode(3);
    LinkedListNode *n4 = new LinkedListNode(4);
    LinkedListNode *n5 = new LinkedListNode(5);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;
    print(n1);

    LinkedListNode *head = reverseLinkedList(n1);
    print(head);

    return 0;
}