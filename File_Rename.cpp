#include <bits/stdc++.h>

using namespace std;

string renameFile(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
            s[i] = '_';
    }
    return s;
}

int main()
{
    string s;
    getline(cin, s);
    string fileName = renameFile(s);
    cout << fileName << endl;

    return 0;
}