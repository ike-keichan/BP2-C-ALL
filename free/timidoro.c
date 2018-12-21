/*****
      kadai3.c
*****/

#include <stdio.h>
#include <handy.h>
#include <math.h>

int main(){
    
    double a, r, x, y, rad;
    
    HgOpen(400.0, 400.0);
    HgSetWidth(1.0);
    HgSetColor(HG_BLACK);

    HgLine(5.0, 200.0, 395.0, 200.0);
    HgLine(200.0, 5.0, 200.0, 395.0);

    HgSetColor(HG_RED);
    for(rad=-M_PI; rad<=M_PI; rad+=0.00174533){
        for(r=0; r<=200; r+=10){
            x=r*cos(rad);
            y=r*sin(rad);

    return 0;
}
