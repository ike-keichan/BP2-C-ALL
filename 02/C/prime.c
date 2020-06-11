/*
   prime.c
   素数を判定
*/

#include <stdio.h>
int main()
{
    int number, i, flag=0, Number;
    scanf("%d", &Number);

    for(number=2; number<=Number; number++){
        flag=0;
        for(i=2; i<number; i++){
            if(number % i == 0){
                flag=1;
            }
        }
        if(flag==0){
            printf("%d is prime\n", number);
        }else {
            printf("%d is not prime\n", number);
        }
        
    }

    return 0;
}
