#include <bits/stdc++.h>

using namespace std;

void print(stack<int> s)
{
    stack<int> temp = s;

    while (!temp.empty())
    {
        cout << temp.top() << "  ";
        temp.pop();
    }
    cout << endl;
}

void sortedInsert(stack<int> &stackk, int element)
{
    if (stackk.empty())
    {
        stackk.push(element);
        return;
    }

    int top = stackk.top();
    if (top >= element)
    {
        stackk.pop();
        sortedInsert(stackk, element);
        stackk.push(top);
    }
    else
    {
        stackk.push(element);
        return;
    }
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    print(s);
    sortedInsert(s, 4);
    print(s);
    return 0;
}