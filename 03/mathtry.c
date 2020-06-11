i/*****
      mathtry.c
      (freework.c 自由課題(最終課題))
      g1744069 Keisuke Ikeda
*****/

#include <stdio.h>
#include <handy.h>
#include <math.h>

int main(){

    int y1=325;
    int x2=425, y2=150, count2=1;
    int x3=275, y3=150, count3=1;
    int x4=175, y4=150, count4=1;
    int y5=150;
    int x6=150, y6=500, count6=1;
    int y7=500;
    int x8=225, y8=300, count8=1;
    int y9=325;
    int x10=325, y10=400, count10=1;
    int x11=350;
    int x12=400, y12=425, count12=1;
    int y13=450;
    int x14=425, y14=500, count14=1;
    int y15=500;
    int x16=525, y16=350, count16=1;
    int x17=500;
    double rad2=9;
    double rad3=0;
    double rad4=9;
    double rad6=9;
    double rad8=0;
    double rad10=9;
    double rad12=0;
    double rad14=9;
    double rad16=9;
    doubleLayer layers;
    int windowID;
    int layerID;
    windowID = HgOpen(600, 600);
    layers = HgWAddDoubleLayer(windowID);

    for(;;){
        
        layerID = HgLSwitch(&layers);
        HgLClear(layerID);
        HgWLine(layerID,400, 350, 400, 150);
        HgWLine(layerID,450, 300, 450, 150);
        HgWLine(layerID,450, 300, 500, 300);
        HgWLine(layerID,400, 350, 500, 350);
        HgWLine(layerID,50, 500, 50, 150);
        HgWLine(layerID,100, 500, 100, 150);
        HgWLine(layerID,500, 500, 500, 350);
        HgWLine(layerID,550, 500, 550, 350);
        HgWLine(layerID,200, 500, 200, 325);
        HgWLine(layerID,250, 500, 250, 325);
        HgWLine(layerID,300, 400, 300, 325);
        HgWLine(layerID,350, 400, 350, 325);
        HgWLine(layerID,350, 400, 400, 400);
        HgWLine(layerID,350, 450, 400, 450);
        HgWLine(layerID,400, 500, 400, 450);
        HgWLine(layerID,450, 500, 450, 450);
        HgWArc(layerID,500, 350, 50, 4.71239, 0);
        HgWArc(layerID,150, 500, 100, 0, 3.14159);
        HgWArc(layerID,150, 500, 50, 0, 3.14159);
        HgWArc(layerID,350, 150, 50, 3.14159, 0);
        HgWArc(layerID,350, 150, 100, 3.14159, 0);
        HgWArc(layerID,225, 150, 25, 0, 3.14159);
        HgWArc(layerID,225, 150, 75, 0, 3.14159);
        HgWArc(layerID,125, 150, 25, 3.14159, 0);
        HgWArc(layerID,125, 150, 75, 3.14159, 0);
        HgWArc(layerID,275, 325, 25, 3.14159, 0);
        HgWArc(layerID,275, 325, 75, 3.14159, 0);
        HgWArc(layerID,350, 400, 50, 1.5708, 3.14159);
        HgWArc(layerID,400, 450, 50, 4.71239, 0);
        HgWArc(layerID,475, 500, 25, 0, 3.14159);
        HgWArc(layerID,475, 500, 75, 0, 3.14159);
        
        if(y1>=150){
            y1=y1-3;
            HgWSetFillColor(layerID,HG_RED);
            HgWCircleFill(layerID, 425, y1, 22, 0);
            HgSleep(0.05);
        }
        if(y1<=150 && rad2>=3.14159){
            rad2=6.28319-0.0872665*count2;
            x2=75*cos(rad2)+350;
            y2=75*sin(rad2)+150;
            count2++;
            HgWSetFillColor(layerID, HG_RED);
            HgWCircleFill(layerID, x2, y2, 22, 0);
            HgSleep(0.05);
        }
        if(rad2<=3.14159 && rad3<=3.14159){
            rad3=0.0872665*count3;
            x3=50*cos(rad3)+225;
            y3=50*sin(rad3)+150;
            count3++;
            HgWSetFillColor(layerID, HG_RED);
            HgWCircleFill(layerID, x3, y3, 22, 0);
            HgSleep(0.05);
        }
        if(rad3>=3.14159 && rad4>=3.14159){
            rad4=6.283319-0.0872665*count4;
            x4=50*cos(rad4)+125;
            y4=50*sin(rad4)+150;
            count4++;
            HgWSetFillColor(layerID, HG_RED);
            HgWCircleFill(layerID, x4, y4, 22, 0);
            HgSleep(0.05);
        }
        if(rad4<=3.14159 && y5<=500){
            y5=y5+3;
            HgWSetFillColor(layerID, HG_RED);
            HgWCircleFill(layerID, 75, y5, 22, 0);
            HgSleep(0.05);
        }
        if(y5>=500 && rad6>=0){
            rad6=3.14159-0.0872665*count6;
            x6=75*cos(rad6)+150;
            y6=75*sin(rad6)+500;
            count6++;
            HgWSetFillColor(layerID, HG_RED);
            HgWCircleFill(layerID, x6, y6, 22, 0);
            HgSleep(0.05);
        }
        if(rad6<=0 && y7>=325){
            y7=y7-3;
            HgWSetFillColor(layerID, HG_RED);
            HgWCircleFill(layerID, 225, y7, 22, 0);
            HgSleep(0.05);
        }
        if(y7<=325 && rad8<=6.283319){
            rad8=3.14159+0.0872665*count8;
            x8=50*cos(rad8)+275;
            y8=50*sin(rad8)+325;
            count8++;
            HgWSetFillColor(layerID, HG_RED);
            HgWCircleFill(layerID, x8, y8, 22, 0);
            HgSleep(0.05);
        }
        if(rad8>=6.283319 && y9<=400){
            y9=y9+3;
            HgWSetFillColor(layerID, HG_RED);
            HgWCircleFill(layerID, 325, y9, 22, 0);
            HgSleep(0.05);
        }
        if(y9>=400 && rad10>=1.5708){
            rad10=3.14159-0.0872665*count10;
            x10=25*cos(rad10)+350;
            y10=25*sin(rad10)+400;
            count10++;
            HgWSetFillColor(layerID, HG_RED);
            HgWCircleFill(layerID, x10, y10, 22, 0);
            HgSleep(0.05);
        }
        if(rad10<=1.5708 && x11<=400){
            x11=x11+3;
            HgWSetFillColor(layerID, HG_RED);
            HgWCircleFill(layerID, x11, 425, 22, 0);
            HgSleep(0.05);
        }
        if(x11>=400 && rad12<=6.283319){
            rad12=4.71239+0.0872665*count12;
            x12=25*cos(rad12)+400;
            y12=25*sin(rad12)+450;
            count12++;
            HgWSetFillColor(layerID, HG_RED);
            HgWCircleFill(layerID, x12, y12, 22, 0);
            HgSleep(0.05);
        }
        if(rad12>=6.283319 && y13<=500){
            y13=y13+3;
            HgWSetFillColor(layerID, HG_RED);
            HgWCircleFill(layerID, 425, y13, 22, 0);
            HgSleep(0.05);
        }
        if(y13>=500 && rad14>=0){
            rad14=3.14159-0.0872665*count14;
            x14=50*cos(rad14)+475;
            y14=50*sin(rad14)+500;
            count14++;
            HgWSetFillColor(layerID, HG_RED);
            HgWCircleFill(layerID, x14, y14, 22, 0);
            HgSleep(0.05);
        }
        if(rad14<=0 && y15>=350){
            y15=y15-3;
            HgWSetFillColor(layerID, HG_RED);
            HgWCircleFill(layerID, 525, y15, 22, 0);
            HgSleep(0.05);
           }
        if(y15<=350 && rad16>=4.71239){
            rad16=6.283319-0.0872665*count16;
            x16=25*cos(rad16)+500;
            y16=25*sin(rad16)+350;
            count16++;
            HgWSetFillColor(layerID, HG_RED);
            HgWCircleFill(layerID, x16, y16, 22, 0);
            HgSleep(0.05);
        }
        if(rad16<=4.71239 && x17>=425){
            x17=x17-3;
            HgWSetFillColor(layerID, HG_RED);
            HgWCircleFill(layerID, x17, 325, 22, 0);
            HgSleep(0.05);
        }
    }

    HgGetChar();
    HgClose();

    return 0;
}
