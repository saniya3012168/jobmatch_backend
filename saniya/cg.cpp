#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#Include<math.h>
#include<dos.h>
class walking{
int x,y;
public:
void draw(int,int);
void draw(int);
};
void walking::draw(int xmov){
setbkcolor(8);
setfillstyle(1,14);
setcolor(GREEN);
line(0,400,639,400);   //platform
secolor(WHITE)
circle(30+xmov,280,20);  //head
line(30+xmov,300,30+xmov,350);  //body
line(30+xmov,310,70+xmov,330);//hand

if(xmov%2==0){
line(30+xmov,350,50+xmov,400); //right leg
line(30+xmov,350,10+xmov,400);  //left leg
line(30+xmov,310,10+xmov,350);  //hand

}
else{
setcolor(WHITE);
line(30+xmov,310,40+xmov,340); //hand
line(30+xmov,350,43+xmov,355); //knee
line(43+xmov,355,60+xmov,400); //below knee
line(30+xmov,350,25+xmov,400); //left leg
delay(25);
}
setcolor(BROWN);
line(70+xmov,250,70+xmov,330);  //handle
arc(60+xmov,330,180,360,10);    //curve
setcolor(YELLOW);
setfittstyle(4,14);
pieslice(60+xmov,250,180,0,80);
}
void walking::draw(int x1,inty1){
for(int i=0;i<=300;i++){
setcolor(BLUE);
x=random(800);
y=random(800);
outtextxy(x,y,"/");
}
}
int main(){
int gd=DETECT,gm,xmov,x1,y1;
initgraph(&gd,&gm,"C:\\TC\\BGI");
walking o;
for(xmov=1;xmov<200;xmov+=5){
o.draw(xmov);
o.draw(x1,y1);
delay(600);
cleardevice();
}
getch();
closegraph();
return 0;}
