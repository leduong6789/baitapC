#include <stdio.h>
#include <ctype.h>
int main()
{
    char c;
    int letter = 0, digit = 0, other = 0;
    printf("Nhap chuoi ky tu: ");
    while ((c = getchar()) != '\n')
    {
        if (isalpha(c))
        {
            letter++;
        }
        else if (isdigit(c))
        {
            digit++;
        }
        else
        {
            other++;
        }
    }

    printf("So luong ky tu: %d\n", letter);
    printf("So luong so: %d\n", digit);
    printf("So luong ky tu khac: %d\n", other);

    return 0;
}

