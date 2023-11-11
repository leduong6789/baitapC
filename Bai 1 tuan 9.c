#include <stdio.h>
#include <math.h>
int main(){
	int x[100];
	int n,i,sum=0;
	float sum1=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Nhap phan tu thu %d: ",i+1);
		scanf("%d",&x[i]);
		sum += x[i];
		sum1 += pow(x[i],2);
	}
	printf("b/ ");
	for(i=0;i<n;i++)
		printf("%d ",x[i]);
	printf("\nc/ ");
	float tb = 1.0*sum/(n*1.0);
	printf("%.2f\n",tb);
	printf("d/ %.2f\n",sum1);
	float d2 = 1.0*(sum1/(float)n) - 1.0*tb*tb;
	float d = sqrt(d2);
	printf("e/ %.2f\nf/ %.2f",d2,d);
	return 0;
}
