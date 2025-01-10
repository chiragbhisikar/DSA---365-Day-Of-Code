#include <bits/stdc++.h>

using namespace std;

class Animal
{
public:
    int age;
    int weight;

    void bark()
    {
        cout << "******Barking Animal******" << endl;
    }
};

class Human
{
public:
    string colour;

    void speak()
    {
        cout << "******Speaking Human******" << endl;
    }
};

class Multiple : public Animal, public Human
{
};
int main()
{
    Multiple m;
    m.bark();
    m.speak();

    return 0;
}