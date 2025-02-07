#include <bits/stdc++.h>

using namespace std;

int lowerBound(vector<int> &arr, int target, int n)
{
    int start = 0, end = n - 1;
    int answer = n;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] >= target)
        {
            answer = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return answer;
}

int upperBound(vector<int> &arr, int target, int n)
{
    int start = 0, end = n - 1;
    int answer = n;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] > target)
        {
            answer = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return answer;
}

void searchRange(vector<int> &nums, int target)
{
    int n = nums.size();
    int lower = lowerBound(nums, target, n);
    int upper = upperBound(nums, target, n);

    if (lower == n || nums[lower] != target)
    {
        cout << "{-1, -1}";
        // return {-1, -1};
    }

    cout << "{" << lower << ", " << upper - 1 << "}";
    // return {lower, upper - 1};
}

int main()
{
    vector<int> v;
    v.push_back(5);
    v.push_back(7);
    v.push_back(7);
    v.push_back(8);
    v.push_back(8);
    v.push_back(10);

    searchRange(v, 8);
    return 0;
}