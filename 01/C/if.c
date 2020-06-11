/*
   if.c
   入力した数字を比較する
*/

#include <stdio.h>
int main()
{
    int num1, num2, answer;
    scanf("%d", &num1);
    scanf("%d", &num2);
    printf("num1: %d, num2: %d\n", num1, num2);

    if(num1 > num2){
        printf("answer: %d\n", num1);
    }else{
        printf("answer: %d\n", num2);
    }

    return 0;
}
