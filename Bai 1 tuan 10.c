// sieu so nguyen to 
#include <stdio.h>
#include <math.h>
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
int PalindromePrime(int n){
    if(!isprime(n,2)) return 0;
    int kq = sodao(n,0);
    return kq == n;
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
typedef struct {
    float x;
    float y;
} Point;

float calculateDistance(Point A, Point B) {
    return sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
}

float findMinDistance(Point points[], int numPoints) {
    float minDistance = calculateDistance(points[0], points[1]);

    for (int i = 0; i < numPoints - 1; ++i) {
        for (int j = i + 1; j < numPoints; ++j) {
            float distance = calculateDistance(points[i], points[j]);
            if (distance < minDistance) {
                minDistance = distance;
            }
        }
    }

    return minDistance;
}

float findMaxDistance(Point points[], int numPoints) {
    float maxDistance = calculateDistance(points[0], points[1]);

    for (int i = 0; i < numPoints - 1; ++i) {
        for (int j = i + 1; j < numPoints; ++j) {
            float distance = calculateDistance(points[i], points[j]);
            if (distance > maxDistance) {
                maxDistance = distance;
            }
        }
    }

    return maxDistance;
}
float calculateVolume(float diameter, float height) {
    float radius = diameter / 2.0;
    return (1.0 / 3.0) * M_PI * pow(radius, 2) * height;
}
int main() {
    Point A[] = {{1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0}, {7.0, 8.0}, {9.0, 10.0}};
    int numPoints = 5;

    float minDistance = findMinDistance(A, numPoints);
    printf("Minimum distance between points: %.2f\n", minDistance);

    float maxDistance = findMaxDistance(A, numPoints);
    printf("Maximum distance between points: %.2f\n", maxDistance);
    // Assume height of the cone is equal to the maximum distance
    float height = maxDistance;

    // Calculate volume of the cone
    float volume = calculateVolume(maxDistance, height);
    printf("Volume of the cone: %.2f\n", volume);
    // int num;
    // int A[5] = { 79, 97, 107,17, 31  };
    // printf("Nhap so can kiem tra: ");
    // scanf("%d", &num);
    // if (isEmirp(num))
    //     printf("%d la so emirp.\n", num);
    // else
    //     printf("%d khong phai la so emirp.\n", num);
    // int x = findmaxSoEmirp(A,5);
    // printf("%d",x);
    return 0;
}
