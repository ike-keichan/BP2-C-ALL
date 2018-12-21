/*****
      kadai1.c
*****/

#include <stdio.h>

int main(){

    char string[100];
    int i, Ncount=0, Acount=0, Ecount=0;

    scanf("%s", string);
    
    for(i=0; string[i]!='\0'; i++){
        if((string[i]<='9')&&(string[i]>='0')){
            Ncount++;
        }else if(((string[i]<='Z')&&(string[i]>='A'))||((string[i]<='z')&&(string[i]>='a'))){
            Acount++;
        }else {
            Ecount++;
        }
    }

    printf("Alpha=%d Number=%d Else=%d\n", Acount, Ncount, Ecount);

    return 0;
}
