#include <stdio.h>
#include <math.h>

int main(){
    int n,i;
    scanf("%d", &n);
    float sum = 0;
    for(i = 0; i <= n; i++){
        sum += pow(-1, i) / pow((2 * i + 1), 2);
    }
    printf("%f", sum);
}

