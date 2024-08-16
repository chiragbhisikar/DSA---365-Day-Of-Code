#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string reverse(string s, int start, int end)
{
    while (start < end)
    {
        swap(s[start], s[end]);
        start++;
        end--;
    }
    return s;
}
void reverseWords(string s)
{
    int i = 0;
    int start = 0;
    int end = 0;
    while (i != s.length())
    {
        if (s[i] == ' ')
        {
            s = reverse(s, start, end);
            i++;
            start = i;
            end = i;
        }
        else
        {
            end = i++;
        }
    }
    s = reverse(s, start, end);
    cout << s << endl;
}
int main()
{
    string s = "My Name Is Chirag";
    reverseWords(s);
    return 0;
}