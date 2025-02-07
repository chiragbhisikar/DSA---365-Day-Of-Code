#include <bits/stdc++.h>

using namespace std;

int main()
{
    queue<int> q;
    q.push(11);
    q.push(15);
    q.push(13);

    cout << "queue size is " << q.size() << endl;
    q.pop();
    cout << "queue size is " << q.size() << endl;

    cout << "queue is empty -> " << (q.empty() ? "yes" : "no") << endl;
    q.pop();
    q.pop();
    cout << "queue is empty -> " << (q.empty() ? "yes" : "no") << endl;

    
    return 0;
}