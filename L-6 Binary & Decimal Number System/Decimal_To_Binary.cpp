#include <iostream>
using namespace std;

int main()
{
    int n = 100;
    int ans = 0;

    int temp = n;
    int i = 0;
    while (temp != 0)
    {
        int bit = temp & 1;
        ans = (bit * pow(10, i)) + ans;
        temp = temp >> 1;
        i++;
    }

    cout << ans << endl;

    return 0;
}