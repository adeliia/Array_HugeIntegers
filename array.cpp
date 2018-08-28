#include <iostream>
using std::cout;
using std::endl;

#include <cctype>
using std::isdigit;

#include <cstring>
using std::strlen;

#include "array.h"

Array::Array(unsigned int arraySize) {
    size = (arraySize > 0 ? arraySize : 10);
    ptr = new int[arraySize];

    for (unsigned int i=0; i < size; i++)
        ptr[i]  = 0;
}

//Array::Array(const Array &arrayToCopy)
//    :size(arrayToCopy.size) {
//    ptr = new int[size];

//    for (unsigned int i=0; i < size; i++)
//        ptr[i] = arrayToCopy.ptr[i];
//}

Array::Array(const char * string)
    :size(strlen(string))
{
    ptr = new int[size];

    for (unsigned int j = 0, k = 0; j <= strlen(string); j++, k++) {
        if (isdigit(string[k]))
            ptr[j] = string[k] - '0';
    }
}

Array::~Array(){
    delete [] ptr;
}

unsigned int Array::getSize() const {
    return size;
}

unsigned int getLongerLength(const Array *a1, const Array &a2) {
    return (a1->getSize() <= a2.getSize() ? a1->getSize() : a2.getSize());
}

// Array + Arrays
Array Array::operator+(const Array &op2) const {
    unsigned int tempLength = (getLongerLength(this, op2) + 1);
//    cout << "tempLength = " << tempLength << "\n";
    Array temp(tempLength);

//    cout << temp << endl;
    int carry = 0;

    if (this->getSize() == op2.getSize()) {
        for (int i = static_cast<int>(tempLength); i > 0; i-- ) {
//            cout << "carry " << carry << endl;
            temp.ptr[i] = (static_cast<int>(this->getSize())>(i-1)? this->ptr[i-1]: 0)
                    +  (static_cast<int>(op2.getSize()) >(i-1) ? op2.ptr[i-1] : 0) + carry;
//            cout << temp << endl;
            if(temp.ptr[i] > 9) {
                temp.ptr[i] %= 10;
//                cout << "\ngot here\n";
                carry = 1;
            } else {
                carry = 0;
            }
        }
    }
    if (carry == 1)
        temp.ptr[0] = 1;

    return temp;
}


const Array &Array::operator=(const Array &right) {
    if (&right != this){
        if(size != right.size) {
            delete [] ptr;
            size = right.size;
            ptr = new int[size];
        }
        for (unsigned int i = 0; i < size; i++)
            ptr[i] = right.ptr[i];
    }
    return *this;
}

bool Array::operator==(const Array &right) const {
    if(size != right.size)
        return false;
    for (unsigned int i = 0; i < size; i++)
        if (ptr[i] != right.ptr[i])
            return false;
    return true;
}



//istream &operator>> ( istream &input, Array &a) {
//    for (unsigned int i = 0; i < a.size; i++)
//        input >> a.ptr[i];
//    return input;
//}

ostream &operator<< ( ostream &output, const Array &num) {
    unsigned int i;
    for (i=0; i < num.size; i++)
        output << num.ptr[i];

    return  output;
}
