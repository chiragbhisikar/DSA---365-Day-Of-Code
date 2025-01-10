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

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "deleted " << value << endl;
    }
};

void print(Node *tail)
{
    Node *temp = tail;

    if (tail != NULL)
    {
        do
        {
            cout << tail->data << " -> ";
            tail = tail->next;
        } while (tail != temp);
        cout << endl;
    }
}
void insertNode(Node *&tail, int element, int data)
{
    // empty list
    if (tail == NULL)
    {
        tail = new Node(data);
        tail->next = tail;

        return;
    }
    Node *currentNode = tail;

    while (currentNode->data != element && currentNode->next != tail)
    {
        currentNode = currentNode->next;
    }

    Node *newNode = new Node(data);
    newNode->next = currentNode->next;
    currentNode->next = newNode;
}
void deleteNode(Node *&tail, int element)
{
    if (tail == NULL)
    {
        cout << "Linked List Is Empty Plz Add Node Then Try To Delete " << endl;
        return;
    }

    Node *previousNode = tail;
    Node *currentNode = tail->next;

    while (currentNode->data != element && previousNode->next != tail)
    {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    // cout << previousNode->data << "\t" << currentNode->data << endl;

    if (currentNode->data != element)
    {
        cout << "element not found !" << endl;
        return;
    }

    // if currentNode & previousNode pointing same means 1 element in LL Only
    if (currentNode->next == previousNode->next && currentNode == previousNode && currentNode == tail)
    {
        currentNode->next = NULL;
        tail = NULL;

        delete currentNode;
        return;
    }

    // deletion at tail
    if (tail->data == element)
    {
        previousNode->next = currentNode->next;
        currentNode->next = NULL;
        tail = previousNode->next;

        return;
    }

    previousNode->next = currentNode->next;
    currentNode->next = NULL;

    delete currentNode;
}

bool isCircular(Node *head)
{
    if (head == NULL)
    {
        return true;
    }

    Node *current = head->next;
    while (current != head && current != NULL)
    {
        current = current->next;
    }

    if (current == head)
    {
        return true;
    }

    return false;
}

int main()
{
    Node *tail = NULL;

    insertNode(tail, 5, 3);
    // cout << "tail: " << tail->data << endl;
    // print(tail);

    insertNode(tail, 3, 5);
    // cout << "tail: " << tail->data << endl;
    // print(tail);

    insertNode(tail, 5, 7);
    // cout << "tail: " << tail->data << endl;
    // print(tail);

    insertNode(tail, 5, 6);
    // cout << "tail: " << tail->data << endl;
    // print(tail);

    insertNode(tail, 3, 4);
    // cout << "tail: " << tail->data << endl;
    // print(tail);

    cout << (isCircular(tail) == 1 ? "Yes Circular" : "No Not A Circular") << endl;
    return 0;
}