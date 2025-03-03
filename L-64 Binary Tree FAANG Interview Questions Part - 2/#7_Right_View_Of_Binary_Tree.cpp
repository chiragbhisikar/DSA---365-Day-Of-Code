#include <bits/stdc++.h>

using namespace std;

void print(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

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

void solve(Node *root, vector<int> &ans, int level)
{
    if (root == NULL)
        return;

    // checking if new level then add that element
    if (level == ans.size())
    {
        ans.push_back(root->data);
        cout << root->data << " ";
    }

    solve(root->right, ans, level + 1);
    solve(root->left, ans, level + 1);
}

void rightView(Node *root)
{
    vector<int> ans;
    solve(root, ans, 0);
}

int main()
{
    Node *root = NULL;
    // 10 20 40 -1 -1 60 -1 -1 30 90 -1 -1 100 -1 -1
    root = buildTree(root);
    cout << "\nRight View Traversal: " << endl;
    rightView(root);
    return 0;
}