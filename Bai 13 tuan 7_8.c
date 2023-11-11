#include <stdio.h>
#include <math.h>
int fibo(int n){
	int i,a=0,b=1,c;
	for(i=2;i<=n;i++){
		c = a+b;
		a=b;
		b=c;
	}
	return c;
}
int validdate(int d,int m,int y){
	int maxd = 31;
	if(d<1||d>31||m<1||m>12) return 0;
	if(m==4||m==6||m==9||m==11) maxd=30;
	else if(m==2){
		if(y%400==0 || ( y%4==0 && y%100!=0)) maxd=29;
		else maxd=28;
	}
	return d<=maxd;
}
int main(){
	int n;
	int d,m,y,choice;
	printf("1.Fibonacci sequence\n2.Check date\n3.Quit\n");
	do{
		printf("Moi chon chuc nang: ");
		scanf("%d",&choice);
	}while(choice<1||choice>3);
	switch(choice){
		case 1:
			do{
				printf("Nhap n: ");
				scanf("%d",&n);
			}while(n<0);
			if(n==0||n==1) {
				printf("So fibo thu %d la:%d",n,n);
				return 0;
			}
			printf("So fibo thu %d la:%d",n,fibo(n));
			break;
		case 2:
			scanf("%d %d %d",&d,&m,&y);
			if(validdate(d,m,y))
				printf("Valid Date");
			else printf("Invalid Date");
			break;
			case 3:
				break;	
	}
	return 0;
}
