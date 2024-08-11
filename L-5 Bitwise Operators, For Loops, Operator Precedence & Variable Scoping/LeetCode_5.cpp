// 476. Number Complement
/*
Input: num = 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
Example 2:

Input: num = 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
*/

#include <iostream>
#include <math.h>
using namespace std;

int findComplement(int num)
{
    int n = num;
    int ans = 0;
    int i = 0;

    while (n != 0)
    {
        if ((n & 1) == 0)
        {
            ans = pow(2, i) + ans;
            // cout << "check n = " << n << " & ans = " << ans << endl;
        }
        n = n >> 1;
        i++;
    }

    return ans;
}

int main()
{
    cout << findComplement(5) << endl;
    cout << findComplement(7) << endl;
    cout << findComplement(10) << endl;
    return 0;
}