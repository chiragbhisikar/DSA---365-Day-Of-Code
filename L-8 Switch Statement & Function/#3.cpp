#include <iostream>
using namespace std;
int power(int a, int b)
{
    int ans = 1;
    for (int i = 1; i <= b; i++)
    {
        ans = ans * a;
    }

    return ans;
}

bool isEven(int num)
{
    if (num & 1)
    {
        return false;
    }
    return true;
}

int factorial(int n)
{
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * i;
    }
    return ans;
}

int nCr(int n, int r)
{
    int ans = factorial(n) / (factorial(r) * factorial(n - r));

    return ans;
}

bool isPrime(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int aP(int n)
{
    return (3 * n + 7);
}

int setBits(int a, int b)
{
    int ans = 0;
    while (a != 0 || b != 0)
    {
        if (a & 1)
        {
            ans++;
        }
        if (b & 1)
        {
            ans++;
        }
        a = a >> 1;
        b = b >> 1;
    }
    return ans;
}

int main()
{

    cout << power(2, 4) << endl;
    cout << isEven(2) << endl;
    cout << nCr(8, 2) << endl;
    cout << isPrime(8) << endl;
    cout << aP(3) << endl;
    cout << setBits(2, 3) << endl;
    return 0;
}