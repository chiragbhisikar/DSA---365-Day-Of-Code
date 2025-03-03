#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();

        q.pop();

        if (temp == NULL) // old level complete travels
        {
            cout << endl;
            if (!q.empty()) // queue still has child nodes
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << "  ";
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }

            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}

Node *insertIntoBST(Node *&root, int data)
{

    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    Node *newNode = new Node(data);
    // insert at right part
    if (data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }
    // insert at left part
    else
    {
        root->left = insertIntoBST(root->left, data);
    }

    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

bool searchInBST(Node *root, int x)
{
    if (root == NULL)
        return false;

    Node *current = root;

    while (current != NULL)
    {
        if (current->data == x)
            return true;

        if (x >= current->data)
        {
            current = current->right;
        }
        else
        {
            current = current->left;
        }
    }

    return false;
}

int main()
{
    Node *root = NULL;
    cout << "enter data to create binary search tree: ";
    takeInput(root);
    cout << "Printing a bst: ";
    levelOrderTraversal(root);

    int searchElement = 2;
    cout << searchElement << (searchInBST(root, searchElement) ? " is present" : " is not present") << " in tree" << endl;
    // 8 3 10 1 6 14 4 7 13 -1
    // 1 5 7 3 4 2 6 -1
    return 0;
}