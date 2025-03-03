
int kthSmallest(BinaryTreeNode<int> *root, int k)
{
    BinaryTreeNode<int> *current = root;
    int i = 0;

    while (current != NULL)
    {
        if (current->left == NULL)
        {
            i++;
            if (i == k)
            {
                return current->data;
            }
            current = current->right;
        }
        else
        {
            BinaryTreeNode<int> *pred = current->left;
            while (pred->right != NULL && pred->right != current)
            {
                pred = pred->right;
            }

            if (pred->right == NULL)
            {
                pred->right = current;
                current = current->left;
            }
            else
            {
                pred->right = NULL;
                i++;
                if (i == k)
                {
                    return current->data;
                }
                current = current->right;
            }
        }
    }

    return -1;
}