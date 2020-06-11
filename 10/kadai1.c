/*
 kadai2.c
 跳ね返る魚
 */

#include <stdio.h>
#include <math.h>
#include <handy.h>
#include <stdlib.h>

int fish(double x, double y, double size, double dx)
{
    int i;
    
    HgSetColor(HG_RED); // 赤色
    HgSetFillColor(HG_RED);
    if(dx <= 0.0){     //左向き
        HgFanFill(x, y, size, 1.25*M_PI, 0.75*M_PI, 0); // アタマを描く
        HgMoveTo(x+size, y); // 胴骨
        HgLineTo(x+size*3.0, y); // 胴骨
        HgLineTo(x+size*4.0, y-size); // 尾びれ
        HgMoveTo(x+size*3.0, y);
        HgLineTo(x+size*4.0, y+size); // 尾びれ
        HgSetFillColor(HG_WHITE); // 白色
        HgCircleFill(x+size/3.0, y+size/2.0, size/4.0, 0); // 目を入れる
        HgSetColor(HG_RED); // 赤色
        for(i=0; i<5; i++) { // 胴骨
            HgLine(x+size*1.2+i*size/3.0, y-size/2.0,
                   x+size*1.2+i*size/3.0, y+size/2.0);
        }
    }else {    //右向き
        HgFanFill(x, y, size, 0.25*M_PI, 1.75*M_PI, 0); // アタマを描く
        HgMoveTo(x-size, y); // 胴骨
        HgLineTo(x-size*3.0, y); // 胴骨
        HgLineTo(x-size*4.0, y-size); // 尾びれ
        HgMoveTo(x-size*3.0, y);
        HgLineTo(x-size*4.0, y+size); // 尾びれ
        HgSetFillColor(HG_WHITE); // 白色
        HgCircleFill(x-size/3.0, y+size/2.0, size/4.0, 0); // 目を入れる
        HgSetColor(HG_RED); // 赤色
        for(i=0; i<5; i++) { // 胴骨
            HgLine(x-size*1.2-i*size/3.0, y-size/2.0,
                   x-size*1.2-i*size/3.0, y+size/2.0);
        }
    }

    return 1;
}

int main()
{
    double x, y, size, dx, dy;
    int i , num;

    HgOpen(400.0, 400.0);

    srand(time(NULL));
    for(i=0; i<10; i++){
        num[i]=rand();

        x[i]=num[i]%400;    // x, y 座標の初期設定
        y[i]=num[i]%400;
        size[i]=num[i]%20;  // アタマの半径を決める
        dx=-0.8 * size[i];   // x 方向の移動速度
        dy=0.4 * size[i];    // y 方向の移動速度
    }
        
    while(1) {

        for(i=0; i<10; i++){

            HgClear();          // 画面を消去
            
            fish(x, y, size, dx);  //魚を描く

            if( y < size || y > (400.0 - size)) dy*=(-1.0); y+= dy;

            if( x < size || x > (400.0 - size)) dx*=(-1.0); x+= dx;

            HgSleep(0.1); // 少し待つ
        }
    }

    return 0;
}

