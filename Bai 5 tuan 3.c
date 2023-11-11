#include <stdio.h>
#include <math.h>
int main(){
	int a,b,c;
	float x1,x2,x;
	scanf("%d %d %d",&a,&b,&c);
	float delta = b*b -(4*a*c);
	if(delta>0){
		x1 = (-(float)b+(sqrt(delta)))/2*(float)a;
		x2 = (-(float)b-(sqrt(delta)))/2*(float)a;
		printf("Co 2 nghiem phan biet la:\nx1 = %.2f x2 = %.2f",x1,x2);
	}else if(delta ==0){
		x = -1.0*(float)b/(2*(float)a);
		printf("Co nghiem kep:\nx = %.2f",x);
	}else printf("Vo nghiem.");
	return 0;
}
