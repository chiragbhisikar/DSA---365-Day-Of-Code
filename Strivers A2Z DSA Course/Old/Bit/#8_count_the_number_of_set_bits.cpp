// #8_count_the_number_of_set_bits

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int number = 12;
    int counter = 0;
    while (number != 0)
    {
        if (number & 1)
        {
            counter++;
        }
        number = number >> 1;
    }
    cout << counter << endl;

    while (number != 0)
    {
        number = number & (number - 1);
        counter++;
    }
    cout << counter << endl;

    return 0;
}