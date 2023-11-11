#include <stdio.h>
#include <math.h>
int main(){
	int a,b,c;
	do{
		printf("nhap a:");
		scanf("%d",&a);
	}while(b<0);
	do{
		printf("nhap b:");
		scanf("%d",&b);
	}while(b<0);
	do{
		printf("nhap c:");
		scanf("%d",&c);
	}while(c<0);
	if(a>(b+c)||b>(c+a)||c>(a+b))
		printf("Day khong phai la tam giac.");
	else if(a==b&&b==c)
		printf("Day la tam giac deu");
	else if(a*a==b*b+c*c||b*b==a*a+c*c||c*c==b*b+a*a){
		if(a ==b||c==b||c==a)
			printf("Day la tam giac vuong can");
		else printf("Day la tam giac vuong ");
	}
	else if(a ==b||c==b||c==a)
		printf("Day la tam giac can");
	
	return 0; 
}
