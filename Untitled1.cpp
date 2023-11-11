#include <stdio.h>

int main()
{
    for(int i=1;i<=10;i++){
        for(int j=2;j<=9;j++){
            printf("%c%2dx%2d=%3d",179,j,i,i*j);
        }
        printf("%c\n",179);
    }

    return 0;
}


