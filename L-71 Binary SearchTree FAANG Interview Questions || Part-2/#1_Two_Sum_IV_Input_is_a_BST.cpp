#include <bits/stdc++.h>

using namespace std;

vector<int> getInorder(BinaryTreeNode<int> *root)
{
    vector<int> answer;
    BinaryTreeNode<int> *current = root;

    while (current != NULL)
    {
        if (current->left == NULL)
        {
            answer.push_back(current->data);
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
                answer.push_back(current->data);
                pred->right = NULL;
                current = current->right;
            }
        }
    }

    return answer;
}

bool twoSumInBST(BinaryTreeNode<int> *root, int k)
{
    vector<int> arr = getInorder(root);

    int start = 0, end = arr.size() - 1;
    while (start < end)
    {
        int sum = arr[start] + arr[end];

        if (sum == k)
        {
            return true;
        }

        if (sum < k)
        {
            start = start + 1;
        }
        else
        {
            end = end - 1;
        }
    }
    return false;
}

int main()
{

    return 0;
}