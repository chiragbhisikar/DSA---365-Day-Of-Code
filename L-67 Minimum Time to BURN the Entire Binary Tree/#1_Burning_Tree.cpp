
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

// Step 1 : create mapping between parent & child
// Step 2 : find target Node
Node *createMapping(Node *root, int target, map<Node *, Node *> &nodeToParent)
{
    Node *targetNode = NULL;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *frontNode = q.front();
        q.pop();

        if (frontNode->data == target)
        {
            targetNode = frontNode;
        }

        if (frontNode->left != NULL)
        {
            nodeToParent[frontNode->left] = frontNode;
            q.push(frontNode->left);
        }

        if (frontNode->right != NULL)
        {
            nodeToParent[frontNode->right] = frontNode;
            q.push(frontNode->right);
        }
    }

    return targetNode;
}

// Step 3 : burn tree in min time
int burnTree(Node *root, map<Node *, Node *> nodeToParent)
{
    int burnTime = 0;
    map<Node *, bool> visited;
    queue<Node *> q;

    visited[root] = true;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        bool flag = false;

        for (int i = 0; i < size; i++)
        {
            Node *frontNode = q.front();
            q.pop();

            if (frontNode->left != NULL && !(visited[frontNode->left]))
            {
                flag = true;
                visited[frontNode->left] = true;
                q.push(frontNode->left);
            }

            if (frontNode->right != NULL && !(visited[frontNode->right]))
            {
                flag = true;
                visited[frontNode->right] = true;
                q.push(frontNode->right);
            }

            Node *parentNode = nodeToParent[frontNode];
            if (parentNode != NULL && !(visited[parentNode]))
            {
                flag = true;
                visited[parentNode] = true;
                q.push(parentNode);
            }
        }

        if (flag)
        {
            burnTime++;
        }
    }

    return burnTime;
}
int minTime(Node *root, int target)
{
    // map<node ,parent>
    map<Node *, Node *> nodeToParent;
    Node *targetNode = createMapping(root, target, nodeToParent);
    int burningTimeForTree = burnTree(targetNode, nodeToParent);

    return burningTimeForTree;
}
int main()
{
    Node *root = buildTree(root);
    cout << "\n";
    levelOrderTraversal(root);
    // 1 2 4 -1 -1 5 7 -1 -1 8 -1 -1 3 -1 6 -1 9 -1 10 -1 -1
    cout << "\nBurning Time For Tree :" << minTime(root, 8) << endl;

    return 0;
}
