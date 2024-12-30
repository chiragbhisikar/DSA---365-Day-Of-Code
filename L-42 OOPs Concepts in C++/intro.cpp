#include <iostream>
#include <bits/stdc++.h>
// #include "Hero.cpp"

using namespace std;

class Hero
{
private:
    int health;
    char level;

public:
    string name;
    static int countOfHero;

    // Default Constructor
    Hero()
    {
        this->name = "";
        this->health = 0;
        this->level = 'Z';
        countOfHero++;
        cout << "*****Default Constructor Called*****" << endl;
    }

    // Parameterized Constructor
    Hero(int health, char level, string name)
    {
        this->name = name;
        this->health = health;
        this->level = level;
        countOfHero++;
        cout << "*****Parameterized Constructor Called*****" << endl;
    }
    // Copy Constructor
    Hero(Hero &hero)
    {
        this->name = hero.name;
        this->health = hero.health;
        this->level = hero.level;
        countOfHero++;
        cout << "*****Copy Constructor Called*****" << endl;
    }

    void setHealth(int health)
    {
        this->health = health;
    }

    int getHealth()
    {
        return this->health;
    }

    void setLevel(int level)
    {
        this->level = level;
    }

    char getLevel()
    {
        return this->level;
    }

    void print()
    {
        cout << "[ Name: " << this->name << ", ";
        cout << "Health: " << this->health << ", ";
        cout << "Level: " << this->level << ", ";
        cout << "noOfHero: " << this->countOfHero << "]" << endl;
    }

    // Destructor
    ~Hero()
    {
        cout << "Destructor Called" << endl;
    }
};

int Hero::countOfHero = 1;
int main()
{

    Hero ramesh;
    ramesh.name = "Paul";
    // ramesh.health = 70;
    ramesh.setHealth(70);
    // ramesh.level = 'A';
    ramesh.setLevel('A');
    ramesh.print();

    // cout << "ramesh Name: " << ramesh.name << endl;
    // // cout << "ramesh Health: " << ramesh.health << endl;
    // cout << "ramesh Health: " << ramesh.getHealth() << endl;
    // // cout << "ramesh Level: " << ramesh.level << endl;
    // cout << "ramesh Level: " << ramesh.getLevel() << endl;

    // dynamic allocation
    Hero *chirag = new Hero();

    chirag->name = "Addi";
    // (*chirag).health = 70;
    chirag->setHealth(70);
    // (*chirag).level = 'A';
    chirag->setLevel('A');
    chirag->print();

    Hero *demoCopy = new Hero(*chirag);
    demoCopy->print();
    delete demoCopy;
    delete chirag;

    return 0;
}