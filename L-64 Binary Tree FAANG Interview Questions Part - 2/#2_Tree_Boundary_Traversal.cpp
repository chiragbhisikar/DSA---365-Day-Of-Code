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

void traverseLeft(Node *root, vector<int> &answer)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;

    answer.push_back(root->data);

    if (root->left)
        traverseLeft(root->left, answer);
    else
        traverseLeft(root->right, answer);
}

// Inorder Traversal Logic
void traverseLeaf(Node *root, vector<int> &answer)
{
    // base case
    if (root == NULL)
        return;

    if ((root->left == NULL && root->right == NULL))
    {
        answer.push_back(root->data);
        return;
    }

    traverseLeaf(root->left, answer);
    traverseLeaf(root->right, answer);
}

void traverseRight(Node *root, vector<int> &answer)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;

    if (root->right)
        traverseRight(root->right, answer);
    else
        traverseRight(root->left, answer);

    // wapas aagye
    answer.push_back(root->data);
}

vector<int> boundaryTraversal(Node *root)
{
    vector<int> answer;

    if (root == NULL)
        return answer;

    answer.push_back(root->data);

    // Traversal left part
    traverseLeft(root->left, answer);
    print(answer);

    // Traversal leaf node
    // left subtree
    traverseLeaf(root->left, answer);
    print(answer);
    // right subtree
    traverseLeaf(root->right, answer);
    print(answer);

    // Traversal right subtree
    traverseRight(root->right, answer);
    print(answer);

    return answer;
}

int main()
{
    Node *root = NULL;
    // 1 2 4 -1 -1 5 8 -1 -1 9 -1 -1 3 6 -1 -1 7 -1 -1
    root = buildTree(root);
    cout << "\nTree Boundary Travelsal: " << endl;
    vector<int> v = boundaryTraversal(root);

    return 0;
}