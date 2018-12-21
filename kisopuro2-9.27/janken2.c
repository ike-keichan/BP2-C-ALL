/*
  janken2.c
  ジャンケンをする
  グー=1,チョキ=2,パー=3
*/

#include <stdio.h>

int main()
{
    int num1, num2;
    printf("グー:1,チョキ:2,パー:3\n");
    scanf("%d", &num1);
    scanf("%d", &num2);
    printf("you: %d, enemy: %d\n", num1, num2);

    if(num1==num2){
        printf("even\n");
    } else if((num1==1 && num2==2)||(num1==2 && num2==3)||(num1==3 && num2==1)){
        printf("win\n");
    } else if((num1==1 && num2==3)||(num1==2 && num2==1)||(num1==3 && num2==2)){
        printf("lose\n");
    }

    return 0;
}
