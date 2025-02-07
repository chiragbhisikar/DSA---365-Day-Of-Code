#include <bits/stdc++.h>

using namespace std;

void print(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int nCr(int n, int r)
{
    int answer = 1;

    for (int i = 0; i < r; i++)
    {
        answer = answer * (n - i);
        answer = answer / (i + 1);
    }

    return answer;
}

vector<int> generateRow(int row)
{
    vector<int> answer;
    answer.push_back(1);

    int res = 1;
    for (int col = 1; col < row; col++)
    {
        res = res * (row - col);
        res = res / col;

        answer.push_back(res);
    }

    // print(answer);

    return answer;
}

void printPascalTriangle(int row)
{
    for (int col = 1; col <= row; col++)
    {
        vector<int> answer;
        answer = generateRow(col);

        print(answer);
    }
}
int main()
{
    // 10C3 -> nCr
    int n = 10;
    int r = 3;
    cout << n << "C" << r << " = " << nCr(n, r) << endl;

    // Generate Row
    vector<int> row = generateRow(n);
    cout << n << "th row Of Pascal Triangle Is " << endl;
    print(row);

    // Print Entire Pascal Triangle
    printPascalTriangle(n);
    return 0;
}