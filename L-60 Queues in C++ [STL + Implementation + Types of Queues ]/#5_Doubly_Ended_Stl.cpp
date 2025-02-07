#include <bits/stdc++.h>

using namespace std;

int main()
{
    deque<int> q;
    q.push_front(12);
    q.push_back(14);

    cout << q.front() << endl;
    cout << q.back() << endl;

    q.pop_front();
    
    cout << q.front() << endl;
    cout << q.back() << endl;
    q.pop_back();

    if (q.empty())
    {
        cout << "queue is empty" << endl;
    }
    else
    {
        cout << "queue is not empty";
    }
    return 0;
}