// 443. String Compression

/**
Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3"
 */

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
void print(vector<char> &chars)
{
    for (int i = 0; i < chars.size(); i++)
    {
        cout << chars[i];
    }
    cout << endl;
}

int compress(vector<char> &chars)
{
    int ansIndex = 0;
    int n = chars.size();
    int i = 0;

    while (i < n)
    {
        int j = i + 1;

        // Counting Occurrence Of Character In Array
        while (j < n && chars[j] == chars[i])
        {
            j++;
        }
        // Number Of Occurrence Of Character
        int count = j - i;

        // For Pushing Old Element
        chars[ansIndex] = chars[i];
        ansIndex++;

        if (count > 1)
        {
            string str = to_string(count);

            for (int i = 0; i < str.size(); i++)
            {
                chars[ansIndex] = str[i];
                ansIndex++;
            }
        }
        cout << count << "\t" << ansIndex << endl;
        i = j;
    }
    return ansIndex;
}

int main()
{
    vector<char> ch;
    ch.push_back('a');
    ch.push_back('a');
    ch.push_back('b');
    ch.push_back('b');
    ch.push_back('c');
    ch.push_back('c');
    ch.push_back('c');
    cout << compress(ch) << endl;
    return 0;
}