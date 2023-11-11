#include <stdio.h>
#include <math.h>
int main(){
	int i,sum=0,d,temp,count;
	for(i=100;i<=1000;i++){
		count = 0;
		int temp = i;
		while(temp){
			temp /= 10;
			count++;
		}
		temp=i;
		while(temp){
			d = temp%10;
			sum += pow(d,count);
			temp /= 10;
		}
		if(sum==i){
			printf("%d  ",sum);
		}
		sum =0;
	}
	return 0;
}
