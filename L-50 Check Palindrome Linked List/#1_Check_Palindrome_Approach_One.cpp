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
// Approach 1
bool checkPalindrome(vector<int> arr)
{
    int front = 0, back = arr.size() - 1;

    while (front < back)
    {
        if (arr[front] != arr[back])
        {
            return false;
        }
        front++;
        back--;
    }

    return true;
}

bool isPalindrome(Node *head)
{
    vector<int> linkedListData;
    Node *temp = head;

    while (temp != NULL)
    {
        linkedListData.push_back(temp->data);
        temp = temp->next;
    }

    return checkPalindrome(linkedListData);
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