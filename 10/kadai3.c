/*****
      kadai3.c
*****/

#include <stdio.h>

int magic(int array[3][3])
{
    int sum1, sum2, i;
    int result=0;

    sum1=array[0][0]+array[0][1]+array[0][2];

    for(i=0; i<3; i++){
        
        sum2=array[i][0]+array[i][1]+array[i][2];

        if(sum1==sum2){
            result+=1;
        }
    }

    for(i=0; i<3; i++){

        sum2=array[0][i]+array[1][i]+array[2][i];

        if(sum1==sum2){
            result+=1;
        }
    }

    sum2=array[0][0]+array[1][1]+array[2][2];

    if(sum1==sum2){
        result+=1;
    }

    sum2=array[0][2]+array[1][1]+array[2][0];

    if(sum1==sum2){
        result+=1;
    }
        
        return result;
}
        
int main()
{
    int array[3][3];
    int i, j, result;

    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
           scanf("%d", &array[i][j]); 
        }
    }

    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    result=magic(array);

    if(result==8){
        printf("Magic Square\n");
    }else {
        printf("Not Magic Square\n");
    }
    
    return 0;
}
