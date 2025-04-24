#include <bits/stdc++.h>

using namespace std;

string PostfixToPrefix(string s)
{
    stack<string> st;

    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (isalnum(s[i]))
        {
            st.push(string(1, s[i]));
        }
        else
        {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();

            st.push(t1 + t2 + s[i]);
        }
    }

    return st.top();
}

int main()
{
    string expression = "/A+BC";

    cout << "Prefix To Postfix " << PostfixToPrefix(expression) << endl;

    return 0;
}

//
// string expression = "(b*l)*(i^7)/((t*9)/(c+(f/p)))";