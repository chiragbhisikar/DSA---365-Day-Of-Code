#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int factorial(int n)
{
    if (n == 1)
    {
        cout << "1" << endl;
        return 1;
    }

    // int smallerProblem = factorial(n - 1);
    // int biggerProblem = n * smallerProblem;
    // return biggerProblem;
    cout << n * factorial(n - 1) << endl;
    return n * factorial(n - 1);
}
int main()
{
    int n;
    cout << "Enter N : ";
    cin >> n;
    cout << "Factorial Of " << n << " is " << factorial(n) << endl;

    return 0;
}