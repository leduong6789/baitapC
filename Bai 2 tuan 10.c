#include <stdio.h>
int main(){
	long long thunhap;
	printf("Thu nhap cua ban trong nam nay: ");
	scanf("%ld",&thunhap);
	long long pa = 9000000,pd=3600000;
	int songuoi;
	printf("So nguoi phu thuoc: ");
	scanf("%d",&songuoi);
	double ti,tf,ts,tt;
	tf = 12*(pa*1.0+1.0*songuoi*pd);
	ti = (double)thunhap - tf;
	if(ti<=0) ti = 0;
	if(ti<=5000000) ts = 0.05;
	if(ti>=5000001 && ti<=10000000) ts = 0.1;
	if(ti>=10000001 && ti<=18000000) ts = 0.15;
	if(ti>=18000001) ts = 0.2;
	tt = ti*ts;
	printf("\nThu nhap mien thue: %.1lf",tf);
	printf("\nThu nhap tinh thue: %.1lf",ti);
	printf("\nThue TNCN: %.1lf",tt);
	return 0;
}
