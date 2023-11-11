#include <stdio.h>
int gcd(int a,int b){
	int i;
	while(a!=b){
		if(a>b) a -= b;
		else b -= a;
	}
	return a;
}
double lcm(int a,int b){
	return (a*b)/(double)gcd(a,b);
}
int main(){
	int a,b;
	do{
		scanf("%d %d",&a,&b);
	}while(a<=0||b<=0);
	int d = gcd(a,b);
	double m = lcm(a,b);
	printf("%d\n%.1f",d,m);
}
