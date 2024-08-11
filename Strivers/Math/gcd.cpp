#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << "\t";
    }
    cout << "\n";
}

// Hint : Euclidium Algorithm : gcd(X, Y) = gcd(Y, X % Y)
// eclidium Algorithm = gcd (a,b) = gcd (a - b,b)

int findGcd(int x, int y)
{
    int a = max(x, y), b = min(x, y);

    while (a > 0 && b > 0)
    {
        if (a > b)
        {
            a = a % b;
        }
        else
        {
            b = b % a;
        }
    }
    if (a == 0)
        return b;

    return a;
}

void lcmAndGcd(long long A, long long B)
{
    cout << gcd(A, B) << endl;
}

int main()
{
    lcmAndGcd(52, 10);
    return 0;
}