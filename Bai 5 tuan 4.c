#include <stdio.h>

int main(){
	int n;
	printf("Nhap so co 2 chu so: ");
	scanf("%d",&n);
	char hang_chuc[10][10] = {"","Muoi","Hai muoi","Ba muoi","Bon muoi","Nam muoi","Sau muoi","Bay muoi","Tam muoi","Chin muoi"};
	char hang_dv[10][10] = {"","mot","hai","ba","bon","nam","sau","bay","tam","chin"};
	int dv = n%10,chuc = n/10;
	if(chuc == 1 && dv == 0)
		printf("Muoi lam");
	else if(chuc ==1 && dv == 5)
		printf("%s lam",hang_chuc[chuc]);
	else if(dv ==1)
		printf("%s mot",hang_chuc[chuc]);
	else if(dv == 5)
		printf("%s lam",hang_chuc[chuc]);
	else printf("%s %s",hang_chuc[chuc],hang_dv[dv]);	
	return(0);		
}
