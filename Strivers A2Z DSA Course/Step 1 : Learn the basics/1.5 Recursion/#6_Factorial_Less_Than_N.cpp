#include <bits/stdc++.h>

using namespace std;

vector<long long> factorialNumbers(long long n, vector<long, long> ans = vector<long, long>(), int i = 0)
{
    if (n < ans[i])
    {
        return ans;
    }
    else
    {
        ans.push_back(ans[i] * i);
    }
    return factorialNumbers(n, ans, ++i);
}

int main()
{

    return 0;
}