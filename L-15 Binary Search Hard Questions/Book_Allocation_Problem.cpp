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

bool isPossible(vector<int> &arr, int size, int student, int mid)
{
    int studentCount = 1;
    int pageSum = 0;

    for (int i = 0; i < size; i++)
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

int findPages(vector<int> &arr, int size, int student)
{
    int start = 0, end = getSum(arr), ans = -1;
    int mid = (start + end) / 2;

    while (start <= end)
    {
        if (isPossible(arr, size, student, mid))
        {
            cout << start << "\t" << mid << "\t" << end << " = isPossible"<< endl;
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
            cout << start << "\t" << mid << "\t" << end << endl;
        }
        mid = (start + end) / 2;
    }
    return ans;
}

int main()
{
    vector<int> arr;
    // arr.push_back(2);
    // arr.push_back(8);
    // arr.push_back(8);
    // arr.push_back(4);
    // arr.push_back(5);
    // cout << findPages(arr, 5, 6) << endl;

    arr.push_back(25);
    arr.push_back(46);
    arr.push_back(28);
    arr.push_back(49);
    arr.push_back(24);
    cout << findPages(arr, 5, 6) << endl;
    return 0;
}