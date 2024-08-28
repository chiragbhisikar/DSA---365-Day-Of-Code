#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void print(int start, int end = 10)
{
    for (int i = start; i <= end; i++)
    {
        cout << i << "\t";
    }
    cout << endl;
}

int main()
{
    print(1, 5);
    print(1);
    return 0;
}