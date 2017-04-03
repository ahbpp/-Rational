//
//  main.cpp
//  Rational
//
//  Created by Alexey Karpov on 21.03.17.
//  Copyright © 2017 Alexey Karpov. All rights reserved.
//

#include <iostream>
#include "Rational.hpp"

using namespace std;

int main(int argc, char** argv) {
    int a;
    cin >> a;
    
    int p, q;
    cin >> p >> q;
    const Rational rc(p, q);
    cout << rc.getNumerator() << ' ' << rc.getDenominator() << endl;
    
    Rational r1, r2;
    cin >> r1 >> r2;
    
    cout << r1 << endl;
    cout << r2 << endl;
    
    try {
        cout << 1/r1 << endl;
    } catch (const RationalDivisionByZero& ex) {
        cout << "Cannot get reciprocal of r1." << endl;
    }
    
    try {
        cout << rc/r2 << endl;
    } catch (const RationalDivisionByZero& ex) {
        cout << "Cannot divide by r2." << endl;
    }
    
    cout << (r1 < r2) << endl;
    cout << (r1 <= r2) << endl;
    cout << (r1 > r2) << endl;
    cout << (r1 >= r2) << endl;
    cout << (r1 == r2) << endl;
    cout << (r1 != r2) << endl;
    
    cout << (r1 < a) << endl;
    cout << (r1 <= a) << endl;
    cout << (r1 > a) << endl;
    cout << (r1 >= a) << endl;
    cout << (r1 == a) << endl;
    cout << (r1 != a) << endl;
    
    cout << (a < r2) << endl;
    cout << (a <= r2) << endl;
    cout << (a > r2) << endl;
    cout << (a >= r2) << endl;
    cout << (a == r2) << endl;
    cout << (a != r2) << endl;
    
    cout << rc + a << endl
    << a + rc << endl
    << -rc * r1 << endl
    << (+r1 - r2 * rc) * a << endl;
    
    cout << ++r1 << endl;
    cout << r1 << endl;
    cout << r1++ << endl;
    cout << r1 << endl;
    cout << --r1 << endl;
    cout << r1 << endl;
    cout << r1-- << endl;
    cout << r1 << endl;
    cout << ++++r1 << endl;
    cout << r1 << endl;
    
    cout << ((((r1 += r2) /= Rational(-5,3)) -= rc) *= a) << endl;
    cout << (r1 += r2 /= 3) << endl;
    cout << r1 << endl;
    cout << r2 << endl;
    return 0;
}
