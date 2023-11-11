#include <stdio.h>
int main(){
	int month,year;
	do{
		printf("Nhap thang:");
		scanf("%d",&month);}while(month<1||month>12);
	printf("Nhap nam:");
	scanf("%d",&year);
	if((year%4==0&&year%100!=0)||year%400==0){
		if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
			printf("so ngay trong thang: 31");
		else if(month==4||month==6||month==9||month==11)
			printf("so ngay trong thang: 30");
		else if(month==2)
			printf("so ngay trong thang: 29");
	}
	else{
		if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
			printf("so ngay trong thang: 31");
		else if(month==4||month==6||month==9||month==11)
			printf("so ngay trong thang: 30");
		else printf("so ngay trong thang: 28");	
	}
	return 0;
}
