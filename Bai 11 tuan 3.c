#include <stdio.h>
int main(){
	int n,st;
	printf("Nhap so kwh: ");
	scanf("%d",&n);
	if(n<100)
		st = n*950;
	if(n>=100&&n<150)
		st =n*1250;
	if(n>=150&&n<200)
		st = n*1350;
	else st = n*1550;
	printf("Tien dien la:%d",st);
	return 0;
	
}
