#include <iostream>

using namespace std;
#include "array.h"

int main()
{
    Array integers1(7);
    Array integers2;

    cout << "Size of Arra integeral1 is"  << integers1.getSize() <<
            "\nArray after init:\n" << integers1;

    cout << "Size of Arra integeral2 is"  << integers2.getSize() <<
            "\nArray after init:\n" << integers2;

    cout << "\nEnter 17 integers:" << endl;
    cin >> integers1 >> integers2;

    cout << "\nAfter input:\n"
            << "integeral1:\n "  << integers1
            << "integeral2:\n" << integers2;

    cout << "\nEvaluating: integers1 != integers2" << endl;

    if (integers1 != integers2)
        cout << "Integers are not equal\n";

    Array integers3(integers1);

    cout << "\nSize od Array integers3 is " << integers3.getSize()
         << "\nArray after init:\n" << integers3;

    cout << "\nAssigning integers2 to integers1:" << endl;
    integers1 = integers2;

    cout << "integers1:\n" << integers1
         << "integers2:\n" << integers2;
    cout << "\nEvaluating: integers1 == integers2" << endl;
    cout << "integers1 and integers2 are equal" << endl;

    cout << "\nintegers1[5] is " << integers1[5];

    cout << "\nAssigning 1000 to integers1[5]" << endl;
    integers1[5] = 1000;
    cout << "integers1:\n" << integers1;

    cout << "\nATtempt to assign 1000 to integers1[15" << endl;
    integers1[15] = 1000;


    return 0;
}
