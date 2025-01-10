#include <bits/stdc++.h>

using namespace std;

int evenlyDivides(int n)
{
    int temp = n;
    int ans = 0;
    while (temp != 0)
    {
        int remainder = temp % 10;

        if (remainder != 0)
        {
            if (n % remainder == 0)
            {
                ans++;
            }
        }

        temp /= 10;
    }
    return ans;
}

int main()
{
    int n = 20;
    int ans = evenlyDivides(n);
    cout << "ans: " << ans << endl;
    return 0;
}