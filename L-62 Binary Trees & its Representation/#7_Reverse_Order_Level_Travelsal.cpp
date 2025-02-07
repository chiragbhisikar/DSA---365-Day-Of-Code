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

Node *buildTree(Node *root)
{
    int data;
    cout << "Enter the data: ";
    cin >> data;

    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter the data for inserting in left of " << data << ": " << endl;
    root->left = buildTree(root->left);

    cout << "Enter the data for inserting in right of " << data << ": " << endl;
    root->right = buildTree(root->right);

    return root;
}

void reverseLevelOrderTraversal(Node *root)
{
    queue<Node *> q;
    stack<Node *> stackk;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        stackk.push(temp);

        if (temp == NULL) // old level complete travels
        {
            cout << endl;
            if (!q.empty()) // queue still has child nodes
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << "  ";
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }

            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
        }
    }

    while (stackk.empty() != true)
    {
        if (stackk.top() != NULL)
        {
            cout << stackk.top()->data << " ";
        }
        else
        {
            cout << endl;
        }

        stackk.pop();
    }
}
int main()
{
    Node *root = NULL;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 21 -1 -1
    /* Constructed binary tree is
            1
          /    \
        3        5
      /  \     /    \
    7     11  17     21
  */
    root = buildTree(root);
    cout << "\nlevelOrderTraversal: " << endl;
    reverseLevelOrderTraversal(root);
    return 0;
}