// https://www.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

// Approach 1
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

Node *reverse(Node *head)
{
    Node *previous = NULL;
    Node *current = head;
    Node *forward = head;

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

void insertAtTail(Node *&head, Node *&tail, int val)
{
    Node *temp = new Node(val);
    // Empty list Or First Element Of Linked List
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

Node *add(Node *num1, Node *num2)
{
    Node *ansHead = NULL;
    Node *ansTail = NULL;

    Node *tempFirst = num1;
    Node *tempSecond = num2;
    int carry = 0;

    while (tempFirst != NULL || tempSecond != NULL || carry != 0)
    {
        int firstData = 0;
        if (tempFirst != NULL)
        {
            firstData = tempFirst->data;
        }

        int secondData = 0;
        if (tempSecond != NULL)
        {
            secondData = tempSecond->data;
        }

        int sum = firstData + secondData + carry;
        int digit = sum % 10;

        // create node and add in answer Linked List
        insertAtTail(ansHead, ansTail, digit);

        carry = sum / 10;
        if (tempFirst != NULL)
            tempFirst = tempFirst->next;
        if (tempSecond != NULL)
            tempSecond = tempSecond->next;
    }

    return ansHead;
}

Node *addTwoLists(Node *num1, Node *num2)
{
    // Step 1 -> reverse two linked list
    num1 = reverse(num1);
    num2 = reverse(num2);

    // Step 2 -> add two linked list
    Node *ans = add(num1, num2);

    // Step 3 -> reverse answer linked list
    ans = reverse(ans);

    return ans;
}

int main()
{
    // First Linked List
    Node *n1 = new Node(4);
    Node *n2 = new Node(5);
    n1->next = n2;
    n2->next = NULL;

    // Second Linked List
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;

    print(n1);
    print(n3);
    cout << endl;

    addTwoLists(n1, n3);
    return 0;
}