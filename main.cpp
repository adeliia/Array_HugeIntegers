#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "array.h"

int main()
{

    Array integer1("9998");
    Array integer2("123");

    cout << "integer1 is " << integer1 << endl;
    cout << "Size of Array integeral1 is "  << integer1.getSize() << endl << endl;

    cout << "integer2 is " << integer2 << endl;
    cout << "Size of Array integeral2 is "  << integer2.getSize() << endl << endl;

    cout << integer1 << " + " << integer2 << " = " << integer1 + integer2 << endl << endl;

    Array hugeInt1("2999");
    Array hugeInt2("1259");
    Array hugeInt3("199123450");
    Array hugeInt4("199123450");

    cout << "Is " << hugeInt1 << " equal to " <<
                  hugeInt2 << ": " << std::boolalpha << (hugeInt1 == hugeInt2) << endl;
    cout << "Is " << hugeInt3 << " equal to " <<
                  hugeInt4 << ": " << std::boolalpha << (hugeInt3 == hugeInt4) << endl;
    cout << endl;

    cout << hugeInt1 << " - " << hugeInt2 << " = " << hugeInt1 - hugeInt2 << endl;
    cout << endl;

    Array hugeInt5("12345");
    Array hugeInt6("2195");

    cout << hugeInt5 << " * " << hugeInt6 << " = " << hugeInt5 * hugeInt6 << endl;
    cout << endl;

    Array hugeInt7("369");
    Array hugeInt8("123");

//    cout << hugeInt7 << " / " << hugeInt8 << " = " << hugeInt7 / hugeInt8 << endl;
    cout << endl;

//    cout << hugeInt7 << " < " <<
                  hugeInt8 << ": " << std::boolalpha << (hugeInt7 < hugeInt8) << endl;
//    cout << hugeInt8 << " < " <<
                  hugeInt7 << ": " << std::boolalpha << (hugeInt8 < hugeInt7) << endl;
    cout << endl;



    return 0;
}
