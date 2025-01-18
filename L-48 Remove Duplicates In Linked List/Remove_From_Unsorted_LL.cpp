#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node()
    {
        this->val = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->val = data;
        this->next = NULL;
    }
    Node(int data, Node *node)
    {
        this->val = data;
        this->next = node;
    }
};

void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

Node *removeDuplicates(Node *head)
{
    // First Store Unique Elements And If It's Unique Then Add It Else Leave It
    unordered_map<int, bool> visited;
    Node *current = head;
    Node *previous = NULL;

    while (current != NULL)
    {
        if (visited[current->val])
        {
            Node *next = current->next;

            Node *deleteNode = current;
            delete deleteNode;

            current = next;
            previous->next = current;
        }
        else
        {
            visited[current->val] = true;
            previous = current;
            current = current->next;
        }
    }

    return head;
}
int main()
{
    // Input: 4 2 5 4 2 2 -1
    // Output: 4 2 5 -1
    Node *n1 = new Node(4);
    Node *n2 = new Node(2);
    Node *n3 = new Node(5);
    Node *n4 = new Node(4);
    Node *n5 = new Node(2);
    Node *n6 = new Node(2);
    Node *n7 = new Node(-1);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = NULL;

    print(n1);
    Node *head = removeDuplicates(n1);
    print(n1);

    return 0;
}