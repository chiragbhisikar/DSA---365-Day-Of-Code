#include <bits/stdc++.h>

using namespace std;

void print(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<int> FirstNegativeInteger(vector<int> &arr, int k)
{
    int n = arr.size();
    deque<int> dq;

    vector<int> ans;

    //   process first window of k size
    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }
    }

    // store answer first k size window
    if (dq.size() > 0) // => queue is empty
    {
        ans.push_back(arr[dq.front()]);
    }
    else
    {
        ans.push_back(0);
    }

    // process for remaining part
    for (int i = k; i < n; i++)
    {
        // removal
        if (!dq.empty() && i - dq.front() >= k) // i - dq.front() >= k means is it comes in window or not
        {
            dq.pop_front();
        }

        // addition
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }

        // answer store
        if (dq.size() > 0)
        {
            ans.push_back(arr[dq.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }

    return ans;
}

int main()
{
    vector<int> v;
    int windowSize = 2;
    v.push_back(-8);
    v.push_back(2);
    v.push_back(3);
    v.push_back(-6);
    v.push_back(1);
    v = FirstNegativeInteger(v, windowSize);
    print(v);
    return 0;
}