// 7. Reverse Integer
// https://leetcode.com/problems/reverse-integer/submissions/1336278341/
#include <iostream>
using namespace std;

int reverse(int x)
{
    long int number = 0;

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

int loveBabbarReverse(int x)
{
    int number = 0;

    while (x != 0)
    {
        int digit = x % 10;

        if (number > INT_MAX / 10 || number < INT_MIN / 10)
        {
            return 0;
        }

        number = (number * 10) + digit;
        x = x / 10;
    }

    return number;
}

int main()
{
    cout << reverse(123);
    return 0;
}
