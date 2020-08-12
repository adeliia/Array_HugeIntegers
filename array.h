#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using std::ostream;
using std::istream;

class LongInt {
    friend ostream &operator<<( ostream &, const LongInt &);
public:
    LongInt(unsigned int = 10);
    LongInt(const char *);
    ~LongInt();
    unsigned int getSize() const;

    int getSign() const;

    LongInt _plus(const LongInt &a, int sign) const;
    LongInt _minus(const LongInt &a, int sign) const;
    bool isBiggerByAbs(const LongInt &) const;

    LongInt operator+(const LongInt &) const;
    LongInt operator-(const LongInt &) const;
    LongInt operator*(const LongInt &) const;
    int operator/(const LongInt &) const;

    const LongInt &operator=(const LongInt &);
    bool operator==( const LongInt &) const;

    bool operator!=( const LongInt &right) const {
        return ! (*this == right);
    }

private:
    unsigned int size;
    int *ptr;
    int sign;
};

unsigned int getLongerLength(const LongInt a1,const LongInt &a2);

#endif // ARRAY_H
