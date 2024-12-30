// Swap Two Number Using XOR
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a = 5;
    int b = 6;

    // 1 0 1
    // 1 1 0
    // 0 1 1
    a = a ^ b;
    // 0 1 1
    // 1 1 0
    // 1 0 1
    b = a ^ b; // 1 0 1 (5) => b
    // 1 0 1
    // 0 1 1
    // 1 1 0
    a = a ^ b; // 1 1 0 (6) => a

    cout << a << " " << b << endl;
    return 0;
}