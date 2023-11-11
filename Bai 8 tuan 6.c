#include <stdio.h>

int main()
{
    double a, i, sum = 0;
    do{
    	printf("Nhap a: ");
    	scanf("%lf",&a);
	}while(a<0);
    for (i = 1; sum <= a; i++) {
        sum += 1.0 / i;
    }
    printf("%.0lf", i - 1);
    return 0;
}

