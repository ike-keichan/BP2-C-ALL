/*
   calc1.c
   演算を試す
    数値はハードコアで与える
*/

#include <stdio.h>
int main()
{
    int num1, num2, answer;
    scanf("%d", &num1);
    scanf("%d", &num2);
    printf("num1: %d, num2: %d\n", num1, num2);
    answer = num1 + num2;

    printf("answer: %d\n", answer);

    return 0;
}
