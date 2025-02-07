#include <bits/stdc++.h>

using namespace std;
// Brute Force O(n^3)
/*

void markRow(vector<vector<int>> &matrix, int rowIndex, int size,
             int markElement)
{
    for (int col = 0; col < size; col++)
    {
        if (matrix[rowIndex][col] != 0)
        {
            matrix[rowIndex][col] = markElement;
        }
    }
}

void markCol(vector<vector<int>> &matrix, int colIndex, int size,
             int markElement)
{
    for (int row = 0; row < size; row++)
    {
        if (matrix[row][colIndex] != 0)
        {
            matrix[row][colIndex] = markElement;
        }
    }
}

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int rowSize,
                               int colSize)
{
    for (int row = 0; row < rowSize; row++)
    {
        for (int col = 0; col < colSize; col++)
        {
            if (matrix[row][col] == 0)
            {
                markRow(matrix, row, colSize, -1);
                markCol(matrix, col, rowSize, -1);
            }
        }
    }

    for (int row = 0; row < rowSize; row++)
    {
        for (int col = 0; col < colSize; col++)
        {
            if (matrix[row][col] == -1)
            {
                matrix[row][col] = 0;
            }
        }
    }

    return matrix;
}
*/
/*
 //  Better Force Approach T.C -> O(n ^ 2) S.C -> O(n + m)
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int rowSize,
                               int colSize)
{
    // row -> matrix[...][0]
    // col -> matrix[0][...]

    bool roww[rowSize] = {false};
    bool coll[colSize] = {false};

    for (int row = 0; row < rowSize; row++)
    {
        for (int col = 0; col < colSize; col++)
        {
            if (matrix[row][col] == 0)
            {
                roww[row] = true;
                coll[col] = true;
            }
        }
    }

    for (int row = 0; row < rowSize; row++)
    {
        for (int col = 0; col < colSize; col++)
        {
            if (roww[row] || coll[col])
            {
                matrix[row][col] = 0;
            }
        }
    }

    return matrix;
}
*/

// Optimal T.C => O(n ^ 2) S.C => O(1)
vector<vector<int> > zeroMatrix(vector<vector<int> > &matrix, int rowSize,
                               int colSize)
{
    // row -> matrix[...][0]
    // col -> matrix[0][...]

    int col0row0 = matrix[0][0];

    // mark 0th row and 0th col if any matrix[row][col] found as an 0
    for (int row = 0; row < rowSize; row++)
    {
        for (int col = 0; col < colSize; col++)
        {
            if (matrix[row][col] == 0)
            {
                matrix[row][0] = 0;

                if (col != 0)
                {
                    matrix[0][col] = 0;
                }
                else
                {
                    col0row0 = 0;
                }
            }
        }
    }

    // start marking as 0 from 1st row and 1st col if 0th row or col is 0
    for (int row = 1; row < rowSize; row++)
    {
        for (int col = 1; col < colSize; col++)
        {
            if (matrix[row][0] == 0 || matrix[0][col] == 0)
            {
                matrix[row][col] = 0;
            }
        }
    }

    // if matrix[0][0] is 0 then mark entire 0th row as 0
    if (matrix[0][0] == 0)
    {
        for (int row = 0; row < colSize; row++)
        {
            matrix[0][row] = 0;
        }
    }

    // if col0row0 is 0 then mark entire 0th col as 0
    if (col0row0 == 0)
    {
        for (int col = 0; col < rowSize; col++)
        {
            matrix[col][0] = 0;
        }
    }

    return matrix;
}
int main()
{
    vector<vector<int> > row;
    
    vector<int> col1;
    col1.push_back(2);
    col1.push_back(4);
    col1.push_back(3);
    
    vector<int> col2;
    col2.push_back(1);
    col2.push_back(0);
    col2.push_back(0);
    
    row.push_back(col1);
    row.push_back(col2);

    vector<vector<int> > ans = zeroMatrix(row,2,3);
    
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
