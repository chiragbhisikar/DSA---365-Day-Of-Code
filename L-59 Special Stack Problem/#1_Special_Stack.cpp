#include <bits/stdc++.h>

using namespace std;

class SpecialStack
{

public:
    stack<int> stackk;
    int mini;
    
    SpecialStack()
    {
        mini = INT_MAX;
    }

    void push(int data)
    {
        if (stackk.empty())
        {
            mini = data;
            stackk.push(data);
        }
        else
        {
            // special case
            if (data < mini)
            {
                int newData = (2 * data) - mini;
                mini = data;
                stackk.push(newData);
            }
            else
            {
                // normal case
                stackk.push(data);
            }
        }
    }

    void pop()
    {
        if (!stackk.empty())
        {
            int data = stackk.top();
            stackk.pop();

            if (data < mini)
            {
                int prevMin = mini;
                int val = 2 * mini - data;
                mini = val;
            }
        }
    }

    int top()
    {
        if (!stackk.empty())
        {
            int data = stackk.top();

            if (mini <= data)
            {
                return data;
            }

            return mini;
        }
        return -1;
    }

    int getMin()
    {
        if (!stackk.empty())
        {
            return mini;
        }
        return -1;
    }
};

int main()
{
    SpecialStack *s = new SpecialStack();
    s->push(13);
    s->push(47);
    cout << "Top Element Of Stack Is " << s->top() << endl;
    s->push(8);
    s->pop();
    cout << "Minimum Element In Stack Is " << s->getMin() << endl;

    return 0;
}