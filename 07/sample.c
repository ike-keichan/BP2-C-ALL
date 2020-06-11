/*
  sample.c
*/

#include <stdio.h>
#include <string.h>
#include <handy.h>

int main(){

    char string[100];
    
    printf("input string >> ");
    scanf("%s", string);

    HgOpen(400.0, 400.0);
    HgText(100.0, 200.0, string);

    HgGetChar();
    HgClose();
    
    return 0;

}
