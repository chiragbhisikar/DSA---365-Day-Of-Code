// 1047.Remove All Adjacent Duplicates In String
/**
Input: s = "abbaca"
Output: "ca"
Explanation:
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".

Input: s = "azxxzy"
Output: "ay"
 */

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
string removeDuplicates(string s)
{
    int i = 1;
    while (i < s.length())
    {
        if (s.at(i - 1) == s.at(i))
        {
            s.erase(i - 1, 2);
            if ((i - 1) == 0)
            {
                i = 1;
            }
            else
            {
                i = i - 1;
            }
            continue;
        }
        i++;
    }
    return s;
}
int main()
{
    cout << removeDuplicates("abbaca") << endl;
    cout << removeDuplicates("azxxzy") << endl;
    return 0;
}