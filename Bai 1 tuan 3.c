#include <stdio.h>
int main(){
	int sl;
	float kq;
	printf("Nhap sl:");
	scanf("%d",&sl);
	kq = sl*5000*1.0;
	if(sl>10)
		kq = kq*0.9;
	printf("So tien: %.2f",kq);
}
