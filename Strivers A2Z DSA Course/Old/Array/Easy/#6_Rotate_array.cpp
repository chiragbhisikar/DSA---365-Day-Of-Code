#include <iostream>
#include <bits/stdc++.h>

using namespace std;
void printArray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}
// BruteForce
/*

vector<int> rotateArrayByOnePlace(vector<int> &arr, int n)
{
    // My Approach
    for (int i = 0; i < n - 1; i++)
    {
        swap(arr[i], arr[i + 1]);
    }

    return arr;
}

void rotateArray(vector<int> arr, int k)
{
    k = k % arr.size();

    for (int i = 0; i < k; i++)
    {
        arr = rotateArrayByOnePlace(arr, arr.size());
        printArray(arr);
    }
}

 */

// Optimal
// vector<int> rotateArray(vector<int> arr, int k) {
//   vector<int> temp = arr;
//   int n = arr.size();

//   k = k % n;

//   int i = 0,index = 0;
//   while(i < (n - k)) {
//       arr[i] = arr[i+k];
//       i++;
//   }

//   while(i < n) {
//       arr[i] = temp[index];
//       index++;
//       i++;
//   }

//   return arr;
// }

// Most Optimal

vector<int> reverse(vector<int> arr, int start, int end)
{
    while (start <= end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }

    return arr;
}
void rotateArray(vector<int> arr, int k)
{
    // 1 2 3 4 5 6 7 k = 3 => ans = 4 5 6 7 1 2 3
    // For Reversing First Part arr = 3 2 1 4 5 6 7
    // For Reversing Last Part arr = 3 2 1 7 6 5 4
    // For Reversing All Element Of An Array arr = 4 5 6 7 3 2 1
    // ans = arr
    /*
        k = k % arr.size();
        // For Reversing First Part
        arr = reverse(arr, 0, k - 1);
        // For Reversing Last Part
        arr = reverse(arr, k, arr.size() - 1);
        // For Reversing All Element Of An Array
        arr = reverse(arr, 0, arr.size() - 1);
    */

    k = k % arr.size();
    // For Reversing First Part
    arr = reverse(arr, 0, k);
    // For Reversing Last Part
    arr = reverse(arr, k + 1, arr.size() - 1);
    // For Reversing All Element Of An Array
    arr = reverse(arr, 0, arr.size() - 1);
    printArray(arr);
}

int main()
{
    vector<int> arr;
    // arr.push_back(99);
    // arr.push_back(-1);
    // arr.push_back(-100);
    // arr.push_back(3);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);

    // arr.push_back(7);
    // arr.push_back(5);
    // arr.push_back(2);
    // arr.push_back(11);
    // arr.push_back(2);
    // arr.push_back(43);
    // arr.push_back(1);
    // arr.push_back(1);

    rotateArray(arr, 3);
    return 0;
}