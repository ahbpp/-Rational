//
//  Rational.hpp
//  Rational
//
//  Created by Alexey Karpov on 21.03.17.
//  Copyright © 2017 Alexey Karpov. All rights reserved.
//

#ifndef Rational_hpp
#define Rational_hpp

#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <cstring>
#include <cmath>

using namespace std;

class Rational {
private:
    int num;
    int den;
    void reduce ();
    void assign(const char *);
    void assign(const Rational &that);
    void assign(const int nom, const int den = 1);
    int compration(const Rational &that) const;
    
public:
    Rational(const int nom, const int den = 1);
    Rational(const Rational &that);
    Rational(const char *);
    Rational();
    int getNumerator() const;
    int getDenominator() const;
    friend istream &operator>>(istream &, Rational &);
    friend ostream &operator<<(ostream &, const Rational &);
    Rational operator+(const Rational &) const;
    Rational operator+(const int) const;
    friend Rational operator+(const int, const Rational &that);
    Rational operator-(const Rational &) const;
    Rational operator-(const int) const;
    friend Rational operator-(const int, const Rational &that);
    Rational operator*(const Rational &) const;
    Rational operator*(const int) const;
    friend Rational operator*(const int, const Rational &that);
    Rational operator/(const Rational &) const;
    Rational operator/(const int) const;
    friend Rational operator/(const int, const Rational &that);
    Rational &operator=(const Rational &that);
    Rational &operator=(const int val);
    Rational &operator+=(const Rational &that);
    Rational &operator+=(const int val);
    Rational &operator-=(const Rational &that);
    Rational &operator-=(const int val);
    Rational &operator*=(const Rational &that);
    Rational &operator*=(const int val);
    Rational &operator/=(const Rational &that);
    Rational &operator/=(const int val);
    bool operator>(const Rational &that) const;
    bool operator>(const int val) const;
    friend bool operator>(const int val, const Rational &that);
    bool operator<(const Rational &that) const;
    bool operator<(const int val) const;
    friend bool operator<(const int val, const Rational &that);
    bool operator==(const Rational &that) const;
    bool operator==(const int val) const;
    friend bool operator==(const int val, const Rational &that);
    bool operator!=(const Rational &that) const;
    bool operator!=(const int val) const;
    friend bool operator!=(const int val, const Rational &that);
    bool operator>=(const Rational &that) const;
    bool operator>=(const int val) const;
    friend bool operator>=(const int val, const Rational &that);
    bool operator<=(const Rational &that) const;
    bool operator<=(const int val) const;
    friend bool operator<=(const int val, const Rational &that);
    friend Rational operator-(const Rational &val);
    friend Rational operator+(const Rational &val);
    Rational &operator++();
    Rational operator++(int);
    Rational &operator--();
    Rational operator--(int);
};

class RationalDivisionByZero : logic_error {
public:
    RationalDivisionByZero();
};

#endif /* Rational_hpp */
