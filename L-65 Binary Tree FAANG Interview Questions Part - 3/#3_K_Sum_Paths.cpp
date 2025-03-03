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

void solve(Node *root, int k, int &count, vector<int> path)
{
    if (root == NULL)
        return;

    path.push_back(root->data);

    // solve root left part
    solve(root->left, k, count, path);
    // solve root right part
    solve(root->right, k, count, path);

    int sum = 0;
    int size = path.size();
    for (int i = size - 1; i >= 0; i--)
    {
        sum = sum + path[i];

        if (sum == k)
        {
            count++;
        }
    }

    path.pop_back();
}

int sumK(Node *root, int k)
{
    vector<int> path;
    int count = 0;
    solve(root, k, count, path);

    return count;
}
int main()
{
    Node *root = NULL;
    // 8 4 3 3 -1 -1 -2 -1 -1 2 1 -1 -1 -1 5 -1 2 -1 -1
    root = buildTree(root);
    cout << "\nK Sum Paths : " << sumK(root, 7) << endl;
    return 0;
}