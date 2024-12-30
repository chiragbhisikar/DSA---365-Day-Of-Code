// Count Prime in a range L-R
#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << (i + 2) << " = " << arr[i] << "\t";
    }
    cout << endl;
}

vector<int> getSieve(int r)
{
    // vector<int> ans;
    // for (int i = 2; i <= r; i++)
    // {
    //     ans.push_back(1);
    // }
    // vector<int> v1(size,value assigned to be each element)
    vector<int> ans(r - 2, 1);
    printArray(ans);

    for (int i = 2; i <= (i * i); i++)
    {
        if (ans[i] == 1)
        {
            for (int j = (i * i); j <= r; j = i + j)
            {
                ans[j - 2] = 0;
            }
        }
    }

    printArray(ans);

    return ans;
}

void countPrimeLToR(int l, int r)
{
    vector<int> prime = getSieve(r);
    int count = 0;
    for (int i = 0; i < prime.size(); i++)
    {
        if (prime[i] == 1)
        {
            prime[i] = ++count;
        }
        else
        {
            prime[i] = count;
        }
    }

    printArray(prime);

    cout << "answer = " << (prime[r - 2] - prime[l - 3]) << endl;
}

int main()
{
    countPrimeLToR(3, 10);
    countPrimeLToR(3, 11);

    return 0;
}