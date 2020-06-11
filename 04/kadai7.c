/*****
      kadai7.c
*****/

#include <stdio.h>
#define num 5

int main(){
    
    int i, j=0, max, icount=0, jcount=0;
    int data1[num];
    int data2[num-1];

    for(i=0; i<num; i++){
        scanf("%d", &data1[i]);
    }

    max=data1[0];

    for(i=0; i<num; i++){
        if(data1[i] >=  max){
            max=data1[i];
        }
    }

    for(i=0; i<num; i++){
        if(max == data1[i]){
            icount++;
        }else {
            data2[j]=data1[i];
            j++;
            jcount++;
        }
    }

    printf("max:%d (%d個)\n", max, icount);

    for(j=jcount-1; j>=0; j--){
        printf("data2[%d]:%d\n", j, data2[j]);
    }

    return 0;
}
