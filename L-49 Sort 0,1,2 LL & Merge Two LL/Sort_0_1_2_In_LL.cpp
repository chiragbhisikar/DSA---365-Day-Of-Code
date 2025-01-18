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

/*
Node *sortList(Node *head){
    // Approach 1 -> Naive Approach
    Node *temp = head;
    int zeroCount = 0, oneCount = 0, twoCount = 0;

    while (temp != NULL) {
      if (temp->data == 0) {
        zeroCount++;
      } else if (temp->data == 1) {
        oneCount++;
      } else {
        twoCount++;
      }
      temp = temp->next;
    }

    // Set Zero
    temp = head;
    while (temp != NULL) {
      if (zeroCount != 0) {
        temp->data = 0;
        zeroCount--;
      } else if (oneCount != 0) {
        temp->data = 1;
        oneCount--;
      } else {
        temp->data = 2;
        twoCount--;
      }
      temp = temp->next;
    }

    return head;

}
*/

void insertAtTail(Node *&tail, Node *current)
{
    tail->next = current;
    tail = current;
}

Node *sortList(Node *head)
{
    Node *zeroNode = new Node(-1);
    Node *zeroTail = zeroNode;
    Node *oneNode = new Node(-2);
    Node *onesTail = oneNode;
    Node *twoNode = new Node(-3);
    Node *twosTail = twoNode;

    Node *current = head;

    while (current != NULL)
    {
        int data = current->data;

        if (data == 0)
        {
            insertAtTail(zeroTail, current);
        }
        else if (data == 1)
        {
            insertAtTail(onesTail, current);
        }
        else
        {
            insertAtTail(twosTail, current);
        }

        current = current->next;
    }

    if (oneNode->next != NULL)
    {
        zeroTail->next = oneNode->next;
    }
    else
    {
        zeroTail->next = twoNode->next;
    }

    onesTail->next = twoNode->next;
    twosTail->next = NULL;

    head = zeroNode->next;

    delete zeroNode;
    delete oneNode;
    delete twoNode;

    return head;
}
int main()
{
    Node *n1 = new Node(1);
    Node *n2 = new Node(0);
    Node *n3 = new Node(2);
    Node *n4 = new Node(1);
    Node *n5 = new Node(2);
    Node *n6 = new Node(0);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = NULL;
    Node *head = n1;

    print(head);
    head = sortList(head);
    print(head);
    return 0;
}