#include <iostream>
using namespace std;

int main()
{
    cout << "Namaste Dunia :-) " << endl;

    int a = 123;
    cout << "a = " << a << endl;

    char b = 'v';
    cout << "b = " << b << " && sizeof(char) = " << sizeof(char) << " byte" << endl;

    bool c = true;
    cout << "c = " << c << " && sizeof(bool) = " << sizeof(bool) << " byte" << endl;

    float d = 1.23;
    cout << "d = " << d << " && sizeof(float) = " << sizeof(float) << " byte" << endl;

    double e = 1.23;
    cout << "e = " << e << " && sizeof(double) = " << sizeof(double) << " byte" << endl;

    // Type Cast

    int f = 'a';
    cout << f << endl;

    char g = 97;
    cout << g << endl;

    unsigned int h = 123456789;
    cout << "h = " << h << " && sizeof(unsigned int) = " << sizeof(unsigned int) << " byte" << endl;
}