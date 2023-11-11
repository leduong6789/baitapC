#include <stdio.h>
#include <math.h>
double tamgiac(double x1,double y1,double x2,double y2,double x3,double y3){
	double d1 = sqrt( pow((x2-x1),2) + pow((y2-y1),2) ); 
	double d2 = sqrt( pow((x3-x2),2) + pow((y3-y2),2) );
	double d3 = sqrt( pow((x3-x1),2) + pow((y3-y1),2) );	
	if(((d1+d2)>d3)&&(d2+d3)>d1&&(d1+d3>d2)){
		return 1;
	}else return 0;
}
double dt(double d1,double d2,double d3){
	double cv = (d1+d2+d3)/2;
	double dt = sqrt(cv*fabs((cv-d1))*fabs((cv-d2))*fabs((cv-d3)));
	return dt;
}
int main(){
	double x1,x2,x3,y1,y2,y3,cv;
	scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3);
	double d1 = sqrt( pow((x2-x1),2) + pow((y2-y1),2) ); 
	double d2 = sqrt( pow((x3-x2),2) + pow((y3-y2),2) );
	double d3 = sqrt( pow((x3-x1),2) + pow((y3-y1),2) );
	double result = tamgiac(x1,y1,x2,y2,x3,y3);
	if(result==1)
		printf("day la tam giac voi dien tich la: %.2lf",dt(d1,d2,d3));
	else printf("day khong phai tam giac");
}
