#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int majorityElement(vector<int> v)
{
    map<int, int> elementCount;

    for (int i = 0; i < v.size(); i++)
    {
        elementCount[v[i]]++;
    }

    for (auto it : elementCount)
    {
        if (it.second > (v.size() / 2))
        {
            return it.first;
        }
    }
    return -1;
}

int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(2);
    v.push_back(1);
    v.push_back(3);
    v.push_back(1);
    v.push_back(1);
    v.push_back(3);
    v.push_back(1);
    v.push_back(1);

    cout << majorityElement(v) << endl;
    return 0;
}