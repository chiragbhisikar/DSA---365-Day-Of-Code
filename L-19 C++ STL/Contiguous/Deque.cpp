// Deque -> Insert & Delete Can Be Done From Both Side(Begin And End)
// Vector -> Complex -> Dynamic
// https://www.geeksforgeeks.org/deque-cpp-stl/

#include <iostream>
#include <deque>
using namespace std;

void print(deque<int> d)
{
    for (int i : d)
    {
        cout << i << "\t";
    }
    cout << endl;
}

int main()
{
    deque<int> d;

    // Push From Front & Back
    d.push_front(1);
    d.push_back(2);
    for (int i : d)
    {
        cout << i << "\t";
    }
    cout << endl;

    // Pop From Front & Back
    d.pop_front();
    d.pop_back();

    d.push_front(1);
    d.push_back(2);
    d.push_back(3);
    d.push_back(4);
    d.push_back(5);

    // Front & Back
    print(d);
    cout << endl;
    cout << "First Index Element " << d.at(0) << endl;
    cout << "First Index Element " << d.front() << endl;
    cout << "Last Index Element " << d.back() << endl;

    // Empty Or Not
    cout << "Empty Or Not -> " << d.empty() << endl;

    // Erase
    cout << "Erase Till 1 To 3 -> " << endl;
    d.erase(d.begin(), d.begin() + 2);
    print(d);

    return 0;
}