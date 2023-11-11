#include <stdio.h>
#include <math.h>
int nguyenam(int n){
	if(n<0) return 1;
	else return 0;
}
int uocso(int n){
	int i,sum=0;
	for(i=1;i<=n;i++){
		if(n%i==0)
			sum += i;
	}
	return sum;
}
int chinhphuong(int n){
	int i = sqrt(n);
	if(i*i==n)
		return 1;
	return 0;
}
int main(){
	int n,choice,result;
	printf("1.So nguyen am\n2.Tong cac uoc so\n3.Kiem tra so chinh phuong\n");
	do{
		printf("Moi chon chuc nang: ");
		scanf("%d",&choice);
	}while(choice<1||choice>3);
	switch(choice){
		case 1:
			scanf("%d",&n);
			result = nguyenam(n);
			if(result==1) printf("%d la so nguyen am",n);
			else printf("%d la so duong",n);
			break;
		case 2:
			do{
				scanf("%d",&n);
			}while(n<=0);
			printf("Tong: %d",uocso(n));
			break;
		case 3:
			do{
				scanf("%d",&n);
			}while(n<=0);
			result = chinhphuong(n);
			if(result==1) printf("%d la so chinh phuong",n);
			else printf("%d khong la so chinh phuong",n);
			break;
	}
	return 0;
}
