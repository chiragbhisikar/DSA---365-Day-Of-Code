#include <iostream>
using namespace std;

void getMin(int arr[], int size)
{
    int mini = arr[0];

    for (int i = 0; i < size; i++)
    {
        mini = min(mini, arr[i]);
        // if (arr[i] <= mini)
        // {
        //     mini = arr[i];
        // }
    }
    cout << "Min Of Array " << mini << endl;
}

void getMax(int arr[], int size)
{
    int maxi = arr[0];

    for (int i = 0; i < size; i++)
    {
        maxi = max(maxi, arr[i]);
        // if (arr[i] >= maxi)
        // {
        //     maxi = arr[i];
        // }
    }
    cout << "Max Of Array " << maxi << endl;
}

int main()
{
    int arr[10] = {12, 15, 16, 18, 20, 25, 27, 30, 90, 87};
    getMin(arr, 10);
    getMax(arr, 10);

    return 0;
}