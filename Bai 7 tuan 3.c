#include <stdio.h>
#include <ctype.h>

int main() {
    char ch;
    printf("Nhap 1 ki tu: ");
    scanf("%c", &ch);

    if (!isalpha(ch)) {
        printf("Day khong phai la chu cai.");
    } else if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
        printf("%c la 1 nguyen am.", ch);
    } else {
        printf("%c la 1 phu am.", ch);
    }

    return 0;
}

