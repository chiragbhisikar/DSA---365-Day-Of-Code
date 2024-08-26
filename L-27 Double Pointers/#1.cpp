#include <iostream>
#include <bits/stdc++.h>

using namespace std;
void update(int **ptr)
{
    // ptr = ptr + 1; // No Change

    *ptr = *ptr + 1; // Change In Ptr

    // **ptr = **ptr + 1;
}

int main()
{
    int n = 5;
    int *ptr = &n;
    int **ptr2 = &ptr;
    /*
        // Getting Value
        cout << "n = " << n << endl;
        cout << "*ptr = " << *ptr << endl;
        cout << "**ptr2 = " << **ptr2 << endl;

        cout << endl;
        // Getting Address Of n
        cout << "Getting Address Of n" << endl;
        cout << "&n = " << &n << endl;
        cout << "ptr = " << ptr << endl;
        cout << "*ptr2 = " << *ptr2 << endl;

        cout << endl;
        cout << "Getting Address Of ptr" << endl;
        // Getting Address Of ptr
        cout << "&ptr = " << &ptr << endl;
        cout << "ptr2 = " << ptr2 << endl;

        cout << endl;
        // Getting Address Of ptr2
        cout << "Getting Address Of ptr2" << endl;
        cout << "&ptr2 = " << &ptr2 << endl;
     */

    update(ptr2);

    // Getting Value
    cout << "n = " << n << endl;
    cout << "*ptr = " << *ptr << endl;
    cout << "**ptr2 = " << **ptr2 << endl;

    cout << endl;
    // Getting Address Of n
    cout << "Getting Address Of n" << endl;
    cout << "&n = " << &n << endl;
    cout << "ptr = " << ptr << endl;
    cout << "*ptr2 = " << *ptr2 << endl;

    cout << endl;
    cout << "Getting Address Of ptr" << endl;
    // Getting Address Of ptr
    cout << "&ptr = " << &ptr << endl;
    cout << "ptr2 = " << ptr2 << endl;

    cout << endl;
    // Getting Address Of ptr2
    cout << "Getting Address Of ptr2" << endl;
    cout << "&ptr2 = " << &ptr2 << endl;

    return 0;
}