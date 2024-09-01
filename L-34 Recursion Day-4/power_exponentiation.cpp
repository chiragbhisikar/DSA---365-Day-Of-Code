#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int powerExponentiation(int number, int power, int ans = 1)
{
    if (power == 1)
    {
        return number * ans;
    }

    cout << number << "  ^  " << power << endl;
    if (power & 1)
    {
        ans = ans * number;
        power--;
    }
    else
    {
        number = number * number;
        power /= 2;
    }
    return powerExponentiation(number, power, ans);
}
int main()
{
    cout << powerExponentiation(3, 11) << endl;
    return 0;
}