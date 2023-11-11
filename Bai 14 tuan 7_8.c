#include <stdio.h>
#include <math.h>
double pt(double a,double b,double c){
	double x,x1,x2;
	if(a==0){
		x = -c/b;
		printf("pt co nghiem x = %.2lf",x);
	}
	else{
		double delta = b*b - 4*a*c;
		if(delta<0) printf("phuong trinh vo nghiem.");
		else if(delta==0){
			x = -b/(2.0*a);
			printf("Phuong trinh co nghiem kep x = %.2lf",x);
		}
		else if(delta>0){
			x1 = (-b+sqrt(delta))/2*a;
			x2 = (-b-sqrt(delta))/2*a;
			printf("%.2lf %.2lf",x1,x2);
		}
	}
}
double deposit(long long n,double ls,long long y){
	double sotien = 1.0*n*pow((1+(ls/100)),y);
	return sotien;
}
int main(){
	double a,b,c,ls;
	long long n,y;
	int choice;
	printf("1.Tinh pt bac 2\n2.Tinh lai suat ngan hang\n3.Thoat\n");
	do{
		printf("Moi chon chuc nang: ");
		scanf("%d",&choice);
	}while(choice<1||choice>3);
	switch(choice){
		case 1:
			scanf("%lf %lf %lf",&a,&b,&c);
			pt(a,b,c);
			break;
		case 2:
			scanf("%ld %ld %lf",&n,&y,&ls);
			printf("%.2lf",deposit(n,ls,y));
			break;
		case 3:
			break;
			
	}
	return 0;
}
