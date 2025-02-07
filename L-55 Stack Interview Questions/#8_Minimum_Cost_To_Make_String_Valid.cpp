#include <bits/stdc++.h>

using namespace std;

string removeValid(string str)
{
    stack<char> stackk;

    for (int i = 0; i < str.length(); i++)
    {
        char currentChar = str[i];
        if (currentChar == '{')
        {
            stackk.push('{');
        }
        else if (currentChar == '}')
        {
            if (!stackk.empty() && stackk.top() == '{')
            {
                stackk.pop();
            }
            else
            {
                stackk.push(currentChar);
            }
        }
    }

    string invalid = "";
    while (!stackk.empty())
    {
        char currentChar = stackk.top();
        invalid = invalid + currentChar;
        stackk.pop();
    }
    cout << invalid << endl;
    return invalid;
}

int findMinimumCost(string str)
{
    if (str.length() % 2 == 1)
    {
        return -1;
    }
    string invalidString = removeValid(str);
    if (invalidString.length() == 0)
    {
        return 0;
    }

    int openingCount = 0;
    int closingCount = 0;

    for (int i = 0; i < invalidString.length(); i++)
    {
        if (invalidString[i] == '{')
        {
            openingCount++;
        }
        else
        {
            closingCount++;
        }
    }

    int answer = ((openingCount + 1) / 2) + ((closingCount + 1) / 2);
    return answer;
}

int main()
{
    // string str = "{{{}";
    // string str = "{{}{}}";
    string str = "{}}{}}";
    cout << findMinimumCost(str);
    return 0;
}