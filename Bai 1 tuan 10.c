#include <stdio.h>

int isPrime(int n, int i) {
    if (n <= 2)
        return n == 2;
    if (n % i == 0)
        return 0;
    if (i * i > n)
        return 1;
    return isPrime(n, i + 1);
}

int SieuNguyenTo(int n) {
    if (!isPrime(n, 2))
        return 0;
    if (n < 10)
        return isPrime(n, 2);
    return isPrime(n, 2) && SieuNguyenTo(n / 10);
}
int CongSo(int n,int s){
	if(n==0) return s;
	else{
		s = s*10 + n%10;
		CongSo(n/10,s);
	}
}
int PerPrime(int n){
	if(!isPrime(n,2)) return 0;
	if(n < 10) return isPrime(n,2);
	int m = CongSo(n,0);
	return isPrime(m,2) && PerPrime(m);
	
}
int Max(int a[], int n) {
    if (n == 1)
        return SieuNguyenTo(a[0]) ? a[0] : -1;
    else {
        int x = Max(a, n - 1);
        if (SieuNguyenTo(a[n - 1]) && (a[n - 1] > x || x == -1))
            return a[n - 1];
        else
            return x;
    }
}
float avgSuperPrimeHelper(int a[], int n, int index, int count, int sum) {
    if (index == n) {
        if (count == 0) return 0; // To avoid division by zero
        return (float) sum / count;
    }

    if (SieuNguyenTo(a[index])) {
        count++;
        sum += a[index];
    }

    return avgSuperPrimeHelper(a, n, index + 1, count, sum);
}

float avgSuperPrime(int a[], int n) {
    return avgSuperPrimeHelper(a, n, 0, 0, 0);
}
int main() {
    int a[5] = {6,733,2399,2939,3119 };
    float x = avgSuperPrime(a, 5);
    printf("%.2f", x);
    return 0;
}

