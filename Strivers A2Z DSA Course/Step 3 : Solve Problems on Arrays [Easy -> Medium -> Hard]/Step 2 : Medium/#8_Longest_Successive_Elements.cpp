#include <bits/stdc++.h>

using namespace std;

void print(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

int longestSuccessiveElements(vector<int> &a)
{
    //   Better Approach
    /*
      Time Complexity: O( N * log( N ) )
      Space Complexity: O( 1 )
    */
    /*
      // step 1 : sort a vector => O(N logN) => O(1)
      sort(a.begin(), a.end());

      // step 2 : do operation
      int lastSmaller = INT_MIN;
      int logestSuccessive = 1;
      int count = 0;

      for (int i = 0; i < a.size(); i++) {
        if (lastSmaller + 1 == a[i]) {
          lastSmaller = a[i];
          count++;
        } else if (lastSmaller != a[i]) {
          count = 1;
          lastSmaller = a[i];
        }
        logestSuccessive = max(count, logestSuccessive);
      }

      return logestSuccessive;
    */

    // Step 1 : Store All Element In Unordered Set
    int n = a.size();
    if (n == 0)
        return 0;
    int longest = 1;
    unordered_set<int> setElements;

    for (int i = 0; i < n; i++)
    {
        setElements.insert(a[i]);
    }

    for (auto iterator : setElements)
    {
        if (setElements.find(iterator - 1) == setElements.end())
        {
            int count = 1;
            int x = iterator;
            while (setElements.find(x + 1) != setElements.end())
            {
                x = x + 1;
                count = count + 1;
            }
            longest = max(longest, count);
        }
    }

    return longest;
}

int main()
{
    vector<int> arr;
    arr.push_back(102);
    arr.push_back(4);
    arr.push_back(100);
    arr.push_back(1);
    arr.push_back(101);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(1);
    print(arr);
    // cout << "Longest Successive Elements = " << longestSuccessiveElements(arr) << endl;
    longestSuccessiveElements(arr);

    return 0;
}