#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num = 5;
    cout << num << endl;
    cout << "address of = " << &num << endl;

    int *ptr = &num;
    cout << "ptr = " << ptr << endl;
    cout << "*ptr = " << *ptr << endl;

    cout << "size of integer " << sizeof(num) << endl;
    cout << "size of pointer " << sizeof(ptr) << endl;

    double num1 = 5;
    cout << num1 << endl;
    cout << "address of = " << &num1 << endl;

    double *ptr1 = &num1;
    cout << "ptr1 = " << ptr1 << endl;
    cout << "*ptr1 = " << *ptr1 << endl;

    cout << "size of double " << sizeof(num1) << endl;
    cout << "size of pointer " << sizeof(ptr1) << endl;
    return 0;
}