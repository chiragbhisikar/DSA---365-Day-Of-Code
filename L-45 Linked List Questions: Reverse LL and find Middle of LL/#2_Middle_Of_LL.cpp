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
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

void print(Node *&head)
{
    Node *currentNode = head;
    while (currentNode != NULL)
    {
        cout << currentNode->data << " --> ";
        currentNode = currentNode->next;
    }
    cout << "NULL" << endl;
}

// Best : T.C => O(n/2) & S.C => O(1)
/*
Node *findMiddle(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }

    return slow;
}
*/

// Brute Force : T.C => O(n) + O(n/2) & S.C => O(1)
Node *findMiddle(Node *head)
{
    Node *temp = head;
    int lengthOfLinkedList = 0;

    while (temp != NULL)
    {
        temp = temp->next;
        lengthOfLinkedList++;
    }

    int cnt = 0;
    temp = head;
    while ((lengthOfLinkedList / 2) != 1)
    {
        lengthOfLinkedList--;
        temp = temp->next;
    }

    return temp;
}

int main()
{
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
    n5->next = NULL;
    // n5->next = n6;
    // n6->next = NULL;
    print(n1);

    Node *ans = findMiddle(n1);
    cout << "ans: " << ans->data << endl;
    return 0;
}