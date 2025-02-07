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

void inorderUsingIteration(Node *root)
{
    vector<int> answer;
    Node *current = root;
    stack<Node *> stackk;

    while (current != NULL || !stackk.empty())
    {
        // for left part until it goes at leaf
        while (current != NULL)
        {
            stackk.push(current);
            current = current->left;
        }

        // node which we have to print
        current = stackk.top();
        cout << current->data << " ";
        // removing because it's already printed
        stackk.pop();

        // for right part
        current = current->right;
    }
}

int main()
{
    Node *root = NULL;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 21 -1 -1

    root = buildTree(root);

    // cout << "\n\n\ninorder : ";
    // inorder(root);

    cout << "\n\n\ninorder : ";
    inorderUsingIteration(root);
    return 0;
}