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

void postorder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Left Node Right -> Inorder

// Node Left Right -> Preorder
// Left Right Node -> Postorder

void preorderUsingIteration(Node *root)
{
    vector<int> postorder;
    Node *curr = root;

    while (curr != NULL)
    {
        // this is root node
        if (curr->right == NULL)
        {
            // If no right child, visit this node
            // and go left
            postorder.push_back(curr->data);
            curr = curr->left;
        }
        else
        {
            Node *prev = curr->right;
            while (prev->left != NULL && prev->left != curr)
            {
                prev = prev->left;
            }

            // if link not exist then link them
            // and push the data and move curr to right part
            if (prev->left == NULL)
            {
                postorder.push_back(curr->data);
                prev->left = curr;
                curr = curr->right;
            }
            // link is exist then remove a link
            // and move curr to left part
            else
            {
                prev->left = NULL;
                curr = curr->left;
            }
        }
    }

    for (int i = postorder.size() - 1; i >= 0; i--)
    {
        cout << postorder[i] << " ";
    }
    cout << endl;
}

int main()
{
    Node *root = NULL;
    // 1 3 7 -1 -1 11 -1 -1 5 13 -1 -1 21 -1 -1

    root = buildTree(root);
    cout << "\n\n\npostorder : ";

    postorder(root);
    cout << endl;
    preorderUsingIteration(root);
    return 0;
}