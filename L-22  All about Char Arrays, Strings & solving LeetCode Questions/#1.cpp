#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int len(char str[])
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

    // name[2] = '\0';

    cout << "My Name Is " << name << endl;

    cout << "Length of string " << len(name) << endl;
    return 0;
}