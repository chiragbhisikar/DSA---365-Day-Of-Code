// Array -> Contiguous
// https://www.geeksforgeeks.org/stdarray-in-cpp/
#include <iostream>
#include <array>
using namespace std;

int main()
{
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    array<int, 10> arr1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int i = 0; i < arr1.size(); i++)
    {
        cout << arr1[i] << "\t";
    }
    cout << endl;
    cout << "Element at index 2 is -> " << arr1.at(2) << endl;

    cout << "Empty Or Not -> " << arr1.empty() << endl;

    cout << "First Element -> " << arr1.front() << endl;

    cout << "Last Element -> " << arr1.back() << endl;
    return 0;
}