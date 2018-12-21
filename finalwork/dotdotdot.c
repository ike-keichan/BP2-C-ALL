/*****
  calc07-5-3.c
  2017/11/10 Saho Igami
  タイルを縦横二次元に配置する
  色をつける+背景色
  提出用
*****/

#include<stdio.h>
#include<handy.h>

#define WINDOWSIZE 400.0
#define SIZE 45 //カラーパレッドのサイズ
#define PLACE 430 //endボタンの位置
#define COLORL 450 //カラーパレッドの左側
#define COLORR 500 //カラーパレッドの右側


int main() {
  hgevent *event;
  double x, y;
  int i, j, k, l;
  int color[14] = {HG_LGRAY,HG_GRAY,HG_DGRAY,HG_BLACK,HG_DBLUE,HG_BLUE,HG_SKYBLUE,HG_DGREEN,HG_PURPLE,HG_DRED,HG_RED,HG_BROWN,HG_YELLOW,HG_WHITE};
  int num; //マス目の数
  int count;

  for(;;) {
    printf("マス目の数は(4,5,8,10,20,25,40,50)?\n");
    scanf("%d", &num);
    if((((num == 4 || num == 5) || (num == 10 || num == 20)) || (num == 25 || num == 40)) || num == 50) break;
  }
  HgOpen(WINDOWSIZE+200.0, WINDOWSIZE);
  HgSetWidth(1.0);
  HgSetEventMask(HG_MOUSE_DOWN);
  HgSetColor(HG_BLACK);
  HgBox(PLACE, 1, 55, 30);
  HgSetFont(HG_G, 25);
  HgText(PLACE, 1, "END");
  HgBox(PLACE+70, 1, 55, 30);
  HgSetFont(HG_G, 15);
  HgText(PLACE+70, 12, "BACK");
  HgText(PLACE+70, 0, "COLOR");

  HgSetColor(HG_LGRAY);
  for(i = 0; i <= WINDOWSIZE; i+=WINDOWSIZE/num) {
    HgLine(i, 0, i, WINDOWSIZE);
    HgLine(0, i, WINDOWSIZE, i);
  }
  j = 350;
  k = 350;
  for(i = 0; i < 14; i++) { //カラーパレッドの作成
    HgSetFillColor(color[i]);
    if(i < 7) {
      HgBoxFill(COLORL, j, SIZE, SIZE, 1);
      HgBoxFill(COLORL+200, j, SIZE, SIZE, 1);
      j -= 50;
    } else {
      HgBoxFill(COLORR, k, SIZE, SIZE, 1);
      HgBoxFill(COLORR+200, k, SIZE, SIZE, 1);
      k -= 50;
    }
  }
  HgSetFillColor(HG_BLACK); //初期のカラー設定
  HgBoxFill(PLACE+130, 0, 20, 20, 1);
  for(;;) {
    event = HgEvent();
    if (event->type == HG_MOUSE_DOWN) {
      x=event->x;
      y=event->y;
      if((x < PLACE+55 && x > PLACE) && (y < 40 && y > 1)) {
        break;
      }
      for(i = 0; i < num; i++) {
        for(j = 0; j < num; j++) {
          if(x > COLORL && x < COLORL+SIZE) {
            l = 0;
            for(k = 350; k >= 50; k -= 50) {
              if(y > k && y < k+SIZE) {
                HgSetFillColor(color[l]);
              }
              l++;
            }
          } else if(x > COLORR && x < COLORR+SIZE) {
            l = 7;
            for(k = 350; k >= 50; k -= 50) {
              if(y > k && y < k+SIZE) {
                HgSetFillColor(color[l]);
              }
              l++;
            }
          }
          HgBoxFill(PLACE+130, 0, 20, 20, 1); //選択中の色を表示
          if((x > PLACE+70 && x < PLACE+125) && (y > 1 && y < 31)) { //選択している色を背景色にする
            HgBoxFill(0, 0, WINDOWSIZE, WINDOWSIZE, 1);
            HgSetColor(HG_LGRAY);
            for(i = 0; i <= WINDOWSIZE; i+=WINDOWSIZE/num) {
              HgLine(i, 0, i, WINDOWSIZE);
              HgLine(0, i, WINDOWSIZE, i);
            }
          }
          if((x > i * WINDOWSIZE / num && x < (i + 1) * WINDOWSIZE / num) && ((y > j * WINDOWSIZE / num && y < (j + 1) * WINDOWSIZE / num))) {
            HgBoxFill(i * WINDOWSIZE / num, j * WINDOWSIZE / num, WINDOWSIZE / num, WINDOWSIZE / num, 1);
          }
        }
      }
    }
  }
  return 0;
}
