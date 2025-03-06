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

Node *insertIntoBST(Node *&root, int data)
{

    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    Node *newNode = new Node(data);
    // insert at right part
    if (data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }
    // insert at left part
    else
    {
        root->left = insertIntoBST(root->left, data);
    }

    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void preorderTraversal(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

vector<int> inorderTraversal(Node *root)
{
    Node *current = root;
    vector<int> ans;

    while (current != NULL)
    {
        if (current->left == NULL)
        {
            ans.push_back(current->data);
            current = current->right;
        }
        else
        {
            Node *pred = current->left;

            while (pred->right != current && pred->right != NULL)
            {
                pred = pred->right;
            }

            if (pred->right == NULL)
            {
                pred->right = current;
                current = current->left;
            }
            else
            {
                pred->right = NULL;
                ans.push_back(current->data);
                current = current->right;
            }
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return ans;
}

// Function to perform preorder traversal of the tree
// and copy the values from the inorder array to nodes
void preorderFill(Node *root, vector<int> &inorderArr,
                  int &index)
{
    if (root == nullptr)
    {
        return;
    }

    // Copy the next element from the inorder array
    root->data = inorderArr[index++];

    // Fill left and right subtree
    preorderFill(root->left, inorderArr, index);
    preorderFill(root->right, inorderArr, index);
}

void convertBSTtoMinHeap(Node *root)
{
    // Step 1: Perform inorder traversal
    // to store values in sorted order
    vector<int> inorderArr = inorderTraversal(root);

    int index = 0;

    // Step 2: Perform preorder traversal and
    // fill nodes with inorder values
    preorderFill(root, inorderArr, index);
}

int main()
{
    Node *root = NULL;
    // 4 2 6 1 3 5 7 -1
    cout << "enter data to create binary search tree: ";
    takeInput(root);

    cout << "Printing a bst: ";
    convertBSTtoMinHeap(root);
    preorderTraversal(root);

    return 0;
}