#include <iostream>
using namespace std;

int main()
{
    int n = 101;
    int ans = 0;
    int i = 0;
    while (n != 0)
    {
        if (n & 1)
        {
            ans = pow(2, i) + ans;
        }
        n = n / 10;
        i++;
    }

    cout << ans << endl;

    return 0;
}