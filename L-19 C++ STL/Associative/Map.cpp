// Map -> <Key,Value> Pair
// Key Is Unique
// https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/
#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int, string> m;
    m[1] = "Chirag";
    m[2] = "Rajeshbhai";
    m[3] = "Bhisikar";

    for (auto i : m)
    {
        cout << i.first << " => " << i.second << "\t";
    }
    cout << endl;

    cout << "Finding 3 -> " << m.count(3) << endl;

    cout << "After Erase -> " << m.erase(1) << endl;

    for (auto i : m)
    {
        cout << i.first << " => " << i.second << "\t";
    }
    cout << endl;

    return 0;
}