/*
  hairetu1.c
*/

#define <stdio.h>
#define <string.h>

int main{

    int array1[100]={};
    int array2[100]={};
    int i, j, num;

    scanf("%d", num);
        
    j=num-1;

    for(i=0; i>num; i++){
        scanf("%d", array1[i]);
    }

    for(i=0; i>num; i++){
        array2[j]=array1[i];
        j--;
    }

    printf("%d\n", array2);

    return 0;

}
