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
    // vector<vector<int>> answer;
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
            // answer.push_back(data);
            // data.clear();
            cout << endl;
            if (!q.empty()) // queue still has child nodes
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << "  ";
            // data.push_back(temp->data);
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

void buildFromLevelOrder(Node* &root)
{
    queue<Node *> q;
    int data;

    cout << "Enter Root Data: ";
    cin >> data;
    root = new Node(data);
    q.push(root);

    while (q.empty() != true)
    {
        Node *temp = q.front();
        q.pop();

        int leftData;
        cout << "Enter Left Node For " << temp->data << " : ";
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        int rightData;
        cout << "Enter Right Node For " << temp->data << " : ";
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

int main()
{
    Node *root;
    buildFromLevelOrder(root);
    // 1 3 7 5 11 17 21 -1 -1 -1 -1 -1 -1 -1 -1
    // 
    cout << "\nlevelOrderTraversal: " << endl;
    levelOrderTraversal(root);
    return 0;
}