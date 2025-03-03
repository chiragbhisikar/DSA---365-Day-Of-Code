// Construct Binary Tree from Postorder and Inorder Traversal
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

int findPosition(vector<int> arr, int n, int element)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == element)
            return i;
    }

    return -1;
}

Node *solve(vector<int> postorder, vector<int> inorder, int &index,
            int inorderStartIndex, int inorderEndIndex, int n)
{
    if (index < 0 || inorderStartIndex > inorderEndIndex)
    {
        return NULL;
    }

    int element = postorder[index--];
    Node *root = new Node(element);
    // (inorderStartIndex, position - 1) --> left node of tree
    // (position + 1, inorderEndIndex) --> right node of tree
    int position = findPosition(inorder, n, element);

    root->right =
        solve(postorder, inorder, index, position + 1, inorderEndIndex, n);
    root->left =
        solve(postorder, inorder, index, inorderStartIndex, position - 1, n);

    return root;
}

Node *buildTree(vector<int> &postorder, vector<int> &inorder)
{
    int n = postorder.size();

    int postorderIndex = n - 1;
    int inorderStartIndex = 0, inorderEndIndex = n - 1;
    Node *ans = solve(postorder, inorder, postorderIndex,
                      inorderStartIndex, inorderEndIndex, n);

    return ans;
}

void preorderTraversal(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main()
{
    vector<int> postorder = {9, 15, 7, 20, 3};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Node *root = buildTree(postorder, inorder);
    preorderTraversal(root);

    return 0;
}