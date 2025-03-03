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

void inorder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorderUsingIteration(Node *root)
{
    vector<int> inorder;
    Node *curr = root;

    while (curr != NULL)
    {
        // this is root node
        if (curr->left == NULL)
        {
            // If no left child, visit this node
            // and go right
            inorder.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            Node *prev = curr->left;
            while (prev->right != NULL && prev->right != curr)
            {
                prev = prev->right;
            }

            // if link not exist then link them
            // and push the data and move curr to left part
            if (prev->right == NULL)
            {
                inorder.push_back(curr->data);
                prev->right = curr;
                curr = curr->left;
            }
            // link is exist then remove a link
            // and move curr to right part
            else
            {
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }

    for (int i = 0; i < inorder.size(); i++)
    {
        cout << inorder[i] << " ";
    }
    cout << endl;
}

int main()
{
    Node *root = NULL;
    // 1 3 7 -1 -1 11 -1 -1 5 13 -1 -1 21 -1 -1

    root = buildTree(root);
    cout << "\n\n\npreorder : ";
    preorderUsingIteration(root);
    return 0;
}