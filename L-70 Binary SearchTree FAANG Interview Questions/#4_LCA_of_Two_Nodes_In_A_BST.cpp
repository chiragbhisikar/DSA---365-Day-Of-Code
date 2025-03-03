
TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    // base case
    if (root == NULL)
        return NULL;

    while (root != NULL)
    {
        if (root->data < P->data && root->data < Q->data)
        {
            root = root->right;
        }
        else if (root->data > P->data && root->data > Q->data)
        {
            root = root->left;
        }
        else
        {
            return root;
        }
    }

    return NULL;
}