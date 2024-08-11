// 7. Reverse Integer
// https://leetcode.com/problems/reverse-integer/description/
//     Input : x = 123 Output : 321
//     Input : x = -123 Output : -321
//     Input : x = 120 Output : 21

#include <iostream>
using namespace std;

int reverse(int x)
{
    long long int number = 0;

    if (x > INT_MAX)
    {
        return 0;
    }

    while (x != 0)
    {
        int digit = x % 10;
        number = (number * 10) + digit;
        x = x / 10;

        if (number > INT_MAX || number < INT_MIN)
        {
            return 0;
        }
    }

    return number;
}

int main()
{
    int n = 1534236469;
    cout << reverse(n);

    return 0;
}
