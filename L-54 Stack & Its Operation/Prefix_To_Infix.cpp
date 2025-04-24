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

string PostfixToInfix(string s)
{
    stack<string> st;

    for (int i = s.length() - 1; i >= 0; i--)
    {

        if (isalnum(s[i]))
            st.push(string(1, s[i]));

        else
        {

            string s1 = st.top();

            st.pop();

            string s2 = st.top();

            st.pop();

            st.push('(' + s1 + s[i] + s2 + ')');
        }
    }

    return st.top();
}

int main()
{
    string expression = "*-a/bc-/dkl";

    cout << "Postfix To Infix " << PostfixToInfix(expression) << endl;

    return 0;
}

//
// string expression = "(b*l)*(i^7)/((t*9)/(c+(f/p)))";