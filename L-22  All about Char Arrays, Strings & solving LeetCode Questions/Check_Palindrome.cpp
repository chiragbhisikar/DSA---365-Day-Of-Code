#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int getLength(char str[])
{
    int count = 0;
    int i = 0;

    while (str[i] != '\0')
    {
        count++;
        i++;
    }
    return count;
}

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

bool checkValidate(char c)
{
    if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') ||
        (c >= 'a' && c <= 'z'))
    {
        return true;
    }

    return false;
}
bool checkPalindrome(string s)
{
    int start = 0;
    int end = s.length() - 1;

    while (start <= end)
    {

        if (!checkValidate(s[start]))
        {
            ++start;
        }
        if (!checkValidate(s[end]))
        {
            --end;
        }

        if (checkValidate(s[start]) && checkValidate(s[end]))
        {
            s[start] = toLowerCase(s[start]);
            s[end] = toLowerCase(s[end]);

            if (!(s[start] == s[end]))
            {
                return false;
            }
            start++;
            end--;
        }
    }
    return true;
}
int main()
{
    string s = "N2 i&nJA?a& jnI2n";
    cout << checkPalindrome(s) << endl;
    return 0;
}