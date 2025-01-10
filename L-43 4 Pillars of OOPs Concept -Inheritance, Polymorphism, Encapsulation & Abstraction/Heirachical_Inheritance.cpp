#include <bits/stdc++.h>

using namespace std;

class A
{
public:
    void displayA()
    {
        cout << "Inside Class A" << endl;
    }
};
class B : public A
{
public:
    void displayB()
    {
        cout << "Inside Class B" << endl;
    }
};

class C : public A
{
public:
    void displayC()
    {
        cout << "Inside Class C" << endl;
    }
};

class D : public B
{
public:
    void displayD()
    {
        cout << "Inside Class D" << endl;
    }
};
class E : public B
{
public:
    void displayE()
    {
        cout << "Inside Class E" << endl;
    }
};

class F : public C
{
public:
    void displayF()
    {
        cout << "Inside Class F" << endl;
    }
};

class G : public C
{
public:
    void displayG()
    {
        cout << "Inside Class G" << endl;
    }
};

int main()
{

    D d;
    d.displayA();
    d.displayB();
    d.displayD();

    E e;
    e.displayA();
    e.displayB();
    e.displayE();

    G g;
    g.displayA();
    g.displayC();
    g.displayG();
    
    F f;
    f.displayA();
    f.displayC();
    f.displayF();

    return 0;
}