// 105. Construct Binary Tree from Preorder and Inorder Traversal
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

Node *solve(vector<int> preorder, vector<int> inorder, int &index,
            int inorderStartIndex, int inorderEndIndex, int n)
{
    if (index >= n || inorderStartIndex > inorderEndIndex)
    {
        return NULL;
    }

    int element = preorder[index++];
    Node *root = new Node(element);
    // (inorderStartIndex, position - 1) --> left node of tree
    // (position + 1, inorderEndIndex) --> right node of tree
    int position = findPosition(inorder, n, element);

    root->left =
        solve(preorder, inorder, index, inorderStartIndex, position - 1, n);
    root->right =
        solve(preorder, inorder, index, position + 1, inorderEndIndex, n);

    return root;
}

Node *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int n = preorder.size();

    int preorderIndex = 0;
    int inorderStartIndex = 0, inorderEndIndex = n - 1;
    Node *ans = solve(preorder, inorder, preorderIndex,
                      inorderStartIndex, inorderEndIndex, n);

    return ans;
}
void postorderTraversal(Node *root)
{
    if (root == NULL)
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}
int main()
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Node *root = buildTree(preorder, inorder);
    postorderTraversal(root);

    return 0;
}