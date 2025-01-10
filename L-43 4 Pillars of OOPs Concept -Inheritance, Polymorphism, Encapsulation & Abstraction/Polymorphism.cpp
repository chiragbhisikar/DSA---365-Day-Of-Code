#include <bits/stdc++.h>

using namespace std;

// Compile Time Polymorphism ==> Function Overloading
class A
{
public:
    void sayHello()
    {
        cout << "Hello Chirag" << endl;
    }

    void sayHello(string name)
    {
        cout << "Hello " << name << endl;
    }
};

// Compile Time Polymorphism ==> Operator Overloading
class B
{
public:
    int a, b;

    int add(int a, int b)
    {
        return a + b;
    }

    void operator+(B &obj)
    {
        int firstNumber = this->a;
        int secondNumber = obj.a;
        int sub = firstNumber - secondNumber;

        cout << "output: " << sub << endl;
    }
};

// Run Time Polymorphism ==> Operator Overriding
class Animal
{
public:
    void speak()
    {
        cout << "Speak" << endl;
    }
};
class Dog : public Animal
{
public:
    void speak()
    {
        cout << "Bark" << endl;
    }
};

int main()
{
    A a;
    a.sayHello();
    a.sayHello("Ankit");

    B obj1, obj2;
    obj1.a = 10;
    obj2.a = 5;

    obj1 + obj2;

    Animal animal;
    animal.speak();

    Dog dog;
    dog.speak();

    return 0;
}