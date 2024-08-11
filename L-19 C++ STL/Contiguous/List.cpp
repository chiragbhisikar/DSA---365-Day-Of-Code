// List -> Dynamic
// Insert & Delete Can Be Done From Both Side(Begin And End) -> Based On Double Ended List
// Not Possible Direct Access
// https://www.geeksforgeeks.org/list-cpp-stl/

#include <iostream>
#include <list>
using namespace std;

void print(list<int> d)
{
    for (int i : d)
    {
        cout << i << "\t";
    }
    cout << endl;
}

int main()
{
    list<int> l;
    l.push_front(2);
    l.push_front(1);
    l.push_back(4);
    l.push_back(3);
    for (int i : l)
    {
        cout << i << "\t";
    }
    cout << endl;
    l.pop_front();
    l.pop_back();
    print(l);

    cout << "after erase -> ";
    l.erase(l.begin());
    print(l);

    cout << "size of list -> " << l.size() << endl
         << endl;

    // Copy One List To Another

    cout << "Copy One List To Another -> list<int> s(l)" << endl;
    list<int> s(l);
    print(s);

    // Assign All Element Same Value
    cout << "Assign All Element Same Value -> list<int> a(5, 100)" << endl;
    list<int> a(5, 100);
    print(a);

    return 0;
}