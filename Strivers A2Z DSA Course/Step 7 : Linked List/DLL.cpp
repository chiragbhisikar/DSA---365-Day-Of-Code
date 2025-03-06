#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    Node(int data, Node *prev, Node *next)
    {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }

    void toString()
    {
        cout << "{" << this << ", " << this->data << ", " << this->prev << ", " << this->next << "}" << endl;
    }
};

void traversal(Node *head)
{
    Node *curr = head;
    Node *tail = NULL;

    while (curr != NULL)
    {
        cout << curr->data << " -> ";
        tail = curr;
        curr = curr->next;
    }

    cout << endl;

    while (tail != NULL)
    {
        cout << " <- " << tail->data;
        tail = tail->prev;
    }

    cout << endl;
}

Node *constructLL(vector<int> &arr)
{
    int n = arr.size();
    Node *head = new Node(arr[0], NULL, NULL);
    Node *prev = head;

    for (int i = 0; i < n - 1; i++)
    {
        Node *newNode = new Node(arr[i + 1], prev, NULL);
        prev->next = newNode;
        prev = newNode;
    }

    return head;
}

void removeHead(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        head = NULL;
        return;
    }

    Node *prev = head;
    head = head->next;
    head->prev = NULL;
    prev->next = NULL;

    delete prev;
    // return head;
}

void removeTail(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        head = NULL;
        return;
    }

    Node *current = head;
    Node *previous = NULL;

    while (current->next != NULL)
    {
        previous = current;
        current = current->next;
    }

    previous->next = NULL;
    current->prev = NULL;
    delete current;

    // return head;
}

void removeK(Node *&head, int k)
{
    if (head == NULL || head->next == NULL)
    {
        head = NULL;
        return;
    }

    if (k == 1)
    {
        removeHead(head);
        return;
    }

    int count = 0;
    Node *current = head;
    Node *previous = NULL;

    while (current->next != NULL)
    {
        count++;
        if (count == k)
        {
            if (current->next == NULL)
            {
                removeTail(head);
                return;
            }
            break;
        }
        previous = current;
        current = current->next;
    }

    Node *oldCurrent = current;
    current = current->next;
    previous->next = current;
    current->prev = previous;
    delete oldCurrent;
}

void insertHead(Node *&head, int data)
{
    Node *newHead = new Node(data, NULL, head);
    if (head == NULL)
    {
        head = newHead;
        return;
    }

    head->prev = newHead;
    head = newHead;
}

void insertTail(Node *&head, int data)
{
    Node *newNode = new Node(data, NULL, NULL);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *tail = head;

    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    tail->next = newNode;
    newNode->prev = tail;
}

void insertK(Node *&head, int data, int k)
{
    Node *newNode = new Node(data, NULL, NULL);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    int count = 0;
    Node *previous = NULL;
    Node *current = head;

    while (current != NULL)
    {
        count++;
        if (count == k)
        {
            break;
        }
        previous = current;
        current = current->next;
    }

    previous->next = newNode;
    current->prev = newNode;
    newNode->prev = previous;
    newNode->next = current;
}

void reverseDLL(Node *&head)
{
    Node *previous = NULL;
    Node *current = head;

    while (current != NULL)
    {
        previous = current->prev;

        current->prev = current->next;
        current->next = previous;

        current = current->prev;
    }

    return previous->prev;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = constructLL(arr);
    traversal(head);

    cout << "delete the head : " << endl;
    removeHead(head);
    traversal(head);

    cout << "delete the tail : " << endl;
    removeTail(head);
    traversal(head);

    cout << "delete the tail : " << endl;
    // removeK(head, 1);
    removeK(head, 2);
    // removeK(head, 3);
    traversal(head);

    cout << "insert 1 at head : " << endl;
    insertHead(head, 1);
    traversal(head);

    cout << "insert 100 at head : " << endl;
    insertTail(head, 100);
    traversal(head);

    cout << "insert 99 at 2nd Position : " << endl;
    insertK(head, 99, 2);
    traversal(head);

    cout << "reverse : " << endl;
    reverseDLL(head);
    traversal(head);
    return 0;
}