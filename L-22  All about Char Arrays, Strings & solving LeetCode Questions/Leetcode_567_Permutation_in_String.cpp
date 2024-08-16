/*
Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool checkEqual(int arr1[], int arr2[])
{
    for (int i = 0; i < 26; i++)
    {
        if (arr1[i] != arr2[i])
        {
            return false;
        }
    }
    return true;
}

bool checkInclusion(string s1, string s2)
{
    int arr1[26] = {0};
    int arr2[26] = {0};

    // For S1 With Marking All Character
    for (int i = 0; i < s1.length(); i++)
    {
        int index = s1[i] - 'a';
        arr1[index]++;
    }

    int i = 0;
    int windowSize = s1.length();

    // For Arr2 Marking With All Character Of S2
    while (i < windowSize && i < s2.length())
    {
        int index = s2[i] - 'a';
        arr2[index]++;
        i++;
    }

    // Checking First Window
    if (checkEqual(arr1, arr2))
    {
        return true;
    }

    while (i < s2.length())
    {
        char oldCharacter = s2[i - windowSize];
        int indexOfOldCharacter = oldCharacter - 'a';
        arr2[indexOfOldCharacter]--;

        char newCharacter = s2[i];
        int indexOfNewCharacter = newCharacter - 'a';
        arr2[indexOfNewCharacter]++;

        i++;

        if (checkEqual(arr1, arr2))
        {
            return true;
        }
    }

    return false;
}

int main()
{
    cout << checkInclusion("ab", "eidbaooo") << endl;
    cout << checkInclusion("ab", "eidboaoo") << endl;
    return 0;
}