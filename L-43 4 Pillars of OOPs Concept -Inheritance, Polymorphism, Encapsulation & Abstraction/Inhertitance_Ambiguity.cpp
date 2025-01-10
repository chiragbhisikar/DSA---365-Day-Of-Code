#include <bits/stdc++.h>

using namespace std;

class A
{
public:
    void func()
    {
        cout << "Inside Class A" << endl;
    }
};
class B
{
public:
    void func()
    {
        cout << "Inside Class B" << endl;
    }
};
class C : public A, public B
{
public:
};
int main()
{
    C c;
    // c.func();  ==> This will give an error because of ambiguity
    c.A::func();
    c.B::func();
    
    return 0;
}