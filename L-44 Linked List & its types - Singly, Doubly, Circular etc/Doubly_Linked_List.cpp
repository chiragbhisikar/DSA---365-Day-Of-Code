#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;

    Node()
    {
        this->prev = NULL;
        this->data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->prev = NULL;
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        int value = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }

        cout << "deleted " << value << endl;
    }
};
void print(Node *head)
{
    Node *currentNode = head;
    while (currentNode != NULL)
    {
        cout << currentNode->data << " --> ";
        currentNode = currentNode->next;
    }
    cout << "NULL" << endl;
}
int getLength(Node *head)
{
    Node *currentNode = head;
    int length = 0;
    while (currentNode != NULL)
    {
        currentNode = currentNode->next;
        length++;
    }
    return length;
}

void insertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        Node *newNode = new Node(data);
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (tail == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        Node *newNode = new Node(data);
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

void deleteNode(Node *&head, Node *&tail, int position)
{
    // deletion at head
    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
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

        // handling tail not give garbage value
        if (currentNode->next == NULL)
        {
            currentNode->prev = NULL;
            previousNode->next = NULL;
            tail = previousNode;

            delete currentNode;
            return;
        }

        previousNode->next = currentNode->next;
        (currentNode->next)->prev = previousNode;
        currentNode->next = NULL;
        currentNode->prev = NULL;
        delete currentNode;
    }
}
void insertAtPosition(Node *&head, Node *&tail, int data, int position)
{
    // insert at head
    if (position == 1)
    {
        insertAtHead(head, tail, data);
        return;
    }

    // Method 2:

    Node *currentNode = head;

    int cnt = 1;
    while (cnt < (position - 1))
    {
        currentNode = currentNode->next;
        cnt++;
    }

    if (currentNode->next == NULL)
    {
        insertAtTail(head, tail, data);
        return;
    }

    Node *newNode = new Node(data);
    newNode->prev = currentNode;
    newNode->next = currentNode->next;
    currentNode->next = newNode;
    (newNode->next)->prev = newNode;
}
int main()
{
    // Node *node = new Node(10);
    Node *head = NULL;
    Node *tail = NULL;
    // print(node);
    // cout << "Linked List Length: " << getLength(head) << endl;

    insertAtHead(head, tail, 90);
    cout << "head: " << head->data << " & tail: " << tail->data << endl;
    insertAtHead(head, tail, 70);
    cout << "head: " << head->data << " & tail: " << tail->data << endl;
    print(head);

    insertAtTail(head, tail, 110);
    print(head);

    insertAtPosition(head, tail, 600, 1);
    print(head);

    insertAtPosition(head, tail, 800, 2);
    print(head);

    insertAtPosition(head, tail, 1200, 6);
    print(head);

    deleteNode(head, tail, 1);
    print(head);
    deleteNode(head, tail, 3);
    print(head);
    deleteNode(head, tail, 4);
    print(head);
    return 0;
}