#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int> &stalls, int k, int mid)
{
    int cowCount = 1;
    int lastPos = stalls[0];

    for (int i = 0; i < stalls.size(); i++)
    {
        if ((stalls[i] - lastPos) >= mid)
        {
            cowCount++;
            cout << "cowCount = " << cowCount << " lastPos = " << lastPos << endl;
            if (cowCount == k)
            {
                return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());

    int start = 0, end = stalls[stalls.size() - 1];
    int mid = (start + end) / 2;
    int ans = -1;

    while (start <= end)
    {
        if (isPossible(stalls, k, mid))
        {
            ans = mid;
            cout << start << "\t" << mid << "\t" << end << " isPossible" << endl;
            start = mid + 1;
        }
        else
        {
            cout << start << "\t" << mid << "\t" << end << endl;
            end = mid - 1;
        }
        mid = (start + end) / 2;
    }
    return ans;
}

int main()
{
    vector<int> arr;
    arr.push_back(0);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(7);
    arr.push_back(10);
    arr.push_back(9);

    cout << aggressiveCows(arr, 4) << endl;
    return 0;
}