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
// Approach 1
void sort012OccurenceApproach(int *arr, int n)
{
    int count[3] = {0, 0, 0};

    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    cout << count[0] << " " << count[1] << " " << count[2] << endl;

    int i = 0;
    while (i != n && (count[0] + count[1] + count[2] != 0))
    {
        if (count[0] != 0)
        {
            arr[i] = 0;
            count[0]--;
        }
        else if (count[1] != 0)
        {
            arr[i] = 1;
            count[1]--;
        }
        else if (count[2] != 0)
        {
            arr[i] = 2;
            count[2]--;
        }
        // cout << count[0] << " " << count[1] << " " << count[2] << endl;
        i++;
    }
    printArray(arr, n);
}

// Approach 2
void sort012ThreePointerApproach(int *arr, int n)
{
    int front = 0, mid = 0, back = n - 1;

    while (front <= back)
    {
        if (arr[front] == 0)
        {
            swap(arr[front], arr[mid]);
            front++;
            mid++;
        }
        else if (arr[front] == 2)
        {
            swap(arr[front], arr[back]);
            back--;
        }
        else
        {
            front++;
        }
        // cout << visited << " " << mid << " " << hasTwo << endl;
    }
    printArray(arr, n);
}

int main()
{
    int arr1[] = {0, 1, 2, 2, 1, 0};
    // int arr[] = {0, 1, 1, 0, 0, 1, 1, 0, 1, 0};

    sort012OccurenceApproach(arr1, sizeof(arr1) / sizeof(int));

    int arr2[] = {0, 1, 2, 1, 2, 1, 2};
    sort012ThreePointerApproach(arr2, sizeof(arr2) / sizeof(int));
    return 0;
}