#include <iostream>
#include <bits/stdc++.h>

using namespace std;
void reverseStringRecursive(string &str, int start, int end)
{
    if (start > end)
    {
        return;
    }

    swap(str[start++], str[end--]);

    reverseStringRecursive(str, start, end);
}

void reverseOnePointer(string &str, int pointer)
{
    int start = pointer;
    int end = str.length() - pointer - 1;
    if (start > end)
    {
        return;
    }

    swap(str[start], str[end]);

    reverseOnePointer(str, ++pointer);
}

string reverseString(string str)
{
    reverseStringRecursive(str, 0, str.length() - 1);
    return str;
}

int main()
{
    string str = "abcde";
    cout << reverseString(str) << endl;
    return 0;
}