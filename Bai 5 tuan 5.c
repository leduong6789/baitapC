#include <stdio.h>
int main(){
	int n,i;
	long sum=0,t=9;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		sum +=t;
		t = t*10+9;
	}
	printf("%ld",sum);
}
