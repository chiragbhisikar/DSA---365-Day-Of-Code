#include <bits/stdc++.h>

using namespace std;

bool findRedundantBrackets(string &s)
{
    stack<char> stackk;
    for (int i = 0; i < s.length(); i++)
    {
        char element = s[i];
        if (element == '(' || element == '+' || element == '-' || element == '*' ||
            element == '/')
        {
            stackk.push(element);
        }
        else
        {
            if (element == ')')
            {
                bool isRedudant = true;

                while (stackk.top() != '(')
                {
                    char currentElement = stackk.top();
                    if (currentElement == '+' || currentElement == '-' ||
                        currentElement == '*' || currentElement == '/')
                    {
                        isRedudant = false;
                    }
                    stackk.pop();
                }

                if (isRedudant == true)
                {
                    return true;
                }
                stackk.pop();
            }
        }
    }

    return false;
}

int main()
{
    string s = "((a+c*b)+(c))";
    cout << s << " brackets are redudant -> " << (findRedundantBrackets(s) ? "YES" : "NO") << endl;

    s = "(a+b)";
    cout << s << " brackets are redudant -> " << (findRedundantBrackets(s) ? "YES" : "NO") << endl;
    return 0;
}