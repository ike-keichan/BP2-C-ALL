/*
 ビンゴ
 */
#include <stdio.h>

#define SIZE 3 // パターンのサイズ 3x3
#define NUM 5 // ルーレットの数字

int main()
{
    int card[SIZE][SIZE];
    int rou[NUM];
    int x, y, i, flag=0;
    
    // カードのデータ入力
    for(y=0; y<SIZE; y++) {
        for(x=0; x<SIZE; x++) {
            scanf("%d", &card[x][y]);
        }
    }
 
    // 確認のため出力
    for(y=0; y<SIZE; y++) {
        for(x=0; x<SIZE; x++) {
            printf(" %2d", card[x][y]);
        }
        printf("\n");
    }

    printf(" -- -- --\n");

    // ルーレットの数字入力
    for(i=0; i<5; i++){
        scanf("%d", &rou[i]);
    }

    // カードを貫く
    for(y=0; y<SIZE; y++) {
        for(x=0; x<SIZE; x++) {
            for(i=0; i<NUM; i++){
                if(card[x][y] == rou[i]){
                    card[x][y]=0;
                }
            }
            if(card[x][y]==0){
                printf(" ・");
            } else{
                printf(" %2d", card[x][y]);
            }
        }
        printf("\n");
    }

    printf(" -- -- --\n");

    // ビンゴを判断
    for(y=0; y<SIZE; y++){
        for(x=0; x<SIZE; x++){
            if((card[x][0]==0)&&(card[x][1]==0)&&(card[x][2]==0)){
                flag=1;
            }else if((card[0][y]==0)&&(card[1][y]==0)&&(card[2][y]==0)){
                flag=1;
            }else if((card[0][0]==0)&&(card[1][1]==0)&&(card[2][2]==0)){
                flag=1;
            }else if((card[0][2]==0)&&(card[1][1]==0)&&(card[2][0]==0)){
                flag=1;
            }
        }
    }

    if(flag==1){
        printf("Bingo\n");
    }else {
        printf("Not Bingo\n");
    }
    
    return 0;
}
