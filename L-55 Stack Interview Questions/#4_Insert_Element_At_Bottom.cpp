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

void solve(stack<int> &myStack, int x)
{
    if (myStack.empty())
    {
        myStack.push(x);
        return;
    }

    int top = myStack.top();
    // Recursive Call
    myStack.pop();
    solve(myStack, x);

    // after comming from executing all task add element
    myStack.push(top);
}

stack<int> pushAtBottom(stack<int> &myStack, int x)
{
    solve(myStack, x);
    return myStack;
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
    s = pushAtBottom(s, 0);
    print(s);

    return 0;
}