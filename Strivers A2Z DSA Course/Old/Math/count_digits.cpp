#include <iostream>
using namespace std;

int evenlyDivides(int N)
{
    int ans = 0;
    int n = N;

    while (n != 0)
    {
        int remainder = n % 10;
        if (remainder != 0)
        {
            if (N % remainder == 0)
            {
                ans++;
            }
        }
        n = n / 10;
    }

    return ans;
}

int main()
{
    cout << evenlyDivides(660) << endl;
    return 0;
}