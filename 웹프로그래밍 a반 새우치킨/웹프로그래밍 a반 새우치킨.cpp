// dfsdfdf.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <windows.h>

#define X_MAX 35 //x축 유저 최대갓 35
#define Y_MAX 22
#define MAXPOO 90
#define MAX 3

void Logo2();
void Logo(void);
void start1();
void start2();
void start3();
void start4();
void move_arrow_key(char chr, int *x, int *y, int x_b, int y_b);
void gotoxy(int x, int y);
int display_dong();
void Init_dong();
/*
void time_pass(time_t start);
void display_time(long nsecond);
void control_watch(void);*/
void user();
void item_cls();
int score();
void MainMap();
void Logo3();
void MaxMin();
void CursorView(char show);
void game_init();

 

enum {HIDE,SHOW};

struct target_st
{
 int flag;
 int X;
 int Y;

}dung[MAXPOO];

struct tartget_st2
{
 int flag2;
 int X;
 int Y;
}item[MAX];

struct _c
{
 int X, Y;

}c;

int sc;


void _tmain(int argc, _TCHAR* argv[])
{  

 int key =0;
 int a;
 
 c.X =20, c.Y = 22;   
 
 
 double second;
 long nsecond;
 time_t now ,start;
 
 CursorView(HIDE);  

 
 while(key != 4)
 {
  do{
   
   Logo();
   key = _getch();

  }while( key>'3' || key< '1' );


  system("cls");
  start3();
  Sleep(400);
  system("cls");
  start2();
  Sleep(400);
  system("cls");
  start1();
  Sleep(400);
  system("cls");
  start4();
  Sleep(1000);
  system("cls");


  
   //충돌체크
   
  MainMap();
  Logo3();

  while(key!=27)
  {
   start=time(NULL);
   
   MaxMin();
   
  if(display_dong()==-1)
 { game_init();
   break;
  }
  
   //충돌체크
   gotoxy(c.X, c.Y);
   printf(" A ");

   item_cls();
  
  }


 }

}

void game_init()
{
 int n,m;
 c.X = 13;
 c.Y = 22;
 sc=0;

 for (n=0; n<=40; n++)
 {
 dung[n].Y=0;
 }
 for (m=0; m<2; m++)
 {
 item[m].Y=0;
 }


}

void Logo3()
{
 gotoxy(46,3);
  printf(" ");
  printf("--------점 수-------");

 gotoxy(46,18);
  printf("웹 프로그래밍 A반");
  Sleep(300);
 gotoxy(44, 20);
  printf("'새우치킨' 조");
  Sleep(300);
 gotoxy(44, 21);
  printf("팀장 : 2012301011 김한솔");
  Sleep(300);
 gotoxy(44, 22); 
  printf("조원 : 2012301002 곽경빈");
  Sleep(300);
 gotoxy(44, 23); 
  printf("       2012301013 남소영");
  

}

void MaxMin()
{
    if(GetAsyncKeyState(VK_LEFT))
   {
    Sleep(20);
    c.X-- ;
    if (c.X<3) 
     c.X=3; //X좌표 최솟값

   }else if(GetAsyncKeyState(VK_RIGHT))
   {
    Sleep(20);
    c.X++ ;
    if (c.X>X_MAX) 
     c.X=X_MAX;
    //X좌표 최솟값
   }else
   {
    Sleep(20);
   } 
}

int score()
{
 int i=0;
 if(dung[i].Y == 24)
 {
  sc+=1;

  gotoxy(46,10);
  printf(" ");
   printf("현재 점수는 %d 입니다",sc);
   
    
 }
 return sc;
 
}

void CursorView(char show)
{
 HANDLE hConsole;
 CONSOLE_CURSOR_INFO ConsoleCursor;
 hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
 ConsoleCursor.bVisible = show;
 ConsoleCursor.dwSize = 1;
 SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}
void Logo(void)
{

 system("cls");

 printf("□□■■■■■□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
 printf("□□■□■□□□□□□□□□□□□■□□□■□□□□■□□□□□□□□□■□□\n");
 printf("□□■□■□□□□□■■■■■■□■□□□■□□□□■□□■■■■■■□■□□\n");
 printf("□□■■■■■□□□□■□□■□□■□■■■■■■□■□□□□□□□■□■□□\n");
 printf("□□□□■□□□□□□■□□■□□■□□■■■□□□■□□□□□□■□□■□□\n");
 printf("□■■■■■■■□□□■□□■□□■□■□□□■□□■■■□□□■□□□■□□\n");
 printf("□□□□□□□□□□■■■■■■□■□■□□□■□□■□□□□■□□□□■□□\n");
 printf("□□□■■■□□□□□□□□□□□■□■□□□■□□■□□□■□□□□□■□□\n");
 printf("□□■□□□■□□□□□□□□□□■□□■■■□□□■□□■□□□□□□■□□\n");
 printf("□□■□□□■□□□□□□□□□□■□□□□□□□□■□□□□□□□□□■□□\n");
 printf("□□■□□□■□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
 printf("□□□■■■□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
 printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
 printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
 printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
 printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
 printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");

 printf("\t\t★ 똥피하기 게임에 오신걸 환영합니다 ★ \n");
 printf("\t\t    지금부터 게임을 시작하겠습니다\n");
 printf("\t\t 1. 게임 시작 \n");
 printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
 printf("\t\t 1번을 눌러 주세요\n");
}

 


void gotoxy(int x, int y)
{
 COORD Pos = {x - 1, y - 1};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void move_arrow_key(char key, int *x, int *y, int x_b,int y_b)
{
 switch(key)
 {
 case 75:
  *x=*x-1;
  if (*x<3) 
   *x=3; //X좌표 최솟값
  break;
 case 77:
  *x=*x+1;
  if(*x>x_b) 
   *x=x_b; //X좌표 최댓값
  break;

 default:
  return;
 }

}
void user()
{
 char key;
 c.X=20, c.Y=22; 
 do
 {
  gotoxy(c.X, c.Y);
  printf(" A ");
  key=_getch();
  move_arrow_key(key, &c.X,&c.Y,X_MAX,Y_MAX);
 }while(key!=27);

 return ;


}


int display_dong()
{
 
 int key = 0;
 
 srand((unsigned int)time(NULL));


 for(int i=0; i<40; i++)
 {
  if(dung[i].flag == 0)
  {
   dung[i].flag = rand()%2;
   dung[i].X = rand()%36+2;
   dung[i].Y = 0;
  }
 }
  
 for(int i=0; i<40; i++){
  if(dung[i].flag == 1)
  {   
   gotoxy(dung[i].X, dung[i].Y);
   printf(" ");
   dung[i].Y++;
   gotoxy(dung[i].X, dung[i].Y);
   printf("l");
   
  }
  if(dung[i].Y > 24)
  {
   dung[i].flag = 0;
   gotoxy(dung[i].X, dung[i].Y);
   printf(" ");

  }
  if(dung[i].Y == 24)
  {
   score();

  }


  if(dung[i].X == c.X && dung[i].Y == c.Y) 
  {
   printf(" ");
   int l;
 
 while(1)
 {
 
  Logo2();
  l = getch();
  try{
   
   switch(l){
   case '1':
     return -1;
   case '2':
    exit(0);
   default:
    throw l;
   }
  }
  catch (int)
  {
   gotoxy(32,22);
   
   printf(" 잘못된 입력입니다");
   gotoxy(49,24);
  }
 }


  

   
  }

 

 }
  
}

void Logo2()
{
 system("cls");
 printf("                                                                                ");
 printf("                                                                                ");
 printf("┌──────────────────────────────────────┐");
 printf("│     ■■■■     ■■      ■   ■    ■■■■■                           │");
 printf("│    ■          ■   ■    ■■ ■■   ■                                   │");
 printf("│    ■   ■■   ■■■■   ■ ■■ ■   ■■■■■                          │");
 printf("│    ■     ■   ■    ■  ■  ■   ■  ■                                   │");
 printf("│      ■■■    ■    ■  ■       ■  ■■■■■                           │");
 printf("│                                                                            │");
 printf("│                       ■■■    ■      ■   ■■■■■  ■■■■          │");
 printf("│                      ■    ■    ■    ■    ■         ■     ■          │");
 printf("│                     ■      ■    ■  ■     ■■■■■  ■■■■          │");
 printf("│                      ■    ■     ■ ■      ■          ■  ■            │");
 printf("│                       ■■■       ■        ■■■■■   ■   ■          │");
 printf("└──────────────────────────────────────┘");
 printf("                                                                       ");
 printf("          score : %d 점 입니다    ",sc);
 printf("                                                                     ");
  
 printf("\n");
 printf("  \t\t 1. 다시 시작                                                      \n");
 printf("  \t\t 2. 게임 끝내기                                                    \n");
 printf("\n");
 printf("\t\t 번호를 눌러 주세요\n");
}

void item_cls()
{
 srand((unsigned int)time(NULL));

 for(int i=0; i<2; i++)
 {
  if(item[i].flag2 == 0)
  {
   if(item[i].X != dung[i].X)
   {
   item[i].flag2 = rand()%2; 
   item[i].X = rand()%35+2;
   item[i].Y = 0;
   }
  }
 }

 for(int i=0; i<2; i++)
 {
  if(item[i].flag2 == 1)
  {   
   gotoxy(item[i].X, item[i].Y);
   printf(" ");
   item[i].Y++;
   gotoxy(item[i].X, item[i].Y);
   printf("★");
  }
  
  if(item[i].Y > 24)
  {
   item[i].flag2 = 0;
   gotoxy(item[i].X, item[i].Y);
   printf(" ");

  }
  
  if(item[i].X == c.X && item[i].Y == c.Y) 
  {
  
   sc+=50;
     gotoxy(item[i].X, item[i].Y);
   printf(" ");
  }
 } 

}

 

 

void start1()
{

 printf("                                                                              \n");
 printf("                                ■■                                          \n");
 printf("                              ■■■                                          \n");
 printf("                            ■  ■■                                          \n");
 printf("                                ■■                                          \n");
 printf("                                ■■                                          \n");
 printf("                                ■■                                          \n");
 printf("                                ■■                                          \n");
 printf("                                ■■                                          \n");
 printf("                                ■■                                          \n");
 printf("                                ■■                                          \n");
 printf("                                ■■                                          \n");
 printf("                                ■■                                          \n");
 printf("                                ■■                                          \n");
 printf("                                ■■                                          \n");
 printf("                                ■■                                          \n");
 printf("                                ■■                                          \n");
 printf("                                ■■                                          \n");
 printf("                          ■■■■■■■■                                    \n");
 printf("                                                                              \n");
 printf("                                                                              \n");
 printf("                                                                              \n");
}

void start2()
{
 
 printf("\n");
 printf("                          ■■■■■■■■                               \n");
 printf("                       ■■■■■■■■■■\n");
 printf("                     ■■              ■■\n");
 printf("                    ■■                 ■■\n");
 printf("                    ■■                 ■■\n");
 printf("                     ■■                 ■■\n");
 printf("                                        ■■\n");
 printf("                                       ■■\n");
 printf("                                      ■■\n");
 printf("                                    ■■\n");
 printf("                                  ■■\n");
 printf("                                 ■■\n");
 printf("                               ■■\n");
 printf("                             ■■ \n");
 printf("                         ■■■\n");
 printf("                      ■■■\n");
 printf("                      ■■■■■■■■■■■■■■\n");
 printf("                      ■■■■■■■■■■■■■■\n");
 printf("\n");
 printf("\n");
 printf("\n");
}

void start3()
{
 
 printf("\n");
 printf("                         ■■■■■■■■\n");
 printf("                       ■■■■■■■■■■\n");
 printf("                     ■■             ■■\n");
 printf("                    ■■                 ■■\n");
 printf("                    ■■                  ■■\n");
 printf("                                       ■■\n");
 printf("                                      ■■\n");
 printf("                                   ■■\n");
 printf("                                ■■\n");
 printf("                              ■■\n");
 printf("                                 ■■\n");
 printf("                                    ■■■\n");
 printf("                                        ■■\n");
 printf("                                         ■■\n");
 printf("                                         ■■\n");
 printf("                     ■                 ■■\n");
 printf("                      ■■■■■■■■■■\n");
 printf("                       ■■■■■■■■■\n");
 printf("\n");
 printf("\n");
 printf("\n");
}

void start4()
{
 
 printf("                                                                                ");
 printf("                                                                                ");
 printf("                                                                                ");
 printf("                                                                                ");
 printf("                                                                                ");
 printf("┌──────────────────────────────────────┐");
 printf("│     ■■■■     ■■■■          ■            ■■■      ■■■■      │");
 printf("│    ■               ■            ■■          ■    ■        ■         │");
 printf("│     ■■■■        ■           ■■■         ■ ■■         ■         │");
 printf("│            ■       ■          ■    ■        ■    ■        ■         │");
 printf("│     ■■■■        ■         ■      ■       ■    ■        ■         │");
 printf("└──────────────────────────────────────┘");
 printf("                                                                                ");
 printf("                                                 ");
 printf("                                  조 작 법                                  ");
 printf("                                                                           ");
 printf("                                                                              ");
 printf("                            왼쪽  :   ←                                    ");
 printf("                            오른쪽 :   →                                     ");
 printf("                                                                            ");
 printf("                                                                            ");
    printf("                                    ");
}

 

void MainMap()
{
 int i;

 for(i=1;i<25;i++)
 {


  gotoxy(40,i);
  printf("□");
  Sleep(30);
 }

 
 for(i=42;i<80;i++)
 {
  gotoxy(i,15);
  printf("_");
  Sleep(30);
 }
 
}

