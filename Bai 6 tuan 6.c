#include <stdio.h>
#include <math.h>
int main(){
	int i,n,temp=1;
	float sum=0;
	do{
		printf("Nhap n: ");
		scanf("%d",&n);
	}while(n<=0);
	for(i=2;i<=2*n;i+=2){
		sum += 1.0*temp/(1.0*pow(i,2));
		temp*=-1;
	}
	printf("%.6f",sum);
}
