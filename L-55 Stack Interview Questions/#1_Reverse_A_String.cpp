#include <bits/stdc++.h>

using namespace std;

int main()
{
    string text = "_chirag_bhisikar_";
    stack<char> st;

    for (int i = 0; i < text.length(); i++)
    {
        st.push(text[i]);
    }

    string ans = "";
    for (int i = 0; i < text.length(); i++)
    {
        char ch = st.top();
        ans.push_back(ch);
        st.pop();
    }

    cout << ans << endl;
    return 0;
}