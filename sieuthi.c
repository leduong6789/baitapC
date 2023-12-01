#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void Nhap(int *a,int *b,int soSieuThi,int X[soSieuThi][2]){
    printf("Nhap toa do hien tai: ");
    scanf("%d %d",a,b);
    for(int i=0;i<soSieuThi;i++){
        printf("Nhap toa do sieu thi thu %d: ",i+1);
        scanf("%d %d",&X[i][0],&X[i][1]);
    }
}

void Chon(int a,int b,int soSieuThi,int X[soSieuThi][2]){
    float kcMin = (sqrt(pow(X[0][0]-a,2) + pow(X[0][1]-b,2)))*2;
    int choose = 0;
    for(int i=1;i<soSieuThi;i++){
        float kcNow = (sqrt(pow(X[i][0]-a,2) + pow(X[i][1]-b,2)))*2;
        if(kcNow<kcMin){
            kcMin=kcNow;
            choose = i;
        }
    }
    printf("Sieu thi %d gan nhat va co toa do (%d/%d).",choose+1,X[choose][0],X[choose][1]);
}
void NhienLieu(int *y,int *z,int a,int b,int soSieuThi,int X[soSieuThi][2]){
    int flag=0;
    printf("\nNhap so nhien lieu con lai: ");
    scanf("%d",y);
    printf("Nhap so nhien lieu tieu ton tren moi km: ");
    scanf("%d",z);
    float kcMax = (*y)*1.0/(*z);
    for(int i=0;i<soSieuThi;i++){
        float kcNow = (sqrt(pow(X[i][0]-a,2) + pow(X[i][1]-b,2)))*2;
        if(kcNow<=kcMax){
            printf("Sieu thi %d phu hop va con thua %.2f lit xang.\n",i+1,(*y)-(kcNow*(*z)));
            flag =1;
        }
    }
    if(!flag){
        printf("Khong co sieu thi phu hop.");
        exit(0);
    }
}

void ChiPhi(int y,int z,int a,int b,int soSieuThi,int X[soSieuThi][2]){
    int prime[1001]={0};
    long long arr[soSieuThi];
    float kcMax = (y)*1.0/(z);
    for(int i=0;i<soSieuThi;i++){
        float kcNow = (sqrt(pow(X[i][0]-a,2) + pow(X[i][1]-b,2)))*2;
        if(kcNow<=kcMax){
            prime[i]=1;
        }
    }
    printf("\n");
    for(int i=0;i<soSieuThi;i++){
        if(prime[i]){
            printf("Nhap chi phi sieu thi %d: ",i+1);
            scanf("%lld",&arr[i]);
        }
    }
    long long res = arr[0];
    for(int i=1;i<soSieuThi;i++){
        if(arr[i]<res) res = arr[i];
    }
    printf("Chi phi thap nhat: %lld",res);
}


int main(){
    int a,b,y,z,soSieuThi;
    printf("Nhap so sieu thi: ");
    scanf("%d",&soSieuThi);
    int X[soSieuThi][2];
    Nhap(&a,&b,soSieuThi,X);
    Chon(a,b,soSieuThi,X);
    NhienLieu(&y,&z,a,b,soSieuThi,X);
    ChiPhi(y,z,a,b,soSieuThi,X);
}