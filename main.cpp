#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "array.h"

int main()
{

    LongInt int1 ("200000000000000000000000000060");
    LongInt int2 ("200000000000000000000000000020");
    LongInt int3 ("40");
    LongInt int4 ("-10000");
    LongInt int5 ("-10");
    LongInt int6 ("9999999999999");
    LongInt int7 ("1");
    LongInt int8 ("10000000000000");
    LongInt int9 ("-200000000000000000000000000060");
    LongInt int10 ("6");
    LongInt int11 ("-146");


    cout << "The integers:\n";
    cout << "int1 "<< int1 << endl;
    cout << "int2 "<< int2 << endl;
    cout << "int3 "<< int3 << endl;
    cout << "int4 "<< int4 << endl;
    cout << "int5 "<< int5 << endl;
    cout << "int6 "<< int6 << endl;
    cout << "int7 "<< int7 << endl;
    cout << "int8 "<< int8 << endl;
    cout << "int9 "<< int9 << endl;
    cout << "int10 "<< int10 << endl;
    cout << "int11 "<< int11 << endl;
    cout << endl;

    cout << "Addition test:\n";
    cout << int1 << " + " << int2 << " = " << int1 + int2 << endl;
    cout << int2 << " + " << int3 << " = " << int2 + int3 << endl;
    cout << int3 << " + " << int4 << " = " << int3 + int4 << endl;
    cout << int4 << " + " << int3 << " = " << int4 + int3 << endl;
    cout << int4 << " + " << int4 << " = " << int4 + int4 << endl;
    cout << int3 << " + " << int3 << " = " << int3 + int3 << endl;
    cout << int4 << " + " << int5 << " = " << int4 + int5 << endl;
    cout << int7 << " + " << int6 << " = " << int7 + int6 << endl;
    cout << int8 << " + " << int6 << " = " << int8 + int6 << endl;
    cout << int9 << " + " << int6 << " = " << int9 + int6 << endl;
    cout << int10 << " + " << int11 << " = " << int9 + int6 << endl;
    cout << endl;

    cout << "Subtraction test:\n";
    cout << int1 << " - " << int2 << " = " << int1 - int2 << endl;
    cout << int2 << " - " << int3 << " = " << int2 - int3 << endl;
    cout << int3 << " - " << int4 << " = " << int3 - int4 << endl;
    cout << int4 << " - " << int3 << " = " << int4 - int3 << endl;
    cout << int4 << " - " << int4 << " = " << int4 - int4 << endl;
    cout << int3 << " - " << int3 << " = " << int3 - int3 << endl;
    cout << int4 << " - " << int5 << " = " << int4 - int5 << endl;
    cout << int7 << " - " << int6 << " = " << int7 - int6 << endl;
    cout << int8 << " - " << int6 << " = " << int8 - int6 << endl;
    cout << int9 << " - " << int6 << " = " << int9 - int6 << endl;
    cout << int10 << " - " << int11 << " = " << int10 - int11 << endl;
    cout << endl;

    cout << "Multiplication test:\n";
    cout << int1 << " * " << int2 << " = " << int1 * int2 << endl;
    cout << int2 << " * " << int3 << " = " << int2 * int3 << endl;
    cout << int3 << " * " << int4 << " = " << int3 * int4 << endl;
    cout << int4 << " * " << int3 << " = " << int4 * int3 << endl;
    cout << int4 << " * " << int4 << " = " << int4 * int4 << endl;
    cout << int3 << " * " << int3 << " = " << int3 * int3 << endl;
    cout << int4 << " * " << int5 << " = " << int4 * int5 << endl;
    cout << int7 << " * " << int6 << " = " << int7 * int6 << endl;
    cout << int8 << " * " << int6 << " = " << int8 * int6 << endl;
    cout << int9 << " * " << int6 << " = " << int9 * int6 << endl;
    cout << int10 << " * " << int11 << " = " << int10 * int11 << endl;
    cout << endl;

    cout << "Multiplication test:\n";
    cout << int1 << " * " << int2 << " = " << int1 * int2 << endl;
    cout << int2 << " * " << int3 << " = " << int2 * int3 << endl;
    cout << int3 << " * " << int4 << " = " << int3 * int4 << endl;
    cout << int4 << " * " << int3 << " = " << int4 * int3 << endl;
    cout << int4 << " * " << int4 << " = " << int4 * int4 << endl;
    cout << int3 << " * " << int3 << " = " << int3 * int3 << endl;
    cout << int4 << " * " << int5 << " = " << int4 * int5 << endl;
    cout << int7 << " * " << int6 << " = " << int7 * int6 << endl;
    cout << int8 << " * " << int6 << " = " << int8 * int6 << endl;
    cout << int9 << " * " << int6 << " = " << int9 * int6 << endl;
    cout << int10 << " * " << int11 << " = " << int10 * int11 << endl;
    cout << endl;

    return 0;
}
