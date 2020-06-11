/*
   datatype1.c
   データ型の確認
*/

#include <stdio.h>
int main()
{
   
    double d;
    d=0.0;

    while(1){
        if(d==10.0) break;
        printf("double %f\n" ,d);
        d+=0.5;
    }

    return 0;
}
