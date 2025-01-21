// https://www.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *random;

    Node()
    {
        this->data = 0;
        this->next = NULL;
        this->random = NULL;
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

    Node(int data, Node *nextNode, Node *randomNode)
    {
        this->data = data;
        this->next = nextNode;
        this->random = randomNode;
    }
};

void print(Node *head)
{
    Node *pointer = head;

    while (pointer != NULL)
    {
        cout << "[" << pointer->data << ", " << pointer->random->data << "]" << " -> ";
        pointer = pointer->next;
    }
    cout << endl;
}

// Optimal Approach T.C => O(n) S.C => O(1)
void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    // Empty list Or First Element Of Linked List
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

Node *cloneLinkedList(Node *head)
{
    // Step 1 : Create A Clone a linked list
    Node *cloneHead = NULL;
    Node *cloneTail = NULL;
    Node *pointer = head;

    while (pointer != NULL)
    {
        insertAtTail(cloneHead, cloneTail, pointer->data);
        pointer = pointer->next;
    }

    // Step 2 : Clone Node Add In Between Original List
    Node *originalNode = head;
    Node *cloneNode = cloneHead;

    while (originalNode != NULL && cloneNode != NULL)
    {
        Node *next = originalNode->next;
        originalNode->next = cloneNode;
        originalNode = next;

        next = cloneNode->next;
        cloneNode->next = originalNode;
        cloneNode = next;
    }

    // Step 3 : Random Pointer Copy
    Node *current = head;

    while (current != NULL)
    {
        if (current->next != NULL)
        {
            current->next->random = (current->random != NULL) ? current->random->next : current->random;
        }
        current = current->next->next;
    }

    // Step 4 : Revert Changes Which Done In Step 2
    originalNode = head;
    cloneNode = cloneHead;

    while (originalNode != NULL && cloneNode != NULL)
    {
        originalNode->next = cloneNode->next;
        originalNode = originalNode->next;

        if (originalNode != NULL)
        {
            cloneNode->next = originalNode->next;
        }
        cloneNode = cloneNode->next;
    }

    // Step 5 : Return Head
    print(cloneHead);
    return cloneHead;
}

int main()
{
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);

    // next setting
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;

    // random setting
    n1->random = n3;
    n2->random = n1;
    n3->random = n5;
    n4->random = n3;
    n5->random = n2;
    print(n1);
    cloneLinkedList(n1);
    return 0;
}