#include <stdio.h>
int main(){
	int i,n,sum=1;
	do{
		printf("Nhap n: ");
		scanf("%d",&n);
	}while(n<0);
	if(n==0) sum =0;
	else if(n%2==0){
		for(i=2;i<=n;i+=2){
			sum *= i;
		}
	}
	else{
		for(i=1;i<=n;i+=2){
			sum *= i;
		}
	}
	printf("%d",sum);
}
