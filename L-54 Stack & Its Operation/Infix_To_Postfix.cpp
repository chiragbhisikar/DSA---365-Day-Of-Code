#include <bits/stdc++.h>

using namespace std;

int priority(char ch)
{
    if (ch == '^')
        return 3;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;
    return -1;
}

string infixToPostfix(string s)
{
    string ans = "";
    stack<char> stackk;

    for (int i = 0; i < s.length(); i++)
    {
        char currentChar = s[i];

        // Operand
        if (currentChar >= 'A' && currentChar <= 'Z' ||
            currentChar >= 'a' && currentChar <= 'z' ||
            currentChar >= '0' && currentChar <= '9')
        {
            ans = ans + currentChar;
        }
        else if (currentChar == '(')
        {
            stackk.push(currentChar);
        }
        else if (currentChar == ')')
        {
            while (stackk.top() != '(')
            {
                ans += stackk.top();
                stackk.pop();
            }
            stackk.pop();
        }
        // operator
        else
        {
            while (!stackk.empty() && priority(s[i]) <= priority(stackk.top()))
            {
                ans += stackk.top();
                stackk.pop();
            }
            stackk.push(currentChar);
        }
        cout << ans << endl;
    }

    while (!stackk.empty())
    {
        char top = stackk.top();
        if (top != '(')
        {
            ans = ans + top;
        }
        stackk.pop();
    }

    return ans;
}

int main()
{
    // string expression = "a+b*(c^d-e)";
    // string expression = "a+b+c+d-e";
    string expression = "(b*l)*(i^7)/((t*9)/(c+(f/p)))";

    cout << "Infix To Postfix " << infixToPostfix(expression) << endl;
    return 0;
}
