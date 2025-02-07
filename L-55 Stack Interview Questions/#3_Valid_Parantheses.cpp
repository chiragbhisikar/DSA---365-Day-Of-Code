#include <bits/stdc++.h>

using namespace std;
void print(stack<char> s)
{
    stack<char> temp = s;

    while (!temp.empty())
    {
        cout << temp.top() << "  ";
        temp.pop();
    }
    cout << endl;
}
bool matches(char top, char current)
{
    if ((top == '(' && current == ')') || (top == '{' && current == '}') ||
        (top == '[' && current == ']'))
    {
        return true;
    }
    return false;
}

bool isValidParenthesis(string expression)
{
    stack<char> st;

    for (int i = 0; i < expression.length(); i++)
    {
        char current = expression[i];

        // if opening bracket
        if (current == '(' || current == '{' || current == '[')
        {
            st.push(current);
        }
        // if closing bracket check stack top and pop it
        else
        {
            if (!st.empty())
            {
                char top = st.top();
                if (matches(top, current))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }

    if (st.empty())
    {
        return true;
    }
    return false;
}

int main()
{
    string s = "[()]{}{[()()]()}";
    cout << s << " is valid -> " << (isValidParenthesis(s) ? "YES" : "NO") << endl;
    return 0;
}