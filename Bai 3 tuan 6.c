#include <stdio.h>
#include <math.h>
#include <stdbool.h>
bool shh(int n){
	int i;
	int sum = 0; 
	for(i=1;i<n;i++){
		if(n % i ==0){
			sum = sum +i;
		}
	}
	return sum ==n;
} 
int main(){
	int i,sum,l,r;
	scanf("%d %d",&l ,&r);
	for(i=l;i<=r;i++){
		if(shh(i)){
			printf("%d ",i);
		}
	}
	return 0;
}
