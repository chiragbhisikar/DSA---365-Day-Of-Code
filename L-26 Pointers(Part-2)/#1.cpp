#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    /**
     *
    cout << "arr = " << arr << endl;               // address of arr[0]
    cout << "&arr[0] = " << &arr[0] << endl;       // address of arr[0]
    cout << "arr[0] = " << arr[0] << endl;         // arr[0]
    cout << "*arr = " << *arr << endl;             // arr[0]
    cout << "*arr + 1 = " << *arr + 1 << endl;     // arr[0] + 1
    cout << "*(arr + 1) = " << *(arr + 1) << endl; // => arr[1]

    cout << *(1 + arr) << endl;
     */

    /*
    cout << "size of arr " << sizeof(arr) << endl;
    cout << "size of arr " << sizeof(&arr) << endl;
    int *ptr = arr;
    cout << "size of ptr " << sizeof(*ptr) << endl;
     */

    int *p = &arr[0];
    cout << "&arr[0] = " << &arr[0] << endl;
    cout << "arr[0] = " << arr[0] << endl;
    cout << "arr = " << arr << endl;

    cout << "\n";

    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;
    cout << "&p = " << &p << endl;

    cout << "\n";
    
    p = p + 1;
    cout << "p + 1 = " << p << endl;
    cout << "*p + 1 = " << *p << endl;
    cout << "&p + 1 = " << &p << endl;

    return 0;
}