/*
Question 1:
arr -> 2 1 4 3
ans -> 1 -1 3 -1
Question 2:
arr -> 1 3 2
ans -> -1 2 -1
*/

#include <bits/stdc++.h>

using namespace std;
void print(vector<int> arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<int> previousSmallerElement(vector<int> &arr, int n)
{
    vector<int> answer(n);

    stack<int> stackk;
    stackk.push(-1);

    for (int i = 0; i < n; i++)
    {
        int current = arr[i];
        while (stackk.top() >= current)
        {
            stackk.pop();
        }

        // add previous smallest element in answer which is stackk->top
        answer[i] = stackk.top();
        stackk.push(current);
    }

    return answer;
}

int main()
{
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(4);
    arr.push_back(3);
    print(arr, arr.size());
    vector<int> nextSmaller = previousSmallerElement(arr, arr.size());
    print(nextSmaller, nextSmaller.size());
    return 0;
}
