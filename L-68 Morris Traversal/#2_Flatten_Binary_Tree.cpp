#include <bits/stdc++.h>

using namespace std;

void flatten(Node *root)
{
    Node *current = root;

    while (current != NULL)
    {
        if (current->left != NULL)
        {
            Node *pred = current->left;

            while (pred->right)
            {
                pred = pred->right;
            }
            
            pred->right = current->right;
            current->right = current->left;
            current->left = NULL;
        }
        current = current->right;
    }
}
int main()
{

    return 0;
}