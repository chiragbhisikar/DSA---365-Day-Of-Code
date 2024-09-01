#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void sayNumber(int n)
{
    if (n <= 0)
    {
        return;
    }
    sayNumber(n / 10);
    string arr[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    cout << arr[n % 10] << "\t";
}
int main()
{
    sayNumber(472);
    return 0;
}