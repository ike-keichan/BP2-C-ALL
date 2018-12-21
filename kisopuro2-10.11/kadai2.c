/*****
      kadai2.c
*****/

#include <stdio.h>
#include <handy.h>
#include <math.h>

int main(){
    
    double x, y, rad;
    
    HgOpen(400.0, 400.0);
    HgSetWidth(1.0);
    HgSetColor(HG_BLACK);

    HgLine(5.0, 200.0, 395.0, 200.0);
    HgLine(200.0, 5.0, 200.0, 395.0);

    HgSetColor(HG_RED);
    for(rad=-M_PI; rad<=M_PI; rad+=0.00174533){
        x=200*cos(rad);
        y=200*sin(rad);
        HgBox(x+200, y+200, 1.0, 1.0);
    }
    
    HgGetChar();
    HgClose();

    return 0;
}
