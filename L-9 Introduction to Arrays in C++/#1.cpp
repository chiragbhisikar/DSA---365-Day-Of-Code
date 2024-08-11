#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
    cout << "Printing the array" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << "\nPrinting done" << endl;
}
int main()
{
    int number[15];
    // accessing an array
    // cout << "number[0] = " << number[0] << endl;
    // cout << "number[14] = " << number[14] << endl
    //      << endl;

    // intializing an array
    int second[3] = {5, 7, 11};
    // printArray(second, 15);

    int third[15] = {5, 7};
    // printArray(third, 15);

    // For Intializing Full Array Value With 0
    int fourth[15] = {0};
    // printArray(fourth, 15);

    // For Intializing Full Array Value With 200
    fill_n(fourth, 15, 200);
    // printArray(fourth, 15);

    int fifth[15] = {0};
    cout << "Size Of fifth[15] is " << sizeof(fifth) / sizeof(int) << endl;

    char ch[5] = {'a', 'b', 'c', 'd', 'e'};
    cout << ch[0] << "\t";
    cout << ch[1] << "\t";
    cout << ch[2] << "\t";
    cout << ch[3] << "\t";
    cout << ch[4] << "\t";

    return 0;
}