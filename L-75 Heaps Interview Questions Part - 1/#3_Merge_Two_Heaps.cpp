#include <bits/stdc++.h>

using namespace std;

void heapify(vector<int> &arr, int n, int index)
{
    int largest = index;
    // 0 base indexing so -> left ---> 2 * index + 1
    int leftChildIndex = 2 * index + 1;
    // 1 base indexing so -> left ---> 2 * index + 2
    int rightChildIndex = 2 * index + 2;

    if (leftChildIndex < n && arr[largest] < arr[leftChildIndex])
    {
        largest = leftChildIndex;
    }

    if (rightChildIndex < n && arr[largest] < arr[rightChildIndex])
    {
        largest = rightChildIndex;
    }

    // update hua he
    if (largest != index)
    {
        swap(arr[largest], arr[index]);
        heapify(arr, n, largest);
    }
}

vector<int> mergeHeaps(vector<int> &arr1, vector<int> &arr2, int n, int m)
{
    vector<int> mergedArray;
    //  step 1 : merge both array into one
    int leftPointer = 0, rightPointer = 0;

    while (leftPointer < n)
    {
        mergedArray.push_back(arr1[leftPointer++]);
    }

    while (rightPointer < m)
    {
        mergedArray.push_back(arr2[rightPointer++]);
    }

    // step 2 : build merged array
    int size = mergedArray.size();

    // 0 base indexing so -> (i = size / 2 - 1 --> i >= 0)
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(mergedArray, size, i);
    }

    return mergedArray;
}

int main()
{
    vector<int> arr1 = {10, 5, 6, 2};
    vector<int> arr2 = {12, 7, 9};

    vector<int> ans = mergeHeaps(arr1, arr2, arr1.size(), arr2.size());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}