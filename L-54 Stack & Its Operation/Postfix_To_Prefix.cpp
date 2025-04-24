#include <bits/stdc++.h>

using namespace std;

string PostfixToPrefix(string s)
{
    stack<string> st;

    for (int i = 0; i < s.length(); i++)
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

            st.push(s[i] + t2 + t1);
        }
    }

    return st.top();
}

int main()
{
    string expression = "ab+cd-*";

    cout << "Postfix To Infix " << PostfixToPrefix(expression) << endl;

    return 0;
}

//
// string expression = "(b*l)*(i^7)/((t*9)/(c+(f/p)))";