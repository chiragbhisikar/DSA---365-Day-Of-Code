#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int integer_arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    char character_arr[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', '\0'};

    cout << "integer_arr = " << integer_arr << endl;
    cout << "character_arr = " << character_arr << endl;

    char *c = &character_arr[0];
    // prints entire array
    cout << "c = " << c << endl;
    return 0;
}