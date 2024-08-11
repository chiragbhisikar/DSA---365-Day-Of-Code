// Print all Divisors of a Number |

#include <iostream>
using namespace std;

void getDivisors(int n) // => O(logN)
{
    for (int i = 1; (i * i) <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << "\t" << (n / i) << "\t";
        }
    }
}
int main()
{
    getDivisors(49);
    return 0;
}