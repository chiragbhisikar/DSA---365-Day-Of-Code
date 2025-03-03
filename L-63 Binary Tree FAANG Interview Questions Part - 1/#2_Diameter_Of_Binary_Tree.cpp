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

// pair<int , int> => first -> Diameter & Second -> Height
pair<int, int> diameterFast(Node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = diameterFast(root->left);   // getting diameter Of left Tree
    pair<int, int> right = diameterFast(root->right); // getting diameter Of Right Tree

    int optionOne = left.first;                         // left diameter
    int optionTwo = right.first;                        // right diameter
    int optionThree = (left.second + right.second) + 1; // height of left tree and right tree

    pair<int, int> answer;
    answer.first = max(optionOne, max(optionTwo, optionThree)); // for diameter of tree
    answer.second = max(left.second, right.second) + 1;         // for height of tree

    return answer;
}

int diameterOfBinaryTree(Node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 0;

    int diameterOfTree = diameterFast(root).first - 1;

    return diameterOfTree;
}

int main()
{
    Node *root = NULL;
    // 1 2 4 -1 -1 5 -1 -1 3 -1 -1
    root = buildTree(root);
    cout << "\nlevelOrderTraversal: " << endl;
    levelOrderTraversal(root);
    cout << "diameter of tree: " << diameterOfBinaryTree(root) << endl;
    return 0;
}
