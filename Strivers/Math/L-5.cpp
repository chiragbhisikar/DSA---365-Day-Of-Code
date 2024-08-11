// Power Exponentiation

#include <iostream>
using namespace std;

void powerExponentiation(int n, int power)
{
    int ans = 1;

    while (power > 0)
    {
        if (power % 2 == 0)
        {
            power = power / 2;
            n = n * n;
        }
        else
        {
            ans = ans * n;
            power--;
        }
        // cout << power << "\t" << n << "\t" << ans << endl;
    }

    cout << ans << endl;
}
int main()
{
    powerExponentiation(2, 5);
    return 0;
}