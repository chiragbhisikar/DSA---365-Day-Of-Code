#include <bits/stdc++.h>

using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;

    ListNode()
    {
        data = 0;
        next = NULL;
    }
    ListNode(int data)
    {
        this->data = data;
        next = NULL;
    }
    ListNode(int data, ListNode *node)
    {
        this->data = data;
        this->next = node;
    }
};

void print(ListNode *&head)
{
    ListNode *currentNode = head;
    while (currentNode != NULL)
    {
        cout << currentNode->data << " --> ";
        currentNode = currentNode->next;
    }
    cout << "NULL" << endl;
}

// Iterative Approach
/**/

ListNode *reverseLinkedList(ListNode *head)
{
    ListNode *previous = NULL;
    ListNode *forward = NULL;
    ListNode *current = head;

    while (current != NULL)
    {
        forward = current->next;
        current->next = previous;
        previous = current;
        current = forward;
    }

    print(previous);
    return previous;
}

ListNode *reverseLinkedList(ListNode *head, int left, int right)
{
    // moving pointers
    int index = 1;
    ListNode *leftPointer = head;
    ListNode *rightPoiner = head;

    while (index != right)
    {
        if (index < left)
        {
            leftPointer = leftPointer->next;
        }
        rightPoiner = rightPoiner->next;
        index++;
    }

    cout << leftPointer->data << "\t" << rightPoiner->data << endl;
    ListNode *newHead = leftPointer;
    ListNode *answer = reverseLinkedList(newHead);

    return head;
}

int main()
{
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    ListNode *n5 = new ListNode(5);
    ListNode *n6 = new ListNode(6);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;
    n6->next = NULL;
    print(n1);

    ListNode *head = reverseLinkedList(n1, 2, 4);
    print(head);

    return 0;
}