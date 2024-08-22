/**
1 => 1
1 ^ 2 => 3
1 ^ 2 ^ 3 => 0
1 ^ 2 ^ 3 ^ 4 => 4

1 ^ 2 ^ 3 ^ 4 ^ 5 => 1 => 1
1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 => 7 => N+1
1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 ^ 7 => 0 => 0
1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 ^ 7 ^ 8 => 8 => N

1 => 1
1 ^ 2 => N + 1
1 ^ 2 ^ 3 => 0
1 ^ 2 ^ 3 ^ 4 => N
 */
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int getXOR(int n)
{
    // Check if n is
    // congruent to 1 modulo 4
    if (n % 4 == 1)
    {
        return 1;
    }
    // Check if n is congruent
    // to 2 modulo 4
    else if (n % 4 == 2)
    {
        return n + 1;
    }
    // Check if n is
    // congruent to 3 modulo 4
    else if (n % 4 == 3)
    {
        return 0;
    }
    // Return condition
    // when n is a multiple
    else
    {
        return n;
    }
}
int getXOR(int l, int r)
{
    int OneToR = getXOR(l - 1);

    return OneToR ^ r;
}
int main()
{
    int n = 5;
    cout << "1 ^ 2 ^ 3 ^ 4 ^ 5 = " << getXOR(n) << endl;
    int l = 5, r = 8;
    cout << "4 ^ 5 ^ 6 ^ 7 ^ 8 = " << getXOR(l, r) << endl;
    return 0;
}