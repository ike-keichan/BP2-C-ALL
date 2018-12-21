/*
   kadai7.c
   うるう年を判定
*/

#include <stdio.h>
    
int leapyear(int year)
{
    if((year % 4 == 0)&&                         // 4で割り切れる
       ((year % 100 != 0)||(year % 400 == 0))){  // 100で割れないor400で割り切れる
        return 1;
    } else{
        return 2;
    }
}

int main()
{
    int year;
    printf("年:");
    scanf("%d", &year);

    switch(leapyear(year)){
    case 1:
        printf("leap\n");
        break;
    case 2:
        printf("Not leap\n");
        break;
    }

    return 0;
}
