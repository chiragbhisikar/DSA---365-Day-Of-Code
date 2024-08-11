// All Elements Are To Be Unique
// BST -> Implemented By
// Sorted & Slow
// https://www.geeksforgeeks.org/set-in-cpp-stl/
#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> s;
    s.insert(5);
    s.insert(1);
    s.insert(2);
    s.insert(4);
    s.insert(5);

    for (auto i : s)
    {
        cout << i << "\t";
    }
    cout << endl;

    s.erase(s.begin());

    for (auto i : s)
    {
        cout << i << "\t";
    }
    cout << endl;

    cout << "Is 5 Exist -> " << s.count(5) << endl;

    set<int>::iterator itr = s.find(4);

    for (auto it = itr; it != s.end(); it++)
    {
        cout << *it << "\t";
    }
    cout << endl;

    return 0;
}