#include <bits/stdc++.h>

using namespace std;
int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int n = gas.size();
    int start = 0;
    int deficit = 0;
    int balance = 0;

    for (int i = 0; i < n; i++)
    {
        balance = (balance + gas[i]) - cost[i];
        if (balance < 0)
        {
            deficit = deficit + balance;
            start = i + 1;
            balance = 0;
        }
    }

    if (deficit + balance >= 0)
    {
        return start;
    }

    return -1;
}

int main()
{
    vector<int> gas;
    gas.push_back(1);
    gas.push_back(2);
    gas.push_back(3);
    gas.push_back(4);
    gas.push_back(5);

    vector<int> cost;
    cost.push_back(3);
    cost.push_back(4);
    cost.push_back(5);
    cost.push_back(1);
    cost.push_back(2);

    int start = canCompleteCircuit(gas, cost);
    cout << "starting point will be " << start << endl;

    
    return 0;
}