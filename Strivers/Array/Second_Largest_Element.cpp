//  Second Largest Number
// https://www.naukri.com/code360/problems/ninja-and-the-second-order-elements_6581960?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems

#include <iostream>
#include <vector>
using namespace std;

// vector<int>
void getSecondOrderElements(int n, vector<int> arr)
{
    int max = arr[0], secondLargest = arr[1];

    for (int i = 0; i < n; i++)
    {
        if (max <= arr[i])
        {
            secondLargest = max;
            max = arr[i];
        }
        else if (max <= secondLargest)
        {
            swap(max, secondLargest);
        }
    }
    cout << max << "\t" << secondLargest << endl;
    // return {max, secondLargest};
}

int main()
{
    vector<int> arr;
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(2);
    // 3 4 5 2

    getSecondOrderElements(5, arr);
    return 0;
}