#include <iostream>
#include <math.h>
using namespace std;

int main()
{

    long long int n = -6;
    unsigned int ans = 0;
    int i = 0;

    if (n < 0)
    {
        n = pow(2, 32) + n;
    }
    cout << n << endl;

    while (n)
    {
        int bit = n & 1;
        ans = (bit * pow(10, i)) + ans;
        n = n >> 1;
        i++;
        cout << ans << endl;
    }
    // cout << ans;

    return 0;
}