#include <bits/stdc++.h>

using namespace std;

int evenlyDivides(int n)
{
    int temp = n;
    long long ans = 0;
    while (temp != 0)
    {
        int remainder = temp % 10;
        ans = (ans * 10) + remainder;
        temp /= 10;
    }

    return ans;
}

int main()
{
    int n = 1534236469;
    int ans = evenlyDivides(n);
    cout << "ans: " << ans << endl;
    return 0;
}