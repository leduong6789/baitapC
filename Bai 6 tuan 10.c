#include <stdio.h>
int main(){
	int n,i,a[n+1],cnt=0,j,k,value;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	for(i=0;i<n;i++) printf("%d ",a[i]);
	for(i=0;i<n;i++){
		if(a[i]>0){
			printf("\nGia tri duong dau tien:%d\nVi tri:%d",a[i],i+1);
			break;
		}
	}
	for(i=n;i>=1;i--){
		if(a[i]>0){
			printf("\nGia tri duong cuoi cung:%d\nVi tri:%d",a[i],i+1);
			break;
		}
	}
	printf("\n");
	for(i=0;i<n;i++){
		if(a[i]%2!=0){
			printf("%d ",a[i]);
		}
	}
	long long res = -1e10;
	for(i=0;i<n;i++){
		if(a[i]>res){
			res = a[i];
			j =i;
		}
	}
	printf("\nGia tri lon nhat:%d",res);
	for(i=0;i<n;i++){
		if(res==a[i]) cnt++;
	}
	printf("\nSo phan tu lon nhat:%d",cnt);
	printf("\nVi tri so lon nhat:%d",j+1);
	do{
		printf("\nNhap vi tri muon them: ");
		scanf("%d",&k);
	}while(k<0&&k>n);
	printf("Nhap gia tri muon them: ");
	scanf("%d",&value);
	for(i=n;i>=k;i--){
		a[i]=a[i-1];
	}
	a[k-1] = value;
	printf("\nMang sau khi duoc them:\n");
	for(i=0;i<=n;i++) printf("%d ",a[i]);
	printf("\n");
	for(i=0;i<n;i++){
		printf("Nhap phan tu thu %d: ",i+1);
		scanf("%d",&a[i]);
	}
	do{
		printf("\nNhap vi tri muon xoa: ");
		scanf("%d",&k);
	}while(k<0&&k>n);
	for(i=k-1;i<n-1;i++){
		a[i] = a[i+1];
	}
	printf("Mang sau khi da xoa:\n");
	for(i=0;i<n-1;i++) printf("%d ",a[i]);
}
