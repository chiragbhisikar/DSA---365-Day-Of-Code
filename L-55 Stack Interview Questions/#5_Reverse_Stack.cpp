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
void insertAtBottom(stack<int> &stackk, int element)
{
    // base case
    if (stackk.empty())
    {
        stackk.push(element);
        return;
    }
    int currentElement = stackk.top();
    stackk.pop();

    //   recursive call
    insertAtBottom(stackk, element);
    // after excuting all next task come and add element
    stackk.push(currentElement);
}

void reverseStack(stack<int> &stackk)
{
    // base case
    if (stackk.empty())
    {
        return;
    }
    int currentElement = stackk.top();
    stackk.pop();
    //   recursive call
    reverseStack(stackk);

    // after excuting all next task come and add element in bottom of stack
    insertAtBottom(stackk, currentElement);
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
    reverseStack(s);
    print(s);

    return 0;
}