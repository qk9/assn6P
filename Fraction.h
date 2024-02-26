#ifndef FRACTION_H

class Fraction {
public:
    Fraction();
    Fraction(int numer, int den);
    Fraction addedTo(const Fraction frac2);
    Fraction subtract(const Fraction frac2);
    Fraction multipliedBy(const Fraction frac2);
    Fraction dividedBy(const Fraction frac2);
    bool isEqualTo(const Fraction frac2);
    void print();
private:
    int numerator;
    int denom;
    void simplify();
};

#endif
