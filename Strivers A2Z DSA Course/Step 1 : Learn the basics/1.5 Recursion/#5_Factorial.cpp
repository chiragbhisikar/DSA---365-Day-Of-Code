#include <bits/stdc++.h>

using namespace std;

int factorial(int n, int ans = 1, int i = 1)
{
    if (i > n)
    {
        return ans;
    }
    ans = ans * i;

    return factorial(n, ans, i + 1);
}
int main()
{
    cout << factorial(5) << endl;
    return 0;
}