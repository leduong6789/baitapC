#include <stdio.h>
int getRelPos(double x ,double y, double r){
	double d2 = x*x + y*y;
	double r2 = r*r;
	if(d2==r2)
		return 1;
	else if(d2<r2){
		return 0;
	}
	else return -1;
}
int main(){
	double r,x,y;
	do{
		scanf("%lf %lf %lf",&x ,&y,&r);
	}while(r<=0);
	int result = getRelPos(x,y,r);
	if(result==1)
		printf("The point is on the circle.");
	else if(result==0)
		printf("The point is inside the circle.");
	else printf("The point is outside the circle.");
	return 0;
}
	
