// Smallest Prime Factor (SPF)

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

vector<int> getSieve(int number)
{
    vector<int> prime(number - 1);
    fill_n(prime.begin(), number - 1, 1);
    // printArray(prime);

    for (int i = 2; i <= i * i; i++)
    {
        if (prime[i - 2] == 1)
        {
            for (int j = (i * i); j <= number; j = j + i)
            {
                if (prime[j - 2] == 1)
                {
                    prime[j - 2] = i;
                }
            }
        }
    }

    // printArray(prime);

    return prime;
}

void smallestPrimeFactor(vector<int> queries)
{
    vector<int> prime = getSieve(*max_element(queries.begin(), queries.end()));

    for (int i = 0; i < queries.size(); i++)
    {
        if (prime[queries[i] - 2] == 1)
        {
            cout << queries[i] << " Smallest Prime Factor is " << queries[i] << endl;
        }
        else
        {
            cout << queries[i] << " Smallest Prime Factor is " << prime[queries[i] - 2] << endl;
        }
    }
}

int main()
{
    vector<int> queries;
    queries.push_back(10);
    queries.push_back(25);
    queries.push_back(50);
    queries.push_back(95);
    queries.push_back(99);
    queries.push_back(91);
    queries.push_back(71);
    queries.push_back(32);
    queries.push_back(105);
    queries.push_back(120);

    smallestPrimeFactor(queries);
    return 0;
}