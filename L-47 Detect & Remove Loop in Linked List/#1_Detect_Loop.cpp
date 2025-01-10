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

// Check Only If Loop Is Exist In Linked List Or Not
bool detectLoop(Node *head)
{
    /*
    if (head == NULL)
    {
        return false;
    }
    map<Node *, bool> visited;
    Node *current = head;

    while (current != NULL)
    {
        if (visited[current] == true)
        {
            cout << "Cycle Cycle Mari Sona Ni Cycle Re Cycle Par Besi Huto Ambaji Gyi Re" << endl;
            return true;
        }
        visited[current] = true;
        current = current->next;
    }

    cout << "Not Cycle Cycle Mari Sona Ni Cycle Re Cycle Par Besi Huto Ambaji Gyi Re" << endl;
    return false;
    */

    //    Approach 2 => Optimized

    Node *slowPoiner = head;
    Node *fastPoiner = head;

    while (fastPoiner != NULL && fastPoiner->next != NULL)
    {
        slowPoiner = slowPoiner->next;
        fastPoiner = (fastPoiner->next)->next;
        if (slowPoiner == fastPoiner)
        {
            return true;
        }
    }
    return false;
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

    cout << (detectLoop(n1) == 1 ? "Yes Loop Is Detected" : "No Loop Is Not Detected") << endl;

    Node *loopNode = floydCycleDetection(n1);
    cout << "Loop Node Data: " << loopNode->data << endl;

    print(n1);

    return 0;
}