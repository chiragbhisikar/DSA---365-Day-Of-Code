// Print all prime factors of a Number
#include <iostream>
using namespace std;

void printPrimeFactor(int n)
{
    int i = 2;
    while (i * i <= n)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                cout << i << "\t";
                n = n / i;
            }
        }
        i++;
    }
}
int main()
{
    printPrimeFactor(16);
    return 0;
}