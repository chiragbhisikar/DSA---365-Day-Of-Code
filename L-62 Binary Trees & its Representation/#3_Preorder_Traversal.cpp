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

Node *buildTree(Node *root)
{
    int data;
    cout << "Enter the data: ";
    cin >> data;

    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter the data for inserting in left of " << data << ": " << endl;
    root->left = buildTree(root->left);

    cout << "Enter the data for inserting in right of " << data << ": " << endl;
    root->right = buildTree(root->right);

    return root;
}

void preorder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void preorderUsingIteration(Node *root)
{
    if (root == NULL)
        return;

    stack<Node *> stackk;
    stackk.push(root);

    while (stackk.empty() != true) // until stack does not become empty loop
    {
        Node *node = stackk.top();
        stackk.pop();
        cout << node->data << " ";

        // this is just because stack follow LIFO
        if (node->right != NULL)
            stackk.push(node->right);
        if (node->left != NULL)
            stackk.push(node->left);
    }
}

int main()
{
    Node *root = NULL;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 21 -1 -1
    /* Constructed binary tree is
             1
           /    \
         3        5
       /  \     /    \
     7     11  17     21
   */
    root = buildTree(root);
    cout << "\n\npreorder: ";
    preorder(root);

    cout << "\npreorder: ";
    preorderUsingIteration(root);
    cout << endl;
    return 0;
}