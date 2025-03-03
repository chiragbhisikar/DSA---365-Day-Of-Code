
pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    TreeNode *current = root;

    int pred = -1;
    int succ = -1;

    while (current->data != key && current != NULL)
    {
        if (current->data > key)
        {
            succ = current->data;
            current = current->left;
        }
        else
        {
            pred = current->data;
            current = current->right;
        }
    }

    TreeNode *leftTree = current->left;
    // find maximum from left subtree
    while (leftTree != NULL)
    {
        pred = leftTree->data;
        leftTree = leftTree->right;
    }

    TreeNode *rightTree = current->right;
    // find minimum from right subtree
    while (rightTree != NULL)
    {
        succ = rightTree->data;
        rightTree = rightTree->left;
    }

    return {pred, succ};
}