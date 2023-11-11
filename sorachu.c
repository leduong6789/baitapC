#include <stdio.h>

int main()
{
    int sum=0,n,a,cnt;
    float sum1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        sum = sum + a;
        cnt++;
    }
    printf("%d\n",sum);
    sum1 = (float)sum /(float)cnt;
    printf("%.1f",sum1);

    return 0;
}
