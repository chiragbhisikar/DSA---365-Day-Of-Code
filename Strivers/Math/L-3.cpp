// Check if a Number if Prime or not

#include <iostream>
using namespace std;

void checkPrimeOrNot(int n) // => O(logN)
{
    int counter = 0;
    for (int i = 1; (i * i) <= n; i++)
    {
        if (n % i == 0)
        {
            counter++;
            if (n / i != i)
            {
                counter++;
            }
        }
        if (counter < 2)
        {
            break;
        }
    }
    if (counter == 2)
    {
        cout << "Prime" << endl;
    }
    else
    {
        cout << "Not A Prime" << endl;
    }
}
int main()
{
    checkPrimeOrNot(4);
    return 0;
}