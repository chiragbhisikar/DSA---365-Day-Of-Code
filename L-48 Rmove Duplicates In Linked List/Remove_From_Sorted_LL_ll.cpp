#include <bits/stdc++.h>

using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode()
    {
        this->val = 0;
        this->next = NULL;
    }
    ListNode(int data)
    {
        this->val = data;
        this->next = NULL;
    }
    ListNode(int data, ListNode *node)
    {
        this->val = data;
        this->next = node;
    }
};

void print(ListNode *head)
{
    ListNode *temp = head;

    while (temp != NULL)
    {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

ListNode *deleteDuplicates(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *result = new ListNode(0, head);
    ListNode *prev = result;

    while (head != NULL && head->next != NULL)
    {
        if (head->val == head->next->val)
        {
            // Loop Till Duplicate Last Element Occur
            while (head->next != NULL && head->val == head->next->val)
            {
                head = head->next;
            }
            // Previous -> Next = Duplicate Last Element -> next
            prev->next = head->next;
        }
        else
        {
            // No Duplicate Found
            prev = prev->next;
        }
        // Moving Pointer
        head = head->next;
    }

    return result->next;
}

int main()
{
    // Input: head = [1,2,3,3,4,4,5]
    // Output: [1,2,5]
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(3);
    ListNode *n5 = new ListNode(4);
    ListNode *n6 = new ListNode(4);
    ListNode *n7 = new ListNode(5);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = NULL;

    print(n1);
    ListNode *head = deleteDuplicates(n1);
    print(n1);
    return 0;
}