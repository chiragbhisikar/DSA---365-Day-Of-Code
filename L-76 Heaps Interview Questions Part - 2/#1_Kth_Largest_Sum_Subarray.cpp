#include <bits/stdc++.h>

using namespace std;

int getKthLargest(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;

    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];

            if (minHeap.size() < k)
            {
                minHeap.push(sum);
            }
            else if (minHeap.top() < sum)
            {
                minHeap.pop();
                minHeap.push(sum);
            }
        }
    }

    return minHeap.top();
}

int main()
{
    vector<int> v = {5, 4, -8, 6};
    int k = 10;
    cout << k << "th Largest Subarray Sum Is " << getKthLargest(v, k) << endl;

    return 0;
}