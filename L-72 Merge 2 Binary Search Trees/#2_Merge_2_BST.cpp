#include <bits/stdc++.h>

using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode *insertIntoBST(TreeNode *&root, int data)
{

    if (root == NULL)
    {
        root = new TreeNode(data);
        return root;
    }

    TreeNode *newNode = new TreeNode(data);
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

void takeInput(TreeNode *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

vector<int> getInorder(TreeNode *root)
{
    vector<int> inorder;
    TreeNode *current = root;

    while (current != NULL)
    {
        if (current->left == NULL)
        {
            inorder.push_back(current->data);
            current = current->right;
        }
        else
        {
            TreeNode *pred = current->left;
            while (pred->right != NULL && pred->right != current)
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
                inorder.push_back(current->data);
                pred->right = NULL;
                current = current->right;
            }
        }
    }

    return inorder;
}

void convertIntoDoublyLinkedList(TreeNode *root, TreeNode *&head)
{
    if (root == NULL)
        return;

    convertIntoDoublyLinkedList(root->right, head);
    root->right = head;
    if (head != NULL)
    {
        head->left = root;
    }
    head = root;

    convertIntoDoublyLinkedList(root->left, head);
}

TreeNode *mergeLinkedList(TreeNode *head1, TreeNode *head2)
{
    TreeNode *head = NULL;
    TreeNode *tail = NULL;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            if (head == NULL)
            {
                head = head1;
                tail = head1;

                head1 = head1->right;
            }
            else
            {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else
        {
            if (head == NULL)
            {
                head = head2;
                tail = head2;

                head2 = head2->right;
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while (head1 != NULL)
    {
        if (head == NULL)
        {
            head = head1;
            tail = head1;

            head1 = head1->right;
        }
        else
        {
            tail->right = head1;
            head1->left = tail;
            tail = head1;
            head1 = head1->right;
        }
    }

    while (head2 != NULL)
    {
        if (head == NULL)
        {
            head = head2;
            tail = head2;

            head2 = head2->right;
        }
        else
        {
            tail->right = head2;
            head2->left = tail;
            tail = head2;
            head2 = head2->right;
        }
    }

    return head;
}

int countNodes(TreeNode *head)
{
    int cnt = 0;
    TreeNode *temp = head;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->right;
    }

    return cnt;
}

TreeNode *sortedLinkedListToBST(TreeNode *&head, int n)
{
    if (n <= 0 || head == NULL)
    {
        return NULL;
    }

    // left subtree
    TreeNode *leftSubtree = sortedLinkedListToBST(head, n / 2);
    TreeNode *root = head;
    root->left = leftSubtree;
    head = head->right;

    TreeNode *rightSubtree = sortedLinkedListToBST(head, (n - n / 2 - 1));
    root->right = rightSubtree;

    return root;
}

TreeNode *mergeBST(TreeNode *root1, TreeNode *root2)
{
    TreeNode *head1 = NULL;
    convertIntoDoublyLinkedList(root1, head1);
    head1->left = NULL;

    TreeNode *head2 = NULL;
    convertIntoDoublyLinkedList(root2, head2);
    head2->left = NULL;

    TreeNode *head = mergeLinkedList(head1, head2);
    TreeNode *temp = head;

    TreeNode *mergedBSTRoot = sortedLinkedListToBST(head, countNodes(head));

    return mergedBSTRoot;
}

int main()
{
    TreeNode *root1 = NULL;
    cout << "enter data to create binary search tree: ";
    // 1 2 3 -1
    takeInput(root1);

    TreeNode *root2 = NULL;
    cout << "enter data to create binary search tree: ";
    takeInput(root2);
    // 4 -1

    TreeNode *mergedBST = mergeBST(root1, root2);
    vector<int> ans = getInorder(mergedBST);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}