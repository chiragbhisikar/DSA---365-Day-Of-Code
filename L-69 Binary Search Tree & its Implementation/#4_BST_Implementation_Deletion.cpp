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

Node *getMin(Node *root)
{
    Node *temp = root;

    while (temp->left != NULL)
    {
        temp = temp->left;
    }

    return temp;
}

Node *searchNode(Node *root, int key)
{
    Node *temp = root;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return temp;
        }

        if (key > temp->data)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }

    return NULL;
}

Node *deleteFromBST(Node *root, int key)
{
    // base case
    if (root == NULL)
        return root;

    if (root->data == key)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // 1 child left side
        else if (root->left != NULL && root->right == NULL)
        {
            Node *leftNode = root->left;
            delete root;

            return leftNode;
        }
        // 1 child right side
        else if (root->left == NULL && root->right != NULL)
        {
            Node *rightNode = root->right;
            delete root;

            return rightNode;
        }
        // 2 child left & right
        else
        {
            int minValue = getMin(root->right)->data;
            root->data = minValue;
            root->right = deleteFromBST(root->right, minValue);

            return root;
        }
    }
    else if (root->data > key)
    {
        root->left = deleteFromBST(root->left, key);
    }
    else
    {
        root->right = deleteFromBST(root->right, key);
    }

    return root;
}

int main()
{
    Node *root = NULL;
    cout << "enter data to create binary search tree: ";
    takeInput(root);

    cout << "Printing a bst: \n";
    levelOrderTraversal(root);

    root = deleteFromBST(root, 7);

    cout << "Printing a bst: \n";
    levelOrderTraversal(root);

    // 8 3 10 1 6 14 4 7 13 -1
    // 1 5 7 3 4 2 6 -1
    return 0;
}