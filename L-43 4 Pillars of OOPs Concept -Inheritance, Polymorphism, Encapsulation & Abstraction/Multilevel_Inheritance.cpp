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

class GermenShepher : public Dog
{
};
int main()
{
    GermenShepher g;
    g.speak();

    return 0;
}