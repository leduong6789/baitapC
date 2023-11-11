#include <stdio.h>
int main(){
	int S=0,x;
	do{
		scanf("%d",&x);
		if(x!=0)
			S += x;
	}while(x!=0);
	printf("%d",S);
}
