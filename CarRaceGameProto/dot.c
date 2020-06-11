/*
 
 スペースキーで全て消すので要注意
 座標を指定したかったら、十字キーで移動、nでペイントがおすすめ
 dキーはデフォルトで黒色、aキーで塗りつぶし
 
 */
#include <stdio.h>
#include <stdbool.h>
#include <handy.h>
#define W 600
#define SIZE 20

long check[100][100];
int move[2] = {-1,1};

void init(){
  for(int i = 0;i < 100;i++){
    for(int j = 0;j < 100;j++){
      check[i][j] = -1;
    }
  }
}

void paint(int x,int y,int acolor,int bcolor){
  if(check[x][y] != bcolor)return;
  if(acolor == bcolor)return;
  check[x][y] = acolor;
  HgBoxFill(x*6,y*6,6,6,0);
  for(int i = 0;i <= 1;i++){
    if(0 <= x+move[i] && x+move[i] < 100)paint(x+move[i],y,acolor,bcolor);
    if(0 <= y+move[i] && y+move[i] < 100)paint(x,y+move[i],acolor,bcolor);
  }
}

int main(){
  int WindowID;
  int color = 0;
  bool bpaint = false;
  int x,y;
  doubleLayer layers;
  hgevent *event = NULL;
  WindowID = HgOpen(W,W);
  layers = HgWAddDoubleLayer(WindowID);
  HgSetEventMask(HG_KEY_DOWN|HG_MOUSE_DOWN);
  init();
  while(1){
    HgSetFillColor(HG_RED);
    HgBoxFill(0,0,10,10,0);
    event = HgEventNonBlocking();
    if(event != NULL){
      if(event->ch == 'q')break;
      else if(event->ch == 'w')color = -1;
      else if(event->ch == 'd')color = 0;
      else if(event->ch == 'r')color = 1;
      else if(event->ch == 'b')color = 2;
      else if(event->ch == 'g')color = 3;
      else if(event->ch == 'y')color = 4;
      else if(event->ch == 'l')color = 5;
      else if(event->ch == 'p')color = 6;
      else if(event->ch == 'c')color = 7;
      else if(event->ch == 'm')color = 8;
      else if(event->ch == 's')color = 9;
      else if(event->ch == 'a'){
        if(bpaint != false)bpaint = false;
        else bpaint = true;
      }else if(event->ch == ' '){
        HgClear();
        init();
      }
      else if(event->ch == HG_U_ARROW)y += 1;
      else if(event->ch == HG_D_ARROW)y -= 1;
      else if(event->ch == HG_R_ARROW)x += 1;
      else if(event->ch == HG_L_ARROW)x -= 1;
      if(x < 0)x = 0;
      if(y < 0)y = 0;
      if(99 < x)x = 99;
      if(99 < y)y = 99;
      switch(color){
        case 0:
          HgSetFillColor(HG_BLACK);
          break;
        case 1:
          HgSetFillColor(HG_RED);
          break;
        case 2:
          HgSetFillColor(HG_BLUE);
          break;
        case 3:
          HgSetFillColor(HG_GREEN);
          break;
        case 4:
          HgSetFillColor(HG_YELLOW);
          break;
        case 5:
          HgSetFillColor(HG_LGRAY);
          break;
        case 6:
          HgSetFillColor(HG_PURPLE);
          break;
        case 7:
          HgSetFillColor(HG_CYAN);
          break;
        case 8:
          HgSetFillColor(HG_MAGENTA);
          break;
        case 9:
          HgSetFillColor(HG_SKYBLUE);
          break;
        case -1:
          HgSetFillColor(HG_WHITE);
          break;
        default:
        break;
      }
      if(event->ch == 'n'){
        check[x][y] = color;
        HgBoxFill(x*6,y*6,6,6,0);
      }
      if(event->x == 0 && event->y == 0)continue;
      if(event->x < 10 && event->y < 10)break;
      else{
        x = event->x/6;
        y = event->y/6;
        if(bpaint){
          paint((int)event->x/6,(int)event->y/6,color,check[(int)event->x/6][(int)event->y/6]);
        }else{
          if(check[(int)event->x/6][(int)event->y/6] == color)check[(int)event->x/6][(int)event->y/6] = -1;
          else check[(int)event->x/6][(int)event->y/6] = color;
          if(check[(int)event->x/6][(int)event->y/6] == -1)HgSetFillColor(HG_WHITE);
          HgBoxFill(((int)event->x/6)*6,((int)event->y/6)*6,6,6,0);
        }
      }
    }
  }
  HgSleep(0.1);
  HgWClose(WindowID);
  return 0;
}
