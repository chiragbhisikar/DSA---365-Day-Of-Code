#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num = 5;
    int *ptr = NULL;
    ptr = &num;

    cout << "before num = " << num << endl;
    *ptr = 10;
    cout << "*ptr = 10 after that num = " << num << endl;

    int *ptr1 = ptr;
    cout << "ptr = " << ptr << " | ptr1 = " << ptr1 << endl;
    cout << "*ptr = " << *ptr << " | *ptr1 = " << *ptr1 << endl;

    ptr1 = ptr + 1;
    cout << "ptr1 = " << ptr1 << " | ptr1 = " << ptr1 << endl;

    return 0;
}