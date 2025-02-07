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
void solve(stack<int> &inputStack, int count, int size)
{
    // base case
    if (count == size / 2)
    {
        inputStack.pop();
        return;
    }

    int number = inputStack.top();
    inputStack.pop();

    // Recursive Call
    solve(inputStack, count + 1, size);
    inputStack.push(number);
}

void deleteMiddle(stack<int> &inputStack, int size)
{
    int count = 0;
    solve(inputStack, count, size);
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

    deleteMiddle(s, s.size());

    print(s);
    return 0;
}