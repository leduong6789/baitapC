#include <stdio.h>

int main()
{
	int i,j;
    for(i=1;i<=10;i++){
        for(j=2;j<=9;j++){
            printf("%c%2dx%2d=%3d",179,j,i,i*j);
        }
        printf("%c\n",179);
    }

    return 0;
}


