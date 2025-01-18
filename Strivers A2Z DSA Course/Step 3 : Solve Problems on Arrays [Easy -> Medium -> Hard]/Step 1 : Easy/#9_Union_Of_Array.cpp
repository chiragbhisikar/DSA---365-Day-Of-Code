#include <bits/stdc++.h>

using namespace std;

void findUnion(int a[], int b[], int n, int m)
{
    vector<int> ans;
    int first = 0, second = 0, lastElement, current;

    while (first != n && second != m)
    {
        if (a[first] <= b[second])
        {
            current = a[first];

            if (lastElement != current)
            {
                lastElement = a[first];
                ans.push_back(a[first]);
            }
            first++;
        }
        else
        {
            current = b[second];

            if (lastElement != current)
            {
                lastElement = b[second];
                ans.push_back(b[second]);
            }
            second++;
        }
    }

    while (first != n)
    {
        current = a[first];
        if (lastElement != current)
        {
            lastElement = a[first];
            ans.push_back(a[first]);
        }
        first++;
    }

    while (second != m)
    {
        current = b[second];
        if (lastElement != current)
        {
            lastElement = b[second];
            ans.push_back(b[second]);
        }
        second++;
    }

    // return ans;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl;
}
int main()
{
    int a[] = {-7, 8};
    int b[] = {-8, -3, 8};

    findUnion(a, b, 2, 3);
    return 0;
}