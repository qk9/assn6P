#include "Fraction.h"
#include <iostream>
#include <cassert>
using namespace std;

Fraction::Fraction() {
    numerator = 0;
    denom = 1;
}

Fraction::Fraction(int numer, int den) {
    numerator = numer;
    assert(den != 0);
    denom = den;
}

void Fraction::print() {
    cout << numerator << '/' << denom;
}

void Fraction::simplify() {
    int gcf = 1;
    for (int i = 2; i <= numerator / 2; i++) {
        if (numerator % i == 0 && denom % i == 0) {
            gcf = i;
        }
    }
    numerator /= gcf;
    denom /= gcf;
}

Fraction Fraction::addedTo(const Fraction frac2) {
    int sumDenom = denom * frac2.denom;
    int sumNumerator = numerator * frac2.denom;
    sumNumerator += frac2.numerator * denom;
    Fraction sum(sumNumerator, sumDenom);
    sum.simplify();
    return sum;
}

Fraction Fraction::subtract(const Fraction frac2) {
    int sumDenom = denom * frac2.denom;
    int sumNumerator = numerator * frac2.denom;
    sumNumerator -= frac2.numerator * denom;
    Fraction sum(sumNumerator, sumDenom);
    sum.simplify();
    return sum;
}

Fraction Fraction::multipliedBy(const Fraction frac2) {
    int productNumerator = numerator * frac2.numerator;
    int productDenom = denom * frac2.denom;
    Fraction product(productNumerator, productDenom);
    product.simplify();
    return product;
}

Fraction Fraction::dividedBy(const Fraction frac2) {
    int quotientDenom = denom * frac2.numerator;
    int quotientNumerator = numerator * frac2.denom;
    Fraction quotient(quotientNumerator, quotientDenom);
    quotient.simplify();
    return quotient;
}
bool Fraction::isEqualTo(const Fraction frac2) {
    return ((numerator * frac2.denom) == (frac2.numerator * denom));
}

