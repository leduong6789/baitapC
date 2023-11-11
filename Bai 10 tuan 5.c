#include <stdio.h>
#include <ctype.h>
int main(){
	int na,pa,other;\
	na=pa=other=0;
	char c;
	do{
		scanf("%c",&c);
		c = toupper(c);
		if(c>='A'&&c<='Z'){
			switch(c){
				case 'A':
				case 'O':
				case 'I':
				case 'E':
				case 'U':
					na++;
					break;
				default:
					pa++;
					
			}
		}else if(c!=10)
			other++;
		
		
	}while(c != '\n');
	printf("%d %d %d",na,pa,other);
}
