#include <stdio.h>
int main(){
	int x,y,tam;
	scanf("%d %d",&x,&y);
	while(y){
		tam = x;
		x=y;
		y=tam%y;	
	}
	printf("UCLN la: %d",x);
}
