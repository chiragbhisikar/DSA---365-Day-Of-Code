// Swap Alternate
/*
 Arr = [1 , 3 , 2, 7 , 11 ,8]
 Answer = [3, 1, 7 , 2, 8, 11]

 Arr = [1 , 3 , 2, 7 , 11]
 Answer = [3, 1, 7 , 2, 11]
*/

#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

void swapAlternate(int arr[], int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        swap(arr[i * 2], arr[(i * 2) + 1]);
    }
}
int main()
{
    int evenArray[] = {1, 3, 2, 7, 11, 8};

    printArray(evenArray, (sizeof(evenArray) / sizeof(int)));
    // swapAlternate(evenArray, (sizeof(evenArray) / sizeof(int)));
    for (int i = 0; i < (sizeof(evenArray) / sizeof(int)) / 2; i++)
    {
        swap(evenArray[i * 2], evenArray[(i * 2) + 1]);
         printArray(evenArray, (sizeof(evenArray) / sizeof(int)));
    }
    printArray(evenArray, (sizeof(evenArray) / sizeof(int)));

    cout << "***************************************" << endl;

    int oddArray[] = {1, 3, 2, 7, 11};
    printArray(oddArray, (sizeof(oddArray) / sizeof(int)));
    swapAlternate(oddArray, (sizeof(oddArray) / sizeof(int)));
    printArray(oddArray, (sizeof(oddArray) / sizeof(int)));

    return 0;
}