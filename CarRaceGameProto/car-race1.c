/*****
      car-race1.c
      自由課題(最終課題)
      g1744069 Keisuke Ikeda
*****/

#include <stdio.h>
#include <handy.h>
#include <math.h>

doubleLayer car1layers;
doubleLayer car2layers;
int windowID;
int car1layerID;
int car2layerID;
int lalelayerID;

int map(){ //マップデータ
    
    HgWSetColor(lalelayerID, HG_ORANGE);
    HgWLine(lalelayerID,1240, 500, 1390, 500); //スタートゴール
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

    return 1;
}

int main(){

    int car1 = HgImageLoad("car1.png");
    int car2 = HgImageLoad("car2.png");
    double x1=1290, y1=525;
    double x2=1340, y2=525;
    double rad1=0, rad2=0;
    int i;
    int key1;
    
    windowID = HgOpen(1440, 870);
    lalelayerID = HgWAddLayer(windowID);
    car1layers = HgWAddDoubleLayer(windowID);
    car2layers = HgWAddDoubleLayer(windowID);

    
    HgWSetColor(lalelayerID, HG_GREEN);
    for(i = 0; i <= 1440 ; i+=5) {
        HgSetColor(HG_GREEN);
         HgWLine(lalelayerID, i, 0, i, 870);
     }
    for(i = 0; i <= 870 ; i+=5) {
        HgSetColor(HG_GREEN);
        HgWLine(lalelayerID, 0, i, 1440, i);
     }

    map();
    
    for(;;){
        
        car1layerID=HgLSwitch(&car1layers);
        car2layerID=HgLSwitch(&car2layers);
        HgLClear(car1layerID);
        HgLClear(car2layerID);

        HgWImagePut(car1layerID, x1, y1, car1, 1, rad1);
        HgWImagePut(car2layerID, x2, y2, car2, 1, rad2);

        key1=HgGetChar(); //車１の操作
        if(key1==HG_U_ARROW){       //上移動
            y1=y1+5;
            if((M_PI>rad1)&&(rad1>=0)){
                rad1=rad1+M_PI/24;
            }else if((0>rad1)&&(rad1>-M_PI)){
                rad1=rad1-M_PI/24;
            }else {
                rad1=M_PI;
            }
        }else if(key1==HG_D_ARROW){ //下移動
            y1=y1-5;
            if((M_PI>=rad1)&&(rad1>0)){
                rad1=rad1-M_PI/24;
            }else if((0>rad1)&&(rad1>=-M_PI)){
                rad1=rad1+M_PI/24;
            }else {
                rad1=0;
            }
        }else if(key1==HG_R_ARROW){ //右移動
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
        }else if(key1==HG_L_ARROW){ //左移動
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
        }else if(key1=='d'){        //右上移動
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
        }else if(key1=='c'){        //右下移動
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
        }else if(key1=='s'){        //左上移動
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
        }else if(key1=='x'){        //左下移動
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
        }else if(key1==' '){        //終了
            break;
        }
        
        HgSleep(0.05);
    }

    HgGetChar();
    HgClose();

    return 0;
}
