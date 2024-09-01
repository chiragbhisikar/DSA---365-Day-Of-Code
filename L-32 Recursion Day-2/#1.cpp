#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void reachHome(int source, int destination)
{
    if (source == destination)
    {
        cout << "Pahuch Gya" << endl;
        return;
    }

    cout << "Step " << source << " -> ";
    reachHome(source + 1, destination);
}
int main()
{
    int destination = 10;
    int source = 1;

    reachHome(source, destination);
    return 0;
}