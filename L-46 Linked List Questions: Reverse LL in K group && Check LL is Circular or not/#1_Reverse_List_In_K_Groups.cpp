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
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

void print(Node *&head)
{
    Node *currentNode = head;
    while (currentNode != NULL)
    {
        cout << currentNode->data << " --> ";
        currentNode = currentNode->next;
    }
    cout << "NULL" << endl;
}

Node *kReverse(Node *head, int k)
{
    // base call
    if (head == NULL)
    {
        return NULL;
    }

    // step1: reverse first k nodes
    Node *previous = NULL;
    Node *current = head;
    Node *forward = NULL;
    int count = 0;

    while (current != NULL)
    {
        current = current->next;
        count++;
    }

    if (count < k)
    {
        return head;
    }
    else
    {
        count = 0;
        current = head;

        while (count < k)
        {
            forward = current->next;
            current->next = previous;
            previous = current;
            current = forward;

            count++;
        }
    }

    print(previous);

    // step2: Recursion dekhlega aage ka
    /*
     */
    if (forward != NULL)
    {
        head->next = kReverse(forward, k);
    }

    // step3: return head of reversed list
    return previous;
}

int main()
{

    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);
    Node *n6 = new Node(6);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = NULL;
    print(n1);

    Node *head = kReverse(n1, 4);
    print(head);
    return 0;
}