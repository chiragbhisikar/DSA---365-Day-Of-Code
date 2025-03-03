#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }

    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }

    void toString()
    {
        cout << "{" << this << ", " << this->data << ", " << this->next << "}" << endl;
    }
};

Node *constructLL(vector<int> &arr)
{
    int n = arr.size();
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 0; i < n - 1; i++)
    {
        Node *node = new Node(arr[i + 1]);
        mover->next = node;
        mover = mover->next; 
        // Or mover = temp
    }

    return head;
}

int main()
{
    vector<int> arr = {1, 3, 2, 4};
    Node *head = constructLL(arr);

    return 0;
}