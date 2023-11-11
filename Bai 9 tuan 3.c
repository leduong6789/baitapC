#include <stdio.h>
int main(){
	float cp,sp,pro=0,loss=0,lossper,proper;
	scanf("%f %f",&cp,&sp);
	if(cp>sp)
		loss = cp-sp;
	if(sp>cp)
		pro = sp -cp;
	lossper = (loss/cp)*100;
	proper = (pro/cp)*100;
	if(cp>sp) printf("Loss percentage: %.2f",lossper);
	if(sp>cp) printf("Proper perceentage: %.2f",proper);
} 
