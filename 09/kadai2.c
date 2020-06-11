/*
 kadai2.c
 跳ね返る魚
 */

#include <stdio.h>
#include <math.h>
#include <handy.h>

int fish(double x, double y, double size, double j)
{
    int i;
    
    HgSetColor(HG_RED); // 赤色
    HgSetFillColor(HG_RED);
    if(j==0){     //左向き
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
    }else if(j==1){    //右向き
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
    int j;

    HgOpen(400.0, 400.0);

    x=200.0; y=200.0; // x, y 座標の初期設定
    size=10.0;        // アタマの半径を決める
    dx=-0.8 * size;   // x 方向の移動速度
    dy=0.4 * size;    // y 方向の移動速度
    j=0;              // j カウント

    while(1) {
        HgClear();          // 画面を消去

        fish(x, y, size, j);  //魚を描く
        
        if( y < size || y > (400.0 - size)) dy*=(-1.0);
        y+= dy;
        if( x < size || x > (400.0 - size)) dx*=(-1.0);
        x+= dx;

        if(x<=12){
            j=1;
        }else if(388<=x){
            j=0;
        }
        HgSleep(0.1); // 少し待つ
    }

    return 0;
}

