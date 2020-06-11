/*
 kadai2.c
 跳ね返る魚
 */

#include <stdio.h>
#include <math.h>
#include <handy.h>

int fish(double x, double y, double z, double size, double j)
{
    int i;
    
    HgSetColor(HG_RED); // 赤色
    HgSetFillColor(HG_RED);
    if(j==0){     //左向き
        HgFanFill(x, y, size, 1.25*M_PI, 0.75*M_PI, 0); // アタマを描く
        HgMoveTo(x*z+size*z, y*z); // 胴骨
        HgLineTo(x*z+size*3.0*z, y*z); // 胴骨
        HgLineTo(x*z+size*4.0*z, y*z-size*z); // 尾びれ
        HgMoveTo(x*z+size*3.0*z, y*z);
        HgLineTo(x*z+size*4.0*z, y*z+size*z); // 尾びれ
        HgSetFillColor(HG_WHITE); // 白色
        HgCircleFill(x*z+size/3.0*z, y*z+size/2.0*z, size/4.0*z, 0); // 目を入れる
        HgSetColor(HG_RED); // 赤色
        for(i=0; i<5; i++) { // 胴骨
            HgLine(x*z+size*1.2*z+i*size/3.0*z, y*z-size/2.0*z,
                   x*z+size*1.2*z+i*size/3.0*z, y*z+size/2.0*z);
        }
    }else if(j==1){    //右向き
        HgFanFill(x, y, size, 0.25*M_PI, 1.75*M_PI, 0); // アタマを描く
        HgMoveTo(x*z-size*z, y*z); // 胴骨
        HgLineTo(x*z-size*3.0*z, y*z); // 胴骨
        HgLineTo(x*z-size*4.0*z, y*z-size*z); // 尾びれ
        HgMoveTo(x*z-size*3.0*z, y*z);
        HgLineTo(x*z-size*4.0*z, y*z+size*z); // 尾びれ
        HgSetFillColor(HG_WHITE); // 白色
        HgCircleFill(x*z-size/3.0*z, y*z+size/2.0*z, size/4.0*z, 0); // 目を入れる
        HgSetColor(HG_RED); // 赤色
        for(i=0; i<5; i++) { // 胴骨
            HgLine(x*z-size*1.2*z-i*size/3.0*z, y*z-size/2.0*z,
                   x*z-size*1.2*z-i*size/3.0*z, y*z+size/2.0*z);
            }
    }

    return 1;
}

int main()
{
    double x, y, z,  size, dx, dy;
    int j, k;

    HgOpen(400.0, 400.0);

    x=200.0; y=200.0; // x, y 座標の初期設定
    z=1.0;            // z 座標の初期設定（倍率）
    size=10.0;        // アタマの半径を決める
    dx=-0.8 * size;   // x 方向の移動速度
    dy=0.4 * size;    // y 方向の移動速度
    j=0; k=0;      // j , k カウント

    while(1) {
        HgClear();          // 画面を消去

        fish(x, y, z, size, j);  //魚を描く
        
        if( y < size || y > (400.0 - size)) dy*=(-1.0);
        y+= dy;
        if( x < size || x > (400.0 - size)) dx*=(-1.0);
        x+= dx;

        if(x<=12){
            j=1;
        }else if(388<=x){
            j=0;
        }

        if(z==1.0){
            k=0;
        }else if(z==5.0){
            k=1;
        }

        if(k==0){
            z++;
        }else if(k==1){
            z--;
        }
            
        
        
        HgSleep(0.1); // 少し待つ
    }

    return 0;
}

