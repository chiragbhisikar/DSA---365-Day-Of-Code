#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void updateByValue(int n)
{
    n++;
}

void updateByReference(int *n)
{
    (*n)++;
}

// Bad Practice Local Variable Is Clear After Execution Of Function
// int& update(int n)
// {
//     int n = 5;
//     int &ans = n;
//     return ans;
// }

// Bad Practice Local Variable Is Clear After Execution Of Function
// int* update(int n)
// {
//     int n = 5;
//     int *ans = &n;
//     return ans;
// }

int main()
{
    int n = 5;
    int &i = n; // => Reference Variable

    cout << "n = " << n << " | i = " << i << endl;
    n++;
    cout << "n = " << n << " | i = " << i << endl;
    i++;
    cout << "n = " << n << " | i = " << i << endl;

    // Pass By Value
    cout << "Pass By Value \nbefore : n = " << n << " | i = " << i << endl;
    updateByValue(n);
    cout << "after : n = " << n << " | i = " << i << endl;

    // Pass By Reference
    cout << "Pass By Reference \nbefore : n = " << n << " | i = " << i << endl;
    // updateByReference(&n);
    updateByReference(&i);
    cout << "after : n = " << n << " | i = " << i << endl;

    return 0;
}