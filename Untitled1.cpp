#include <stdio.h>

void Nhap(int *ts, int *ms){
    printf("Nhap tu so: ");
    scanf("%d", ts);
    do{
        printf("Nhap mau so: ");
        scanf("%d", ms);
    }while(*ms == 0);
}

void Tong(int ts1,int ms1,int ts2,int ms2,int *tskq,int *mskq){
    *tskq = ts1*ms2 + ts2*ms1;
    *mskq = ms1*ms2;
}
void Hieu(int ts1,int ms1,int ts2,int ms2,int *tskq,int *mskq){
	*tskq = ts1*ms2 - ts2*ms1;
    *mskq = ms1*ms2;
}
void Tich(int ts1,int ms1,int ts2,int ms2,int *tskq,int *mskq){
	*tskq = ts1*ts2;
	*mskq = ms1*ms2;
}
void Thuong(int ts1,int ms1,int ts2,int ms2,int *tskq,int *mskq,int *error){
	if(ts2==0)
		*error = 1;
	else{
		*tskq = ts1*ms2;
		*mskq = ms1*ts2;
	}
}
char ChonPhepTinh(){
	char pt;
	do{
		printf("Moi nhap phep tinh (+,-,*,/): ");
		scanf(" %c",&pt);
	}while(pt!='+'&&pt!='-'&&pt!='*'&&pt!='/');
	return pt;
}
int ucln(int a,int b){
	if(a<0) a*=-1;
	if(b<0) b*=-1;
	while(a!=b){
		if(a>b) a-=b;
		else b-=a;
	}
	return a;
}
void ToiGian(int *tskq,int *mskq){
	int u = ucln(*tskq,*mskq);
	*tskq /= u;
	*mskq /= u;
}
void NhapCacPhanSo(int ts1, int ms1, int ts2, int ms2, int *tskq, int *mskq, int *error){
	char phepToan=ChonPhepTinh();
	switch(phepToan){
		case '+':
			Tong(ts1,ms1,ts2,ms2,tskq,mskq);
			ToiGian(tskq,mskq);
			printf("%d / %d",*tskq,*mskq);
			break;
		case '-':
			Hieu(ts1, ms1, ts2,ms2,tskq,mskq);
			ToiGian(tskq,mskq);
			printf("%d / %d",*tskq,*mskq);
			break;
		case '*':
			Tich(ts1, ms1, ts2,ms2,tskq,mskq);
			ToiGian(tskq,mskq);
			printf("%d / %d",*tskq,*mskq);
			break;
		default:
			Thuong(ts1, ms1, ts2,ms2,tskq,mskq,error);
			if(*error == 1){
				printf("Loi phep tinh.\n");
			}else{
				ToiGian(tskq,mskq);
				printf("%d / %d",*tskq,*mskq);
			}
	}
}
int main(){
    int ts1, ms1, ts2, ms2, tskq, mskq,error;
    printf("Nhap phan so thu nhat:\n");
    Nhap(&ts1, &ms1);
    printf("Nhap phan so thu hai:\n");
    Nhap(&ts2, &ms2);
	NhapCacPhanSo(ts1,ms1,ts2,ms2,&tskq,&mskq,&error);
}
