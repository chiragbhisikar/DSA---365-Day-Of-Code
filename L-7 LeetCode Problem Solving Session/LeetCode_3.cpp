
#include <iostream>
using namespace std;

bool loveBabbarIsPowerOfTwo(int n)
{
    for (int i = 0; i <= 30; i++)
    {
        if (pow(2, i) == n)
        {
            return true;
        }
        if (pow(2, i) > n)
        {
            return false;
        }
    }

    return false;
}

bool isPowerOfTwo(int n)
{
    int count = 0;
    while (n != 0)
    {
        if (n & 1)
        {
            count = count + 1;
        }
        n = n >> 1;
    }

    if (count == 1)
    {
        return true;
    }
    return false;
}

int main()
{
    cout << isPowerOfTwo(10) << endl;
    cout << isPowerOfTwo(16) << endl;

    cout << loveBabbarIsPowerOfTwo(10) << endl;
    cout << loveBabbarIsPowerOfTwo(16) << endl;

    cout << isPowerOfTwo(1073741824) << endl;
    cout << loveBabbarIsPowerOfTwo(1073741824) << endl;

    return 0;
}