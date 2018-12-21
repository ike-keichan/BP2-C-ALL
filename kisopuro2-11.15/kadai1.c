/*
  kadai1.c
*/

#include <stdio.h>
#include <string.h>
#include <handy.h>

int main(){

    char string[100];
    char array[2];
    int i, x, y, num;
    
    printf("input string >> ");
    scanf("%s", string);
    
    num=0;
    while(string[num]!='\0'){
        num++;
    }

    HgOpen(400.0, 400.0);
    x=100.0;
    y=100.0;

    for(i=0; i<num; i++){
        array[0]=string[i];
        HgText(x, y, array);
        x=x+25;
        y=y+25;
    }

    HgGetChar();
    HgClose();
    
    return 0;

}
