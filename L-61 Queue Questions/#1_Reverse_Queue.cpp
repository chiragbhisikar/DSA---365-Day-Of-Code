#include <bits/stdc++.h>

using namespace std;
// Using Stack

/*
queue<int> reverseQueue(queue<int> &q)
{
    stack<int> stackk;
    while (!q.empty())
    {
        int element = q.front();
        stackk.push(element);
        q.pop();
    }

    while (!stackk.empty())
    {
        int element = stackk.top();
        q.push(element);
        stackk.pop();
    }

    return q;
}
*/

// Using Recursion
void solve(queue<int> &q)
{
    if (q.empty())
    {
        return;
    }

    int element = q.front();
    cout << element << endl;
    q.pop();

    solve(q);
    q.push(element);
}

queue<int> reverseQueue(queue<int> &q)
{
    solve(q);

    return q;
}

int main()
{
    queue<int> q;
    q.push(4);
    q.push(3);
    q.push(2);
    q.push(1);

    q = reverseQueue(q);
    while (!q.empty())
    {
        int element = q.front();
        cout << element << " ";
        q.pop();
    }

    return 0;
}