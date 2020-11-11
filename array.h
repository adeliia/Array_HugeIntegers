#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using std::ostream;
using std::istream;
using std::pair;

class LongInt {
    friend ostream &operator<<( ostream &, const LongInt &);
public:
    LongInt(unsigned int = 10);
    LongInt(const char *);
    LongInt(const LongInt &copy);
    ~LongInt();

    unsigned int getSize() const;
    int getSign() const;
    void setSign(int);

    LongInt operator+(const LongInt &) const;
    LongInt operator-(const LongInt &) const;
    LongInt operator*(const LongInt &) const;
    pair<int,LongInt> operator/(const LongInt &) const;
    LongInt operator=(const LongInt &) const;
    bool operator>(const LongInt &) const;

private:
    unsigned int size;
    int *ptr;
    int sign;

    LongInt _plus(const LongInt &a, int sign) const;
    LongInt _minus(const LongInt &a, int sign) const;
    bool isBiggerByAbs(const LongInt &) const;
};

unsigned int getLongerLength(const LongInt a1,const LongInt &a2);

#endif // ARRAY_H
