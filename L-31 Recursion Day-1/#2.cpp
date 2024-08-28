#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int power(int n)
{
    if (n == 1)
    {
        return 1;
    }
    int smallerProblem = power(n - 1);
    int biggerProblem = 2 * smallerProblem;

    return biggerProblem;
    // return 2 * power(n - 1);
}

int main()
{
    int n = 5;
    cout << "Enter Power : ";
    cin >> n;

    cout << power(n) << endl;
    return 0;
}