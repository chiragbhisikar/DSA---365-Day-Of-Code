#include <bits/stdc++.h>

using namespace std;

void printNos(int N, int i = 1)
{
    /*

        if (i == N)
        {
            cout << i << " ";
            return;
        }
        cout << i << " ";
        printNos(N, ++i);
     */
    
    // backtraking
    if (i < 1)
    {
        return;
    }
    printNos(N, i - 1);
    cout << i << "\t";
}

int main()
{
    printNos(5, 5);
    return 0;
}