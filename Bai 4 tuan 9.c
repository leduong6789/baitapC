#include <stdio.h>
#include <stdbool.h>
int main(){
	int n,m,i;
	printf("Nhap so luong cua mang a: ");
	scanf("%d",&n);
	printf("Nhap so luong cua mang b: ");
	scanf("%d",&m);
	int a[n],b[m];
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=0;i<m;i++)
	scanf("%d",&b[i]);
	bool da_xuat_hien[10001] = {false};
	for(i=0;i<m;i++){
		if(b[i]>=0 && b[i]<=10000)
			da_xuat_hien[b[i]] = true;
	}
	printf("A hieu B: ");
	for(i=0;i<n;i++){
		if(a[i]>=0 && a[i]<=10000 &&!da_xuat_hien[a[i]]){
			printf("%d ",a[i]);
		}
	}
	for(i=0;i<10000;i++)
		da_xuat_hien[i] = false;
	for(i=0;i<n;i++){
		if(a[i]>=0 && a[i]<=10000)
			da_xuat_hien[a[i]] = true;
	}
	printf("\nA giao B: ");
	for(i=0;i<m;i++){
		if(da_xuat_hien[b[i]]){
			printf("%d ",b[i]);
		}
	}
	for(i=0;i<10000;i++)
		da_xuat_hien[i] = false;
	printf("\nA hop B: ");
	for(i=0;i<n;i++){
		if(!da_xuat_hien[a[i]]){
			printf("%d ",a[i]);
			da_xuat_hien[a[i]] = true;
		}
	}
	for(i=0;i<m;i++){
		if(!da_xuat_hien[b[i]]){
			printf("%d ",b[i]);
			da_xuat_hien[b[i]] = true;
		}
	}
}
