/*
   kadai7-1.c
   うるう年を判定
*/

#include <stdio.h>

int result(int x)
{
    switch(leapyear(x)){
        if(x==0){
            return 1;
        } else{
            return 2;
        }
    }
}
    
int leapyear(int year, int x)
{
    if((year % 4 == 0)&&                         // 4で割り切れる
       ((year % 100 != 0)||(year % 400 == 0))){  // 100で割れないor400で割り切れる
        x=0;
    } else{
        x=1;
    }
}

int main()
{
    int year;
    printf("年:");
    scanf("%d", &year);

    switch(result(x)){
    case 1:
        printf("leap\n");
        break;
    case 2:
        printf("Not leap\n");
        break;
    }

    return 0;
}
