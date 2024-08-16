#include <iostream>
#include <bits/stdc++.h>

using namespace std;
void print(vector<char> &s)
{
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i];
    }
    cout << endl;
}

void reverseString(vector<char> &s)
{
    int start = 0;
    int end = s.size() - 1;

    while (start < end)
    {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;

        start++;
        end--;
    }
    print(s);
}

int main()
{
    vector<char> v;
    v.push_back('C');
    v.push_back('h');
    v.push_back('i');
    v.push_back('r');
    v.push_back('a');
    v.push_back('g');

    reverseString(v);
    return 0;
}