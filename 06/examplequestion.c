/*****
      examplequestion.c
*****/

#include <stdio.h>

int main(){

    char string[100];
    int length;

    scanf("%s", string);

    length=0;
    while( string[length]!='\0'){
        length++;
    }

    printf("%d\n", length);

    return 0;
}
