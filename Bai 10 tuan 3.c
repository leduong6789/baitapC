#include <stdio.h>
int main(){
	int n,st;
	scanf("%d",&n);
	if(n<=3)
		st = n*120000;
	if(n>=4&&n<=6)
		st = n*90000;
	if(n>=7&&n<=10)
		st = n*85000;
	if(n>=11)
		st = n*70000;
	printf("So tien tra la: %d",st);
}
