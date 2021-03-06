/*****
      car-race.c
      自由課題(最終課題)
      g1744069 Keisuke Ikeda
*****/

#include <stdio.h>
#include <handy.h>
#include <math.h>
#include <time.h>

#define MAPX 1440
#define MAPY 860
#define CELLX MAPX/5
#define CELLY MAPY/5

doubleLayer car1layers;
doubleLayer car2layers;
doubleLayer lalelayers;
int windowID;
int subwindowID;
int pausewindowID;
int car1layerID;
int car2layerID;
int lalelayerID;
hgevent *event;

int map(){ //マップデータ

    HgWSetColor(lalelayerID, HG_ORANGE);
    HgWLine(lalelayerID,1240, 500, 1390, 500); //スタートゴール
    HgWLine(lalelayerID,300, 500, 490, 500);   //チェックポイント
    HgWLine(lalelayerID,690, 50, 690, 200);
    HgWLine(lalelayerID,940, 300, 940, 450); 
    HgWSetColor(lalelayerID, HG_BLACK);
    HgWLine(lalelayerID,1390, 650, 1390, 250); //右タテ直線コース
    HgWLine(lalelayerID,1240, 650, 1240, 250);
    HgWLine(lalelayerID,1140, 650, 1140, 500); //下ヨコ直線コース
    HgWLine(lalelayerID,990, 650, 990, 500);
    HgWLine(lalelayerID,250, 50, 1190, 50);    //中タテ直線コース
    HgWLine(lalelayerID,250, 200, 1190, 200);
    HgWLine(lalelayerID,890, 650, 890, 500);   // 左タテ直線コース
    HgWLine(lalelayerID,740, 650, 740, 500);
    HgWLine(lalelayerID,450, 500, 490, 500);   // 小さい直線コース
    HgWLine(lalelayerID,450, 650, 490, 650);
    HgWArc(lalelayerID,1190, 650, 50, 0, M_PI);            //右上カーブコース
    HgWArc(lalelayerID,1190, 650, 200, 0, M_PI);
    HgWArc(lalelayerID,940, 500, 50, M_PI, 2.0*M_PI);      //右中カーブコース
    HgWArc(lalelayerID,940, 500, 200, M_PI, 2.0*M_PI);
    HgWArc(lalelayerID,1190, 250, 50, 1.5*M_PI, 2.0*M_PI); //右下カーブコース
    HgWArc(lalelayerID,1190, 250, 200, 1.5*M_PI, 2.0*M_PI);
    HgWArc(lalelayerID,250, 250, 50, 0.5*M_PI, 1.5*M_PI);  //左下カーブコース
    HgWArc(lalelayerID,250, 250, 200, 0.5*M_PI, 1.5*M_PI);
    HgWArc(lalelayerID,250, 500, 50, 1.5*M_PI, 2.0*M_PI);  //左中カーブコース
    HgWArc(lalelayerID,250, 500, 200, 1.5*M_PI, 2.0*M_PI);
    HgWArc(lalelayerID,690, 650, 50, 0, M_PI);             //中上カーブコース
    HgWArc(lalelayerID,690, 650, 200, 0, M_PI);
    HgWArc(lalelayerID,490, 650, 150, 1.5*M_PI, 2.0*M_PI); //中下カーブコース
    HgWArc(lalelayerID,450, 500, 150, 0.5*M_PI, M_PI);
            
    return 0;
}

int hp(int car1HP){ //HPデータ
    
    HgWSetColor(lalelayerID,HG_BLACK);
    HgWSetFont(lalelayerID,HG_GB, 50);
    HgWText(lalelayerID, 10, 800, "HP:");
    HgWBox(lalelayerID, 100, 795, 190, 60);

    HgWSetFillColor(lalelayerID, HG_GREEN);       //HPゲージ
    if(car1HP>=1){
        HgWBoxFill(lalelayerID, 110, 800, 20, 50, 0);
    }
    if(car1HP>=2){
        HgWBoxFill(lalelayerID, 135, 800, 20, 50, 0);
    }
    if(car1HP>=3){
        HgWBoxFill(lalelayerID, 160, 800, 20, 50, 0);
    }
    if(car1HP>=4){
        HgWBoxFill(lalelayerID, 185, 800, 20, 50, 0);
    }
    if(car1HP>=5){
        HgWBoxFill(lalelayerID, 210, 800, 20, 50, 0);
    }
    if(car1HP>=6){
        HgWBoxFill(lalelayerID, 235, 800, 20, 50, 0);
    }
    if(car1HP>=7){
        HgWBoxFill(lalelayerID, 260, 800, 20, 50, 0);
    }

    return 1;
}

int count(int check){ //カウントデータ
    
    HgWSetColor(lalelayerID,HG_BLACK);
    HgWSetFont(lalelayerID,HG_GB, 50);
    HgWText(lalelayerID, 10, 690, "CHECK POINT:");

    HgWSetColor(lalelayerID, HG_RED);       //チェックポイント回数
    if(check<=1){
        HgWText(lalelayerID, 10, 630, "0/4");
    }
    if(check==2){
        HgWText(lalelayerID, 10, 630, "1/4");
    }
    if(check==3){
        HgWText(lalelayerID, 10, 630, "2/4");
    }
    if(check==4){
        HgWText(lalelayerID, 10, 630, "3/4");
    }
    if(check==5){
        HgWText(lalelayerID, 10, 630, "4/4");
    }
    

    return 2;
}

int timeattack(int time){ //タイムアタックデータ
    
    HgWSetColor(lalelayerID,HG_BLACK);
    HgWSetFont(lalelayerID,HG_GB, 50);
    HgWText(lalelayerID, 10, 740, "TIME:");

    HgWSetColor(lalelayerID, HG_PINK);       //時間
    HgWText(lalelayerID, 160, 740, ");

    return 3;
}

int clear(){ //クリア画面
    
     subwindowID=HgOpen(1050, 200);
     HgWSetColor(subwindowID,HG_DRED);
     HgWSetFont(subwindowID,HG_GB, 100);
     HgWText(subwindowID,10, 10, "G");
     HgWText(subwindowID,80, 10, "A");
     HgWText(subwindowID,150, 10, "M");
     HgWText(subwindowID,220, 10, "E");
     HgWText(subwindowID,290, 10, "C");
     HgWText(subwindowID,360, 10, "L");
     HgWText(subwindowID,430, 10, "E");
     HgWText(subwindowID,500, 10, "A");
     HgWText(subwindowID,570, 10, "R");
     HgWText(subwindowID,640, 10, "!");
     HgWText(subwindowID,710, 10, "(");
     HgWText(subwindowID,780, 10, "＾");
     HgWText(subwindowID,850, 10, "ω");
     HgWText(subwindowID,920, 10, "＾");
     HgWText(subwindowID,990, 10, ")");

     return 4;
    
}

int over(){ //ゲームオーバー画面

    subwindowID=HgOpen(900, 200);
    HgWSetColor(subwindowID,HG_DBLUE);
    HgWSetFont(subwindowID,HG_GB, 100);
    HgWText(subwindowID,10, 10, "G");
    HgWText(subwindowID,80, 10, "A");
    HgWText(subwindowID,150, 10, "M");
    HgWText(subwindowID,220, 10, "E");
    HgWText(subwindowID,290, 10, "O");
    HgWText(subwindowID,360, 10, "V");
    HgWText(subwindowID,430, 10, "E");
    HgWText(subwindowID,500, 10, "R");
    HgWText(subwindowID,570, 10, "(");
    HgWText(subwindowID,640, 10, "T");
    HgWText(subwindowID,710, 10, "ω");
    HgWText(subwindowID,780, 10, "T");
    HgWText(subwindowID,850, 10, ")");

    return 5;

}

int pause(){
    
    double x, y;
    int flag;
    int keypause;

    pausewindowID=HgOpen(600, 500);
    HgWSetFillColor(pausewindowID,HG_DRED);
    HgWBoxFill(pausewindowID,50, 50, 200, 150, 0);
    HgWSetFillColor(pausewindowID,HG_DBLUE);
    HgWBoxFill(pausewindowID,350, 50, 200, 150, 0);
    HgWSetColor(pausewindowID,HG_MAGENTA);
    HgWSetFont(pausewindowID,HG_GB, 100);
    HgWText(pausewindowID,60, 300, "P");
    HgWText(pausewindowID,160, 300, "A");
    HgWText(pausewindowID,260, 300, "U");
    HgWText(pausewindowID,360, 300, "S");
    HgWText(pausewindowID,460, 300, "E");
    HgWSetColor(pausewindowID,HG_RED);
    HgWSetFont(pausewindowID,HG_GB, 50);
    HgWText(pausewindowID,55, 100, "続");
    HgWText(pausewindowID,105, 100, "け");
    HgWText(pausewindowID,155, 100, "る");
    HgWText(pausewindowID,205, 100, "？");
    HgWSetColor(pausewindowID,HG_BLUE);
    HgWText(pausewindowID,355, 100, "や");
    HgWText(pausewindowID,405, 100, "め");
    HgWText(pausewindowID,455, 100, "る");
    HgWText(pausewindowID,505, 100, "？");

    for(;;){

        keypause=HgGetChar();

        if(keypause==' '){
           flag=2;
        }

        HgSetWidth(1.0);
        HgSetEventMask(HG_MOUSE_DOWN);
        event = HgEvent();

        if(event->type == HG_MOUSE_DOWN){
            x=event->x;
            y=event->y;

            if((x > 350) && (x < 550)){
                if((y > 50)  && (y < 200)){
                    flag=1;
                    break;
                }
            }else if((x > 50 && x < 200)){
                if((y > 50  && y < 200)){
                    flag=2;
                    break;
                }
            }
        }
    }

    if(flag==1){
        HgCloseAll();
    }else if(flag==2){
        HgClose();
    }else {
    }

    return 6;
    
}

int main(){

    int car1 = HgImageLoad("car1.png");
    int car2 = HgImageLoad("car2.png");
    int cell[CELLX][CELLY]={};
    int i=0, j=0;
    int key1;
    int car1HP=7;
    int check=0;
    double x1=1290, y1=525;
    double x2=1340, y2=525;
    double rad1=0, rad2=0;
    clock_t start, end;
    
    
    windowID = HgOpen(MAPX, MAPY);
    lalelayers = HgWAddDoubleLayer(windowID);
    car1layers = HgWAddDoubleLayer(windowID);
    car2layers = HgWAddDoubleLayer(windowID);

    for(j=50; j<130; j++){  //右タテ直線コース当たり判定
        cell[278][j]=3;
    }
    for(j=50; j<130; j++){
        cell[248][j]=4;
    }
    for(j=100; j<130; j++){  //下ヨコ直線コース当たり判定
        cell[228][j]=3;
    }
    for(j=100; j<130; j++){
        cell[198][j]=4;
    }
    for(i=50; i<238; i++){   //中タテ直線コース当たり判定
        cell[i][10]=2;
    }
    for(i=50; i<238; i++){
        cell[i][40]=1;
    }
    for(j=100; j<130; j++){  // 左タテ直線コース当たり判定
        cell[178][j]=3;
    }
    for(j=100; j<130; j++){
        cell[148][j]=4;
    }
    for(i=90; i<98; i++){    // 小さい直線コース当たり判定
        cell[i][100]=1;
    }
    for(i=90; i<98; i++){
        cell[i][130]=2;
    }
    
    map();
    
    for(;;){
        
        car1layerID=HgLSwitch(&car1layers);
        car2layerID=HgLSwitch(&car2layers);
        lalelayerID=HgLSwitch(&lalelayers);
        HgLClear(car1layerID);
        HgLClear(car2layerID);
        HgLClear(lalelayerID);
        
        HgWImagePut(car1layerID, x1, y1, car1, 1, rad1);
        HgWImagePut(car2layerID, x2, y2, car2, 1, rad2);

        start=clock();

        if((x1>=1240)&&(x1<=1390)){  //チェックポイントのカウント
            if(y1==500){
                check++;
            }
        }
        if((x1>=300)&&(x1<=490)){
            if(y1==500){
                check++;
            }
        }
        if((y1>=50)&&(y1<=200)){
            if(x1==690){
                check++;
            }
        }
        if((y1>=300)&&(y1<=450)){
            if(x1==940){
                check++;
            }
        }
        
        key1=HgGetChar(); //車１の操作
        if(key1==HG_U_ARROW){       //上移動
            i=x1/5;
            j=y1/5;
            if(cell[i][j]==1){
                x1=x1+0;
                y1=y1-1;
                car1HP=car1HP-1;
            }else {
                y1=y1+5;
                if((M_PI>rad1)&&(rad1>=0)){
                    rad1=rad1+M_PI/24;
                }else if((0>rad1)&&(rad1>-M_PI)){
                    rad1=rad1-M_PI/24;
                }else {
                    rad1=M_PI;
                }
            }
        }else if(key1==HG_D_ARROW){ //下移動
            i=x1/5;
            j=y1/5;
            if(cell[i][j]==2){
                x1=x1+0;
                y1=y1+1;
                car1HP=car1HP-1;
            }else {
                y1=y1-5;
                if((M_PI>=rad1)&&(rad1>0)){
                    rad1=rad1-M_PI/24;
                }else if((0>rad1)&&(rad1>=-M_PI)){
                    rad1=rad1+M_PI/24;
                }else {
                    rad1=0;
                }
            }
        }else if(key1==HG_R_ARROW){ //右移動
            i=x1/5;
            j=y1/5;
            if(cell[i][j]==3){
                x1=x1-1;
                y1=y1+0;
                car1HP=car1HP-1;
            }else {
                x1=x1+5;
                if((0.5*M_PI>rad1)&&(rad1>=-0.5*M_PI)){
                    rad1=rad1+M_PI/24;
                }else if(M_PI>=rad1){
                    rad1=rad1-M_PI/24;
                }else if((-0.5*M_PI>rad1)&&(rad1>-M_PI)){
                    rad1=rad1-M_PI/24;
                }else if(rad1==-M_PI){
                    rad1=M_PI;
                }else if(rad1==0.5*M_PI){
                    rad1=0.5*M_PI;
                }else {
                    rad1=0.5*M_PI;
                }
            }
        }else if(key1==HG_L_ARROW){ //左移動
            i=x1/5;
            j=y1/5;
            if(cell[i][j]==4){
                x1=x1+1;
                y1=y1+0;
                car1HP=car1HP-1;
            }else {
                x1=x1-5;
                if((0.5*M_PI>=rad1)&&(rad1>-0.5*M_PI)){
                    rad1=rad1-M_PI/24;
                }else if(rad1>=-M_PI){
                    rad1=rad1+M_PI/24;
                }else if((M_PI>rad1)&&(rad1>0.5*M_PI)){
                    rad1=rad1-M_PI/24;
                }else if(rad1==M_PI){
                    rad1=-M_PI;
                }else if(rad1==-0.5*M_PI){
                    rad1=-0.5*M_PI;
                }else {
                    rad1=-0.5*M_PI;
                }
            }
        }else if(key1=='d'){        //右上移動
            i=x1/5;
            j=y1/5;
            if(cell[i][j]==1){
                x1=x1+0;
                y1=y1-1;
                car1HP=car1HP-1;
            }else if(cell[i][j]==3){
                x1=x1-1;
                y1=y1+0;
                car1HP=car1HP-1;
            }else {
                x1=x1+3;
                y1=y1+3;
                if((0.75*M_PI>rad1)&&(rad1>=-0.25*M_PI)){
                    rad1=rad1+M_PI/24;
                }else if((M_PI>=rad1)&&(rad1>0.75*M_PI)){
                    rad1=rad1-M_PI/24;
                }else if((-0.25*M_PI>rad1)&&(rad1>-M_PI)){
                    rad1=rad1-M_PI/24;
                }else if(rad1==-M_PI){
                    rad1=M_PI;
                }else if(rad1==0.75*M_PI){
                    rad1=0.75*M_PI;
                }else {
                    rad1=0.75*M_PI;
                }
            }
        }else if(key1=='c'){        //右下移動
            i=x1/5;
            j=y1/5;
            if(cell[i][j]==2){
                x1=x1+0;
                y1=y1+1;
                car1HP--;
            }else if(cell[i][j]==3){
                x1=x1-1;
                y1=y1+0;
                car1HP--;
            }else {
                x1=x1+3;
                y1=y1-3;
                if((0.25*M_PI>rad1)&&(rad1>=-0.75*M_PI)){
                    rad1=rad1+M_PI/24;
                }else if((M_PI>=rad1)&&(rad1>0.25*M_PI)){
                    rad1=rad1-M_PI/24;
                }else if((-0.75*M_PI>rad1)&&(rad1>-M_PI)){
                    rad1=rad1- M_PI/24;
                }else if(rad1==-M_PI){
                    rad1=M_PI;
                }else if(rad1==0.25*M_PI){
                    rad1=0.25*M_PI;
                }else {
                    rad1=0.25*M_PI;
                }
            }
        }else if(key1=='s'){        //左上移動
            i=x1/5;
            j=y1/5;
            if(cell[i][j]==1){
                x1=x1+0;
                y1=y1-1;
                car1HP--;
            }else if(cell[i][j]==4){
                x1=x1+1;
                y1=y1+0;
                car1HP--;
            }else {
                x1=x1-3;
                y1=y1+3;
                if((0.25*M_PI>=rad1)&&(rad1>-0.75*M_PI)){
                    rad1=rad1-M_PI/24;
                }else if((M_PI>rad1)&&(rad1>0.25*M_PI)){
                    rad1=rad1+M_PI/24;
                }else if((-0.75*M_PI>rad1)&&(rad1>=-M_PI)){
                    rad1=rad1+M_PI/24;
                }else if(rad1==M_PI){
                    rad1=-M_PI;
                }else if(rad1==-0.75*M_PI){
                    rad1=-0.75*M_PI;
                }else {
                    rad1=-0.75*M_PI;
                }
            }
        }else if(key1=='x'){        //左下移動
            i=x1/5;
            j=y1/5;
            if(cell[i][j]==2){
                x1=x1+0;
                y1=y1+1;
                car1HP--;
            }else if(cell[i][j]==4){
                x1=x1+1;
                y1=y1+0;
                car1HP--;
            }else {
                x1=x1-3;
                y1=y1-3;
                if((0.75*M_PI>=rad1)&&(rad1>-0.25*M_PI)){
                    rad1=rad1-M_PI/24;
                }else if((M_PI>rad1)&&(rad1>0.75*M_PI)){
                    rad1=rad1+M_PI/24;
                }else if((-0.25*M_PI>rad1)&&(rad1>=-M_PI)){
                    rad1=rad1+M_PI/24;
                }else if(rad1==M_PI){
                    rad1=-M_PI;
                }else if(rad1==-0.75*M_PI){
                    rad1=-0.75*M_PI;
                }else {
                    rad1=-0.75*M_PI;
                }
            }
        }else if(key1==' '){        //休止
            pause();
        }

        hp(car1HP);
        count(check);
        timeattack();

        if(check==5){ //ゲームクリア
            end=clock();
            clear();
            HgSleep(2.0);
            break;
        }

        if(car1HP==1){ //ゲームオーバー
            end=clock();
            over();
            HgSleep(2.0);
            break;
        }
        
        HgSleep(0.05);
    }
    
    HgClose();

    return 0;
}
