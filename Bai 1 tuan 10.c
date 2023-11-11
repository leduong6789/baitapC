#include <stdio.h>
int main(){
	float a,b,c,dc;
	printf("Nhap diem chuan: ");
	scanf("%f",&dc);
	printf("Nhap diem 3 mon thi: ");
	scanf("%f %f %f",&a,&b,&c);
	char kv;
	int dt;
	do{
		printf("Nhap khu vuc (A,B,C,X): ");
		scanf(" %c",&kv);
		if(kv!='A' && kv!='B' && kv!='C' && kv!='X'){
			char trl;
			printf("Ban co muon nhap lai khu vuc khong (y/n)");
			scanf(" %c",&trl);
			if(trl=='n'||trl=='N') break;
		}
	}while(kv!='A' && kv!='B' && kv!='C' && kv!='X');
	do{
		printf("Nhap doi tuong uu tien (1,2,3,0):");
		scanf("%d",&dt);
	}while(dt!=1 && dt!=2 && dt!=3 && dt!=0);
	
	float sum;
	sum = a+b+c;
	if(kv=='A') sum += 2;
	if(kv=='B') sum +=1;
	if(kv=='C') sum += 0.5;
	if(dt==1) sum += 2.5;
	if(dt==2) sum += 1.5;
	if(dt==3) sum += 1;
	if(sum>=dc) printf("Dau [%.2f]",sum);
	else printf("Rot [%.2f]",sum);
}

