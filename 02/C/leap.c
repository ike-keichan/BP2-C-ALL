/*
   leap.c
   うるう年を判定
*/

#include <stdio.h>
int main()
{
    int year;
    scanf("%d", &year);
    printf("%d\n", year);

    if((year % 4 == 0)&&((year % 100 != 0)||(year % 400 == 0))){
        printf("leap\n");
    }

    return 0;
}
