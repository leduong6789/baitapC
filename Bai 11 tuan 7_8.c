#include <stdio.h>
#include <math.h>
int prime(int n){
	int i;
	for(i=2;i<=sqrt(n);i++){
		if(n%i==0)
			return 0;
	}
	return n>1;
} 
void min_max(int n){
	int i,d,min,max;
	min=max=n%10;
	n/=10;
	while(n){
		d = n%10;
		n/=10;
		if(min>d)
			min = d;
		else if(max<d)
			max = d;
	}
	printf("%d %d",min,max);
}
int main(){
	int choice,i;
	long long n;
	printf("1.So nguyen to\n2.In chu so min max\n3.Thoat\n");
	do{
		printf("Moi chon chuc nang: ");
		scanf("%d",&choice);
	}while(choice<1||choice>3);
	switch(choice){
		case 1:
			do{
				printf("Nhap n: ");
				scanf("%ld",&n);
			}while(n<0);
			if(prime(n)) printf("%lld la so nguyen to",n);
			else printf("%d khong la so nguyen to",n);
			break;
		case 2:
			do{
				printf("Nhap n: ");
				scanf("%ld",&n);
			}while(n<0);
			min_max(n);
			break;
			case 3:
				break;
	}
	return 0;
}
