#include <bits/stdc++.h>

using namespace std;

void print(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

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

void bottomView(Node *root)
{
    if (root == NULL)
        return;

    // map<horizontalDistance, data>
    map<int, int> topNodes;

    // pair<Node, horizontalDistance>
    queue<pair<Node *, int> > q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> front = q.front();
        q.pop();

        Node *frontNode = front.first;
        int horizontalDistance = front.second;

        // if one value is present then do nothing
        if (topNodes.find(horizontalDistance) == topNodes.end())
        {
            topNodes[horizontalDistance] = frontNode->data;
        }

        if (frontNode->left != NULL)
            q.push(make_pair(frontNode->left, horizontalDistance - 1));

        if (frontNode->right != NULL)
            q.push(make_pair(frontNode->right, horizontalDistance + 1));
    }

    for (auto i : topNodes)
    {
        cout << i.second << " ";
    }

    // return ans;
}

int main()
{
    Node *root = NULL;
    // 10 20 40 -1 -1 60 -1 -1 30 90 -1 -1 100 -1 -1
    root = buildTree(root);
    cout << "\Bottom View Traversal: " << endl;
    bottomView(root);
    return 0;
}