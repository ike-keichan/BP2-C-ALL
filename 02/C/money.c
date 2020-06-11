/*
   money.c
   金種計算
*/

#include <stdio.h>
int main()
{
    int total, i;
    int array[6] = {500, 100, 50, 10, 5, 1};
    int num[6];
    scanf("%d", &total);

    for(i=0; i<6; i++){
        num[i] = total / array[i];
        total = total % array[i];
    }

    printf("500:%d 100:%d 50:%d 10:%d 5:%d 1:%d\n", num[0],num[1], num[2], num[3], num[4], num[5]);

    return 0;
}
