#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int getLength(char str[])
{
    int count = 0;
    int i = 0;

    while (str[i] != '\0')
    {
        count++;
        i++;
    }
    return count;
}
int main()
{
    char name[20];
    cout << "Enter name : ";
    cin >> name;
    cout << "My Name Is " << name << endl;

    cout << "Length of string " << getLength(name) << endl;
    return 0;
}