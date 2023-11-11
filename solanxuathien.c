#include <stdio.h>
int main(){
	int t;
	printf("Nhap so test case: ");
	scanf("%d",&t);
	while(t--){
		int n,i;
		printf("Nhap so luong phan tu trong mang: ");
		scanf("%d",&n);
		int a[n],cnt[100] = {0};
		int cnt_copy[100] = {0};
		for(i=0;i<n;i++){
			printf("Nhap phan tu thu %d: ",i+1);
			scanf("%d",&a[i]);
			cnt[a[i]]++;
			cnt_copy[a[i]]++;
		}
		int res = 0;
		for(i=0;i<n;i++){
			if(cnt[a[i]]>res)
				res = cnt[a[i]];
		}
		for(i=0;i<n;i++){
			if(cnt[a[i]]!=0){
				printf("Phan tu %d xuat hien %d lan.\n",a[i],cnt[a[i]]);
				cnt[a[i]]=0;
			}
		}
		for(i=0;i<n;i++){
			if(cnt_copy[a[i]]==res){
				printf("Phan tu xuat hien nhieu nhat: %d ",a[i]);
				cnt_copy[a[i]] = 0;
			}
		}
		printf("\n");
	}
}
