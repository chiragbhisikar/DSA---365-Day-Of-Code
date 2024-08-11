
#include <iostream>
#include <vector>

using namespace std;

int getSum(vector<int> &arr)
{
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }
    return sum;
}

bool isPossible(vector<int> &arr, int student, int mid)
{
    int studentCount = 1;
    int pageSum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (pageSum + arr[i] <= mid)
        {
            pageSum = pageSum + arr[i];
        }
        else
        {
            studentCount++;
            if (studentCount > student || arr[i] > mid)
            {
                return false;
            }
            pageSum = arr[i];
        }
        if (studentCount > student)
        {
            return false;
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &arr, int painters)
{
    int start = 0, end = getSum(arr), ans = -1;
    int mid = (start + end) / 2;

    while (start <= end)
    {
        if (isPossible(arr, painters, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = (start + end) / 2;
    }
    return ans;
}

int main()
{
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(2);
    arr.push_back(3);
    cout << findLargestMinDistance(arr, 2) << endl;
    return 0;
}