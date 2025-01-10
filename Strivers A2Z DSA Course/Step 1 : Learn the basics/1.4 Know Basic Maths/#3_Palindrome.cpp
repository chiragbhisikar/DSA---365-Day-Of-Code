#include <bits/stdc++.h>

using namespace std;

bool checkPalindrome(int n)
{
    int temp = n;
    long long ans = 0;
    while (temp != 0)
    {
        int remainder = temp % 10;
        ans = (ans * 10) + remainder;
        temp /= 10;
    }

    return ans == n;
}

int main()
{
    int n = 212;
    bool ans = checkPalindrome(n);
    cout << "ans: " << (ans ? "YES" : "NO") << endl;
    return 0;
}