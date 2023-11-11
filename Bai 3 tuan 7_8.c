#include <stdio.h>
int tongcs(int n){
	int i, sum=0;
	while(n>0){
		int d = n%10;
		sum += d;
		n/=10;
	}
	return sum;
}
int main(){
	int n;
	do{
		scanf("%d",&n);
	}while(n<0);
	int s = tongcs(n);
	printf("%d",s);
	return 0;
}
