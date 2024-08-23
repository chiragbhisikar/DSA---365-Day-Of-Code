#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num = 5;
    int *ptr = NULL; // int *ptr = num; => Same
    ptr = &num;

    cout << "num = " << num << endl;
    cout << "address of = " << &num << endl;

    cout << "ptr = " << ptr << endl;
    cout << "*ptr = " << *ptr << endl;

    int *ptr1 = NULL; // int *ptr1 = num; => Same
    ptr1 = &num;
    cout << "ptr1 = " << ptr << endl;
    cout << "*ptr1 = " << *ptr << endl;

    return 0;
}