#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "array.h"
#include "devidebyzeroexception.h"

int main()
{
    try {
        LongInt int1 ("20060");
        LongInt int2 ("20020");
        LongInt int3 ("4000000000000000000000000");
        LongInt int4 ("-100000000000000000000000");
        LongInt int5 ("-10");
        LongInt int6 ("9999999999999");
        LongInt int7 ("1");
        LongInt int8 ("10000000000000");
        LongInt int9 ("-200000000000000000000000000060");
        LongInt int10 ("6");
        LongInt int11 ("-146");
        LongInt int0 ("0");


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
        cout << "int0 "<< int0 << endl;
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
        cout << int10 << " + " << int0 << " = " << int10 + int0 << endl;
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
        cout << int10 << " - " << int0 << " = " << int10 - int0 << endl;
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
        cout << int10 << " * " << int0 << " = " << int10 * int0 << endl;
        cout << endl;


        cout << "Division test:\n";

        LongInt num1("1000050");
        LongInt num2("500000");
        LongInt num3("-500");
        LongInt num4("-500");
        LongInt num5("500000");
        LongInt num6("-12500");
        LongInt num7("-1234500");
        LongInt num8("-12345");
        LongInt num10("2000000000000000000000000040");
        LongInt num11("-50000000000000000000000500");
        LongInt num9("0");

        cout << num1 << " / " << num2 << " = ";
        auto res1 = num1/num2;
        cout << res1.first << " (rem = " << res1.second << ")"<< endl;

        cout << num2 << " / " << num3 << " = ";
        auto res2 = num2/num3;
        cout << res2.first << " (rem = " << res2.second << ")"<< endl;

        cout << num3 << " / " << num4 << " = ";
        auto res3 = num3/num4;
        cout << res3.first << " (rem = " << res3.second << ")"<< endl;

        cout << num4 << " / " << num5 << " = ";
        auto res4 = num4/num5;
        cout << res4.first << " (rem = " << res4.second << ")"<< endl;

        cout << num5 << " / " << num6 << " = ";
        auto res5 = num5/num6;
        cout << res5.first << " (rem = " << res5.second << ")"<< endl;

        cout << num6 << " / " << num7 << " = ";
        auto res6 = num6/num7;
        cout << res6.first << " (rem = " << res6.second << ")"<< endl;

        cout << num7 << " / " << num8 << " = ";
        auto res7 = num7/num8;
        cout << res7.first << " (rem = " << res7.second << ")"<< endl;

        cout << num10 << " / " << num11 << " = ";
        auto res9 = num10/num11;
        cout << res9.first << " (rem = " << res9.second << ")"<< endl;

        cout << num8 << " / " << num9 << " = ";
        auto res8 = num8/num9;
        cout << res8.first << " (rem = " << res8.second << ")"<< endl;

    }
    catch (const DivideByZeroException& divideByZeroException) {
        cout << "\nException occurred: "
           << divideByZeroException.what() << endl;
    }

    return 0;
}
