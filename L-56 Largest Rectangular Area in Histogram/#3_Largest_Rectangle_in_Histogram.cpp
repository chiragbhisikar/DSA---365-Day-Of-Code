/*
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

Input: heights = [2,4]
Output: 4
*/
#include <bits/stdc++.h>

using namespace std;
void print(vector<int> arr, int n) {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
vector<int> previousSmallerElement(vector<int> arr, int n) {
        vector<int> answer(n);

        stack<int> stackk;
        stackk.push(-1);

        for (int i = 0; i < n; i++) {
            int current = arr[i];
            // find previous smallest element in stack
            while (stackk.top() != -1 && arr[stackk.top()] >= current) { // -> this is for index not value
                stackk.pop();
            }
            // adding previous smaller bar length in answer
            answer[i] = stackk.top();
            // pushing previous new smallest bar height in stack
            stackk.push(i);
        }
        print(answer,n);
        return answer;
    }

    vector<int> nextSmallerElement(vector<int> arr, int n) {
        vector<int> answer(n);

        stack<int> stackk;
        stackk.push(-1);

        for (int i = n - 1; i >= 0; i--) {
            int current = arr[i];
            // find next smallest element in stack
            while (stackk.top() != -1 && arr[stackk.top()] >= current) { // -> this is for index not value
                stackk.pop();
            }
            // adding next smaller bar length in answer
            answer[i] = stackk.top();
            // pushing next new smallest bar height in stack
            stackk.push(i);
        }
        print(answer,n);
        return answer;
    }

    int largestRectangleArea(vector<int>& heightsOfBar) {
        int n = heightsOfBar.size();
        int area = INT_MIN;

        
        vector<int> previousSmallestElements(n);
        previousSmallestElements = previousSmallerElement(heightsOfBar, n);
        vector<int> nextSmallestElements(n);
        nextSmallestElements = nextSmallerElement(heightsOfBar, n);

        for (int i = 0; i < n; i++) {
            int height = heightsOfBar[i];

            if (nextSmallestElements[i] == -1) {
                nextSmallestElements[i] = n;
            }
            int breadth =
                nextSmallestElements[i] - previousSmallestElements[i] - 1;

            int newArea = height * breadth;
            area = max(area, newArea);
        }

        return area;
    }

int main()
{

    return 0;
}