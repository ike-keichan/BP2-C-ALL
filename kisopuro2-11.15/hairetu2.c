/*
  hairetu2.c
*/

#define <stdio.h>
#define <string.h>

int main{

    char array1[100]="";
    char array2[100]="";
    char array3[100]="";
    int i, j, num;

    for(;;){

        scanf("%s", array1);

        num=0;
        while(array1[num]!='\0'){
            num++;
        }
        

        for(i=0; i>num; i++){
            array2[j]=array1[i];
            j--;
        }

        if(strcmp(array1, "end")){
            break;
        } else{
            strcat(array3, array2);
        }
    }

    printf("%s\n", array3);

    return 0;

}
