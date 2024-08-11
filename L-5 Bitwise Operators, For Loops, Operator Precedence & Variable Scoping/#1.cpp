#include <iostream>
using namespace std;

int main()
{
    int a = 4;
    int b = 6;

    cout << "Bitwise Operator(AND(&), OR(|), NOT(~) & XOR(^))" << endl;
    // 1 0 0 => 4
    // 1 1 0 => 6
    // 1 0 0 => 4
    cout << "a & b = " << (a & b) << endl;

    // 1 0 0 => 4
    // 1 1 0 => 6
    // 1 1 0 => 6
    cout << "a | b = " << (a | b) << endl;

    //  0 0 0 0 0 1 0 0 => 4
    //~ 1 1 1 1 1 0 1 1 => (-)(Negative)
    //~ 0 0 0 0 0 1 0 0 => 1's (-)(Negative)
    //+               1 => 2's
    //  0 0 0 0 0 1 0 1 => -5
    cout << "~a = " << (~a) << endl;

    //  0 0 0 0 0 1 1 0 => 6
    //  1 1 1 1 1 0 0 1 => (-)(Negative)
    //  0 0 0 0 0 1 1 0 => 1's Compliment
    //+               1 => 2's Compliment
    //  0 0 0 0 0 1 1 1 => -7
    cout << "~b = " << (~b) << endl;

    // 1 0 0 => 4
    // 1 1 0 => 6
    // 0 1 0 => 2
    cout << "a ^ b = " << (a ^ b) << endl;

    cout << "Left & Right Shift" << endl;
    // Left Shift
    cout << "19 << 1 = " << (19 << 1) << endl; // => 19 * 2 = 38
    cout << "21 << 2 = " << (21 << 2) << endl; // => 21 * 2 * 2 = 42 * 2 = 84

    // Right Shift
    cout << "17 >> 1 = " << (17 >> 1) << endl; // 17 / 2 = 8
    cout << "17 >> 2 = " << (17 >> 2) << endl; // 17 / 4 = 4

    cout << "Pre & Post Increament " << endl;
    int i = 7;
    cout << "++i = " << ++i << endl;
    // i = 7 , ++i = 8
    cout << "i++ = " << i++ << endl;
    // i = 8 , i++ = 8

    // i = 9 , i++ = 8
    cout << "--i = " << --i << endl;
    // i = 8 , i++ = 7
    cout << "i-- = " << i-- << endl;
    return 0;
}