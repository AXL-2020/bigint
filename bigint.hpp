/*Aidan Latessa
Project 1 Milestone 2
CS23001*/

#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <ostream>

constexpr int MAXSIZE  = 200;
constexpr int CAPACITY = MAXSIZE - 1;

class bigint {

    int myInt[MAXSIZE];
    int getStartIndex();
    bool defaultFlag;

public:
    bigint();
    bigint(int);
    bigint(const char[]);

    void debugPrint(std::ostream&)   const;
    friend std::ostream& operator<<(std::ostream&, bigint&);
    std::istream& operator>>(std::istream&);
    bool   operator==(const bigint&) const;
    //bigint& operator=(bigint);
    bool   operator==(int)           const;
    bigint operator+ (const bigint&) const;
    int    operator[](const int)     const;
    

    //bigint& operator*(const bigint&);
    //bigint timesDigit(int) const;
    //bigint times10(int) const;
};

#endif

