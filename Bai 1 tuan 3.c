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
#include <stdio.h>

// Khai báo c?u trúc phân s?
struct Fraction {
    int Numerator;
    int Denominator; // > 0
};

// Hàm tìm u?c chung l?n nh?t c?a hai s?
int findGCD(int a, int b) {
    if (b == 0)
        return a;
    return findGCD(b, a % b);
}

// Hàm rút g?n phân s?
struct Fraction simplifyFraction(struct Fraction frac) {
    int gcd = findGCD(frac.Numerator, frac.Denominator);
    frac.Numerator /= gcd;
    frac.Denominator /= gcd;
    return frac;
}

// Hàm tính t?ng hai phân s?
struct Fraction AddFractions(struct Fraction f1, struct Fraction f2) {
    struct Fraction result;
    result.Numerator = f1.Numerator * f2.Denominator + f2.Numerator * f1.Denominator;
    result.Denominator = f1.Denominator * f2.Denominator;
    return simplifyFraction(result);
}
int count(struct Fraction fracs[],int n,int i){
	if (i >= n)
        return 0;

    // Check if the current fraction is positive
    int current = (fracs[i].Numerator > 0 && fracs[i].Denominator > 0);

    // Recursive case: count positive fractions starting from the next index
    return current + count(fracs, n, i + 1);
}
// Hàm chia hai phân s?
struct Fraction DivideFractions(struct Fraction f1, struct Fraction f2) {
    struct Fraction result;
    result.Numerator = f1.Numerator * f2.Denominator;
    result.Denominator = f1.Denominator * f2.Numerator;
    return simplifyFraction(result);
}

// Hàm tr? giúp d? quy tính giá tr? trung bình c?a các ph?n t? duong trong m?ng phân s?
struct Fraction helper(struct Fraction fracs[], int i, int n) {
    struct Fraction sum = {0, 1}; // Kh?i t?o t?ng ban d?u là 0/1
    int count = 0; // S? lu?ng phân s? duong
    if (i == n) { // N?u dã x? lý h?t các ph?n t? trong m?ng
        if (count == 0) // N?u không có phân s? duong nào, tr? v? 0/1
            return sum;
        else { // Ngu?c l?i, tính giá tr? trung bình và tr? v?
            sum.Denominator *= count; // Nhân m?u s? v?i s? lu?ng phân s? duong
            sum = simplifyFraction(sum); // Rút g?n phân s?
            return sum;
        }
    }
    if (fracs[i].Numerator > 0 && fracs[i].Denominator > 0) { // N?u phân s? là duong
        ++count; // Tang s? lu?ng phân s? duong
        sum = AddFractions(sum, fracs[i]); // C?ng phân s? vào t?ng
    }
    // G?i d? quy d? x? lý ph?n t? ti?p theo trong m?ng
    return AddFractions(sum, helper(fracs, i + 1, n));
}

// Hàm tính giá tr? trung bình c?a các phân s? duong trong m?ng
struct Fraction AvgPosFracArr(struct Fraction fracs[], int n) {
    int x = count(fracs,n,0);
    if(x==0) return (struct Fraction){0,1};
    Fraction s = helper(fracs,0,n);
    s.Denominator *= x;
    return simplifyFraction(s);
}

int main() {
    // Ví d? v? vi?c s? d?ng hàm AvgPosFracArr
    struct Fraction fracs[] = {{-1, 2}, {-2, 3}, {-3, 4}, {4, 5}, {5, 6}};
    int n = sizeof(fracs) / sizeof(fracs[0]);
    struct Fraction avgPosFrac = AvgPosFracArr(fracs, n);
    printf("Average of positive fractions: %d/%d\n", avgPosFrac.Numerator, avgPosFrac.Denominator);
    return 0;
}

