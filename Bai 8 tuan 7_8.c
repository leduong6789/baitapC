#include <stdio.h>
void mm(int n){
    int min,max,i,d;
    min=max=n%10;
    while(n){
        d = n%10;
        n/=10;
        if(min>d)
            min = d;
        else if(max<d)
            max=d;
    }
    printf("%d %d",min,max);
    
}
int main(){
    int n;
    do{
    	scanf("%d",&n);
	}while(n<0);
    mm(n);
    return 0;
}
