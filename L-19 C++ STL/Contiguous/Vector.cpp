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

    // vector<int> v;
    //     v.push_back(1);
    //     v.emplace_back(2);
    //     print(v);

    //     vector<pair<int, int> > v1;
    //     pair<int, int> p(1, 2);
    //     v1.push_back(p);
    //     cout << v1[0].first << "\t" << v1[0].second << "\t" << v1.size() << endl;
    //     v1.emplace_back(3, 4);
    //     cout << v1[1].first << "\t" << v1[1].second << "\t" << v1.size() << endl;

    //     vector<int> v2(5,100); // => (size, element to filled with value)
    //     print(v2);

    //     vector<int> v3(5); // => (size)
    //     print(v3);

    //     vector<int> v4(v2); // => (copy vector)
    //     print(v2);

    //     vector<int>::iterator it  = v2.begin();
    //     for (vector<int>::iterator i = it; it != v2.end(); it++)
    //     {
    //         cout << *(it) << "\t";
    //     }
    //     //  OR
    //     for (auto i = it; it != v2.end(); it++)
    //     {
    //         cout << *(it) << "\t";
    //     }
    //     cout<<endl;

    //     vector<int> v5;
    //     v5.push_back(1);
    //     v5.push_back(2);
    //     v5.push_back(3);
    //     v5.push_back(4);
    //     v5.push_back(5);
    //     v5.push_back(6);
    //     v5.push_back(7);
    //     print(v5);
    //     v5.erase(v5.begin(),v5.end()); // -> Same As Clear
    //     cout << "Before Erase Capacity -> "<<v5.capacity() <<endl;
    //     print(v5);
    //     cout << "After Erase Capacity -> "<<v5.capacity() <<endl;
    //     v5.shrink_to_fit(); // Do Capacity To 0
    //     cout << "After Clear Capacity -> "<<v5.capacity() <<endl;

    //     vector<int> v6;
    //     // v6.insert(position,value);
    //     v6.insert(v6.begin(),5);
    //     // v6.insert(iterator(position),no of element to be adeed,value);
    //     v6.insert(v6.end(), 5, 10);
    //     print(v6);
    return 0;
}
