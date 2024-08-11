// Containers -> Last In First Out
// https://www.geeksforgeeks.org/stack-in-cpp-stl/

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<string> s;
    s.push("Chirag");
    s.push("Rajeshbhai");
    s.push("Bhisikar");

    cout << "Top Element -> " << s.top() << endl;
    s.pop();
    // Size
    cout << "Size Of Stack -> " << s.size() << endl;
    // Empty Or Not
    cout << "Empty Or Not Stack -> " << s.empty() << endl;
    return 0;
}