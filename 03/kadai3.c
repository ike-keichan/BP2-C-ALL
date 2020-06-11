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
        for(r=0; r<=200; r+=50){
            x=r*cos(rad);
            y=r*sin(rad);
            for(a=0; a<=400; a+=50){
                HgBox(x+a, y+a, 1.0, 1.0);
                HgBox(x+a, y+400-a, 1.0, 1.0);                
            }
        }
    }
    
    HgGetChar();
    HgClose();

    return 0;
}
