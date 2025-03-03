
vector<int> getInorder(TreeNode<int> *root)
{
    vector<int> answer;
    TreeNode<int> *current = root;

    while (current != NULL)
    {
        if (current->left == NULL)
        {
            answer.push_back(current->data);
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
                answer.push_back(current->data);
                pred->right = NULL;
                current = current->right;
            }
        }
    }

    return answer;
}

TreeNode<int>* inorderToBST(int start, int end, vector<int> arr){
    // base case
    if(start > end)
        return NULL;
    
    int mid = (start + end) / 2;
    
    TreeNode<int>* root = new TreeNode<int>(arr[mid]);
    root -> left = inorderToBST(start, mid - 1, arr);
    root -> right = inorderToBST(mid + 1, end, arr);

    return root;
}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector<int> arr = getInorder(root);

    return inorderToBST(0 , arr.size() - 1, arr);
}
