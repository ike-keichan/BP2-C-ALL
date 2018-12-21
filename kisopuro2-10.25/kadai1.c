/*
 二次元配列の各要素にデータを格納して横（行ごと）の合計を出す
 */
#include <stdio.h>

int main()
{
    int data[3][5];
    int i, j, xsum, ysum;

    for (i=0; i<3; i++){
        for (j=0; j<5; j++){
            scanf("%d", &data[i][j]);
        }
    }

    for (i=0; i<3; i++){
        xsum=0;
        for (j=0; j<5; j++) {
            printf(" %2d", data[i][j]);
            xsum += data[i][j];
        }
        printf(" : %2d\n", xsum);
    }

    printf(" -- -- -- -- --\n");

    for (j=0; j<5; j++){
        ysum=0;
        for (i=0; i<3; i++){
            ysum += data[i][j];
        }
        printf(" %d", ysum);
    }

    printf("\n");

    return 0;
}
