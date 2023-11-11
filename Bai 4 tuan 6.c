#include <stdio.h>
#include <math.h>
int main(){
	int i,sum1=0,sum2=0,j;
	float n;
	do{
		printf("Nhap n: ");
		scanf("%f",&n);
	}while(n<0);
	for(i=1;i<=n;i++){
		sum1 += i;
		sum2 += pow(i,2);
	}
	float s1 = (float)sum1/(float)n;
	float s2 = sqrt((float)sum2);
	printf("%.2f  %.4f  ",s1,s2);
	float temp1=1.0,temp2=1.0,sum3;
    for(i=1;i<=2*n-1;i+=2){
        temp1 *= i*1.0;
    }
    for(j=2;j<=2*n;j+=2){
        temp2 *= j*1.0;
    }
    sum3 = temp1/temp2;
    printf("%f  ",sum3);
    int sum4=0;
    for(i=1;i<=n;i++){
        sum4 += i*(i+1)*(i+2);
    }
    printf("%d",sum4);
	return 0;

}
