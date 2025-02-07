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

void postorder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void postorderUsingIteration(Node *root)
{
    if (root == NULL)
        return;

    stack<Node *> stack1, stack2;
    stack1.push(root);

    while (stack1.empty() != true)
    {
        Node *current = stack1.top();
        stack2.push(current);
        stack1.pop();

        if (current->left != NULL)
            stack1.push(current->left);
        if (current->right != NULL)
            stack1.push(current->right);
    }

    while (stack2.empty() != true)
    {
        int element = (stack2.top())->data;
        cout << element << " ";
        stack2.pop();
    }
}

int main()
{
    Node *root = NULL;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 21 -1 -1
    root = buildTree(root);

    cout << "\n\npost order: ";
    postorder(root);

    cout << "\npost order: ";
    postorderUsingIteration(root);

    return 0;
}