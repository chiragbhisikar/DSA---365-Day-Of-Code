
class Solution
{
public:
    class compare
    {
    public:
        bool operator()(ListNode *a, ListNode *b) { return a->val > b->val; }
    };

    ListNode *mergeKLists(vector<ListNode *> &listArray)
    {
        int k = listArray.size();

        if (k == 0)
        {
            return NULL;
        }

        if (k == 1)
        {
            return listArray[0];
        }

        priority_queue<ListNode *, vector<ListNode *>, compare> minHeap;

        for (int i = 0; i < k; i++)
        {
            if (listArray[i] != NULL)
            {
                // Node *temp = new Node(listArray[i] -> data, listArray[i]);
                minHeap.push(listArray[i]);
            }
        }

        ListNode *sortedHeapHead = NULL;
        ListNode *sortedHeapTail = NULL;

        while (minHeap.size() > 0)
        {
            ListNode *top = minHeap.top();
            minHeap.pop();

            if (top->next != NULL)
            {
                ListNode *temp = top->next;
                minHeap.push(temp);
            }

            // insert at head
            if (sortedHeapHead == NULL)
            {
                sortedHeapHead = top;
                sortedHeapTail = top;
            }
            // insert at end
            else
            {
                sortedHeapTail->next = top;
                sortedHeapTail = sortedHeapTail->next;
            }
        }

        return sortedHeapHead;
    }