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

pair<int, int> solve(Node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }
    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);

    pair<int, int> result;
    result.first = root->data + left.second + right.second;
    result.second = max(left.first, left.second) + max(right.first, right.second);

    return result;
}

// Function to return the maximum sum of non-adjacent nodes.
int getMaxSum(Node *root)
{
    pair<int, int> ans = solve(root);

    return max(ans.first, ans.second);
}

int main()
{
    Node *root = NULL;
    // 1 2 4 -1 -1 -1 3 5 -1 -1 6 -1 -1
    root = buildTree(root);
    cout << "\nMaximum sum of Non-adjacent nodes : " << getMaxSum(root) << endl;
    return 0;
}