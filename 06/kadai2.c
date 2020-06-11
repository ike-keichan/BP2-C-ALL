/*****
      kadai2.c
*****/

#include <stdio.h>
#include <string.h>

int main(){

    char string1[100];
    char string2[100];
    int i=0;

    for(;;){
        scanf("%s", string2);
        if(string2=='end'){
            break;
        }else {
            strcat(string1, string2);
            string2[i]=0;
        }
    }

    printf("%s\n", string1);

    return 0;
}
