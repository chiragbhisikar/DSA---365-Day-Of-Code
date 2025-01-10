#include <bits/stdc++.h>

using namespace std;

class Animal
{
public:
    int age;
    int weight;

    void speak()
    {
        cout << "******Speaking Animal******" << endl;
    }
};

class Dog : public Animal
{
};

int main()
{
    Dog d;
    d.speak();

    return 0;
}