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

// // head , current ,currentFirst
void insertAtCorrectOrder(Node *&head, Node *&current, Node *&currentNode)
{
    Node *next = currentNode->next;
    if (current == NULL)
    {
        head = currentNode;
        current = currentNode;
    }
    else
    {
        current->next = currentNode;
        current = current->next;
    }
    currentNode = next;
}

Node *sortTwoLists(Node *first, Node *second)
{
    if (first == NULL)
        return second;

    if (second == NULL)
        return first;

    Node *currentFirst = first;
    Node *currentSecond = second;
    Node *current = NULL;
    Node *head = NULL;
    Node *next = NULL;

    while (currentFirst != NULL && currentSecond != NULL)
    {
        int firstData = currentFirst->data;
        int secondData = currentSecond->data;

        if (firstData >= secondData)
        {
            insertAtCorrectOrder(head, current, currentSecond);
        }
        else
        {
            insertAtCorrectOrder(head, current, currentFirst);
        }
    }

    while (currentFirst != NULL)
    {
        insertAtCorrectOrder(head, current, currentFirst);
    }

    while (currentSecond != NULL)
    {
        insertAtCorrectOrder(head, current, currentSecond);
    }

    return head;
}

Node *findMiddle(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node *mergeSort(Node *head)
{
    // base case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // break linked list into 2 halvs, after finding mid
    Node *mid = findMiddle(head);

    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;

    // recursive calls to sort both halves
    left = mergeSort(left);
    right = mergeSort(right);

    // merge both left and right halves
    Node *result = sortTwoLists(left, right);

    return result;
}

int main()
{

    Node *n1 = new Node(6);
    Node *n2 = new Node(5);
    Node *n3 = new Node(4);
    Node *n4 = new Node(3);
    Node *n5 = new Node(2);
    Node *n6 = new Node(1);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = NULL;

    print(n1);
    Node *sortedListHead = mergeSort(n1);
    print(sortedListHead);
    return 0;
}