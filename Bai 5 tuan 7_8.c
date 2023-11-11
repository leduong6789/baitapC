#include <stdio.h>
#include <math.h>
int snt(int n){
	int i;
	for(i=2;i<=sqrt(n);i++){
		if(n%i==0)
		return 0;
	}
	return n>1;
}
int main(){
	int n,i;
	do{
		scanf("%d",&n);
	}while(n<=1);
	for(i=2;i<=n;i++){
		if(snt(i)) printf("%d ",i);
	}
}
