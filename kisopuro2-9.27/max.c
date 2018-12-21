/*
   max.c
   入力した数字を比較する
*/

#include <stdio.h>
int main()
{
    int num1, num2, num3, answer;
    scanf("%d", &num1);
    scanf("%d", &num2);
    scanf("%d", &num3);
    printf("num1: %d, num2: %d, num3: %d\n", num1, num2, num3);

    if(num1 > num2){
        answer = num1;
        if(num1 > num3){
            printf("answer: %d\n", answer);
        } else{
            answer = num3;
            printf("answer: %d\n", answer);
        }
    } else{
        answer = num2;
        if(num2 > num3){
            printf("answer: %d\n", answer);
        } else{
            answer = num3;
            printf("answer: %d\n", answer);
        }
    }

    return 0;
}
