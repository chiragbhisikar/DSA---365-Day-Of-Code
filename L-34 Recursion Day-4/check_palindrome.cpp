#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool check(string str, int pointer)
{
    int start = pointer;
    int end = str.length() - pointer - 1;
    
    if (start > end)
    {
        return true;
    }

    if (str[start] != str[end])
    {
        return false;
    }

    return check(str, ++pointer);
}

bool checkPalindrome(string str)
{
    return check(str, 0);
}
int main()
{
    string str = "nayan";
    cout << checkPalindrome(str) << endl;
    return 0;
}