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
void verticalOrder(Node *root)
{
    vector<int> ans;
    if (root == NULL)
      return;

    // map<horizontalDistance, map <level,data>>
    map<int, map<int, vector<int> > > mapp;
    // queue<pair<TreeNode *, pair<horizontalDistance,level>>
    queue<pair<Node *, pair<int, int> > > q;
    q.push(make_pair(
        root, make_pair(0, 0))); // because it root node level -> 0 hd -> 0

    while (!q.empty())
    {
        // pair<TreeNode *, pair<horizontalDistance,level>
        pair<Node *, pair<int, int> > node = q.front();
        q.pop();

        // destructuring data
        Node *frontNode = node.first;
        int horizontalDistance = node.second.first;
        int level = node.second.second;

        // push data at it's horizontalDistance,level -> position
        mapp[horizontalDistance][level].push_back(frontNode->data);

        // same as level order traversal ->
        // q.push_back(make_pair(root,make_pair(horizontalDistance,level)));
        if (frontNode->left != NULL)
        {
            q.push(make_pair(frontNode->left,
                             make_pair(horizontalDistance - 1, level + 1)));
        }

        if (frontNode->right != NULL)
            q.push(make_pair(frontNode->right,
                             make_pair(horizontalDistance + 1, level + 1)));
    }

    for (auto i : mapp)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                cout << k << " ";
                // ans.push_back(k);
            }
        }
    }

    // return ans;
}

int main()
{
    Node *root = NULL;
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 8 -1 -1 7 -1 9 -1 -1
    root = buildTree(root);
    cout << "\nVertical Tree Traversal: " << endl;
    verticalOrder(root);
    return 0;
}