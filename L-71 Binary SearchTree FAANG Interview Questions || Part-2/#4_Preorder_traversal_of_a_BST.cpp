
BinaryTreeNode<int> *solve(vector<int> preorder, int mini, int maxi, int &index)
{
    if (index >= preorder.size())
        return NULL;

    if (preorder[index] < mini || preorder[index] > maxi)
        return NULL;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(preorder[index++]);
    root->left = solve(preorder, mini, root->data, index);
    root->right = solve(preorder, root->data, maxi, index);

    return root;
}

BinaryTreeNode<int> *preorderToBST(vector<int> &preorder)
{
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;

    return solve(preorder, mini, maxi, i);
}