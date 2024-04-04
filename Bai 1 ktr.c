#include <stdio.h>
#include <stdlib.h> // For abs function

typedef struct {
    int Numerator;
    int Denominator;
} Fractions;

// Hàm tìm ước chung lớn nhất của hai số
int findGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Hàm rút gọn phân số
void ReduceFraction(Fractions *frac) {
    int gcd = findGCD(abs(frac->Numerator), abs(frac->Denominator));
    frac->Numerator /= gcd;
    frac->Denominator /= gcd;
}

// Hàm rút gọn tất cả các phân số trong mảng
void ReduceAllFractions(Fractions lsfrac[], int size) {
    for (int i = 0; i < size; ++i) {
        if (lsfrac[i].Denominator < 0 && lsfrac[i].Numerator <0) {
            ReduceFraction(&lsfrac[i]);
            continue;
        }
        if (lsfrac[i].Denominator < 0) {
            lsfrac[i].Numerator *= -1; // Chuyển tử số thành số âm
            lsfrac[i].Denominator *= -1; // Chuyển mẫu số thành số dương
        }
        ReduceFraction(&lsfrac[i]);
    }
}

// Hàm hiển thị các phân số đã được rút gọn
void DisplayFractions(Fractions lsfrac[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("(%d/%d) ", lsfrac[i].Numerator, lsfrac[i].Denominator);
    }
    printf("\n");
}


