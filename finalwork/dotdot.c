/*
 dotdot.c
 */
#include <stdio.h>
#include <stdbool.h>
#include <handy.h>

int main(){
    hgevent *event;
    double x, y;

    HgOpen(400.0, 400.0);
    HgSetWidth(1.0);
    HgSetColor(HG_BLACK);

    HgSetEventMask(HG_MOUSE_DOWN);

    for(;;){
        event=HgEvent();
        if(event->type==HG_MOUSE_DOWN){
            x=event->x;
            y=event->y;
            printf("x=%5.2f, y=%5.2f\n", x, y);
            HgBox(x, y, 5.0, 5.0);
        }
    }

}
