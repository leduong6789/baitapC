#include <stdio.h>

// Define the Fractions structure
typedef struct {
    int Numerator;
    int Denominator;
} Fractions;

// Function to calculate the greatest common divisor (GCD)
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to reduce a fraction
Fractions ReduceFractions(Fractions fraction) {
    int commonDivisor = gcd(fraction.Numerator, fraction.Denominator);
    fraction.Numerator /= commonDivisor;
    fraction.Denominator /= commonDivisor;
    return fraction;
}

// Function to add two fractions
Fractions AddFractions(Fractions f1, Fractions f2) {
    Fractions result;
    result.Numerator = f1.Numerator * f2.Denominator + f2.Numerator * f1.Denominator;
    result.Denominator = f1.Denominator * f2.Denominator;
    return ReduceFractions(result);
}

// Function to subtract two fractions
Fractions SubtractFractions(Fractions f1, Fractions f2) {
    Fractions result;
    result.Numerator = f1.Numerator * f2.Denominator - f2.Numerator * f1.Denominator;
    result.Denominator = f1.Denominator * f2.Denominator;
    return ReduceFractions(result);
}

// Function to multiply two fractions
Fractions MultiplyFractions(Fractions f1, Fractions f2) {
    Fractions result;
    result.Numerator = f1.Numerator * f2.Numerator;
    result.Denominator = f1.Denominator * f2.Denominator;
    return ReduceFractions(result);
}

// Function to divide two fractions
Fractions DivideFractions(Fractions f1, Fractions f2) {
    Fractions result;
    result.Numerator = f1.Numerator * f2.Denominator;
    result.Denominator = f1.Denominator * f2.Numerator;
    return ReduceFractions(result);
}

// Function to perform the desired operation based on the option
Fractions CalculatorFraction(Fractions f1, Fractions f2, int option) {
    switch (option) {
        case 1: // Sum
            return AddFractions(f1, f2);
        case 2: // Subtract
            return SubtractFractions(f1, f2);
        case 3: // Multiply
            return MultiplyFractions(f1, f2);
        case 4: // Divide
            return DivideFractions(f1, f2);
        default:
            printf("Invalid option. Please choose 1, 2, 3, or 4.\n");
            return f1; // Return f1 as a placeholder
    }
}

