#include <stdio.h>
int main(){
	int x,y;
	scanf("%d %d",&x,&y);
	if(x>=0 && y>=0)
		printf("The cordinate point (%d,%d) lies in the First quadrant",x,y);
	if(x<=0&&y>=0)
		printf("The cordinate point (%d,%d) lies in the Second quadrant",x,y);
	if(x<=0&&y<=0)
		printf("The cordinate point (%d,%d) lies in the Third quadrant",x,y);
	if(x>=0&&y<=0)
		printf("The cordinate point (%d,%d) lies in the Fourth quadrant",x,y);
	return 0;
}
