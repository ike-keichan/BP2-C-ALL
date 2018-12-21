/*****
      kadai8.c
*****/

#include <stdio.h>
#define num 5
#define NUM 100

int main(){
    
    int i, j=0, k=0;
    int data1[num];
    int data2[NUM];
    int data3[num];

    for(i=0; i<num; i++){
        scanf("%d", &data1[i]);
        j=data1[i];
        data2[j]=1;
    }

    for(j=0; j<NUM; j++){
        if(data2[j]==1){
            data3[k]=j;
            k++;
        }
    }

    for(k=0; k<num; k++){
        printf("%d ", data3[k]);
    }

    printf("\n");

    return 0;
}
