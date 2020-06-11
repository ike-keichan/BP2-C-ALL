#include <stdio.h>
#include <handy.h>
#define R  30
#define WIDTH   360.0
#define HEIGHT  180.0
int main(void)
{
double x, v;
int count;
int layer1, layer2;
HgOpen(WIDTH, HEIGHT);
layer1 = HgWAddLayer(0);
layer2 = HgWAddLayer(0);
HgWSetFillColor(0, HG_DGRAY);
for (v = 20.0; v < WIDTH; v += WIDTH * 0.2)
HgWBoxFill(0, v, HEIGHT*0.4, R*1.2, HEIGHT*0.6, 0); HgWSetFillColor(layer2, HG_ORANGE); /* 前景を描く */ for (v = 50.0; v < WIDTH; v += WIDTH * 0.15)
    HgWBoxFill(layer2, v, 0, R*0.5, HEIGHT*0.55, 0);
    HgWSetComposite(layer1, HG_BLEND_COPY);
    x = R;
    for (count = 0; count < 30; count++) {
        HgWSetFillColor(layer1, HG_CLEAR);
        HgWCircleFill(layer1, x, HEIGHT/2.0, R, 0);
        x += R*2.0;
        if (x > WIDTH) x = R;
        HgWSetFillColor(layer1, HG_BLUE);
        HgWCircleFill(layer1, x, HEIGHT/2.0, R-1.0, 0);
        HgSleep(0.3);
    }
    HgClose();
    return 0;
}
