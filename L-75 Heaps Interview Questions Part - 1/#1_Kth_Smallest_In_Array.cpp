#include <bits/stdc++.h>

using namespace std;

int kthSmallest(vector<int> &arr, int k)
{
    int n = arr.size();
    // create max heap
    priority_queue<int> pq;

    // 0 --> k
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    // k --> n
    for (int i = k; i < n; i++)
    {
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    return pq.top();
}

int kthLargest(vector<int> &arr, int k)
{
    int n = arr.size();
    // create max heap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // 0 --> k
    for (int i = 0; i < k; i++)
    {
        minHeap.push(arr[i]);
    }

    // k --> n
    for (int i = k; i < n; i++)
    {
        if (arr[i] > minHeap.top())
        {
            minHeap.pop();
            minHeap.push(arr[i]);
        }
    }

    return minHeap.top();
}

int main()
{
    vector<int> arr = {5, 6, 1, 2, 4};
    int k = 4;
    cout << k << "th Smallest Element Is " << kthSmallest(arr, k) << endl;
    cout << k << "th Largest Element Is " << kthLargest(arr, k) << endl;

    return 0;
}