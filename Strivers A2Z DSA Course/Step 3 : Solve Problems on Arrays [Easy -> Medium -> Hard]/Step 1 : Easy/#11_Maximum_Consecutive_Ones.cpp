#include <bits/stdc++.h>

using namespace std;
int consecutiveOnes(vector<int> &arr)
{
    int maxConsecutiveOnes = 0;
    int tempConsecutiveOnes = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 1)
        {
            tempConsecutiveOnes++;
        }
        else
        {
            if (maxConsecutiveOnes < tempConsecutiveOnes)
            {
                maxConsecutiveOnes = tempConsecutiveOnes;
            }
            tempConsecutiveOnes = 0;
        }
    }

    if (tempConsecutiveOnes > maxConsecutiveOnes)
    {
        maxConsecutiveOnes = tempConsecutiveOnes;
    }

    return maxConsecutiveOnes;
}
int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(0);
    arr.push_back(0);
    arr.push_back(0);
    arr.push_back(0);
    arr.push_back(1);

    int consecutive = consecutiveOnes(arr);
    cout << "consecutive once occured " << consecutive << " times" << endl;

    return 0;
}