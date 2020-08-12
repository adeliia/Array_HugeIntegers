#include <iostream>
using std::cout;
using std::endl;

#include <cctype>
using std::isdigit;

#include <cstring>
using std::strlen;

#include <cmath>

#include "array.h"

LongInt::LongInt(unsigned int arraySize) {
    size = (arraySize > 0 ? arraySize : 10);
    ptr = new int[arraySize];
    this->sign = 1;
    for (unsigned int i=0; i < size; i++)
        ptr[i]  = 0;
}

LongInt::LongInt(const char * string)
    :size(strlen(string)),sign(1)
{
    ptr = new int[size];
    this->sign = 1;
    for (int j = static_cast<int>(strlen(string))-1, k = 0; j >= 0; j--, k++) {
        if (string[k] == '-') {
            this->sign = -1;
            j = static_cast<int>(strlen(string))-1;
        }
        else {
            if(isdigit(string[k]))
                ptr[j] = string[k] - '0';
        }
    }
}

LongInt::~LongInt(){
    delete [] ptr;
}

int LongInt::getSign() const {
    return sign;
}

unsigned int LongInt::getSize() const {
    return size;
}

unsigned int getLongerLength(const LongInt *a1, const LongInt &a2) {
    return (a1->getSize() >= a2.getSize() ? a1->getSize() : a2.getSize());
}

bool LongInt::isBiggerByAbs(const LongInt & op2) const {
    // if this' size is longer than op2's
    if(this->getSize() > op2.getSize()){return true;}
    else
        // if this' size is equal to op2's
        if (this->getSize() == op2.getSize()){
            for (int i=this->getSize()-1; i >= 0 ; i--) {
                if (this->ptr[i] > op2.ptr[i]) {return true;}
                else if (this->ptr[i] < op2.ptr[i]) {return false;}
            }
        }
        // if op2's size is bigger
        else {return false;}
    // if the compared numbers are equal, there is no difference in the order
    return true;
}

LongInt LongInt::_plus(const LongInt &op2, int sign) const {
    unsigned int tempLength = (getLongerLength(this, op2) + 1);
    int thisSize = static_cast<int>(this->getSize());
    int op2Size = static_cast<int>(op2.getSize());

    // if any of any of integers are negative ignore the '-' in the string
    if (this->getSign()==-1) {thisSize-=1;}
    if (op2.getSign()==-1) {op2Size-=1;}

    LongInt temp(tempLength);
    temp.sign = sign;
    int carry = 0;

    for (int i = 0,j = 0, k = 0;
        i < static_cast<int>(tempLength); i++, j++, k++ ) {
        temp.ptr[i] = ( j < thisSize ? this->ptr[j] : 0)
                    +  (k < op2Size ? op2.ptr[k] : 0) + carry;
        if(temp.ptr[i] > 9) {
            temp.ptr[i] %= 10;
            carry = 1;
        } else { carry = 0;}
        }
        if (carry == 1)
            temp.ptr[0] = 1;
    return temp;
}

LongInt LongInt::_minus(const LongInt &op2, int sign) const {
    unsigned int tempLength = (getLongerLength(this, op2));
    int thisSize = static_cast<int>(this->getSize());
    int op2Size = static_cast<int>(op2.getSize());

    // if any of any of integers are negative ignore the '-' in the string
    if (this->getSign()==-1) {thisSize-=1;}
    if (op2.getSign()==-1) {op2Size-=1;}

    LongInt temp(tempLength);
    temp.sign = sign;
    int carry = 0;

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

LongInt LongInt::operator+(const LongInt &op2) const {
    // *this >= 0
    if (this->getSign()==1) {
        // op2 >= 0
        if (op2.getSign()==1) {return (*this)._plus(op2,1);}
        // op2 < 0
        else
            if (this->isBiggerByAbs(op2)) {return (*this)._minus(op2,1);}
            else {return op2._minus(*this,-1);}
    }
    // *this < 0
    else {
        // op2 < 0
        if (op2.getSign()==-1) {return (*this)._plus(op2,-1);}
        // op2 >= 0
        else
            if (this->isBiggerByAbs(op2)) {return (*this)._minus(op2,-1);}
            else {return op2._minus(*this,1);}
    }
}

LongInt LongInt::operator-(const LongInt &op2) const {
    // *this >= 0
    if (this->getSign()==1) {
        // op2 >= 0
        if (op2.getSign()==-1) {return (*this)._plus(op2,1);}
        // op2 < 0
        else
            if (this->isBiggerByAbs(op2)) {return (*this)._minus(op2,1);}
            else {return op2._minus(*this,-1);}
    }
    // *this < 0
    else {
        // op2 < 0
        if (op2.getSign()==1) {return (*this)._plus(op2,-1);}
        // op2 >= 0
        else
            if (this->isBiggerByAbs(op2)) {return (*this)._minus(op2,-1);}
            else {return op2._minus(*this,1);}
    }
}

LongInt LongInt::operator*(const LongInt &op2) const {
    unsigned int tempSize = this->getSize() * op2.getSize();
    int thisSize = static_cast<int>(this->getSize());
    int op2Size = static_cast<int>(op2.getSize());

    // if any of any of integers are negative ignore the '-' in the string
    if (this->getSign()==-1) {thisSize-=1;}
    if (op2.getSign()==-1) {op2Size-=1;}

    LongInt temp (tempSize);

    // the sign
    if ((this->getSign()==-1 && op2.getSign()==-1)||
         (this->getSign()==1 && op2.getSign()==1)) {
        temp.sign = 1;
    }
    else temp.sign = -1;

    for (int j = 0; j < thisSize; j++) {
        for (int k = 0; k < op2Size; k++) {
            temp.ptr[j + k] += this->ptr[j] * op2.ptr[k];
            // carry
            if (temp.ptr[j + k] > 9) {
                temp.ptr[j + k + 1] += temp.ptr[j + k]/10;
                temp.ptr[j + k] %= 10;
            }

        }
    }
    return temp;
}


ostream &operator<<( ostream &output, const LongInt &num) {
    int i;
    int start = static_cast<int>(num.size)-1;
    if (num.getSign()==-1) {
        start = start-1;
        output << "-";
    }
    // skip the first zeros
    for (i = start; num.ptr[i] == 0; i-- ){};

    if (i > 0)
        for ( ; i >= 0; i--) {output << num.ptr[i];}
    else output << num.ptr[0];

    return  output;
}
