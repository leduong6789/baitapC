#include <stdio.h>

int main()
{
    int sum=0,n,a,i;
    float sum1,cnt;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a);
        sum = sum + a;
        cnt++;
    }
    printf("%d\n",sum);
    sum1 = (float)sum / cnt;
    printf("%.1f",sum1);

    return 0;
}

