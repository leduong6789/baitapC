#include <stdio.h>
int main() {
    int t;
    printf("Nhap so luong test case: ");
    scanf("%d", &t);
    while (t--) {
        int n, i;
        printf("Nhap so luong phan tu cua mang: ");
        scanf("%d", &n);
        int a[n];
        int cnt[100] = {0};
        int cnt_copy[100] = {0};
        for (i = 0; i < n; i++) {
            printf("Nhap phan tu thu %d:", i + 1);
            scanf("%d", &a[i]);
            cnt[a[i]]++;
            cnt_copy[a[i]]++;
        }
        
        int max = 0;
        for (i = 0; i < n; i++) {
            if (cnt[a[i]] > max) {
                max = cnt[a[i]];
            }
        }
        
        for (i = 0; i < n; i++) {
            if (cnt[a[i]] != 0) {
                printf("phan tu %d xuat hien %d lan.\n", a[i], cnt[a[i]]);
                cnt[a[i]] = 0; // set the count to zero to avoid duplicates
            }
        }
        
        printf("Phan tu xuat hien nhieu nhat la: ");
        for (i = 0; i < n; i++) {
            if (cnt_copy[a[i]] == max) {
                printf("%d ", a[i]);
                cnt_copy[a[i]] = 0; // set the count to zero to avoid duplicates
            }
        }
        printf("\n");
    }
    return 0;
}

