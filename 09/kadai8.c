/*
   kadai8.c
   素数を判定
*/

#include <stdio.h>

int judge(int Num)
{
    int i, num;
    
    for(num=2; num<=Num; num++){
        for(i=2; i<num; i++){
            if(num % i == 0){
                return 1;
            } else{
                return 2;
            }
        }
    }
}



int main()
{
    int number, Num;
    scanf("%d", &Num);

     number=judge(Num);

    switch(judge(Num)){
        
    case 1:
            printf("%d is prime\n", number);
    case 2:
            printf("%d is not prime\n", number);
    }

    return 0;
}
