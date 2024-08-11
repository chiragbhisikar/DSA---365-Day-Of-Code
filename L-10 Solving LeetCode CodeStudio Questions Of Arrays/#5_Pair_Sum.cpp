//  Pair Sum
// https://www.naukri.com/code360/problems/pair-sum_697295?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1
/*
Problem statement
You are given an integer array 'ARR' of size 'N' and an integer 'S'. Your task is to return the list of all pairs of elements such that each sum of elements of each pair equals 'S'.

Note:

Each pair should be sorted i.e the first value should be less than or equals to the second value.

Return the list of pairs sorted in non-decreasing order of their first value. In case if two pairs have the same first value, the pair with a smaller second value should come first.

Constraints:
1 <= N <= 10^3
-10^5 <= ARR[i] <= 10^5
-2 * 10^5 <= S <= 2 * 10^5

Sample Input 1:
5 5
1 2 3 4 5
Sample Output 1:
1 4
2 3
Explaination For Sample Output 1:
Here, 1 + 4 = 5
      2 + 3 = 5
Hence the output will be, (1,4) , (2,3).
Sample Input 2:
5 0
2 -3 3 3 -2
Sample Output 2:
-3 3
-3 3
-2 2
*/

#include <iostream>
#include <vector>

using namespace std;

void printArray(vector<vector<int> > &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i][0] << arr[i][1] << "\t" << endl;
    }
    cout << endl;
}

void pairSum(vector<int> &arr, int s)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] + arr[j] == s)
            {
                cout << min(arr[i], arr[j]) << "\t" << max(arr[i], arr[j]) << endl;
            }
        }
    }
}

int main()
{
    vector<int> arr;
    // 1 2 3 4 5
    // Sum = 5
    // arr.push_back(1);
    // arr.push_back(2);
    // arr.push_back(3);
    // arr.push_back(4);
    // arr.push_back(5);

    // 2 -6 2 5 2
    arr.push_back(2);
    arr.push_back(-6);
    arr.push_back(2);
    arr.push_back(5);
    arr.push_back(2);

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] + arr[j] == 4)
            {
                cout << min(arr[i], arr[j]) << "\t" << max(arr[i], arr[j]) << endl;
            }
        }
    }
    // pairSum(arr, 4);

    // 2 -3 3 3 -2
    // Sum = 0
    // arr.push_back(2);
    // arr.push_back(-3);
    // arr.push_back(3);
    // arr.push_back(3);
    // arr.push_back(-2);

    // arr.push_back(-4);
    // arr.push_back(7);
    // arr.push_back(-3);
    // arr.push_back(4);
    // arr.push_back(-8);
    // arr.push_back(4);
    // arr.push_back(4);
    // arr.push_back(0);
    // arr.push_back(-6);
    // arr.push_back(-7);
    // arr.push_back(6);
    // arr.push_back(9);
    // arr.push_back(3);
    // arr.push_back(5);
    // arr.push_back(4);
    // arr.push_back(-1);
    // arr.push_back(-1);
    // arr.push_back(-6);
    // arr.push_back(-9);
    // arr.push_back(0);
    // arr.push_back(9);
    // arr.push_back(-3);
    // arr.push_back(8);
    // arr.push_back(5);
    // arr.push_back(2);
    // arr.push_back(6);
    // arr.push_back(2);
    // arr.push_back(0);
    // arr.push_back(9);
    // arr.push_back(-4);
    // arr.push_back(-3);
    // arr.push_back(0);
    // arr.push_back(0);
    // arr.push_back(8);
    // arr.push_back(4);

    // printArray(arr);

    return 0;
}

/**
 *     sort(arr.begin(), arr.end());
    printArray(arr);
    int front = 0;
    int back = arr.size() - 1;

    while (front <= back)
    {
        int target = arr[front] + arr[back];
        if (target == sum)
        {
            // cout << arr[front] << "\t" << arr[back] << endl;
            if (arr[front] == arr[front + 1] || arr[back] == arr[back - 1])
            {
                int k = 1;
                int index = front;
                for (index = front; index < arr.size(); index++)
                {
                    if (arr[index] == arr[index + 1])
                    {
                        k++;
                    }
                    else
                    {
                        break;
                    }
                }
                // cout << "k = " << k << " index = " << index << endl;
                // cout << arr[front] << "\t" << arr[back] << endl;

                int l = 1;
                if (!(arr[front] == arr[back]))
                {
                    for (index = back; index != front; index--)
                    {
                        if (arr[index] == arr[index - 1])
                        {
                            l++;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                else
                {

                }

                // cout << "k = " << k << " index = " << index << endl;
                // cout << "l = " << l << " index = " << index << endl;
                // cout << arr[front] << "\t" << arr[back] << endl;

                int mul = k * l;
                cout << k << " && " << l << endl;

                for (int i = 1; i <= mul; i++)
                {
                    // vector<int> temp;
                    // temp.push_back(min(arr[front], arr[back]));
                    // temp.push_back(max(arr[front], arr[back]));
                    // ans.push_back(temp);
                    cout << arr[front] << "\t" << arr[back] << endl;
                }
                front = front + k;
                back = back - l;
            }
            else
            {
                // cout << arr[front] << "\t" << arr[back] << endl;
                back--;
            }
        }
        else if (target > sum)
        {
            back--;
        }
        else
        {
            front++;
        }
        // cout << "-------------------------" << endl;
        // cout << "sum = " << sum << " & target = " << target << endl;
        // cout << arr[front] << "\t" << arr[back] << endl;
        // cout << "-------------------------" << endl;
    }

 */