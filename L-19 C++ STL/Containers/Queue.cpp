// Containers -> First In First Out
// https://www.geeksforgeeks.org/queue-cpp-stl/

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<string> q;
    q.push("Chirag");
    q.push("Rajeshbhai");
    q.push("Bhisikar");

    cout << "Front Element -> " << q.front() << endl;
    q.pop();
    cout << "Front Element -> " << q.front() << endl;

    cout << "Size Of Queue -> " << q.size() << endl;

        return 0;
}