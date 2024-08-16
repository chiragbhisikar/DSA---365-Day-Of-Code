#include <iostream>
#include <bits/stdc++.h>

using namespace std;

char toLowerCase(char c)
{
    // is Capital => Yes => Convert Into Lower Case
    if (c >= 'A' && c <= 'Z')
    {
        c = c + 32;
        return c;
    }
    return c;
}

char getMaxOccuringChar(string str)
{
    vector<int> arr(26, 0);

    for (int i = 0; i < str.length(); i++)
    {
        char element = toLowerCase(str[i]);
        element = element - 'a';
        arr[int(element)]++;
    }

    int maxi = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[maxi] < arr[i])
        {
            maxi = i;
        }
    }

    return char('a' + maxi);
}

int main()
{
    string s = "test";
    cout << getMaxOccuringChar(s) << endl;
    return 0;
}