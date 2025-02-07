#include <bits/stdc++.h>

using namespace std;

void print(vector<vector<int> > mat)
{
    int n = mat.size();

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            cout << mat[row][col] << " ";
        }
        cout << endl;
    }
}

vector<int> previousSmallerElement(vector<int> arr, int n)
{
    vector<int> answer(n);

    stack<int> stackk;
    stackk.push(-1);

    for (int i = 0; i < n; i++)
    {
        int current = arr[i];
        // find previous smallest element in stack
        while (stackk.top() != -1 && arr[stackk.top()] >= current)
        { // -> this is for index not value
            stackk.pop();
        }
        // adding previous smaller bar length in answer
        answer[i] = stackk.top();
        // pushing previous new smallest bar height in stack
        stackk.push(i);
    }
    // print(answer, n);
    return answer;
}

vector<int> nextSmallerElement(vector<int> arr, int n)
{
    vector<int> answer(n);

    stack<int> stackk;
    stackk.push(-1);

    for (int i = n - 1; i >= 0; i--)
    {
        int current = arr[i];
        // find next smallest element in stack
        while (stackk.top() != -1 && arr[stackk.top()] >= current)
        { // -> this is for index not value
            stackk.pop();
        }
        // adding next smaller bar length in answer
        answer[i] = stackk.top();
        // pushing next new smallest bar height in stack
        stackk.push(i);
    }
    // print(answer, n);
    return answer;
}

int largestRectangleArea(vector<int> &heightsOfBar)
{
    int n = heightsOfBar.size();
    int area = INT_MIN;

    vector<int> previousSmallestElements(n);
    previousSmallestElements = previousSmallerElement(heightsOfBar, n);
    vector<int> nextSmallestElements(n);
    nextSmallestElements = nextSmallerElement(heightsOfBar, n);

    for (int i = 0; i < n; i++)
    {
        int height = heightsOfBar[i];

        if (nextSmallestElements[i] == -1)
        {
            nextSmallestElements[i] = n;
        }
        int breadth =
            nextSmallestElements[i] - previousSmallestElements[i] - 1;

        int newArea = height * breadth;
        area = max(area, newArea);
    }

    return area;
}

int maxArea(vector<vector<int> > &mat)
{
    int rowSize = mat.size();
    int colSize = mat[0].size();
    vector<int> heights = mat[0];
    
    int area = largestRectangleArea(heights);

    for (int row = 1; row < rowSize; row++)
    {
        for (int col = 0; col < colSize; col++)
        {
            if(mat[row][col] == 0){
                heights[col] = 0;
            }
            else{
                heights[col]++;
            }
        }

        int newArea = largestRectangleArea(heights);
        area = max(area , newArea);
    }
    

    return area;
}

int main()
{
    vector<vector<int> > mat;
    vector<int> row0;
    row0.push_back(0);
    row0.push_back(1);
    row0.push_back(1);
    row0.push_back(0);

    vector<int> row1;
    row1.push_back(1);
    row1.push_back(1);
    row1.push_back(1);
    row1.push_back(1);

    vector<int> row2;
    row2.push_back(1);
    row2.push_back(1);
    row2.push_back(1);
    row2.push_back(1);

    vector<int> row3;
    row3.push_back(1);
    row3.push_back(1);
    row3.push_back(0);
    row3.push_back(0);

    mat.push_back(row0);
    mat.push_back(row1);
    mat.push_back(row2);
    mat.push_back(row3);

    print(mat);
    cout << "max area = "<< maxArea(mat) << endl;
    return 0;
}