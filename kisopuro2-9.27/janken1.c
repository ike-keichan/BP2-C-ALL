/*
  janken1.c
  ジャンケンをする
  グー=1,チョキ=2,パー=3
*/

#include <stdio.h>

int main()
{
    int a=1, b=2, c=3, num1, num2;
    printf("グー:1,チョキ:2,パー:3\n");
    scanf("%d", &num1);
    scanf("%d", &num2);
    printf("you: %d, enemy: %d\n", num1, num2);

    if(num1==a){
        if(num2==a){
            printf("even\n");
        } else if(num2==b){
            printf("win\n");
        } else if(num2==c){
            printf("lose\n");
        }
    }else if(num1==b){
        if(num2==a){
            printf("lose\n");
        } else if(num2==b){
            printf("even\n");
        } else if(num2==c){
            printf("win\n");
        }
    }else if(num1==c){
        if(num2==a){
            printf("win\n");
        } else if(num2==b){
            printf("lose\n");
        } else if(num2==c){
            printf("even\n");
        }
    }

    return 0;
}

    
