// https://www.geeksforgeeks.org/c-magicians-stl-algorithms/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    cout << "Finding 5 -> " << binary_search(v.begin(), v.end(), 5) << endl;
    cout << "Finding 6 -> " << binary_search(v.begin(), v.end(), 6) << endl;

    auto lb = lower_bound(v.begin(), v.end(), 6);
    cout << "Lower Bound 6 -> " << lb - v.begin() << endl;

    auto ub = upper_bound(v.begin(), v.end(), 6);
    cout << "Lower Bound 6 -> " << ub - v.begin() << endl;

    return 0;
}