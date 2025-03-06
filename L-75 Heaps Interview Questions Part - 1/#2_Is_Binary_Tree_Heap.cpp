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
    vector<vector<int>> answer;
    vector<int> data;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();

        q.pop();

        if (temp == NULL) // old level complete travels
        {
            answer.push_back(data);
            data.clear();
            cout << endl;
            if (!q.empty()) // queue still has child nodes
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << "  ";
            data.push_back(temp->data);
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

void countNode(Node *root, int &totalNodes)
{
    if (root == NULL)
        return;

    totalNodes++;
    countNode(root->left, totalNodes);
    countNode(root->right, totalNodes);
}

bool isCBT(Node *root, int index, int totalNodes)
{
    if (root == NULL)
        return true;

    if (index >= totalNodes)
        return false;

    bool left = isCBT(root->left, (index * 2) + 1, totalNodes);
    bool right = isCBT(root->right, (index * 2) + 2, totalNodes);

    return left && right;
}

bool isMaxOrder(Node *root)
{
    if (root->left == NULL && root->right == NULL)
        return true;

    if (root->right == NULL)
    {
        return (root->data > root->left->data);
    }
    else
    {
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);

        return left && right &&
               ((root->data > root->left->data) &&
                (root->data > root->right->data));
    }
}

bool isHeap(Node *root)
{
    int index = 0, totalNodes = 0;
    countNode(root, totalNodes);

    if (isCBT(root, index, totalNodes) && isMaxOrder(root))
        return true;

    return false;
}

int main()
{
    Node *root = NULL;
    // 97 46 12 6 -1 -1 9 -1 -1 3 -1 -1 37 7 -1 -1 31 -1 -1
    root = buildTree(root);
    cout << endl;
    levelOrderTraversal(root);
    cout << "Tree is head tree -> " << (isHeap(root) ? "yes it is" : "no it is not") << endl;

    // 97 46 12 -1 -1 3 2 -1 -1 4 -1 -1 37 7 -1 -1 31 -1 -1
    root = buildTree(root);
    cout << endl;
    levelOrderTraversal(root);
    cout << "Tree is head tree -> " << (isHeap(root) ? "yes it is" : "no it is not") << endl;

    return 0;
}