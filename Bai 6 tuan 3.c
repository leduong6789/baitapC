#include <stdio.h>
int main(){
	char kt;
	scanf("%s",&kt);
	if(kt>=65 && kt<=90)
		printf("This is an uppercase character");
	if(kt>=97 && kt<=122)
		printf("This is a lowercase character");
	if((kt>=0&&kt<=47)||(kt>=58&&kt<=64)||(kt>=91&&kt<=96)||(kt>=123&&kt<=127))
		printf("This is a special character");
	return 0;
}
