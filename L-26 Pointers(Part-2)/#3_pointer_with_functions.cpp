#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void print(int *ptr)
{
    cout << "ptr = " << ptr << endl;
    cout << "*ptr = " << *ptr << endl;
}
void update(int *ptr)
{
    *ptr = *ptr + 5;
}

int getSum(int arr[], int size)
{
    cout << "size of arr " << sizeof(arr) << endl;

    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
        // sum += i[arr]; // => Same As sum += arr[i];
    }
    return sum;
}
int main()
{
    int value = 5;
    int *ptr = &value;
    // print(&value);
    // print(ptr);

    cout << "Before : p = " << value << " | *ptr = " << *ptr << endl;
    update(ptr);
    cout << "After : p = " << value << " | *ptr = " << *ptr << endl;

    int arr[5] = {1, 2, 3, 4, 5};

    cout << getSum(arr, 5) << endl;
    return 0;
}