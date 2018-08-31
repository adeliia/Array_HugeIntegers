#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "array.h"

int main()
{

    Array integers1("9998");
    Array integers2("123");

    cout << "integers is " << integers1 << endl;
    cout << "Size of Array integeral1 is "  << integers1.getSize() << endl;

    cout << "integers is " << integers2 << endl;
    cout << "Size of Array integeral2 is "  << integers2.getSize() << endl;

    cout << integers1 << " + " << integers2 << " = " << integers1 + integers2 << endl;

    Array hugeInt1("1990");
    Array hugeInt2("989");

    cout << "Is hugeInt1 equal to hugeInt2: " << std::boolalpha << (hugeInt1 == hugeInt2) << endl;
    cout << hugeInt1 << " - " << hugeInt2 << " = " << hugeInt1 - hugeInt2 << endl;

    Array hugeInt3("12345");
    Array hugeInt4("15");

    cout << hugeInt3 << " * " << hugeInt4 << " = " << hugeInt3 * hugeInt4 << endl;

    return 0;
}
