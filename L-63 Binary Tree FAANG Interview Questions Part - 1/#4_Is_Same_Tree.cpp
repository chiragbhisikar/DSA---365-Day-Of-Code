
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

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();

        q.pop();

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
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }

            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}

bool isSameTree(Node *p, Node *q)
{
    if (p == NULL && q == NULL)
    {
        return true;
    }

    if (p == NULL && q != NULL || p != NULL && q == NULL)
    {
        return false;
    }

    int left = isSameTree(p->left, q->left);
    int right = isSameTree(p->right, q->right);

    bool value = p->data == q->data;

    if (left && right && value)
    {
        return true;
    }

    return false;
}

int main()
{
    Node *root1 = NULL;
    Node *root2 = NULL;
    // 1 2 4 -1 -1 5 -1 -1 3 -1 -1
    root1 = buildTree(root1);
    root2 = buildTree(root2);

    cout << "\nlevelOrderTraversal: " << endl;
    levelOrderTraversal(root1);
    cout << "\nlevelOrderTraversal: " << endl;
    levelOrderTraversal(root2);

    cout << "Same Tree = " << (isSameTree(root1, root2) ? "Yes" : "No") << endl;

    return 0;
}
