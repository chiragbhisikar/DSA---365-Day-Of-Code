#include <iostream>
using namespace std;

bool isKthBitSet(int n, int k)
{
    int i = 1;
    while (i <= (k))
    {
        n = n >> 1;
        i++;
    }
    if (n & 1 == 1)
    {
        return true;
    }
    return false;
}

int main()
{
    cout << isKthBitSet(10, 3) << endl;
    return 0;
}