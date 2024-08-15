#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void printArray(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << "\t";
    }
    cout << endl;
}

vector<int> findArraySum(vector<int> &a, int m, vector<int> &b, int n)
{
    int i = m - 1, j = n - 1;
    int index = 0, carry = 0;
    vector<int> ans;

    if (m > n)
    {
        index = m - 1;
        ans = a;
    }
    else
    {
        index = n - 1;
        ans = b;
    }

    while (i >= 0 && j >= 0)
    {
        int sum = a[i] + b[j] + carry;
        carry = sum / 10;
        sum = sum % 10;
        i--;
        j--;

        ans[index] = sum;
        index--;
    }

    while (i >= 0)
    {
        int sum = a[i] + carry;
        carry = sum / 10;
        sum = sum % 10;
        i--;

        ans[index] = sum;
        index--;
    }

    while (j >= 0)
    {
        int sum = b[j] + carry;
        carry = sum / 10;
        sum = sum % 10;
        j--;

        ans[index] = sum;
        index--;
    }

    if (carry == 1)
    {
        ans.insert(ans.begin(), 1);
    }

    return ans;
}

int main()
{
    vector<int> a;
    a.push_back(9);
    a.push_back(9);
    a.push_back(9);
    // a.push_back(6);

    vector<int> b;
    b.push_back(9);
    b.push_back(9);
    b.push_back(9);
    // b.push_back(4);
    // b.push_back(5);

    findArraySum(a, a.size(), b, b.size());
    return 0;
}