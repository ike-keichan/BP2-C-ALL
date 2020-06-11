/*
  kadai6.c
*/

#include <stdio.h>

int janken(int me, int you)
{
    if(me==you){ //あいこだった
        return 1;
    } else if(((me==1)&&(you==2)) //自分がグー
             ||((me==2)&&(you==3)) //チョキ
             ||((me==3)&&(you==1))){ //パー
        return 2;
    } else{
        return 3;
    }
}

int main(){
    int me,you;

    printf("1:グー,2:チョキ,3:パー\n");
    printf("私:");
    scanf("%d", &me);
    printf("相手:");
    scanf("%d", &you);
    

    switch(janken(me, you)){
    case 1:
        printf("even\n");
        break;
    case 2:
        printf("win\n");
        break;
    default:
        printf("loose\n");
        break;
    }

    return 0;
}
