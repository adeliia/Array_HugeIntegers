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

    for (int j = static_cast<int>(strlen(string))-1, k = 0; j >= 0; j--, k++) {
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
    return (a1->getSize() >= a2.getSize() ? a1->getSize() : a2.getSize());
}

// Array + Arrays
Array Array::operator+(const Array &op2) const {
    unsigned int tempLength = (getLongerLength(this, op2) + 1);
    int thisSize = static_cast<int>(this->getSize());
    int op2Size = static_cast<int>(op2.getSize());

    Array temp(tempLength);
    int carry = 0;

        for (int i = 0,j = 0, k = 0;
             i < static_cast<int>(tempLength); i++, j++, k++ ) {
            temp.ptr[i] = ( j < thisSize ? this->ptr[j] : 0)
                    +  (k < op2Size ? op2.ptr[k] : 0) + carry;

            if(temp.ptr[i] > 9) {
                temp.ptr[i] %= 10;
                carry = 1;
            } else {
                carry = 0;
            }
        }

    if (carry == 1)
        temp.ptr[0] = 1;

    return temp;
}

Array Array::operator-(const Array &op2) const {
    unsigned int tempLength = (getLongerLength(this, op2));
    int thisSize = static_cast<int>(this->getSize());
    int op2Size = static_cast<int>(op2.getSize());

    int carry = 0;

    Array temp(tempLength);

    for (int i = 0, j = 0, k = 0;
         i < static_cast<int>(tempLength); i++, j++, k++ ) {

        int a = ( j < thisSize ? this->ptr[j] : 0);
        int b = ( k < op2Size ? op2.ptr[k] : 0);

        if ( a - carry >= b) {
            temp.ptr[i] = (a - carry) - b;
            carry = 0;
        }
        else {
            temp.ptr[i] = (10 + a - carry) - b;
            carry = 1;
        }
    }
    return temp;
}

Array Array::operator*(const Array &op2) const {
    unsigned int tempSize = this->getSize() * op2.getSize();
    int thisSize = static_cast<int>(this->getSize());
    int op2Size = static_cast<int>(op2.getSize());

    Array temp (tempSize);

    int carry = 0;

    for (int j = 0; j < thisSize; j++) {
        for (int k = 0; k < op2Size; k++) {
            temp.ptr[j + k] += this->ptr[j] * op2.ptr[k] + carry ;
            if (temp.ptr[j + k] > 9) {
                carry = temp.ptr[j + k]/10;
                temp.ptr[j + k] %= 10;
            }
            else carry = 0;
        }
    }

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
    int i;

    // skip the first zeros
    for (i = static_cast<int>(num.size)-1; num.ptr[i] == 0; i-- ){};

    if (i > 0)
        for ( ; i >= 0; i--) output << num.ptr[i];
    else cout << 0; // if all of the digits are zero

    return  output;
}
