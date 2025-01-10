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
};

void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

Node *floydCycleDetection(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *slowPointer = head;
    Node *fastPointer = head;

    while (slowPointer != NULL && fastPointer != NULL)
    {
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next;

        if (fastPointer->next != NULL)
        {
            fastPointer = fastPointer->next;
        }

        if (fastPointer == slowPointer)
        {
            return slowPointer;
        }
    }

    return NULL;
}

Node *getStartingPointOfLoop(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *intersection = floydCycleDetection(head);

    if (intersection == NULL)
    {
        cout << "intersection is NULL => No Loop Exist In Linked List" << endl;
        return NULL;
    }
    Node *slowPoiner = head;

    while (slowPoiner != intersection)
    {
        slowPoiner = slowPoiner->next;
        intersection = intersection->next;
    }

    return slowPoiner;
}

void removeLoop(Node *&head)
{
    if (head == NULL)
    {
        return;
    }

    Node *startOfLoop = getStartingPointOfLoop(head);

    if (startOfLoop == NULL)
    {
        return;
    }
    // return head;

    Node *temp = startOfLoop;

    while (temp->next != startOfLoop)
    {
        temp = temp->next;
    }

    temp->next = NULL;

    // return head;
}

int main()
{
    Node *head = NULL;
    // Loop
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
    n6->next = n2;

    // cout << (detectLoop(n1) == 1 ? "Yes Loop Is Detected" : "No Loop Is Not Detected") << endl;

    Node *startingLoopNode = floydCycleDetection(n1);
    cout << "startingLoopNode->data: " << startingLoopNode->data << endl;

    removeLoop(n1);
    print(n1);

    return 0;
}