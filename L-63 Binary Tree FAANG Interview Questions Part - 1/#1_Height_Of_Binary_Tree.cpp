
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

int getHeight(Node *root)
{
    if (root == NULL)
        return 0;

    int left = getHeight(root->left);
    int right = getHeight(root->right);

    int answer = max(left, right) + 1;

    return answer;
}

int heightOfTree(Node *root)
{
    return getHeight(root);
}

int main()
{
    Node *root = NULL;
    // 1 2 4 -1 -1 5 -1 -1 3 -1 -1
    root = buildTree(root);
    cout << "\nlevelOrderTraversal: " << endl;
    levelOrderTraversal(root);
    cout << "Height Tree = " << heightOfTree(root) << endl;
    return 0;
}
