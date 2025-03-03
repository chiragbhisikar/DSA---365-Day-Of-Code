#include <bits/stdc++.h>

using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode *insertIntoBST(TreeNode *&root, int data)
{

    if (root == NULL)
    {
        root = new TreeNode(data);
        return root;
    }

    TreeNode *newNode = new TreeNode(data);
    // insert at right part
    if (data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }
    // insert at left part
    else
    {
        root->left = insertIntoBST(root->left, data);
    }

    return root;
}

void takeInput(TreeNode *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

vector<int> getInorder(TreeNode *root)
{
    vector<int> inorder;
    TreeNode *current = root;

    while (current != NULL)
    {
        if (current->left == NULL)
        {
            inorder.push_back(current->data);
            current = current->right;
        }
        else
        {
            TreeNode *pred = current->left;
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
                inorder.push_back(current->data);
                pred->right = NULL;
                current = current->right;
            }
        }
    }

    return inorder;
}

vector<int> mergeTwoSortedArray(vector<int> arr1, vector<int> arr2)
{
    vector<int> mergedArray;
    int firstPointer = 0, secondPointer = 0;
    int n = arr1.size(), m = arr2.size();

    while (firstPointer < n && secondPointer < m)
    {
        if (arr1[firstPointer] <= arr2[secondPointer])
        {
            mergedArray.push_back(arr1[firstPointer]);
            firstPointer++;
        }
        else
        {
            mergedArray.push_back(arr2[secondPointer]);
            secondPointer++;
        }
    }

    while (firstPointer < n)
    {
        mergedArray.push_back(arr1[firstPointer]);
        firstPointer++;
    }

    while (secondPointer < m)
    {
        mergedArray.push_back(arr2[secondPointer]);
        secondPointer++;
    }

    return mergedArray;
}

TreeNode *inorderToBST(int start, int end, vector<int> arr)
{
    // base case
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;

    TreeNode *root = new TreeNode(arr[mid]);
    root->left = inorderToBST(start, mid - 1, arr);
    root->right = inorderToBST(mid + 1, end, arr);

    return root;
}

TreeNode *mergeBST(TreeNode *root1, TreeNode *root2)
{
    vector<int> arr1 = getInorder(root1);
    vector<int> arr2 = getInorder(root2);

    vector<int> mergedArray = mergeTwoSortedArray(arr1, arr2);

    return inorderToBST(0, mergedArray.size() - 1, mergedArray);
}

int main()
{
    TreeNode *root1 = NULL;
    cout << "enter data to create binary search tree: ";
    // 1 2 3 -1
    takeInput(root1);

    TreeNode *root2 = NULL;
    cout << "enter data to create binary search tree: ";
    takeInput(root2);
    // 4 -1

    TreeNode *mergedBST = mergeBST(root1, root2);
    vector<int> ans = getInorder(mergedBST);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}