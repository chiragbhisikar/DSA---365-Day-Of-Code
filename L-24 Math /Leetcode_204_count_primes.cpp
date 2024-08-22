#include <iostream>
#include <bits/stdc++.h>

using namespace std;
void printArray(vector<int> arr)
{
    for (int i = 2; i < arr.size(); i++)
    {
        cout << (i) << " = " << arr[i - 2] << endl;
    }
}
int countPrimes(int n)
{
    int counter = 0;
    vector<bool> prime(n, true);

    for (int i = 2; (i * i) < n; i++)
    {
        if (prime[i - 1])
        {
            for (int j = (i * i); j <= n; j = j + i)
            {
                prime[j - 1] = false;
            }
        }
    }

    for (int i = 2; i < n; i++)
    {
        if (prime[i - 1])
        {
            counter++;
        }
    }

    cout << counter << endl;
    return counter;
}
int main()
{
    int n = 10;
    cout << countPrimes(n) << endl;
    return 0;
}