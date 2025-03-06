#include <bits/stdc++.h>

using namespace std;

int minCost(vector<int> &arr)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < arr.size(); i++)
    {
        minHeap.push(arr[i]);
    }

    int size = minHeap.size();
    int cost = 0;
    while (size > 1)
    {
        int first = minHeap.top();
        minHeap.pop();

        int second = minHeap.top();
        minHeap.pop();

        int answer = first + second;
        cost = cost + answer;
        minHeap.push(answer);

        size = minHeap.size();
    }

    return cost;
}

int main()
{
    vector<int> arr = {4, 2, 7, 6, 9};
    cout << "Min Cost Is " << minCost(arr) << endl;

    return 0;
}