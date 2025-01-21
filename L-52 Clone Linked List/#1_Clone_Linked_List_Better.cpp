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

// Better Approach T.C => O(n) S.C => O(n)
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
    // Step 1 : Clone a linked list
    Node *cloneHead = NULL;
    Node *cloneTail = NULL;
    Node *pointer = head;

    while (pointer != NULL)
    {
        insertAtTail(cloneHead, cloneTail, pointer->data);
        pointer = pointer->next;
    }

    // Step 2 : Store All Mapping
    unordered_map<Node *, Node *> oldToNew;

    Node *originalListPointer = head;
    Node *cloneListPointer = cloneHead;

    while (originalListPointer != NULL && cloneListPointer != NULL)
    {
        oldToNew[originalListPointer] = cloneListPointer;
        originalListPointer = originalListPointer->next;
        cloneListPointer = cloneListPointer->next;
    }

    // Step 3 : Arrange All Random Pointer
    originalListPointer = head;
    cloneListPointer = cloneHead;
    while (originalListPointer != NULL && cloneListPointer != NULL)
    {
        cloneListPointer->random = oldToNew[originalListPointer->random];
        originalListPointer = originalListPointer->next;
        cloneListPointer = cloneListPointer->next;
    }

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