#include <bits/stdc++.h>

using namespace std;

void printNos(int N, int i = 1)
{
    /*
        if (i == -1)
        {
            printNos(N, N);
        }
        if (i == 0)
        {
            return;
        }
        cout << i << " ";
        printNos(N, --i);
    */

    // backtraking answer
    if (i > N)
    {
        return;
    }
    printNos(N, i + 1);
    cout << i << "\t";
}

int main()
{
    printNos(5);
    return 0;
}