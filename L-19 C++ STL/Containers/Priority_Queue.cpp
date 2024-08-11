// https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // max heap
    priority_queue<int> max;
    // min heap
    priority_queue<int, vector<int>, greater<int> > min;

    max.push(1);
    max.push(3);
    max.push(2);
    max.push(0);
    
    int size = max.size();
    for (int i = 0; i < size; i++)
    {
        cout << max.top() <<"\t";
        max.pop();
    }cout << endl;
    
    cout << "isEmpty -> "<<max.empty()<<endl;
    return 0;
}