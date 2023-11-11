#include <stdio.h>
int main(){
	float diem;
	scanf("%f",&diem);
	if(diem>=8.5&&diem<=10) printf("A");
	if(diem>=7.0&&diem<=8.4) printf("B");
	if(diem>=5.5&&diem<=6.9) printf("C");
	if(diem>=4.0&&diem<=5.4) printf("D");
	if(diem>=0&&diem<4.0) printf("F");
	return 0;
} 
