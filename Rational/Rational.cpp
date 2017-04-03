//
//  Rational.cpp
//  Rational
//
//  Created by Alexey Karpov on 21.03.17.
//  Copyright © 2017 Alexey Karpov. All rights reserved.
//

#include "Rational.hpp"

using namespace std;

void Rational::reduce() {
    int newnom = abs(this->num);
    int newden = this->den;
    while (newnom != 0 && newden != 0) {
        if (newnom > newden) {
            newnom = newnom % newden;
        }
        else {
            newden = newden % newnom;
        }
    }
    this->num /= newnom + newden;
    this->den /= newnom + newden;
}
void Rational::assign(const char *str) {
    int num = 0;
    int i = 0;
    int sign = 1;
    while (str[i] != '/' && str[i] != 0) {
        if (str[i] == '-') {
            sign = -1;
        }
        else {
            num = num * 10 + str[i] - '0';
        }
        i++;
    }
    int den = 0;
    if (str[i] == 0) {
        den = 1;
    }
    else {
        i++;
        while (str[i] != 0) {
            den = den * 10 + str[i] - '0';
            i++;
        }
    }
    this->num = num * sign;
    this->den = den;
}
void Rational::assign(const Rational &that){
    this->num = that.num;
    this->den = that.den;
}
void Rational::assign(const int num, const int den){
    this->num = abs(num);
    this->den = abs(den);
    if (num * den < 0)
    {
        this->num *= -1;
    }
    reduce();
}


Rational::Rational(const int num, const int den){
    assign(num, den);
}
Rational::Rational(const Rational &that){
    assign(that);
}
Rational::Rational(const char *str){
    assign(str);
}
Rational::Rational()
{
    this->num = 0;
    this->den = 1;
}
int Rational::getNumerator() const{
    return this->num;
}
int Rational::getDenominator() const {
    return this->den;
}

istream &operator>>(istream &in, Rational &rat)
{
    char str[1001];
    in >> str;
    rat.assign(str);
    return in;
}
ostream &operator<<(ostream &out, const Rational &rat)
{
    if (rat.den == 1)
    {
        out << rat.num;
    } else {
        out << rat.num << "/" << rat.den;
    }
    return out;
}


Rational Rational::operator+(const Rational &that) const
{
    Rational res;
    res.num = this->num * that.den + this->den * that.num;
    res.den = this->den * that.den;
    res.reduce();
    return res;
}
Rational Rational::operator+(const int val) const
{
    return *this + Rational(val);
}
Rational operator+(const int val, const Rational &rat)
{
    return Rational(val) + rat;
}
Rational Rational::operator-(const Rational &that) const
{
    Rational newthat(that);
    newthat.num *= -1;
    return *this + newthat;
}
Rational Rational::operator-(const int val) const
{
    return *this - Rational(val);
}
Rational operator-(const int val, const Rational &rat)
{
    return Rational(val) - rat;
}
Rational Rational::operator*(const Rational &that) const
{
    Rational res;
    res.num = this->num * that.num;
    res.den = this->den * that.den;
    res.reduce();
    return res;
}
Rational Rational::operator*(const int val) const
{
    return *this * Rational(val);
}
Rational operator*(const int val, const Rational &rat)
{
    return Rational(val) * rat;
}
Rational Rational::operator/(const Rational &that) const
{
    if (that.num == 0) {
        throw RationalDivisionByZero();
    }
    Rational res;
    res.num = this->num * that.den;
    res.den = this->den * that.num;
    if (res.den < 0)
    {
        res.num *= -1;
        res.den *= -1;
    }
    res.reduce();
    return res;
}
Rational Rational::operator/(const int val) const
{
    return *this / Rational(val);
}
Rational operator/(const int val, const Rational &rat)
{
    return Rational(val) / rat;
}
Rational &Rational::operator=(const Rational &that)
{
    assign(that);
    return *this;
}
Rational &Rational::operator=(const int val)
{
    assign(val);
    return *this;
}
Rational &Rational::operator+=(const Rational &that)
{
    *this = *this + that;
    return *this;
}
Rational &Rational::operator+=(const int val)
{
    *this = *this + val;
    return *this;
}
Rational &Rational::operator-=(const Rational &that)
{
    *this = *this - that;
    return *this;
}
Rational &Rational::operator-=(const int val)
{
    *this = *this - val;
    return *this;
}
Rational &Rational::operator*=(const Rational &that)
{
    *this = *this * that;
    return *this;
}
Rational &Rational::operator*=(const int val)
{
    *this = *this * val;
    return *this;
}
Rational &Rational::operator/=(const Rational &that)
{
    *this = *this / that;
    return *this;
}
Rational &Rational::operator/=(const int val)
{
    *this = *this / val;
    return *this;
}
int Rational::compration(const Rational &that) const
{
    int thisnum = this->num * that.den;
    int thatnum = that.num * this->den;
    if (thisnum > thatnum)
    {
        return -1;
    } else {
        if (thatnum > thisnum) {
            return 1;
        } else {
            return 0;
        }
    }
}
bool Rational::operator>(const Rational &that) const
{
    bool flag = false;
    if (compration(that) == -1)
    {
        flag = true;
    }
    return flag;
}
bool Rational::operator>(const int val) const
{
    return *this > Rational(val);
}
bool operator>(const int val, const Rational &rat)
{
    return Rational(val) > rat;
}
bool Rational::operator<(const Rational &that) const
{
    bool flag = false;
    if (compration(that) == 1)
    {
        flag = true;
    }
    return flag;
}
bool Rational::operator<(const int val) const
{
    return *this < Rational(val);
}
bool operator<(const int val, const Rational &rat)
{
    return Rational(val) < rat;
}
bool Rational::operator==(const Rational &that) const
{
    bool flag = false;
    if (compration(that) == 0)
    {
        flag = true;
    }
    return flag;
}
bool Rational::operator==(const int val) const
{
    return *this == Rational(val);
}
bool operator==(const int val, const Rational &rat)
{
    return Rational(val) == rat;
}
bool Rational::operator!=(const Rational &that) const
{
    return !(*this == that);
}
bool Rational::operator!=(const int val) const
{
    return !(*this == val);
}
bool operator!=(const int val, const Rational &rat)
{
    return !(val == rat);
}
bool Rational::operator>=(const Rational &that) const
{
    if (*this == that || *this > that)
    {
        return true;
    } else {
        return false;
    }
}
bool Rational::operator>=(const int val) const
{
    if (*this == val || *this > val)
    {
        return true;
    } else {
        return false;
    }
}
bool operator>=(const int val, const Rational &rat)
{
    if (val == rat || val > rat)
    {
        return true;
    } else {
        return false;
    }
}
bool Rational::operator<=(const Rational &that) const
{
    if (*this == that || *this < that)
    {
        return true;
    } else {
        return false;
    }
}
bool Rational::operator<=(const int val) const
{
    if (*this == val || *this < val)
    {
        return true;
    } else {
        return false;
    }
}
bool operator<=(const int val, const Rational &rat)
{
    if (val == rat || val < rat)
    {
        return true;
    } else {
        return false;
    }
}
Rational operator-(const Rational &val)
{
    Rational res(val);
    res.num *= (-1);
    return res;
}
Rational operator+(const Rational &val)
{
    Rational res(val);
    return res;
}
Rational &Rational::operator++() {
    this->num += this->den;
    return *this;
}

Rational Rational::operator++(int) {
    Rational old(*this);
    ++*this;
    return old;
}

Rational &Rational::operator--() {
    this->num -= this->den;
    return *this;
}

Rational Rational::operator--(int) {
    Rational old(*this);
    --*this;
    return old;
}




RationalDivisionByZero::RationalDivisionByZero(): logic_error("error") {}
