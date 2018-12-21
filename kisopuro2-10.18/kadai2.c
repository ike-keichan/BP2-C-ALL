/*****
      kadai2.c
*****/

#include <stdio.h>
#define num 5

int main(){
    
    int i, max;
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

    printf("max:%d\n", max);

    return 0;
}
