#include <iostream>
#include <bits/stdc++.h>

using namespace std;
void update(int **ptr)
{
    // ptr = ptr + 1; // No Change

    // *ptr = *ptr + 1; // Change In Ptr

    **ptr = **ptr + 1; // Change In Value Of n
}

int main()
{
    int n = 5;
    int *ptr = &n;
    int **ptr2 = &ptr;

    /*
    // No Change In Value => // ptr = ptr + 1; // No Change
        // Getting Value
        cout << "Before " << endl;
        cout << "n = " << n << endl;
        cout << "*ptr = " << *ptr << endl;
        cout << "**ptr2 = " << **ptr2 << endl;

        update(ptr2);

        // Getting Value
        cout << "After " << endl;
        cout << "n = " << n << endl;
        cout << "*ptr = " << *ptr << endl;
        cout << "**ptr2 = " << **ptr2 << endl;
    */

    /*
     // Change In ptr => *ptr = *ptr + 1;
     cout << "Before " << endl;
     cout << "ptr = " << &ptr << endl;
     cout << "*ptr = " << *ptr << endl;
     cout << "*ptr = " << *ptr2 << endl;

     update(ptr2);

     cout << "After => Change In ptr" << endl;
     cout << "ptr = " << &ptr << endl;
     cout << "*ptr = " << *ptr << endl;
     cout << "*ptr = " << *ptr2 << endl;
    */

    // Change In Value => **ptr = **ptr + 1;
    cout << "Before " << endl;
    cout << "n = " << n << endl;
    cout << "*ptr = " << *ptr << endl;
    cout << "**ptr2 = " << **ptr2 << endl;

    update(ptr2);

    cout << "After => Change In ptr" << endl;
    cout << "n = " << n << endl;
    cout << "*ptr = " << *ptr << endl;
    cout << "**ptr2 = " << **ptr2 << endl;

    return 0;
}