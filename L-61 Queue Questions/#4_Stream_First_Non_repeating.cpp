#include <bits/stdc++.h>

using namespace std;

string FirstNonRepeating(string &s)
{
    unordered_map<char, int> count;
    queue<char> q;
    string ans = "";

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        //   increase count
        count[ch]++;

        // push into q
        q.push(ch);
        while (!q.empty())
        {
            if (count[q.front()] > 1)
            {
                // repeating character
                q.pop();
            }
            else
            {
                // non reapeating character
                ans.push_back(q.front());
                break;
            }
        }
        if (q.empty())
        {
            ans.push_back('#');
        }
    }

    return ans;
}
int main()
{
    string s = "aabc";
    cout << "s = " << s << endl;
    string ans = FirstNonRepeating(s);
    cout << "ans = " << ans << endl;
    
    return 0;
}