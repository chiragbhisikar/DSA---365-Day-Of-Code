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

void zigZagTraversal(Node *root)
{
    vector<int> result;

    // if (root == NULL)
    // return result;

    queue<Node *> q;
    q.push(root);

    bool leftToRight = true;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);

        // process level
        for (int i = 0; i < size; i++)
        {
            Node *frontNode = q.front();
            q.pop();

            int index = leftToRight ? i : size - i - 1;
            ans[index] = frontNode->data;

            if (frontNode->left)
                q.push(frontNode->left);

            if (frontNode->right)
                q.push(frontNode->right);
        }

        for (auto i : ans)
        {
            // result.push_back(i);
            cout << i << " ";
        }
        
        cout << endl;
        // direction change
        leftToRight = !leftToRight;
    }

    // return result;
}

int main()
{
    Node *root = NULL;
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    root = buildTree(root);
    cout << "\nZigZagTraversal: " << endl;
    zigZagTraversal(root);
    return 0;
}