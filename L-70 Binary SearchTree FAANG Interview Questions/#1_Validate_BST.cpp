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
/**
bool isBST(Node *root, long min, long max)
{
    if (root == NULL)
    {
        return true;
    }

    if (root->data >= min && root->data <= max)
    {
        bool left = isBST(root->left, min, root->data);
        bool right = isBST(root->right, root->data, max);

        return left && right;
    }
    else
        return false;
}

bool validateBST(Node *root)
{
    return isBST(root, LONG_MIN, LONG_MAX);
}
 */

bool validateBST(Node *root)
{
    long min = INT_MIN;
    Node *current = root;

    while (current != NULL)
    {
        if (current->left == NULL)
        {
            if (current != NULL && min < current->data)
            {
                min = current->data;
            }
            else
            {
                return false;
            }
            current = current->right;
        }
        else
        {
            Node *pred = current->left;
            while (pred->right != NULL && pred->right != current)
            {
                pred = pred->right;
            }

            if (pred->right == NULL)
            {
                pred->right = current;
                current = current->left;
            }
            else
            {
                if (current != NULL && min < current->data)
                {
                    min = current->data;
                }
                else
                {
                    return false;
                }
                pred->right = NULL;
                current = current->right;
            }
        }
    }

    return true;
}
int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 4 2 1 -1 -1 3 -1 -1 5 -1 -1 -> Valid
    // 4 2 1 -1 -1 5 -1 -1 3 -1 -1 -> Not Valid
    // 5 1 -1 -1 4 3 -1 -1 6 -1 -1
    cout << "\nBinary Search Tree Is " << (validateBST(root) ? "Valid" : "Not Valid") << endl;

    return 0;
}