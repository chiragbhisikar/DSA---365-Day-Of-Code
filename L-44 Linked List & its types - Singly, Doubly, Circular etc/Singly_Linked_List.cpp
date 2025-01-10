#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        int value = this->data;

        // memory free if in between linked list
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "deleted: " << value << endl;
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
void insertAtHead(Node *&head, int data)
{
    // new node copy
    Node *newNode = new Node(data);
    newNode->next = head;

    head = newNode;
}

void insertAtTail(Node *&tail, int data)
{
    // new node copy
    Node *newNode = new Node(data);
    tail->next = newNode;

    tail = newNode;
}

void insertAtPosition(Node *&head, Node *&tail, int data, int position)
{
    // insert at head
    if (position == 1)
    {
        insertAtHead(head, data);
        return;
    }

    Node *newNode = new Node(data);
    Node *temp = head;
    int cnt = 1;

    while (cnt < (position - 1) && temp != NULL)
    {
        temp = temp->next;
        cnt++;
    }

    // insert At Tail
    if (temp->next == NULL)
    {
        insertAtTail(tail, data);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteNode(Node *&head, Node *&tail, int position)
{
    // deletion at head
    if (position == 1)
    {
        Node *temp = head;
        head = temp->next;

        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *previousNode = NULL;
        Node *currentNode = head;

        // traversing until position
        int cnt = 1;
        while (cnt < position)
        {
            previousNode = currentNode;
            currentNode = currentNode->next;
            cnt++;
        }

        previousNode->next = currentNode->next;
        // handling tail not give garbage value
        if (currentNode->next == NULL)
        {
            tail = previousNode;
        }
        currentNode->next = NULL;
        delete currentNode;
    }
}
int main()
{
    Node *head = new Node(30);
    Node *tail = head;
    insertAtHead(head, 40);
    insertAtTail(tail, 50);

    insertAtPosition(head, tail, 60, 2); // position > 1 && position < last --> insertAtPosition()
    insertAtPosition(head, tail, 70, 1); // position 1 --> insertAtHead()
    insertAtPosition(head, tail, 80, 6); // position last --> insertAtTail()

    print(head);
    cout << "head: " << head->data << "\ntail: " << tail->data << endl;

    deleteNode(head, tail, 1); // position 1 --> deleteAtHead()
    print(head);
    deleteNode(head, tail, 2); // position > 1 && position < last --> deleteAtPosition()
    print(head);
    deleteNode(head, tail, 4); // position last --> deleteAtTail()
    print(head);

    cout << "head: " << head->data << "\ntail: " << tail->data << endl;
    return 0;
}