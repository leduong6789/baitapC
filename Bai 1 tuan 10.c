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
int sumOfDigits(int n) {
    if (n == 0)
        return 0;
    return (n % 10) + sumOfDigits(n / 10);
}

int PerPrime(int n) {
    if (!isPrime(n, 2))
        return 0;
    if (n < 10)
        return isPrime(n, 2);

    int sum = sumOfDigits(n);
    return PerPrime(sum);
}
int Count(int a[],int n,int i){
	if(i>=n) return 0;
	int cnt = PerPrime(a[i]);
	return cnt + Count(a,n,i+1);
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
float avgPerPrimeHelper(int a[], int n, int index, int sum) {
	int cnt = Count(a,n,0);
    if (index == n) {
        if (cnt == 0) return 0; // To avoid division by zero
        return (float) sum/cnt;
    }

    if (PerPrime(a[index])) {
        sum += a[index];
    }

    return avgPerPrimeHelper(a, n, index + 1, sum);
}

float avgPerPrime(int a[], int n) {
    return avgPerPrimeHelper(a, n, 0, 0);
}
typedef struct {
    float x;
    float y;
} Point;

float KhoangCach(Point A, Point B) {
    return sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
}

float KCMin(Point points[], int n) {
    float min = KhoangCach(points[0], points[1]);

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            float distance = KhoangCach(points[i], points[j]);
            if (distance < min) {
                min = distance;
            }
        }
    }

    return min;
}

float KcMax(Point points[], int n) {
    float max = KhoangCach(points[0], points[1]);
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            float distance = KhoangCach(points[i], points[j]);
            if (distance > max) {
                max = distance;
            }
        }
    }

    return max;
}
float TheTich(float d, float h) {
    float r = d / 2.0;
    return (1.0 / 3.0) * M_PI * pow(r, 2) * h;
}
int main() {
    int a[5] = {1,2,3,8,29};
    float x = avgPerPrime(a,5);
    printf("%.2f", x);
    return 0;
}

