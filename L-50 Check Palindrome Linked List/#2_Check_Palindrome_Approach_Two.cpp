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

// Approach 2
Node *getMiddle(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
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

    return previous;
}

bool compareLinkedList(Node *head, Node *middle)
{
    Node *head1 = head;
    Node *head2 = middle->next;
    bool isPalindrome = true;
    while (head2 != NULL)
    {
        if (head1->data != head2->data)
        {
            isPalindrome = false;
            break;
        }
        // cout << head1->data << " & " << head2->data << endl;
        head1 = head1->next;
        head2 = head2->next;
    }

    // Reversing Reversed Linked List To Make Original One
    Node *temp = middle->next;
    middle->next = reverse(temp);

    return isPalindrome;
}
bool isPalindrome(Node *head)
{
    // Step 1 : Empty Or Single Element
    if (head == NULL || head->next == NULL)
    {
        return true;
    }
    // Step 2 : Gotten Middle Node Of Linked List
    Node *middle = getMiddle(head);

    // Step 3 : Reverse Linked List After Middle
    Node *temp = middle->next;
    middle->next = reverse(temp);

    // Compare Both Half & Repease Step 3
    return compareLinkedList(head, middle);
}

int main()
{
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(1);
    Node *n4 = new Node(2);
    Node *n5 = new Node(1);
    // Node *n6 = new Node(3);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;
    // n6->next = NULL;
    print(n1);
    isPalindrome(n1);
    cout << "Linked List Is " << (isPalindrome(n1) ? "Palindrome" : "Not Palindrome") << endl;
    return 0;
}