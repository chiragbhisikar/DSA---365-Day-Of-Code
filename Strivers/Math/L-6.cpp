// 1 To N Prime

#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 1)
        {
            cout << i << "\t";
        }
    }
    cout << endl;
}
void sieveOfEratosthenes(int n)
{
    // vector<int> arr;

    // for (int i = 2; i <= n; i++)
    // {
    //     arr.push_back(1);
    // }

    // vector<int> v1(size,value assigned to be each element)
    vector<int> arr(n - 2, 1);

    printArray(arr);

    for (int i = 2; i <= (i * i); i++)
    {
        if (arr[i] == 1)
        {
            for (int j = (i * i); j <= n; j = (i + j))
            {
                arr[j] = 0;
            }
        }
    }

    printArray(arr);
}
int main()
{
    sieveOfEratosthenes(11);
    return 0;
}