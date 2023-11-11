#include <stdio.h>

int main() {
    int day;

    printf("Nhap so tu 1 den 7: ");
    scanf("%d", &day);

    switch (day) {
        case 1:
            printf("Thu hai");
            break;
        case 2:
            printf("Thu ba");
            break;
        case 3:
            printf("Thu tu");
            break;
        case 4:
            printf("Thu nam");
            break;
        case 5:
            printf("Thu sau");
            break;
        case 6:
            printf("Thu bay");
            break;
        case 7:
            printf("Chu nhat");
            break;
        default:
            printf("So khong hop le. Moi ban nhap lai so tu 1 den 7.");
    }

    return 0;
}

