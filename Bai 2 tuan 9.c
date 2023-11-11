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
int main(){
	int x[100];
	int n,i,j;
	printf("Nhap so luong cua mang: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Nhap phan tu thu %d: ",i+1);
		scanf("%d",&x[i]);
	}
	printf("b/ ");
	for(i=0;i<n;i++)
		printf("%d ",x[i]);
	printf("\nc/ ");
	for(i=0;i<n;i++){
		if(prime(x[i])){
			printf("%d  ",x[i]);
		}
	}
	printf("\n");
	int a,b;
	printf("Nhap khoang a va b: ");
	scanf("%d %d",&a,&b);
	for(i=0;i<n;i++){
		if(x[i]>=a&&x[i]<=b){
			printf("%d ",x[i]);
		}
	}
	int c,d;
	printf("\nNhap vi tri: ");
	scanf("%d %d",&c,&d);
	for(i=c;i<=d;i++){
		printf("%d ",x[i]);
	}
	int sum3 =0;
	for(i=0;i<n;i++){
		if(x[i]%2==0){
			sum3 += x[i];
		}
	}
	printf("\nTong so chan: %d",sum3);
	int digit,count =0;
	for(i=0;i<n;i++){
		while(x[i]){
			digit = x[i] % 10;
			if(x[i]%4==0 && digit ==6)
				count++;
				break;
		}
	}
	printf("\nSo phan tu chia het cho 4 va chu so cuoi cung la 6:%d\n",count);
	for(i=0;i<n;i++){
		if(x[i]%2!=0){
			printf("So le ban dau:%d \n",x[i]);
			x[i]*=2;
			printf("So le sau khi nhan doi: %d\n",x[i]);
		}
	}
	for(i=0;i<n;i++){
		printf("Nhap phan tu thu %d: ",i+1);
		scanf("%d",&x[i]);
	}
	int vitri,value;
	printf("Nhap vi tri can them: ");
	scanf("%d",&vitri);
	printf("Nhap gia tri: ");
	scanf("%d",&value);
	for(i=n;i>=vitri;i--){
		x[i] = x[i-1];
	}
	x[vitri-1] = value;
	printf("Mang sau khi da them:\n");
	for(i=0;i<=n;i++){
		printf("%d ",x[i]);
	}
	printf("\n");
	for(i=0;i<n;i++){
		printf("Nhap phan tu thu %d: ",i+1);
		scanf("%d",&x[i]);
	}
	printf("Nhap vi tri can xoa: ");
	scanf("%d",&vitri);
	for(i=vitri-1;i<n-1;i++){
		x[i] = x[i+1];
	}
	printf("Mang sau khi da xoa phan tu: \n");
	for(i=0;i<n-1;i++){
		printf("%d ",x[i]);
	}
	int giatri,sum =0,tam;
	printf("\nNhap gia tri can tim kiem: ");
	scanf("%d",&giatri);
	for(i=0;i<n;i++){
		if(giatri == x[i]){
			sum =1;
			tam = x[i];
			break;
		}
	}
	if(sum ==1){
		printf("Gia tri tim kiem la %d",tam);
	}else printf("Khong tim thay gia tri trong mang.");
	int temp;
	printf("\nL/ Nhap so luong cua mang: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Nhap phan tu thu %d: ",i+1);
		scanf("%d",&x[i]);
	}
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(x[j]>x[j+1]){
				temp = x[j];
				x[j] = x[j+1];
				x[j+1] = temp;
			}
		}
	}
	printf("Mang tu nho den lon:\n");
	for(i=0;i<n;i++)
		printf("%d ",x[i]);
	printf("\nL/ Nhap so luong cua mang: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Nhap phan tu thu %d: ",i+1);
		scanf("%d",&x[i]);
	}
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(x[j]<x[j+1]){
				temp = x[j];
				x[j] = x[j+1];
				x[j+1] = temp;
			}
		}
	}
	printf("\nMang tu lon ve nho:\n");
	for(i=0;i<n;i++)
		printf("%d ",x[i]);
	
	return 0;
	
}
