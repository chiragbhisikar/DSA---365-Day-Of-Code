#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }

    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }

    void toString()
    {
        cout << "{" << this << ", " << this->data << ", " << this->next << "}" << endl;
    }
};

Node *constructLL(vector<int> &arr)
{
    int n = arr.size();
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 0; i < n - 1; i++)
    {
        Node *node = new Node(arr[i + 1]);
        mover->next = node;
        mover = mover->next;
        // Or mover = temp
    }

    return head;
}

void traversal(Node *head)
{
    Node *curr = head;

    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

Node *removeHead(Node *head)
{
    if (head == NULL)
        return head;

    Node *temp = head;
    head = head->next;
    delete temp;

    return head;
}

Node *removeTail(Node *head)
{
    if (head == NULL)
        return head;

    Node *previous = NULL;
    Node *current = head;
    while (current != NULL)
    {
        previous = current;
        current = current->next;
    }
    previous->next = NULL;

    return head;
}

Node *removeK(Node *head, int k)
{
    if (head == NULL)
        return head;

    if (k == 1)
        return removeHead(head);

    int count = 0;
    Node *previous = NULL;
    Node *current = head;

    while (current != NULL)
    {
        count++;
        if (count == k)
        {
            previous->next = current->next;
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }

    return head;
}

Node *removeElement(Node *head, int element)
{
    if (head == NULL)
        return head;

    if (element == head->data)
        return removeHead(head);

    int count = 0;
    Node *previous = NULL;
    Node *current = head;

    while (current != NULL)
    {
        if (current->data == element)
        {
            previous->next = current->next;
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }

    return head;
}

Node *insertAtHead(Node *&head, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
        return newNode;

    newNode->next = head;
    head = newNode;

    return head;
}

Node *insertAtTail(Node *&head, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
        return newNode;

    Node *mover = head;

    while (mover->next != NULL)
    {
        mover = mover->next;
    }
    mover->next = newNode;

    return head;
}

Node *insertAtK(Node *&head, int data, int k)
{
    Node *newNode = new Node(data);
    if (k == 1)
        return insertAtHead(head, data);
    if (head == NULL)
        return newNode;

    Node *previous = NULL;
    Node *current = head;
    int counter = 0;

    while (current->next != NULL)
    {
        counter++;
        if (counter == k)
        {
            previous->next = newNode;
            newNode->next = current;
            break;
        }
        previous = current;
        current = current->next;
    }

    if (counter != k)
    {
        return insertAtTail(head, data);
    }

    return head;
}
int main()
{
    vector<int> arr = {1, 3, 2, 4};
    Node *head = constructLL(arr);
    insertAtHead(head, 99);
    insertAtTail(head, 5);
    insertAtK(head, 55, 2);
    traversal(head);

    return 0;
}