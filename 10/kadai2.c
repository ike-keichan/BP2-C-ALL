/*****
      kadai2.c
*****/

#include <stdio.h>
#define num 5


int judge( int data[])
{

    int max, i;

        max=data[0];

        for(i=0; i<num; i++){
            if(data[i] >=  max){
                max=data[i];
            }
        }
        
        return max;
}
        
int main()
{
    
    int i, max=0;
    int data[num];

    for(i=0; i<num; i++){
        scanf("%d", &data[i]);
    }

    max=judge(data);

    printf("max:%d\n", max);

    return 0;
}
