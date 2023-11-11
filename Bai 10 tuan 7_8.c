#include <stdio.h>
#include <math.h>

double giaithua(double n){
	long long i,gth=1;
	for(i=1;i<=n;i++){
		gth *= i;
	}
	return gth;
}
int main(){
	double n=2,temp_sum,sum,x;
	scanf("%lf",&x);
	sum = 1 +x;
	do{
		temp_sum = sum;
		sum = sum + pow(x,n)/giaithua(n);
		n++;
	}while((sum-temp_sum)>0.0001);
	printf("%.4lf",sum);
}
