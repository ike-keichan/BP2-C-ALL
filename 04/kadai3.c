/*****
      kadai3.c
*****/

#include <stdio.h>
#define num 5

int main(){
    
    int i, max, count=0;
    int data[num];

    for(i=0; i<num; i++){
        scanf("%d", &data[i]);
    }

    max=data[0];

    for(i=0; i<num; i++){
        if(data[i] >=  max){
            max=data[i];
        }
    }

    for(i=0; i<num; i++){
        if(max == data[i]){
            count++;
        }
    }     

    printf("max:%d (%d個)\n", max, count);

    return 0;
}
