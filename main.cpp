#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "array.h"

int main()
{

    Array integers1("9999");
    Array integers2("1337");

    cout << "integers is " << integers1 << endl;
    cout << "Size of Array integeral1 is "  << integers1.getSize() << endl;

    cout << "integers is " << integers2 << endl;
    cout << "Size of Array integeral2 is "  << integers2.getSize() << endl;

    cout << integers1 << " + " << integers2 << " = " << integers1 + integers2 << endl;



    return 0;
}
