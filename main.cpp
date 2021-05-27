#include <fract.h>
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    Fraction* fractions = new Fraction[3];
    void (*operations[4])(Fraction fract[3]) = {
        addition,
        subtraction,
        multiply,
        division
    };

    for (int i = 0; i < 2; i++) {
        cout << "Enter a fraction - " << i + 1 << endl;
        init_fract(fractions[i]);
    }

    char operation = '\0';
    cout << "Choose operation( +, -, *, / ): ";
    cin >> operation;

    if (operation == '+')
        operations[0](fractions);
    else if (operation == '-')
        operations[1](fractions);
    else if (operation == '*')
        operations[2](fractions);
    else if (operation == '/')
        operations[3](fractions);
    else {
        cout << "incorrect choise";
        exit(0);
    }

    fract_reduction(fractions[2].numerator, fractions[2].denominator);

    output_fract(fractions, operation);

    delete[] fractions;
    system("pause");
    return 0;
}
