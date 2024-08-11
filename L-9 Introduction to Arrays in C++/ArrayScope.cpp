#include <iostream>
using namespace std;

void update(int arr[], int size)
{
    cout << "Inside the function" << endl;

    arr[0] = 120;

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}
int main()
{
    int arr[3] = {1, 2, 3};
    update(arr, 3);

    for (int i = 0; i < 3; i++)
    {
        cout << arr[i] << "\t";
    }
    return 0;
}