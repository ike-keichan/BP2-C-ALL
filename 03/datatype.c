/*
   datatype.c
   データ型の確認
*/

#include <stdio.h>
int main()
{
    short s;
    float f;
    int i;
    double d;

    s=100;
    i=200;
    f=300.0f;
    d=400.0;

    printf("short %d\n" ,s);
    printf("int %d\n" ,i);
    printf("float %f\n" ,f);
    printf("double %f\n" ,d);

    return 0;
}
