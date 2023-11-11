#include <stdio.h>
#include <math.h>
double gth(int n){
	int i;
	double sum=1;
	for(i=1;i<=n;i++){
		sum *= 1.0*i;
	}
	return sum;
}
int main(){
	int n;
	do{
		scanf("%d",&n);
	}while(n<0);
	double p = gth(n);
	printf("%.1lf",p);
	return 0;
}

