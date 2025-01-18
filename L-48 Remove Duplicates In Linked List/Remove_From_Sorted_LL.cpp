#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node()
    {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data, Node *next, Node *prev)
    {
        this->data = data;
        this->prev = prev;
        this->next = next;
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

void print_reverse(Node *tail)
{
    Node *temp = tail;

    while (temp != NULL)
    {
        cout << " <- " << temp->data;
        temp = temp->prev;
    }
    cout << endl;
}

Node *removeDuplicates(Node *head)
{
    // if (head == NULL)
    //     return NULL;

    // Node *current = head;

    // while (current != NULL)
    // {
    //     if ((current->next != NULL) && (current->data == current->next->data))
    //     {
    //         Node *next_next = current->next->next;

    //         Node *nodeToDelete = current->next;
    //         delete nodeToDelete;

    //         current->next = next_next;
    //         current->next->prev = current;
    //     }
    //     else
    //     {
    //         current = current->next;
    //     }
    // }

    // return head;

    if (head == NULL)
        return NULL;

    Node *current = head;

    while (current != NULL)
    {
        if ((current->next != NULL) && (current->data == current->next->data))
        {
            Node *next_next = current->next->next;

            Node *deleteNode = current->next;
            delete deleteNode;

            current->next = next_next;
            current->next->prev = current;
        }
        else
        {
            current = current->next;
        }
    }

    return head;
}

int main()
{
    // 1 2 2 2 3
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(2);
    Node *n4 = new Node(2);
    Node *n5 = new Node(3);

    n1->prev = NULL;
    n1->next = n2;

    n2->prev = n1;
    n2->next = n3;

    n3->prev = n2;
    n3->next = n4;

    n4->prev = n3;
    n4->next = n5;

    n5->prev = n4;
    n5->next = NULL;

    print(n1);
    print_reverse(n5);
    Node *head = removeDuplicates(n1);
    print(n1);
    print_reverse(n5);

    return 0;
}