
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

    cout << "Enter the data for inserting in left of " << data << ": ";
    root->left = buildTree(root->left);

    cout << "Enter the data for inserting in right of " << data << ": ";
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

pair<bool, int> isSumTreeFast(Node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    // check for left part
    pair<bool, int> left = isSumTreeFast(root->left);
    // check for right part
    pair<bool, int> right = isSumTreeFast(root->right);

    // check for left part is it's sum tree
    bool isLeftSumTree = left.first;
    // check for right part is it's sum tree
    bool isRightSumTree = right.first;

    // now check sum of left & right with root node data
    int leftSum = left.second;
    int rightSum = right.second;
    bool checkSum = (left.second + right.second) == root->data;

    pair<bool, int> answer;
    if (isLeftSumTree && isRightSumTree && checkSum)
    {
        answer.first = true;
        answer.second = left.second + right.second + root->data; // 10 + 20 + 30 = 60
        // or
        // answer.second = root->data * 2; // 30 * 2 = 60
    }
    else
    {
        answer.first = false;
        answer.second = 0;
    }

    return answer;
}

bool isSumTree(Node *root)
{
    return isSumTreeFast(root).first;
}

int main()
{
    Node *root = NULL;
    // 1 2 4 -1 -1 5 -1 -1 3 -1 -1
    // 70 20 10 -1 -1 10 -1 -1 30 -1 -1
    root = buildTree(root);

    cout << "\nlevelOrderTraversal: " << endl;
    levelOrderTraversal(root);

    cout << "Sum Tree = " << (isSumTree(root) ? "Yes" : "No") << endl;

    return 0;
}
