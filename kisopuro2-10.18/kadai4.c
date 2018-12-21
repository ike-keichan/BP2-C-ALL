/*****
      kadai4.c
*****/

#include <stdio.h>
#define num 5

int main(){
    
    int i, j=0, max, icount=0, jcount=0;
    int data[num];
    int other[num-1];

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
            icount++;
        }else {
            other[j]=data[i];
            j++;
            jcount++;
        }
    }

    printf("max:%d (%d個)\n", max, icount);
    printf("other:");

    for(j=0; j<jcount; j++){
        printf("%d ", other[j]);
    }

    printf("\n");

    return 0;
}
