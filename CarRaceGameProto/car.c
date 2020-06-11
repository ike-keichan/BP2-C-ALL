/*****
      car.c
      g1744069 Keisuke Ikeda
*****/

#include <stdio.h>
#include <handy.h>
#include <math.h>

int car1(int x1, int y1){

    HgSetColor(HG_RED);
    HgSetFillColor(HG_RED);
    HgLine(x1+10,  y1, x1+30,  y1);       //車体前面
    HgLine(x1+10, y1+50, x1+30, y1+50);   //車体後面
    HgLine(x1+5, y1+5, x1+5, y1+45);      //車体左面
    HgLine(x1+35, y1+5, x1+35, y1+45);    //車体右面
    HgLine(x1, y1+5, x1+5, y1+5);         //左前輪
    HgLine(x1, y1+15, x1+5, y1+15);
    HgLine(x1, y1+5, x1, y1+15);
    HgLine(x1, y1+30, x1+5, y1+30);       //左後輪
    HgLine(x1, y1+40, x1+5, y1+40);
    HgLine(x1, y1+30, x1, y1+40);
    HgLine(x1+35, y1+5, x1+40, y1+5);     //右前輪
    HgLine(x1+35, y1+15, x1+40, y1+15);
    HgLine(x1+40, y1+5, x1+40, y1+15);
    HgLine(x1+35, y1+30, x1+40, y1+30);   //右後輪
    HgLine(x1+35, y1+40, x1+40, y1+40);
    HgLine(x1+40, y1+30, x1+40, y1+40);
    HgArc(x1+10, y1+5, 5, M_PI, 1.5*M_PI);//角
    HgArc(x1+10, y1+45, 5, 0.5*M_PI, M_PI);
    HgArc(x1+30, y1+5, 5, 1.5*M_PI, 2.0*M_PI);
    HgArc(x1+30, y1+45, 5, 0, 0.5*M_PI);
    HgLine(x1+15, y1+5, x1+10, y1+15);    //くぼみ
    HgLine(x1+25, y1+5, x1+30, y1+15);
    HgBoxFill(x1+15, y1+15, 10, 5, 0);  //フロントガラス
    HgFanFill(x1+15, y1+15, 5, 0.5*M_PI, M_PI, 0);
    HgFanFill(x1+25, y1+15, 5, 0, 0.5*M_PI, 0);
    HgBoxFill(x1+10, y1+25, 5, 10, 0);  //ライトガラス
    HgFanFill(x1+10, y1+25, 5, 1.5*M_PI, 2.0*M_PI, 0);
    HgFanFill(x1+10, y1+35, 5, 0, 0.5*M_PI, 0);
    HgBoxFill(x1+25, y1+25, 5, 10, 0);  //レフトガラス
    HgFanFill(x1+30, y1+25, 5, M_PI, 1.5*M_PI, 0);
    HgFanFill(x1+30, y1+35, 5, 0.5*M_PI, M_PI, 0);
    
    

    return 1;
    
}

int car2(int x2, int y2){

    HgSetColor(HG_BLUE);
    HgSetFillColor(HG_BLUE);
    HgLine(x2+10,  y2, x2+30,  y2);       //車体前面
    HgLine(x2+10, y2+50, x2+30, y2+50);   //車体後面
    HgLine(x2+5, y2+5, x2+5, y2+45);      //車体左面
    HgLine(x2+35, y2+5, x2+35, y2+45);    //車体右面
    HgLine(x2, y2+5, x2+5, y2+5);         //左前輪
    HgLine(x2, y2+15, x2+5, y2+15);
    HgLine(x2, y2+5, x2, y2+15);
    HgLine(x2, y2+30, x2+5, y2+30);       //左後輪
    HgLine(x2, y2+40, x2+5, y2+40);
    HgLine(x2, y2+30, x2, y2+40);
    HgLine(x2+35, y2+5, x2+40, y2+5);     //右前輪
    HgLine(x2+35, y2+15, x2+40, y2+15);
    HgLine(x2+40, y2+5, x2+40, y2+15);
    HgLine(x2+35, y2+30, x2+40, y2+30);   //右後輪
    HgLine(x2+35, y2+40, x2+40, y2+40);
    HgLine(x2+40, y2+30, x2+40, y2+40);
    HgArc(x2+10, y2+5, 5, M_PI, 1.5*M_PI);//角
    HgArc(x2+10, y2+45, 5, 0.5*M_PI, M_PI);
    HgArc(x2+30, y2+5, 5, 1.5*M_PI, 2.0*M_PI);
    HgArc(x2+30, y2+45, 5, 0, 0.5*M_PI);
    HgLine(x2+15, y2+5, x2+10, y2+15);    //くぼみ
    HgLine(x2+25, y2+5, x2+30, y2+15);
    HgBoxFill(x2+15, y2+15, 10, 5, 0);  //フロントガラス
    HgFanFill(x2+15, y2+15, 5, 0.5*M_PI, M_PI, 0);
    HgFanFill(x2+25, y2+15, 5, 0, 0.5*M_PI, 0);
    HgBoxFill(x2+10, y2+25, 5, 10, 0);  //ライトガラス
    HgFanFill(x2+10, y2+25, 5, 1.5*M_PI, 2.0*M_PI, 0);
    HgFanFill(x2+10, y2+35, 5, 0, 0.5*M_PI, 0);
    HgBoxFill(x2+25, y2+25, 5, 10, 0);  //レフトガラス
    HgFanFill(x2+30, y2+25, 5, M_PI, 1.5*M_PI, 0);
    HgFanFill(x2+30, y2+35, 5, 0.5*M_PI, M_PI, 0);
    

    return 2;
    
}


int main(){

    int x1=0, y1=0;
    int x2=0, y2=0;

    HgOpen(40, 50);

    car2(x2, y2);

    HgGetChar();
    HgClose();

    return 0;
}
