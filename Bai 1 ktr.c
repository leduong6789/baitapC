#include <stdio.h>

// Ð?nh nghia ki?u d? li?u s? ph?c
typedef struct {
    int a;
    int b;
} Complex;

// Hàm nhân hai s? ph?c
Complex multiply_complex(Complex a, Complex b) {
    Complex result;
    result.a = a.a * b.a - a.b * b.b;
    result.b = a.a * b.b + a.b * b.a;
    return result;
}

// Hàm d? quy d? nhân t?t c? các s? ph?c trong m?ng C
Complex multiply_complex_array(Complex C[], int n) {
    if (n == 1) {
        return C[0];
    } else {
        // Ð? quy nhân (n-1) s? ph?c d?u tiên
        Complex result = multiply_complex(C[n-1], multiply_complex_array(C, n-1));
        return result;
    }
}

int main() {
    // Ví d? s? d?ng
    Complex C[] = {{2, 1}, {2, 3}};
    int n = sizeof(C) / sizeof(C[0]);
    Complex result = multiply_complex_array(C, n);
    printf("%d + %di\n", result.a, result.b);
    return 0;
}
