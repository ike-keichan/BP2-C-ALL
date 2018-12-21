/*
 kadai3.c
 */
#include <stdio.h>

#define NUM 3
#define ALL 9

int main()
{
    int box1[NUM][NUM];
    int box2[NUM][NUM];
    int tmp[ALL];
    int x, y, i=0;
    
    // データ入力
    for(x=0; x<NUM; x++) {
        for(y=0; y<NUM; y++) {
            scanf("%d", &box1[x][y]);
        }
    }
 
    // 出力
    printf("before\n");

    for(x=0; x<NUM; x++) {
        for(y=0; y<NUM; y++) {
            if(box1[x][y]==1){
                printf(" ■");
            }else {
                printf(" □");
            }
        }
        printf("\n");
    }

    // 配列を入れ替える
    for(y=0; y<NUM; y++) {
        for(x=2; 0<=x; x--) {
            tmp[i]=box1[x][y];
            i++;
        }
    }
    i=0;
    for(x=0; x<NUM; x++) {
        for(y=0; y<NUM; y++) {
            box2[x][y]=tmp[i];
            i++;
        }
    }
    
    // 出力
    printf("after\n");

    for(x=0; x<NUM; x++) {
        for(y=0; y<NUM; y++) {
            if(box2[x][y]==1){
                printf(" ■");
            }else {
                printf(" □");
            }
        }
        printf("\n");
    }
                
    return 0;
}
