#include <bits/stdc++.h>

using namespace std;

bool isArmstrong(int n)
{
    int temp = n;
    int cnt = 0;

    while (temp != 0)
    {
        cnt++;
        temp /= 10;
    }

    int ans = 0;
    int sum = 0;
    temp = n;

    while (temp != 0)
    {
        int remainder = temp % 10;
        sum = sum + pow(remainder, cnt);
        temp /= 10;
    }
    cout << sum << endl;
    return sum == n;
}

int main()
{
    int n = 371;
    bool ans = isArmstrong(n);
    cout << "ans: " << (ans ? "YES" : "NO") << endl;
    return 0;
}