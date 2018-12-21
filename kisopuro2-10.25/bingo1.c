/*
 ビンゴ
 */
#include <stdio.h>

#define SIZE 3 // パターンのサイズ 3x3

int main()
{
    int card[SIZE][SIZE];
    int x, y;
    
    // カードのデータ入力
    for (y=0; y<SIZE; y++) {
        for (x=0; x<SIZE; x++) {
            scanf("%d", &card[x][y]);
        }
    }
 
    // 確認のため出力
    for (y=0; y<SIZE; y++) {
        for (x=0; x<SIZE; x++) {
            printf(" %2d", card[x][y]);
        }
        printf("\n");
    }
    
    return 0;
}
