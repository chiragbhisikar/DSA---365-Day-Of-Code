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

void solve(Node *root, int sum, int &maxSum, int len, int &maxLen)
{
    if (root == NULL)
    {
        if (len > maxLen)
        {
            maxLen = len;
            maxSum = sum;
        }
        else if (len == maxLen)
        {
            maxSum = max(sum, maxSum);
        }

        return;
    }

    sum = sum + root->data;

    solve(root->left, sum, maxSum, len + 1, maxLen);
    solve(root->right, sum, maxSum, len + 1, maxLen);
}

int sumOfLongRootToLeafPath(Node *root)
{
    int length = 0;
    int maxLength = 0;

    int sum = 0;
    int maxSum = INT_MIN;

    solve(root, sum, maxSum, length, maxLength);

    return maxSum;
}

int main()
{
    Node *root = NULL;
    // 4 2 7 -1 -1 1 6 -1 -1 -1 -1 5 2 -1 -1 3 -1 -1
    root = buildTree(root);
    cout << "\nSum Of Longest Sum Root To Leaf : " << sumOfLongRootToLeafPath(root) << endl;
    return 0;
}