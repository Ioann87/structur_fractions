#include <cmath>
#include <fract.h>
#include <iomanip>
#include <iostream>
using namespace std;

void init_fract(Fraction& fract)
{
    cin >> fract.numerator;
    cout << "---" << endl;
    cin >> fract.denominator;
    return;
}

void addition(Fraction fract[3])
{
    int numer = 0;
    int denom = 0;
    if (fract[0].denominator == fract[1].denominator) {
        fract[2].numerator = fract[0].numerator + fract[1].numerator;
        fract[2].denominator = fract[0].denominator;
    } else {
        numer = fract[0].numerator * fract[1].denominator;
        denom = fract[0].denominator * fract[1].denominator;
        fract[2].numerator += numer;
        fract[2].denominator = denom;
        numer = fract[1].numerator * fract[0].denominator;
        fract[2].numerator += numer;
    }
    return;
}

void subtraction(Fraction fract[3])
{
    int numer = 0;
    int denom = 0;

    if (fract[0].denominator == fract[1].denominator) {
        fract[2].numerator = fract[0].numerator - fract[1].numerator;
        fract[2].denominator = fract[0].denominator;
    } else {
        numer = fract[0].numerator * fract[1].denominator;
        denom = fract[0].denominator * fract[1].denominator;
        fract[2].numerator += numer;
        fract[2].denominator = denom;
        numer = fract[1].numerator * fract[0].denominator;
        fract[2].numerator -= numer;
    }
    return;
}

void multiply(Fraction fract[3])
{
    fract[2].numerator = fract[0].numerator * fract[1].numerator;
    fract[2].denominator = fract[0].denominator * fract[1].denominator;
    return;
}

void division(Fraction fract[3])
{
    fract[2].numerator = fract[0].numerator * fract[1].denominator;
    fract[2].denominator = fract[0].denominator * fract[1].numerator;
    return;
}

void fract_reduction(int& num, int& denom)
{
    int divisor = gcd(num, denom);
    if (divisor != 0) {
        num /= divisor;
        denom /= divisor;
    }
    return;
}

int gcd(int& num, int& denom)
{
    int a = 0;
    int b = 0;
    int temp = 0;
    if (num > denom) {
        a = abs(num);
        b = abs(denom);
    } else if (num < denom) {
        a = abs(denom);
        b = abs(num);
    }
    while (a != b) {
        if (a > b) {
            temp = a;
            a = b;
            b = temp;
        }
        b = b - a;
    }
    return a;
}

void output_fract(Fraction fract[3], char operation)
{
    cout << setw(2) << fract[0].numerator
         << setw(7) << fract[1].numerator
         << setw(9) << fract[2].numerator << endl;
    cout << "----" << setw(2) << operation
         << " ----" << setw(5) << " = "
         << "----" << endl;
    cout << setw(2) << fract[0].denominator
         << setw(7) << fract[1].denominator
         << setw(9) << fract[2].denominator << endl;
    return;
}
