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

    while (current != NULL)
    {
        // it means that we are standing at a Root Of That Subtree
        if (current->left == NULL)
        {
            answer.push_back(current->data);
            current = current->right;
        }
        // if it's an left node
        else
        {
            // predecessor -> pred
            Node *pred = current->left;
            while (
                // if tree link not exist then
                pred->right != NULL &&
                // if tree link is exist then
                pred->right != current)
            {
                pred = pred->right;
            }

            // if tree link not exist then
            if (pred->right == NULL)
            {
                pred->right = current;
                current = current->left;
            }
            // if tree link is exist then
            else
            {
                // remove that link
                pred->right = NULL;
                // print a data
                answer.push_back(current->data);
                // go to right part
                current = current->right;
            }
        }
    }

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    cout << endl;
}

int main()
{
    Node *root = NULL;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 21 -1 -1

    root = buildTree(root);
    cout << "\n\n\ninorder : ";
    inorder(root);
    cout << "\n";
    inorderUsingIteration(root);
    return 0;
}