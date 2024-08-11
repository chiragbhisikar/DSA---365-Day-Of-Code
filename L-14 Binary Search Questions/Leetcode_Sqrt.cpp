#include <iostream>
using namespace std;

int binarySearch(int num)
{
    int start = 0, end = num - 1;
    long long int mid = (start + end) / 2;
    long long int ans = 0;

    while (start <= end)
    {
        // cout << start << "\t" << end << endl;
        long long int square = mid * mid;
        if (square == num)
        {
            return mid;
        }
        else if (square > num)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
            ans = mid;
        }
        mid = (start + end) / 2;
    }
    return ans;
}

double morePrecision(int num, int precisionCount)
{
    double ans = binarySearch(num);
    double factor = 1;

    for (int i = 1; i <= precisionCount; i++)
    {
        factor = factor / 10;
        for (double j = ans; j * j < num; j = j + factor)
        {
            ans = j;
        }
    }
    return ans;
}

void mySqrt(int num)
{
    cout << morePrecision(num, 6) << endl;
}

int main()
{
    mySqrt(37);

    return 0;
}