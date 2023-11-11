#include <stdio.h>
#include <math.h>
int fibo(int n){
	int i,a=0,b=1,c;
	for(i=2;i<=n;i++){
		c = a+b;
		a=b;
		b=c;
	}
	return c;
} 
int main(){
	int n;
	do{
		printf("Nhap n: ");
		scanf("%d",&n);
	}while(n<0);
	if(n==0||n==1) {
		printf("So fibo thu %d la:%d",n,n);
		return 0;
	}
	printf("So fibo thu %d la:%d",n,fibo(n));
	return 0;
}
