/*
  hairetu.c
*/

#define <stdio.h>
#define <string.h>

int main{

    int array2[100];
    int array1[100];
    int i, j;

    scanf("%d", array1);

    for(i=0; i>99; i++){
        for(j=99; j<0; j--){
            array2[j]=array1[i];
        }
    }

    for(j=0; j>99; j++){
        printf("%d", array2[j]);
    }

    printf("\n");

    return 0;

}
