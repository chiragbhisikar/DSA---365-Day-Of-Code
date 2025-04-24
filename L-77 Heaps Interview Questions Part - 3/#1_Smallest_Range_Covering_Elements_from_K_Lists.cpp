
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    int row;
    int col;

    Node(int data, int row, int col)
    {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

int kSorted(vector<vector<int>> &a, int k, int n)
{
    int mini = INT_MAX, maxi = INT_MIN;

    // step 1 : create a min heap for starting element of each list & tracking mini & maxi
    priority_queue<Node *, vector<Node *>, compare> minHeap;

    for (int i = 0; i < k; i++)
    {
        int element = a[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        minHeap.push(new Node(element, i, 0));
    }

    // step 2 : process ranges
    int start = mini, end = maxi;
    while (!minHeap.empty())
    {
        // mini fetch
        Node *top = minHeap.top();
        mini = top->data;
        int row = top->row;
        int col = top->col;
        minHeap.pop();

        // range or ans updation
        if (maxi - mini < end - start)
        {
            start = mini;
            end = maxi;
        }

        // list next element is exist
        if (col + 1 < n)
        {
            int element = a[row][col + 1];
            maxi = max(maxi, element);
            minHeap.push(new Node(element, row, col + 1));
        }
        else
        {
            // next element is does not exist
            break;
        }
    }

    int answer = (end - start) + 1;

    return answer;
}

int main()
{

    return 0;
}