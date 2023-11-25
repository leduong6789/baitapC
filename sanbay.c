/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
void Nhap(int *a, int *b, int soSanBay, int X[soSanBay][2]) {
    printf("Nhap toa do cua may bay: ");
    scanf("%d %d", a, b);
    for (int i = 0; i < soSanBay; i++) {
        printf("Nhap toa do san bay thu %d: ", i + 1);
        scanf("%d %d", &X[i][0], &X[i][1]);
    }
}

void ChonSanBay(int a, int b, int soSanBay, int X[soSanBay][2]) {
    float kcMin = sqrt(pow((X[0][0] - a), 2) + pow((X[0][1] - b), 2));
    int choosen = 0;
    for (int k = 1; k < soSanBay; k++) {
        float kcNow = sqrt(pow((X[k][0] - a), 2) + pow((X[k][1] - b), 2));
        if (kcNow < kcMin) {
            kcMin = kcNow;
            choosen = k;
        }
    }
    printf("Vay san bay gan nhat o thu %d co toa do la (%d, %d)\n", choosen + 1, X[choosen][0], X[choosen][1]);
}

void NhienLieu(int *y, int *z, int a, int b, int soSanBay, int X[soSanBay][2]) {
    printf("Nhap so nhien lieu con lai (tinh theo lit xang): ");
    scanf("%d", y);
    printf("Nhap so lit xang tieu ton tren moi km: ");
    scanf("%d", z);
    int SanDuocChon = 0;
    for (int i = 0; i < soSanBay; i++) {
        float SoKc = sqrt(pow((X[i][0] - a), 2) + pow((X[i][1] - b), 2));
        int SoNhienLieu = SoKc * (*z);
        if (SoNhienLieu <= *y) {
            printf("San bay thu %d co toa do %d %d co so xang tieu to la %d va con thua %d\n", i + 1, X[i][0], X[i][1], SoNhienLieu, *y - SoNhienLieu);
        }
    }
}
void ChiPhi(int a,int b,int y,int z,int soSanBay,int arr[soSanBay],int X[soSanBay][2]){
    bool brr[3] = {false};
    for(int i=0;i<soSanBay;i++){
        float SoKc = sqrt(pow((X[i][0] - a), 2) + pow((X[i][1] - b), 2));
        int SoNhienLieu = SoKc * (z);
        if (SoNhienLieu <= y)
            brr[i] = true;
    }
    for(int i=0;i<soSanBay;i++){
        printf("Nhap chi phi san bay thu %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    int res = arr[0];
    for(int i=0;i<soSanBay;i++){
        if(arr[i]<res) res = arr[i];
    }
    for(int i=0;i<soSanBay;i++){
        if(brr[i]){
            for(int i=0;i<soSanBay;i++){
                if(arr[i]<res) res = arr[i];
            }
        }
    }
    printf("%d",res);
}
int main() {
    int a, b, soSanBay,y,z;
    printf("Nhap so luong san bay: ");
    scanf("%d", &soSanBay);
    int X[soSanBay][2];
    int arr[soSanBay];
    Nhap(&a, &b, soSanBay, X);
    ChonSanBay(a, b, soSanBay, X);
    NhienLieu(&y,&z,a,b,soSanBay,X);
    ChiPhi(a,b,y,z,soSanBay,arr,X);
    return 0;
}


