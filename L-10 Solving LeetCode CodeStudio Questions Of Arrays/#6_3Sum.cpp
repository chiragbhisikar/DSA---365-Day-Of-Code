// 3Sum
/**
 * Problem statement
You are given an array/list ARR consisting of N integers. Your task is to find all the distinct triplets present in the array which adds up to a given number K.

An array is said to have a triplet {ARR[i], ARR[j], ARR[k]} with sum = 'K' if there exists three indices i, j and k such that i!=j, j!=k and i!=j and ARR[i] + ARR[j] + ARR[k] = 'K'.

Note:
1. You can return the list of values in any order. For example, if a valid triplet is {1, 2, -3}, then {2, -3, 1}, {-3, 2, 1} etc is also valid triplet. Also, the ordering of different triplets can be random i.e if there are more than one valid triplets, you can return them in any order.
2. The elements in the array need not be distinct.
3. If no such triplet is present in the array, then return an empty list, and the output printed for such a test case will be "-1".

Constraints:
1 <= T <=  50
1 <= N <= 10^3
-10^6 <= ARR[i] <= 10^6
-10^9 <= K <= 10^9
Sample Input 1:
1
5
10 5 5 5 2
12
Sample Output 1:
5 5 2
Explanation for Sample Input 1:
5 5 2 is the only triplet that adds up to 12. Note that the order of the output doesn’t matter, so 5 2 5 or 2 5 5 is also acceptable.
Sample Input 2:
No. Of Input : 3
Size : 6
1 2 3 1 2 3
Sum = 6
4
1 2 3 4
11
6
1 1 2 2 1 1
4
Sample Output 2:
1 2 3
-1
1 1 2
Explanation for Sample Input 2:
In the first input, (1, 2, 3) is the only unique triplet that adds up to six.

In the second input, since there are no such triplets, we print -1.

For the third input, the only distinct triplet is (1, 1, 2), so just print 1 1 2.
 */

#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

void pairSum(vector<int> &arr, int s)
{
    sort(arr.begin(), arr.end());
    printArray(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            for (int k = j + 1; k < arr.size(); k++)
            {
                if (arr[i] + arr[j] + arr[k] == s)
                {
                    // vector<int> temp;
                    // temp.push_back(arr[i]);
                    // temp.push_back(arr[j]);
                    // temp.push_back(arr[k]);
                    // ans.push_back(temp);
                    
                }
            }
        }
    }
}

int main()
{
    vector<int> arr;
    // 10 5 5 5 2
    // Sum = 5
    // arr.push_back(10);
    // arr.push_back(5);
    // arr.push_back(5);
    // arr.push_back(5);
    // arr.push_back(2);
    // [-26,32,4,17,-16,18,1,8,6,8,3,-13]
    arr.push_back(-26);
    arr.push_back(32);
    arr.push_back(4);
    arr.push_back(17);
    arr.push_back(-16);
    arr.push_back(18);
    arr.push_back(1);
    arr.push_back(8);
    arr.push_back(6);
    arr.push_back(8);
    arr.push_back(3);
    arr.push_back(-13);

    printArray(arr);
    pairSum(arr, 10);

    return 0;
}