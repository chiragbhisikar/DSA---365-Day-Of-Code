// 1009. Complement of Base 10 Integer
// https://leetcode.com/problems/complement-of-base-10-integer/

#include <iostream>
#include <math.h>
using namespace std;

int loveBabbarbitwiseComplement(int n)
{
    int num = n;
    int mask = 0;
    while (num != 0)
    {
        mask = (mask << 1) | 1;
        num = num >> 1;
    }

    int ans = mask ^ n;
    // cout << (mask ^ n) << endl;

    return ans;
}

int bitwiseComplement(int n)
{
    int i = 0;
    int ans = 0;

    while (n != 0)
    {
        if ((n & 1) == 0)
        {
            ans = pow(2, i) + ans;
        }
        n = n >> 1;
        i++;
    }

    return ans;
}

int main()
{
    cout << loveBabbarbitwiseComplement(5) << endl;
    cout << bitwiseComplement(5) << endl;

    cout << loveBabbarbitwiseComplement(7) << endl;
    cout << bitwiseComplement(7) << endl;

    cout << loveBabbarbitwiseComplement(10) << endl;
    cout << bitwiseComplement(10) << endl;
    return 0;
}