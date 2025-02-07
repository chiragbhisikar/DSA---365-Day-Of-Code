#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > mergeOverlappingIntervals(vector<vector<int> > &arr)
{
    int n = arr.size();

    sort(arr.begin(), arr.end());
    vector<vector<int> > answer;

    for (int i = 0; i < n; i++)
    {
        // new interval
        if (answer.empty() || arr[i][0] > answer.back()[1])
        {
            answer.push_back(arr[i]);
        }
        // inside that interval
        else
        {
            answer.back()[1] = max(arr[i][1], answer.back()[1]);
        
        }
    }

    return answer;
}

int main()
{
    vector<vector<int> > v;
    vector<int> temp;
    temp.push_back(1);
    temp.push_back(3);
    v.push_back(temp);
    temp.clear();

    temp.push_back(2);
    temp.push_back(4);
    v.push_back(temp);
    temp.clear();

    temp.push_back(4);
    temp.push_back(6);
    v.push_back(temp);
    temp.clear();

    temp.push_back(8);
    temp.push_back(10);
    v.push_back(temp);
    temp.clear();


    temp.push_back(2);
    temp.push_back(3);
    v.push_back(temp);
    temp.clear();


    temp.push_back(11);
    temp.push_back(13);
    v.push_back(temp);
    temp.clear();
    
    temp.push_back(16);
    temp.push_back(17);
    v.push_back(temp);
    temp.clear();
    vector<vector<int> > answer = mergeOverlappingIntervals(v);

    for (int i = 0; i < answer.size(); i++)
    {
        cout << "{" << answer[i][0] << "," << answer[i][1] << "}, ";
    }
    
    return 0;
}