/*****
      car-raceF.c
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

doubleLayer carlayers;
doubleLayer statuslayers;
doubleLayer startlayers;
int windowID;
int startwindowID;
int subwindowID;
int pausewindowID;
int carlayerID;
int statuslayerID;
hgevent *event;

int map(){ //マップデータ

    HgWSetColor(windowID, HG_ORANGE);
    HgWLine(windowID,1240, 500, 1390, 500); //スタートゴール
    HgWLine(windowID,300, 500, 490, 500);   //チェックポイント
    HgWLine(windowID,690, 50, 690, 200);
    HgWLine(windowID,940, 300, 940, 450); 
    HgWSetColor(windowID, HG_BLACK);
    HgWLine(windowID,1390, 650, 1390, 250); //右タテ直線コース
    HgWLine(windowID,1240, 650, 1240, 250);
    HgWLine(windowID,1140, 650, 1140, 500); //下ヨコ直線コース
    HgWLine(windowID,990, 650, 990, 500);
    HgWLine(windowID,250, 50, 1190, 50);    //中タテ直線コース
    HgWLine(windowID,250, 200, 1190, 200);
    HgWLine(windowID,890, 650, 890, 500);   // 左タテ直線コース
    HgWLine(windowID,740, 650, 740, 500);
    HgWLine(windowID,450, 500, 490, 500);   // 小さい直線コース
    HgWLine(windowID,450, 650, 490, 650);
    HgWArc(windowID,1190, 650, 50, 0, M_PI);            //右上カーブコース
    HgWArc(windowID,1190, 650, 200, 0, M_PI);
    HgWArc(windowID,940, 500, 50, M_PI, 2.0*M_PI);      //右中カーブコース
    HgWArc(windowID,940, 500, 200, M_PI, 2.0*M_PI);
    HgWArc(windowID,1190, 250, 50, 1.5*M_PI, 2.0*M_PI); //右下カーブコース
    HgWArc(windowID,1190, 250, 200, 1.5*M_PI, 2.0*M_PI);
    HgWArc(windowID,250, 250, 50, 0.5*M_PI, 1.5*M_PI);  //左下カーブコース
    HgWArc(windowID,250, 250, 200, 0.5*M_PI, 1.5*M_PI);
    HgWArc(windowID,250, 500, 50, 1.5*M_PI, 2.0*M_PI);  //左中カーブコース
    HgWArc(windowID,250, 500, 200, 1.5*M_PI, 2.0*M_PI);
    HgWArc(windowID,690, 650, 50, 0, M_PI);             //中上カーブコース
    HgWArc(windowID,690, 650, 200, 0, M_PI);
    HgWArc(windowID,490, 650, 150, 1.5*M_PI, 2.0*M_PI); //中下カーブコース
    HgWArc(windowID,450, 500, 150, 0.5*M_PI, M_PI);
            
    return 0;
}

int hp(int carHP){ //HPデータ
    
    HgWSetColor(statuslayerID,HG_BLACK);
    HgWSetFont(statuslayerID,HG_GB, 50);
    HgWText(statuslayerID, 10, 800, "HP:");
    HgWBox(statuslayerID, 100, 795, 190, 60);

    HgWSetFillColor(statuslayerID, HG_GREEN);       //HPゲージ
    if(carHP>=1){
        HgWBoxFill(statuslayerID, 110, 800, 20, 50, 0);
    }
    if(carHP>=2){
        HgWBoxFill(statuslayerID, 135, 800, 20, 50, 0);
    }
    if(carHP>=3){
        HgWBoxFill(statuslayerID, 160, 800, 20, 50, 0);
    }
    if(carHP>=4){
        HgWBoxFill(statuslayerID, 185, 800, 20, 50, 0);
    }
    if(carHP>=5){
        HgWBoxFill(statuslayerID, 210, 800, 20, 50, 0);
    }
    if(carHP>=6){
        HgWBoxFill(statuslayerID, 235, 800, 20, 50, 0);
    }
    if(carHP>=7){
        HgWBoxFill(statuslayerID, 260, 800, 20, 50, 0);
    }

    return 1;
}

int count(int check1, int check2, int check3, int check4){ //カウントデータ
    
    HgWSetColor(statuslayerID,HG_BLACK);
    HgWSetFont(statuslayerID,HG_GB, 50);
    HgWText(statuslayerID, 10, 690, "CHECK POINT:");

    HgWSetColor(statuslayerID, HG_RED);       //チェックポイント回数
    if(check1==1){
        HgWText(statuslayerID, 10, 630, "4/4");
    }else if(check4==1){
        HgWText(statuslayerID, 10, 630, "3/4");
    }else if(check3==1){
        HgWText(statuslayerID, 10, 630, "2/4");
    }else if(check2==1){
        HgWText(statuslayerID, 10, 630, "1/4");
    }else{
        HgWText(statuslayerID, 10, 630, "0/4");
    }
    

    return 2;
}

int timeattack(int t){ //タイムアタックデータ
    
    HgWSetColor(statuslayerID,HG_BLACK);
    HgWSetFont(statuslayerID,HG_GB, 50);
    HgWText(statuslayerID, 10, 740, "TIME:");

    HgWSetColor(statuslayerID, HG_PINK);       //時間
    HgWText(statuslayerID, 160, 740, "%03d秒", t);

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
    
    double xp, yp;
    //int keypause;
    hgevent *eventpause;

    pausewindowID=HgOpen(600, 500);
    HgWSetFillColor(pausewindowID,HG_DRED);
    HgWBoxFill(pausewindowID,50, 50, 200, 150, 0);
    HgWSetFillColor(pausewindowID,HG_DBLUE);
    HgWBoxFill(pausewindowID,350, 50, 200, 150, 0);
    HgWSetColor(pausewindowID,HG_MAGENTA);
    HgWSetFont(pausewindowID,HG_GB, 100);
    HgWText(pausewindowID,100, 300, "PAUSE");
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
        
        HgWSetWidth(pausewindowID, 1.0);
        HgWSetEventMask(pausewindowID, HG_MOUSE_DOWN);
        eventpause = HgEvent();

        if(eventpause != NULL){
            if(eventpause->ch == ' ')break;
           
            xp=eventpause->x;
            yp=eventpause->y;
            printf("%f,%f\n",xp,yp);

            if((350<xp)&&(xp<550)){
                if((50<yp)&&(yp<200)){
                    HgCloseAll();
                }
            }else if((50<xp)&&(xp<200)){
                if((50<yp)&&(yp<200)){
                    HgWClose(pausewindowID);
                }
            }
        }
    }

    return 6;
    
}

int main(){

    int car1 = HgImageLoad("car1.png");
    int car2 = HgImageLoad("car2.png");
    int cell[CELLX][CELLY]={};           //当たり判定　
    int i=0, j=0;                        //ループ変数
    int xx=0, yy=0;                      //スタート画面
    int carHP=7, check1=0, check2=0, check3=0, check4=0;  //車の情報
    int key;
    double x=1290, y=525, rad=0;         //x,y座標_r角度
    double t;                            //タイム
    time_t start, end;
    
    
    windowID = HgOpen(MAPX, MAPY);

    for(;;){

        startlayers = HgWAddDoubleLayer(windowID);

        HgWSetFillColor(pausewindowID,HG_PINK);
        HgWBoxFill(startwindowID, 0, 0, MAPX, MAPY, 0);
        HgWSetColor(startwindowID,HG_MAGENTA);
        HgWSetFillColor(pausewindowID,HG_DBLUE);
        HgWSetFont(startwindowID,HG_GB, 100);
        HgWText(startwindowID,300, 600, "");
        HgWText(startwindowID,350, 400, "CarTimeAttack");
        HgWBoxFill(startwindowID, 500, 100, 420, 200, 0);
        HgWText(startwindowID,538, 120, "START");

        HgWImagePut(startwindowID, 100, 125, car1, 5, 0);
        HgWImagePut(startwindowID, 100, 375, car2, 5, 0);
        HgWImagePut(startwindowID, 100, 625, car1, 5, 0);
        HgWImagePut(startwindowID, 100, 875, car2, 5, 0);
        HgWImagePut(startwindowID, 1340, 125, car2, 5, 0);
        HgWImagePut(startwindowID, 1340, 375, car1, 5, 0);
        HgWImagePut(startwindowID, 1340, 625, car2, 5, 0);
        HgWImagePut(startwindowID, 1340, 875, car1, 5, 0);
        HgWImagePut(startwindowID, 720, 700, car1, 5, 0);
        
        HgWSetWidth(startwindowID, 1.0);
        HgWSetEventMask(startwindowID, HG_MOUSE_DOWN);
        event = HgEvent();

        if(event->type == HG_MOUSE_DOWN){
            xx=event->x;
            yy=event->y;

            if((500<=xx)&&(xx<=940)){
                if((100<=yy)&&(yy<=300)){
                    HgLClear(startwindowID);
                    break;
                }
            }
        }
    }

    statuslayers = HgWAddDoubleLayer(windowID);
    carlayers = HgWAddDoubleLayer(windowID);
    start=time(NULL);

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
    for(rad=0; rad<=M_PI; rad+=M_PI/180){  //右上カーブコース当たり判定
        i=(50*cos(rad)+1190)/5;
        j=(50*sin(rad)+650)/5;
        cell[i][j]=5;
    }
    for(rad=0; rad<=M_PI; rad+=M_PI/180){  
        i=(200*cos(rad)+1190)/5;
        j=(200*sin(rad)+650)/5;
        cell[i][j]=5;
    }
    for(rad=0; rad<=M_PI; rad+=M_PI/180){  //中上カーブコース当たり判定
        i=(50*cos(rad)+690)/5;
        j=(50*sin(rad)+650)/5;
        cell[i][j]=5;
    }
    for(rad=0; rad<=M_PI; rad+=M_PI/180){
        i=(200*cos(rad)+690)/5;
        j=(200*sin(rad)+650)/5;
        cell[i][j]=5;
    }
    for(rad=M_PI; rad<=2*M_PI; rad+=M_PI/180){ //右中カーブコース当たり判定
        i=(50*cos(rad)+940)/5;
        j=(50*sin(rad)+500)/5;
        cell[i][j]=5;
    }
    for(rad=M_PI; rad<=2*M_PI; rad+=M_PI/180){
        i=(200*cos(rad)+940)/5;
        j=(200*sin(rad)+500)/5;
        cell[i][j]=5;
    }
    for(rad=1.5*M_PI; rad<=2*M_PI; rad+=M_PI/180){ //右下カーブコース当たり判定
        i=(50*cos(rad)+1190)/5;
        j=(50*sin(rad)+250)/5;
        cell[i][j]=5;
    }
    for(rad=1.5*M_PI; rad<=2*M_PI; rad+=M_PI/180){
        i=(200*cos(rad)+1190)/5;
        j=(200*sin(rad)+250)/5;
        cell[i][j]=5;
    }
    for(rad=0.5*M_PI; rad<=1.5*M_PI; rad+=M_PI/180){ //左下カーブコース当たり判定
        i=(50*cos(rad)+250)/5;
        j=(50*sin(rad)+250)/5;
        cell[i][j]=5;
    }
    for(rad=0.5*M_PI; rad<=1.5*M_PI; rad+=M_PI/180){
        i=(200*cos(rad)+250)/5;
        j=(200*sin(rad)+250)/5;
        cell[i][j]=5;
    }
    for(rad=1.5*M_PI; rad<=2*M_PI; rad+=M_PI/180){ //左中カーブコース当たり判定
        i=(50*cos(rad)+250)/5;
        j=(50*sin(rad)+500)/5;
        cell[i][j]=5;
    }
    for(rad=1.5*M_PI; rad<=2*M_PI; rad+=M_PI/180){
        i=(200*cos(rad)+250)/5;
        j=(200*sin(rad)+500)/5;
        cell[i][j]=5;
    }
    for(rad=0.5*M_PI; rad<=M_PI; rad+=M_PI/180){ //中下カーブコース当たり判定
        i=(150*cos(rad)+450)/5;
        j=(150*sin(rad)+500)/5;
        cell[i][j]=5;
    }
    for(rad=1.5*M_PI; rad<=2*M_PI; rad+=M_PI/180){
        i=(150*cos(rad)+490)/5;
        j=(150*sin(rad)+650)/5;
        cell[i][j]=5;
    }
    

    rad=0;
    
    map();
    
    for(;;){
        
        carlayerID=HgLSwitch(&carlayers);
        statuslayerID=HgLSwitch(&statuslayers);
        HgLClear(carlayerID);
        HgLClear(statuslayerID);

        end=time(NULL);
        t=(int)(end-start);
        timeattack(difftime(time(NULL),start));
        
        HgWImagePut(carlayerID, x, y, car1, 1, rad);

        if((x>=1240)&&(x<=1390)){  //チェックポイントのカウント
            if((y>=498)&&(y<=503)){
                if(check4==1){
                    check1=1;
                }
            }
        }
        if((x>=300)&&(x<=490)){
            if((y>=498)&&(y<=503)){
                if(check2==1){
                    check3=1;
                }
            }
        }
        if((y>=50)&&(y<=200)){
            if((x>=688)&&(x<=693)){
                check2=1;
            }
        }
        if((y>=300)&&(y<=450)){
            if((x>=938)&&(x<=943)){
                if(check3==1){
                    check4=1;
                }
            }
        }
        
        key=HgGetChar(); //車の操作
        if(key==HG_U_ARROW){       //前移動
            i=x/5;
            j=y/5;
            if(cell[i][j]==1){
                x=x+0;
                y=y-1;
                carHP--;
            }else if(cell[i][j]==2){
                x=x+0;
                y=y+1;
                carHP--;
            }else if(cell[i][j]==3){
                x=x-1;
                y=y+0;
                carHP--;
            }else if(cell[i][j]==4){
                x=x+1;
                y=y+0;
                carHP--;
            }else if(cell[i][j]==5){
                y+=cos(rad)*5;
                x-=sin(rad)*5;
                carHP--;
            }else {
                y-=cos(rad)*5;
                x+=sin(rad)*5;
            }
        }else if(key==HG_D_ARROW){ //後ろ移動
            i=x/5;
            j=y/5;
            if(cell[i][j]==1){
                x=x+0;
                y=y-1;
                carHP--;
            }else if(cell[i][j]==2){
                x=x+0;
                y=y+1;
                carHP--;
            }else if(cell[i][j]==3){
                x=x-1;
                y=y+0;
                carHP--;
            }else if(cell[i][j]==4){
                x=x+1;
                y=y+0;
                carHP--;
            }else if(cell[i][j]==5){
                y-=cos(rad)*5;
                x+=sin(rad)*5;
                carHP--;
            }else {
                y+=cos(rad)*5;
                x-=sin(rad)*5;
            }
        }else if(key==HG_R_ARROW){ //右回転
            rad=rad+M_PI/24;
            if(rad==24*M_PI/24){
                rad=-24*M_PI/24;
            }
        }else if(key==HG_L_ARROW){ //左回転
            rad=rad-M_PI/24;
            if(rad==-24*M_PI/24){
                rad=24*M_PI/24;
            }
        }else if(key==' '){        //休止
            pause();
        }

        hp(carHP);
        count(check1, check2, check3, check4);

        if(check1==1){ //ゲームクリア
            clear();
            HgSleep(2.0);
            break;
        }

        if(carHP==0){ //ゲームオーバー
            over();
            HgSleep(2.0);
            break;
        }
        
        HgSleep(0.05);
    }
    
    HgClose();

    return 0;
}
