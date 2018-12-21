/*
 二次元配列の各要素にデータを格納して横（行ごと）の合計を出す
 */
#include <stdio.h>

int main()
{
	int data[3][5];
	int i, j, sum;
	
	for (i=0; i<3; i++) {
		for (j=0; j<5; j++) {
			scanf("%d", &data[i][j]);
		}
	}

	for (i=0; i<3; i++) {
		sum=0;
		for (j=0; j<5; j++) {
			printf(" %2d", data[i][j]);
			sum += data[i][j];
		}
		printf(" : %2d\n", sum);
	}
	
	return 0;
}
