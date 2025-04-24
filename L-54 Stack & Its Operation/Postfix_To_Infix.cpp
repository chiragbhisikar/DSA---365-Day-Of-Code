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
    int n = s.size();

    stack<string> st;

    for (int i = 0; i < n; i++)
    {

        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' &&

                                             s[i] <= 'z') ||
            (s[i] >= '0' && s[i] <= '9'))

            st.push(string(1, s[i]));

        else
        {

            string s1 = st.top();

            st.pop();

            string s2 = st.top();

            st.pop();

            st.push('(' + s2 + s[i] + s1 + ')');
        }
    }

    return st.top();
}

int main()
{
    string expression = "ab+c+";

    cout << "Postfix To Infix " << PostfixToInfix(expression) << endl;

    return 0;
}

//
// string expression = "(b*l)*(i^7)/((t*9)/(c+(f/p)))";