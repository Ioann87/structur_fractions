#ifndef FRACT_H
#define FRACT_H

struct Fraction {
    int numerator = 0;
    int denominator = 0;
};

void init_fract(Fraction& fract);

void addition(Fraction fract[3]);

void subtraction(Fraction fract[3]);

void multiply(Fraction fract[3]);

void division(Fraction fract[3]);

void fract_reduction(int& num, int& denom);

int gcd(int& num, int& denom);

void output_fract(Fraction fract[3], char operation);

#endif // FRACT_H
