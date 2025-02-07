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

// Brute Force => O(n^2)
/*
int celebrity(vector<vector<int> > &mat)
{
int n = mat.size();

for (int i = 0; i < n; i++)
{
    bool checkRow = true;
    bool checkCol = true;

    // check for row => mat[i][...]
    for (int row = 0; row < n; row++)
    {
        if (mat[i][row] != 0 && row != i)
        {
                checkRow = false;
        }
    }


if(checkRow == true){
    // check for col
    for (int col = 0; col < n; col++)
    {
            if (mat[col][i] != 1 && col != i)
            {
                checkCol = false;
                break;
            }

    }
}

    if (checkRow && checkCol)
    {
        return i;
    }
}

return -1;
}
*/

// Optimal Approach T.C => O(n) S.C => O(n) => n = length of mat 
int verify(vector<vector<int> > &mat, int answer, int n)
{
    bool checkRow = true;
    bool checkCol = true;

    // check for row => mat[i][...]
    for (int row = 0; row < n; row++)
    {
        if (mat[answer][row] != 0 && row != answer)
        {
            checkRow = false;
        }
    }

    if (checkRow == true)
    {
        // check for col
        for (int col = 0; col < n; col++)
        {
            if (mat[col][answer] != 1 && col != answer)
            {
                checkCol = false;
                break;
            }
        }
    }

    if (checkRow && checkCol)
    {
        return answer;
    }
    return -1;
}
bool knows(vector<vector<int> > &mat, int a, int b)
{
    if (mat[a][b] == 1)
    {
        return true;
    }
    return false;
}
int celebrity(vector<vector<int> > &mat)
{
    int n = mat.size();
    stack<int> stackk;

    // step 1 : push all elements in stackk
    for (int index = 0; index < n; index++)
    {
        stackk.push(index);
    }

    while (stackk.size() > 1)
    {
        int a = stackk.top();
        stackk.pop();

        int b = stackk.top();
        stackk.pop();

        if (knows(mat, a, b))
        { // a knows b
            stackk.push(b);
        }
        else // b knows a
        {
            stackk.push(a);
        }
    }

    // step 3: single element of stack is potential celebrity
    // so verify it
    int answer = stackk.top();

    return verify(mat, answer, n);
}

int main()
{
    vector<vector<int> > mat;
    vector<int> row0;
    row0.push_back(0);
    row0.push_back(1);
    row0.push_back(0);

    vector<int> row1;
    row1.push_back(0);
    row1.push_back(0);
    row1.push_back(0);

    vector<int> row2;
    row2.push_back(0);
    row2.push_back(1);
    row2.push_back(0);

    mat.push_back(row0);
    mat.push_back(row1);
    mat.push_back(row2);

    print(mat);
    cout << "celebrity is " << celebrity(mat) << endl;
    // celebrity(mat);
    return 0;
}