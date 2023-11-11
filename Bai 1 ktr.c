#include <stdio.h>

int main(){
	int lo,tien_du,x=4;
	long long von,so_co;
	float gia_cophieu,gia_moi;
	do{
		printf("Nhap so von: ");
		scanf("%ld",&von);
	}while(von<=0);
	do{
		printf("Nhap loai lo: ");
		scanf("%d",&lo);
	}while(lo!=10 && lo !=100);
	gia_cophieu = 25000;
	so_co = (von/gia_cophieu)/lo*lo;
	tien_du = von - gia_cophieu*so_co;
	printf("Vay co the mua toi da %d co phieu theo lo %d.\n",so_co,lo);
	printf("So tien con thua la: %d\n",tien_du);
	// 50 +50*(x/10) = 50*1.4
	printf("De tang von dieu le len 40 phan tram can tra co tuc theo ti le 10:%d.\n",x);
	so_co = so_co + (int)(so_co*0.4);
	gia_moi = (float)von/so_co;
	printf("Vay sau khi duoc tra co tuc thi so co phieu la %d.\n",so_co);
	printf("Gia moi co phieu sau khi duoc pha loang: %.2f.\n",gia_moi);
	so_co = so_co%lo;
	printf("Vay con thua %d co.",so_co);
	return 0;
	
}
