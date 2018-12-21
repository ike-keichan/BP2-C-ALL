/*****
      kadai6.c
*****/

#include <stdio.h>
#define num 5

int main(){
    
    int i;
    int data1[num];
    int data2[num];

    for(i=0; i<num; i++){
        scanf("%d", &data1[i]);
    }

    for(i=num-1; i>=0; i--){
        data2[num-1-i]=data1[i];
        printf("data2[%d]:%d\n", num-1-i, data2[num-1-i]);
    }

    return 0;
}
