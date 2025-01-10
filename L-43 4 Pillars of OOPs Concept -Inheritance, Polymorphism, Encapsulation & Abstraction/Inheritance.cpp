#include <bits/stdc++.h>

using namespace std;

class Human
{
public:
    int height, weight, age;

    void setAge(int weight)
    {
        this->weight = weight;
    }
    int getAge()
    {
        return this->age;
    }
};

class Male : public Human
{
private:
    string colour;

public:
    void attack()
    {
        cout << "Male Attack()" << endl;
    }
    void sleep()
    {
        cout << "Male Sleep()" << endl;
    }
};
int main()
{
    Male obj;
    cout << obj.weight << endl;
    cout << obj.age << endl;
    cout << obj.height << endl;

    obj.attack();
    obj.sleep();
    obj.setAge(18);

    cout << obj.weight << endl;
    cout << obj.age << endl;
    cout << obj.height << endl;

    return 0;
}