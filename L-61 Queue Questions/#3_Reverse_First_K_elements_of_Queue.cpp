#include <bits/stdc++.h>

using namespace std;
void reverse(queue<int> &q, int k)
{
    int n = q.size();
    stack<int> stackk;

    // step 1 : pop first k numbers and push it into stack
    for (int i = 0; i < k; i++)
    {
        int element = q.front();
        stackk.push(element);
        q.pop();
    }

    // step 2 : pop element untial stackk does not become empty so elements become reverse
    while (!stackk.empty())
    {
        int element = stackk.top();
        q.push(element);
        stackk.pop();
    }

    // put first n - k elements to their right place
    for (int i = 0; i < (n - k); i++)
    {
        int element = q.front();
        q.pop();
        q.push(element);
    }
}

int main()
{

    return 0;
}