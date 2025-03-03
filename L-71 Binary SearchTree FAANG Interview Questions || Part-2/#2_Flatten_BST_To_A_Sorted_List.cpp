
vector<TreeNode<int> *> getInorder(TreeNode<int> *root)
{
    vector<TreeNode<int> *> answer;
    TreeNode<int> *current = root;

    while (current != NULL)
    {
        if (current->left == NULL)
        {
            answer.push_back(current);
            current = current->right;
        }
        else
        {
            TreeNode<int> *pred = current->left;
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
                answer.push_back(current);
                pred->right = NULL;
                current = current->right;
            }
        }
    }

    return answer;
}

TreeNode<int> *flatten(TreeNode<int> *root)
{
    vector<TreeNode<int> *> arr = getInorder(root);
    TreeNode<int> *newRoot = new TreeNode<int>(arr[0]->data);
    TreeNode<int> *current = newRoot;

    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        TreeNode<int> *temp = new TreeNode<int>(arr[i]->data);
        current->left = NULL;
        current->right = temp;
        current = temp;
    }

    return newRoot;
}