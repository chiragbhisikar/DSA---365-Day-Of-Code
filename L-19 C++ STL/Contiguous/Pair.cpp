#include <iostream>
#include <utility>
using namespace std;

// Driver Code
int main()
{
    // defining a pair
    pair<int, int> p1(1, 2);
    cout << "p1.first = " << p1.first << " ";
    cout << "p1.second = " << p1.second << endl;

    // first part of the pair
    p1.first = 1;
    // second part of the pair
    p1.second = 2;

    cout << "p1.first = " << p1.first << " ";
    cout << "p1.second = " << p1.second << endl;

    pair<int, pair<int, int> > p2;

    // first part of the pair
    p2.first = 1;
    // second pair first element
    p2.second.first = 2;
    // second pair second element
    p2.second.second = 3;

    cout << p2.first << "\t" << p2.second.first << "\t" << p2.second.second << endl;

    pair<int, pair<int, int> > p3[10];

    // first part of the pair
    p3[0].first = 01;
    // second pair first element
    p3[0].second.first = 02;
    // second pair second element
    p3[0].second.second = 03;

    cout << p3[0].first << "\t" << p3[0].second.first << "\t" << p3[0].second.second << endl;

    return 0;
}
