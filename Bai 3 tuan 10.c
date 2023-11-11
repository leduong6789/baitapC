#include <stdio.h>

void tinh_von_tich_luy(float p, int n, float r) {
	int i;
    for (i = 1; i <= n; i++) {
        p = p + (p * r / 100);
        printf("Sau %d nam, so tien ban nhan duoc la: %.2f\n", i, p);
    }
}

int main() {
    float p;
    int n;
    float r;
    
    printf("Nhap so tien goc: ");
    scanf("%f", &p);
    
    printf("Nhap so nam: ");
    scanf("%d", &n);
    
    printf("Nhap lai suat hang nam (%): ");
    scanf("%f", &r);

    tinh_von_tich_luy(p, n, r);
    
    return 0;
}

