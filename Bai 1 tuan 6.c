#include <stdio.h>
int main(){
	int i,j=31,l,r;
	float fahrenheit,celsius;
	printf("Celsius\t \tFahrenheit\tFahrenheit\t\tCelsius\n");
	for(i=0;i<=10;i++){
		fahrenheit = (9*i*1.0)/5.0 + 32.0;
		printf("\t%d\t  %.2f\t\t",i,fahrenheit);
		j++;
		for(j;j<=42;j++){
			celsius = 5.0/9.0*(1.0*j-32.0);
			printf("\t%d\t    \t%.2f\n",j,celsius);
			break;
		}
	}
	return 0;	
}

