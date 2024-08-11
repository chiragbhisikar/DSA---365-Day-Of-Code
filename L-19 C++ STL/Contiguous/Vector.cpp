// Vector -> Contiguous -> Dynamic
// https://www.geeksforgeeks.org/vector-in-cpp-stl/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    // Capacity
    cout << "Capacity Of Vector -> " << v.capacity() << endl;
    v.push_back(1);
    cout << "Capacity Of Vector -> " << v.capacity() << endl;
    v.push_back(2);
    cout << "Capacity Of Vector -> " << v.capacity() << endl;
    v.push_back(3);
    cout << "Capacity Of Vector -> " << v.capacity() << endl;

    // Size
    cout << "Size Of Vector -> " << v.size() << endl;

    // Element At Paticular Location -> v[2] = v.at(2)
    cout << "Element at index 2 is -> " << v.at(2) << endl;

    // Front
    cout << "First Or Front Element -> " << v.front() << endl;
    // Back Or Last
    cout << "Back Or Last Element -> " << v.back() << endl;

    // Push
    cout << "Push In Vector -> v.push_back(5)" << endl;
    v.push_back(5);
    // Pop
    cout << "Pop 5 In Vector -> v.pop_back()" << endl;
    v.pop_back();

    // Before Clear
    cout << "Before Clear Vector Size " << v.size() << endl;
    v.clear();
    // After Clear
    cout << "After Clear Vector Size " << v.size() << endl;

    // vector<int> v1(size,value assigned to be each element)
    vector<int> v1(5, 1);
    cout << "print v1" << endl;
    for (int i : v1)
    {
        cout << i << "\t";
    }
    cout << endl;

    // vector<int> v2 = v1;
    vector<int> v2(v1);
    cout << "print v2" << endl;
    for (int i : v2)
    {
        cout << i << "\t";
    }
    cout << endl;

    return 0;
}