#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using std::ostream;
using std::istream;

class Array {
    friend ostream &operator<<( ostream &, const Array &);
//    friend istream &operator>>( istream &, Array &);
public:
    Array(unsigned int = 10);
//    Array(const Array &);
    Array(const char *);
    ~Array();
    unsigned int getSize() const;

    Array operator+(const Array &) const;
    Array operator-(const Array &) const;
    Array operator*(const Array &) const;
    int operator/(const Array &) const;

    const Array &operator=(const Array &);
    bool operator==( const Array &) const;
    bool operator<(const Array &) const;

    bool operator!=( const Array &right) const {
        return ! (*this == right);
    }

private:
    unsigned int size;
    int *ptr;
};

unsigned int getLongerLength(const Array a1,const Array &a2);

#endif // ARRAY_H
