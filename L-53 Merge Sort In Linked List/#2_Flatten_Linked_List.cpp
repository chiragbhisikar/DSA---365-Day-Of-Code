#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *child;

    Node()
    {
        this->data = 0;
        this->next = NULL;
        this->child = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->child = NULL;
    }
    Node(int data, Node *nextNode, Node *childNode)
    {
        this->data = data;
        this->next = nextNode;
        this->child = childNode;
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

Node *solve(Node *head)
{
    Node *temp = head;
    Node *childTemp = temp;

    while (childTemp->child != NULL)
    {
        Node *old = childTemp;
        childTemp = childTemp->child;
        old->child = NULL;
        temp->next = childTemp;
        temp = temp->next;
    }

    return childTemp;
}

Node *flattenLinkedList(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        Node *next = temp->next;
        Node *check = solve(temp);
        check->next = next;
        temp = next;
    }

    return head;
}
int main()
{

    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);
    Node *n6 = new Node(6);
    Node *n7 = new Node(7);
    Node *n8 = new Node(8);
    Node *n9 = new Node(9);
    Node *n12 = new Node(12);
    Node *n20 = new Node(20);

    n1->child = n2;
    n2->child = n3;
    n3->child = NULL;

    n4->child = n5;
    n5->child = n6;
    n6->child = NULL;

    n7->child = n8;
    n8->child = NULL;

    n9->child = n12;
    n12->child = NULL;

    n1->next = n4;
    n4->next = n7;
    n7->next = n9;
    n9->next = n20;

    print(n1);
    n1 = flattenLinkedList(n1);
    print(n1);
    return 0;
}