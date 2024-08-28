#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define PI 3.14
#define RECTANGLE_AREA(l, b) (l * b)
#define RATIO_CIRCLE_CIRCUMFERENCE PI
#define minimum(a, b) (((a) < (b)) ? (a) : (b))

void getArea(int r);

int main()
{
    int r = 5;
    double area = PI * r * r;
    cout << "area of circle is >> " << area << endl;
    getArea(r);

    area = RATIO_CIRCLE_CIRCUMFERENCE * r * r;
    cout << "area of circle is >> " << area << endl;

    int l = 5, b = 4;
    area = RECTANGLE_AREA(l, b);
    cout << "area of rectangle is >> " << area << endl;

    cout << "minimum of 4 & 5 is " << minimum(4, 5) << endl;

    return 0;
}

void getArea(int r)
{
    double area = PI * r * r;
    cout << "area of circle is >> " << area << endl;
}