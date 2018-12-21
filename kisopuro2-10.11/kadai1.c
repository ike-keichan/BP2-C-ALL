/*****
      kadai1.c
*****/

#include <stdio.h>
#include <handy.h>
#include <math.h>

int main(){
    
    double x,y;
    
    HgOpen(400.0, 400.0);
    HgSetWidth(1.0);
    HgSetColor(HG_BLACK);

    HgLine(5.0, 200.0, 395.0, 200.0);
    HgLine(200.0, 5.0, 200.0, 395.0);

    HgSetColor(HG_RED);
    for(x=-180; x<=180; x+=0.1){
        y=sin(M_PI*x/180);
        HgBox(x+200, y*200+200, 1.0, 1.0);
    }
    
    HgGetChar();
    HgClose();

    return 0;
}
