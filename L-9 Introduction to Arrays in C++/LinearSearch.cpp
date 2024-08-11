#include <iostream>
using namespace std;

bool isPresent(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int arr[5] = {13, 15, 17, 18, 20};
    bool isExist = isPresent(arr, 5, 21);

    cout << "21 Is " << (isExist ? "Present " : "Not Present ");
    return 0;
}