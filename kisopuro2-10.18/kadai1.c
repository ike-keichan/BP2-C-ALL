/*****
      kadai1.c
*****/

#include <stdio.h>
#define num 5

int main(){
    
    int i;
    int data[num];

    for(i=0; i<num; i++){
        scanf("%d", &data[i]);
    }

    for(i=num-1; i>=0; i--){
        printf("data[%d]:%d\n", i, data[i]);
    }

    return 0;
}
