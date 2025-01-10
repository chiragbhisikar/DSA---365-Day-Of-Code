#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int divide(int dividend, int divisor)
{
    // Check if dividend and divisor
    // are equal, return 1 if true
    if (dividend == divisor)
    {
        return 1;
    }

    // Determine the sign of the result,
    // true for positive, false for negative
    bool sign = true;

    // If dividend is positive and
    // divisor is negative, set sign to negative
    if (dividend >= 0 && divisor < 0)
    {
        sign = false;
    }
    // If dividend is negative and divisor
    // is positive, set sign to negative
    else if (dividend <= 0 && divisor > 0)
    {
        sign = false;
    }

    // Take absolute values
    // of dividend and divisor
    long n = abs(dividend);
    long d = abs(divisor);

    // Store original divisor absolute
    // value in divisor variable
    divisor = abs(divisor);

    // Initialize quotient to 0
    long quotient = 0;

    // Perform division using
    // repeated subtraction
    while (n >= d)
    {
        // Count how many times divisor can
        // be doubled before exceeding dividend
        int cnt = 0;
        while (n >= (d << (cnt + 1)))
        {
            cnt += 1;
        }
        // Add the value corresponding
        // to the current doubling to the quotient
        cout << "before quotient = " << quotient << " & cnt = " << cnt << endl;
        quotient = quotient + (1 << cnt);
        cout << "after quotient = " << quotient << " & cnt = " << cnt << endl;
        // Subtract the product of divisor
        // and the doubled value from dividend
        n = n - (d << cnt);
        cout << "n = " << n << endl;
    }

    // Handle overflow cases
    // If quotient equals (2^31) and the result
    // is supposed to be positive, return INT_MAX
    if (quotient == (1 << 31) && sign)
    {
        return INT_MAX;
    }
    // If quotient equals (2^31) and the result
    // is supposed to be negative, return INT_MIN
    if (quotient == (1 << 31) && !sign)
    {
        return INT_MIN;
    }
    // Return the quotient with correct sign
    return sign ? quotient : -quotient;
}

int main()
{
    int dividend = 45;
    int divisor = 7;
    cout << "Dividend: " << dividend << " Divisor: " << divisor << endl;
    int result = divide(dividend, divisor);

    cout << "Result of division: " << result << endl;
    return 0;
}