// sieu so nguyen to 
#include <stdio.h>
int isprime(int n,int i){
    if(n<=2) return n==2;
    if(n % i==0) return 0;
    if(i*i > n) return 1;
    return isprime(n,i+1);
}
int isSuperPrime(int n){
    if(!isprime(n,2)) return 0;
    if(n<10) return 1;
    return isSuperPrime(n/10);
}
// so emirp
int sodao(int n,int sdn){
    if(n==0) return sdn;
    else{
        sdn = sdn*10 + n%10;
        return sodao(n/10,sdn);
    }
}
int isEmirp(int n){
    if(!isprime(n,2)) return 0;
    int kq = sodao(n,0);
    return kq != n && isprime(kq,2);
}
int findMaxSoSieuNguyenTo(int A[],int n){
    if(n==0) return -1;
    if(n==1) return isSuperPrime(A[0]) ? A[0] : 0;
    else{
        int kq = findMaxSoSieuNguyenTo(A,n-1);
        if(A[n-1] < kq && isSuperPrime(A[n-1])) return A[n-1];
        return kq;
    }
}
int findmaxSoEmirp(int A[],int n){
    if(n==0) return -1;
    if(n==1) return isEmirp(A[0]) ? A[0] : 0;
    else{
        int kq = findmaxSoEmirp(A,n-1);
        if(A[n-1] < kq && isEmirp(A[n-1])) return A[n-1];
        return kq;
    }
}
int main() {
    int num;
    int A[5] = { 79, 97, 107,17, 31  };
    // printf("Nhap so can kiem tra: ");
    // scanf("%d", &num);
    // if (isEmirp(num))
    //     printf("%d la so emirp.\n", num);
    // else
    //     printf("%d khong phai la so emirp.\n", num);
    int x = findmaxSoEmirp(A,5);
    printf("%d",x);
    return 0;
}
