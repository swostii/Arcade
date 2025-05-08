#include<graphics.h>
#include<iostream>
#include<dos.h>
using namespace std;
void menu();
void instruction();
void about();
void maingame();
void playgame1();
void playgame2();
void playgame3();
void playgame4();

void coin();

void draw1();
void bg1bug1();
void bg1bug2();
void bg1food();

void draw2();
void bg2bug1();
void bg2bug2(); 

void draw3();

void draw4();

void gameover_bug(int a,int b);
void gameover_bird(int a,int b);
void gameover();



void drawfire();
void drawcharacterright();
void drawcharacterleft();
void menu();
int score=0;
int life=3;
char arr[50];
void loadingpage()
{
	int color=0;
	initwindow(1368,766,"Loading");
	setfillstyle(SLASH_FILL,8);
	rectangle(100,100,1268,666);
	rectangle(60,60,1308,706);
	floodfill(80,80,15);
	settextstyle(3,0,10);
	
	for(int i=150;i<300;i++)
	{	
		outtextxy(i,200,"ARCADE");
		outtextxy(1050-i,200,"GAME");
		delay(1);
	}
		cleardevice();
		setfillstyle(SLASH_FILL,8);
		rectangle(100,100,1268,666);
		rectangle(60,60,1308,706);
		floodfill(80,80,15);
		
	for(int color=0;color<16;color++)
	{
		setcolor(color);
		outtextxy(325,200,"ARCADE GAME");
		delay(200);
	}
	settextstyle(5,0,5);
	outtextxy(575,550,"loading...");

	settextstyle(3,0,3);
	for(int i=530;i<780;i=i+2)
	{
		if(color==15)
		{
			color=0;
		}
		setcolor(color);
		outtextxy(i,592,"l");
		delay(25);
		color++;
	}
	
}

void gameover_bug(int a,int b)
{
		line(a+200,b+135,a+210,b+135);		//head top
		//left ear
	line(a+200,b+135,a+200,b+130);
	line(a+200,b+130,a+195,b+130);
	line(a+195,b+130,a+195,b+135);
		//left side
	line(a+195,b+135,a+190,b+135);
	line(a+190,b+135,a+190,b+140);
	line(a+190,b+140,a+185,b+140);
	line(a+185,b+140,a+185,b+145);
	line(a+185,b+145,a+190,b+145);
	line(a+190,b+145,a+190,b+150);
	
		//right ear
	line(a+210,b+135,a+210,b+130);
	line(a+210,b+130,a+215,b+130);
	line(a+215,b+130,a+215,b+135);
		//right side
	line(a+215,b+135,a+220,b+135);
	line(a+220,b+135,a+220,b+140);
	line(a+220,b+140,a+225,b+140);
	line(a+225,b+140,a+225,b+145);
	line(a+225,b+145,a+220,b+145);
	line(a+220,b+145,a+220,b+150);

		//base
	line(a+190,b+150,a+220,b+150);
		//leg
	rectangle(a+195,b+150,a+200,b+155);
	rectangle(a+210,b+150,a+215,b+155);
		//eyes
	circle(a+200,b+142,1);
	circle(a+210,b+142,1);
}

void gameover_bird(int a,int b)
{
		//head
	line(a,b-300,a+10,b-300);	//top
	line(a,b-300,a-5,b-285);	//lside
	line(a-5,b-285,a+5,b-280);
	line(a+10,b-300,a+15,b-285);	//rside
	line(a+15,b-285,a+5,b-280);
	
		//left wing
	line(a-2,b-297,a-15,b-297);
	line(a-15,b-297,a-5,b-285);
	line(a-15,b-297,a-25,b-285);
	line(a-25,b-285,a-5,b-285);
	
		//right wing
	line(a+12,b-297,a+25,b-297);
	line(a+25,b-297,a+15,b-285);
	line(a+25,b-297,a+35,b-285);
	line(a+35,b-285,a+15,b-285);
		//eyes
	circle(a+2,b-293,1);	//left
	circle(a+8,b-293,1);
	arc(a+5,b-286,190,350,2);
		//ears
	//left
	line(a,b-300,a+3,b-305);
	line(a+3,b-305,a+4,b-300);
	//right
	line(a+10,b-300,a+7,b-305);
	line(a+7,b-305,a+6,b-300); 		
}
void gameover()
{	
	int a=0,b=0;
	initwindow(1368,766,"gameover");
	setfillstyle(SLASH_FILL,8);
	rectangle(100,100,1268,666);
	rectangle(60,60,1308,706);
	floodfill(80,80,15);
	
	setcolor(RED);
	settextstyle(3,0,10);
	outtextxy(390,280,"GAME OVER");

	
	setcolor(WHITE);
	settextstyle(10,0,3);
	outtextxy(480,450,"Enter any key to return to menu");
	
		
	gameover_bug(a,b+510);
	gameover_bug(a+50,b+510);
	gameover_bug(a+500,b+510);
	gameover_bug(a+600,b+510);
	gameover_bug(a+900,b+510);
	
	gameover_bird(a+200,b+450);
	gameover_bird(a+270,b+470);
	gameover_bird(a+500,b+550);
	gameover_bird(a+800,b+500);
	gameover_bird(a+1000,b+450);
	gameover_bird(a+1200,b+530);
	
	life=3;
	
	getch();
	
	maingame();
	
}

void menu()
{	
//	readimagefile("menubg.jpg",0,0,1366,780);
	settextstyle(10,0,4);     //use 8 or 10 for required font type
	setfillstyle(SLASH_FILL,8);
	rectangle(300,150,1050,600);
	rectangle(320,170,1030,580);
	floodfill(310,160,8);
	
	//options
	setfillstyle(SOLID_FILL,BLACK);
	rectangle(500,220,850,270);
	floodfill(600,250,8);
	outtextxy(590,230,"PLAY GAME");
	
	
	rectangle(500,305,850,355);
	floodfill(600,340,8);
	outtextxy(568,315,"INSTRUCTION");
	
	rectangle(500,390,850,440);
	floodfill(600,420,8);
	outtextxy(630,400,"ABOUT");
	
	rectangle(500,475,850,525);
	floodfill(600,490,8);
	outtextxy(635,485,"EXIT");
}
void coin(int x, int y)
{
	//line(x,50,x,800);
	//line(40,620,1500,620);	
	
	arc(x-5,y+15,310,50,20);
	arc(x+12,y+15,130,230,20);	
	
	arc(x-3,y+15,310,50,20);
	//arc(x+14,y+15,130,230,20);
	
	arc(x-1,y+15,310,50,20);
	//arc(x+16,y+15,130,230,20);
	
	line(x,y,x+7,y);
	line(x,y+30,x+7,y+30);
	
	outtextxy(x,y+6,"$");
}
void drawcharacter(int x, int y, int a, int b)
{
		

	sprintf(arr,"Score: %d",score);
	outtextxy(10,10,arr);
	
	sprintf(arr,"Life: %d",life);
	outtextxy(310,10,arr);
	
		//character
	
//	setfillstyle(SOLID_FILL,RED);
	rectangle(x-30,y-70,x+5,y-65);		//hat bottom
	rectangle(x-22,y-80,x-3,y-70);		//hat top
//	floodfill(x-29,y-69,WHITE);
//	floodfill(x-20,y-75,WHITE);
	

	rectangle(x-25,y-65,x,y-50);		//face
	rectangle(x-17,y-50,x-7,y-45);		//neck

	
//	setfillstyle(SOLID_FILL,CYAN);   
	rectangle(x-25,y-45,x,y-15);		//body
//	floodfill(x-20,y-40,WHITE);
	
//	setfillstyle(SOLID_FILL,DARKGRAY);
	rectangle(x-25,y-15,x-15,y-10);		//r leg
	rectangle(x-8,y-15,x-3,y-5);		//l leg
//	floodfill(x-20,y-11,WHITE);
//	floodfill(x-5,y-10,WHITE);
	

	rectangle(x-10,y-5,x,y);		 	//l foot   //important point x,y  
	rectangle(x-30,y-16,x-25,y-7);		//r foot

	
//	rectangle(x-5,y-63,x-2,y-60);	//eye
	circle(x-5,y-60,3);					//eye

	
//	setfillstyle(SOLID_FILL,WHITE);
	rectangle(x-20,y-40,x-17,y-27);		//l hand top
	rectangle(x-17,y-30,x-10,y-27);		//l hand bottom
//	floodfill(x-18,y-30,WHITE);
//	floodfill(x-15,y-28,WHITE);
	
	
	
}

void drawcharacterleft(int m,int n,int a,int b)
{
	
	
		//mirrored character
	
	sprintf(arr,"Score: %d",score);
	outtextxy(10,10,arr);
	
	sprintf(arr,"Life: %d",life);
	outtextxy(310,10,arr);
	
	rectangle(m+3,n-80,m+22,n-70);	//hat top
	rectangle(m-5,n-70,m+30,n-65);	//hat bottom
	rectangle(m,n-65,m+25,n-50);	//face
	circle(m+5,n-60,3);	//eye
	rectangle(m+8,n-50,m+18,n-45);	//neck
	rectangle(m,n-45,m+25,n-15);	//body
	rectangle(m+20,n-40,m+17,n-27);	// l hand top
	rectangle(m+10,n-27,m+17,n-30);	//l hand bottom
	rectangle(m+3,n-15,m+8,n-5);	//r leg 
	rectangle(m,n-5,m+11,n);	// r foot //important point m,n
	rectangle(m+15,n-15,m+25,n-10);	//l leg
	rectangle(m+25,n-16,m+30,n-7);	//l foot
}



void draw1(int x,int y,int a,int b)
{
	outtextxy(1200,100,"BACKGROUND1");
	//log
	line(200,600,200,660);		//verticle l
	line(200,600,205,595);		//curve l
	line(205,595,255,595);		//horizontal
	line(255,595,260,600);		//curve r
	line(260,600,260,660);		//verticle r
	line(200,660,260,660);		//base

	
	//block

	rectangle(305,500,375,535);	//doubleblock1
	line(340,500,340,535);

			
	rectangle(430,435,605,470);	//5 blocks
	rectangle(465,435,500,470);
	rectangle(535,435,570,470);
	
	//rectangle(490,400,500,410);//food

	
	rectangle(660,390,695,425);	//single1

	
	rectangle(750,440,785,475);	//single2

	rectangle(840,560,875,595);		//single3
	
	rectangle(930,530,1000,565);	//double2
	line(965,530,965,565);


	
//bird 1
		//head
	line(a,b-300,a+10,b-300);	//top
	line(a,b-300,a-5,b-285);	//lside
	line(a-5,b-285,a+5,b-280);
	line(a+10,b-300,a+15,b-285);	//rside
	line(a+15,b-285,a+5,b-280);
	
		//left wing
	line(a-2,b-297,a-15,b-297);
	line(a-15,b-297,a-5,b-285);
	line(a-15,b-297,a-25,b-285);
	line(a-25,b-285,a-5,b-285);
	
		//right wing
	line(a+12,b-297,a+25,b-297);
	line(a+25,b-297,a+15,b-285);
	line(a+25,b-297,a+35,b-285);
	line(a+35,b-285,a+15,b-285);
		//eyes
	circle(a+2,b-293,1);	//left
	circle(a+8,b-293,1);
	arc(a+5,b-286,190,350,2);
		//ears
	//left
	line(a,b-300,a+3,b-305);
	line(a+3,b-305,a+4,b-300);
	//right
	line(a+10,b-300,a+7,b-305);
	line(a+7,b-305,a+6,b-300); 
	
//bird 2
		//head
	line(a+200,b-400,a+210,b-400);	//top
	line(a+200,b-400,a+195,b-385);	//lside
	line(a+195,b-385,a+205,b-380);
	line(a+210,b-400,a+215,b-385);	//rside
	line(a+215,b-385,a+205,b-380);
	
		//left wing
	line(a+198,b-397,a+185,b-397);
	line(a+185,b-397,a+195,b-385);
	line(a+185,b-397,a+175,b-385);
	line(a+175,b-385,a+195,b-385);
	
		//right wing
	line(a+212,b-397,a+225,b-397);
	line(a+225,b-397,a+215,b-385);
	line(a+225,b-397,a+235,b-385);
	line(a+235,b-385,a+215,b-385);
		//eyes
	circle(a+202,b-393,1);	//left
	circle(a+208,b-393,1);
	arc(a+205,b-386,190,350,2);
		//ears
	//left
	line(a+200,b-400,a+203,b-405);
	line(a+203,b-405,a+204,b-400);
	//right
	line(a+210,b-400,a+207,b-405);
	line(a+207,b-405,a+206,b-400); 
	
//bird 3
		//head
	line(a+700,b-250,a+710,b-250);	//top
	line(a+700,b-250,a+695,b-235);	//lside
	line(a+695,b-235,a+705,b-230);
	line(a+710,b-250,a+715,b-235);	//rside
	line(a+715,b-235,a+705,b-230);
	
		//left wing
	line(a+698,b-247,a+685,b-247);
	line(a+685,b-247,a+695,b-235);
	line(a+685,b-247,a+675,b-235);
	line(a+675,b-235,a+695,b-235);
	
		//right wing
	line(a+712,b-247,a+725,b-247);
	line(a+725,b-247,a+715,b-235);
	line(a+725,b-247,a+735,b-235);
	line(a+735,b-235,a+715,b-235);
		//eyes
	circle(a+702,b-243,1);	//left
	circle(a+708,b-243,1);
	arc(a+705,b-236,190,350,2);
		//ears
	//left
	line(a+700,b-250,a+703,b-255);
	line(a+703,b-255,a+704,b-250);
	//right
	line(a+710,b-250,a+707,b-255);
	line(a+707,b-255,a+706,b-250); 
	
	//pipe
	rectangle(1100,580,1180,660);
	rectangle(1090,560,1190,580);
	
	//ground
	line(0,660,1366,660);	//top
	line(0,670,1366,670);	//bottom

	//mid cloud
	line(95,120,315,120);
	arc(120,120,70,180,25);
	arc(145,100,69,170,20);
	arc(191,81,40,180,40);
	arc(220,104,30,90,50);
	arc(265,105,36,95,25);
	arc(278,130,15,80,40);

	//small cloud
	line(990,150+60,1101,150+60);
	arc(1000,150+60,70,180,10);
	arc(1022,143+60,69,170,20);
	arc(1055,140+60,0,152,30);
	arc(1090,150+60,1,120,12);
}

void bg1food(int f1,int f2)
{
	line(f1+700,f2+655,f1+680,f2+635);
	line(f1+700,f2+655,f1+720,f2+635);
	arc(f1+690,f2+635,0,180,10);
	arc(f1+710,f2+635,0,180,10);
}
void bg1bug1(int a, int b)
{
	//bug 1
	line(a+200,b+135,a+210,b+135);		//head top
		//left ear
	line(a+200,b+135,a+200,b+130);
	line(a+200,b+130,a+195,b+130);
	line(a+195,b+130,a+195,b+135);
		//left side
	line(a+195,b+135,a+190,b+135);
	line(a+190,b+135,a+190,b+140);
	line(a+190,b+140,a+185,b+140);
	line(a+185,b+140,a+185,b+145);
	line(a+185,b+145,a+190,b+145);
	line(a+190,b+145,a+190,b+150);
	
		//right ear
	line(a+210,b+135,a+210,b+130);
	line(a+210,b+130,a+215,b+130);
	line(a+215,b+130,a+215,b+135);
		//right side
	line(a+215,b+135,a+220,b+135);
	line(a+220,b+135,a+220,b+140);
	line(a+220,b+140,a+225,b+140);
	line(a+225,b+140,a+225,b+145);
	line(a+225,b+145,a+220,b+145);
	line(a+220,b+145,a+220,b+150);

		//base
	line(a+190,b+150,a+220,b+150);
		//leg
	rectangle(a+195,b+150,a+200,b+155);
	rectangle(a+210,b+150,a+215,b+155);
		//eyes
	circle(a+200,b+142,1);
	circle(a+210,b+142,1);
	
}
	
void bg1bug2(int a,int b)
{
	
	//bug 2
		//head top
	line(a+350,b+135,a+360,b+135);	
		//left ear
	line(a+350,b+135,a+350,b+130);
	line(a+350,b+130,a+345,b+130);
	line(a+345,b+130,a+345,b+135);
		//left side
	line(a+345,b+135,a+340,b+135);
	line(a+340,b+135,a+340,b+140);
	line(a+340,b+140,a+335,b+140);
	line(a+335,b+140,a+335,b+145);
	line(a+335,b+145,a+340,b+145);
	line(a+340,b+145,a+340,b+150);
	
		//right ear
	line(a+360,b+135,a+360,b+130);
	line(a+360,b+130,a+365,b+130);
	line(a+365,b+130,a+365,b+135);
		//right side
	line(a+365,b+135,a+370,b+135);
	line(a+370,b+135,a+370,b+140);
	line(a+370,b+140,a+375,b+140);
	line(a+375,b+140,a+375,b+145);
	line(a+375,b+145,a+370,b+145);
	line(a+370,b+145,a+370,b+150);

		//base
	line(a+340,b+150,a+370,b+150);
		//leg
	rectangle(a+345,b+150,a+350,b+155);
	rectangle(a+360,b+150,a+365,b+155);
		//eyes
	circle(a+350,b+142,1);
	circle(a+360,b+142,1);
	
}



void draw2(int x,int y,int a,int b)
{   	
	
	//setcolor(BLUE);
	//small block
	rectangle(95,575,120,600);
	
	//block
	outtextxy(1200,100,"BACKGROUND2");	
	

	rectangle(185,525,325,560);	//4 blocks
	line(220,525,220,560);
	rectangle(255,525,290,560);

	
	rectangle(390,465,425,500);	//single1

	
	rectangle(655,495,725,530);	//double
	line(690,495,690,530);

	
	rectangle(790,430,825,465);	//single2

	
	rectangle(890,530,995,565);	//triple
	rectangle(925,530,960,565);

	//pipe

	rectangle(500,580,580,660);//bottom
	rectangle(490,560,590,580);//top

	

	//log

	line(1060,600,1060,660);		//verticle l
	line(1060,600,1065,595);		//curve l
	line(1065,595,1115,595);		//horizontal
	line(1115,595,1120,600);		//curve r
	line(1120,600,1120,660);		//verticle r
	line(1060,660,1120,660);		//base

	

	

//bird
		//head
	line(a,b-300,a+10,b-300);	//top
	line(a,b-300,a-5,b-285);	//lside
	line(a-5,b-285,a+5,b-280);
	line(a+10,b-300,a+15,b-285);	//rside
	line(a+15,b-285,a+5,b-280);
	
		//left wing
	line(a-2,b-297,a-15,b-297);
	line(a-15,b-297,a-5,b-285);
	line(a-15,b-297,a-25,b-285);
	line(a-25,b-285,a-5,b-285);
	
		//right wing
	line(a+12,b-297,a+25,b-297);
	line(a+25,b-297,a+15,b-285);
	line(a+25,b-297,a+35,b-285);
	line(a+35,b-285,a+15,b-285);
		//eyes
	circle(a+2,b-293,1);	//left
	circle(a+8,b-293,1);
	arc(a+5,b-286,190,350,2);
		//ears
	//left
	line(a,b-300,a+3,b-305);
	line(a+3,b-305,a+4,b-300);
	//right
	line(a+10,b-300,a+7,b-305);
	line(a+7,b-305,a+6,b-300); 
	
	//ground

	rectangle(0,660,880,670);	//top1
	rectangle(1015,660,1366,670);	//top2

	

	line(880,660,880,880);	//left
	line(1015,660,1015,880);	//right

	//mid cloud
	line(105,120,325,120);
	arc(130,120,70,180,25);
	arc(155,100,69,170,20);
	arc(201,81,40,180,40);
	arc(230,104,30,90,50);
	arc(275,105,36,95,25);
	arc(288,130,15,80,40);
	
	//small cloud
	line(990,150+60,1101,150+60);
	arc(1000,150+60,70,180,10);
	arc(1022,143+60,69,170,20);
	arc(1055,140+60,0,152,30);
	arc(1090,150+60,1,120,12);

}

void bg2bug1(int x,int y,int a, int b)
{
	//bug 1
	line(a+100,b+135,a+110,b+135);		//head top
		//left ear
	line(a+100,b+135,a+100,b+130);
	line(a+100,b+130,a+95,b+130);
	line(a+95,b+130,a+95,b+135);
		//left side
	line(a+95,b+135,a+90,b+135);
	line(a+90,b+135,a+90,b+140);
	line(a+90,b+140,a+85,b+140);
	line(a+85,b+140,a+85,b+145);
	line(a+85,b+145,a+90,b+145);
	line(a+90,b+145,a+90,b+150);
	
		//right ear
	line(a+110,b+135,a+110,b+130);
	line(a+110,b+130,a+115,b+130);
	line(a+115,b+130,a+115,b+135);
		//right side
	line(a+115,b+135,a+120,b+135);
	line(a+120,b+135,a+120,b+140);
	line(a+120,b+140,a+125,b+140);
	line(a+125,b+140,a+125,b+145);
	line(a+125,b+145,a+120,b+145);
	line(a+120,b+145,a+120,b+150);

		//base
	line(a+90,b+150,a+120,b+150);
		//leg
	rectangle(a+95,b+150,a+100,b+155);
	rectangle(a+110,b+150,a+115,b+155);
		//eyes
	circle(a+100,b+142,1);
	circle(a+110,b+142,1);	
} 

void bg2bug2(int x, int y, int a, int b)
{
	//bug 2
	line(a+500,b+135,a+510,b+135);		//head top
		//left ear
	line(a+500,b+135,a+500,b+130);
	line(a+500,b+130,a+495,b+130);
	line(a+495,b+130,a+495,b+135);
		//left side
	line(a+495,b+135,a+490,b+135);
	line(a+490,b+135,a+490,b+140);
	line(a+490,b+140,a+485,b+140);
	line(a+485,b+140,a+485,b+145);
	line(a+485,b+145,a+490,b+145);
	line(a+490,b+145,a+490,b+150);
	
		//right ear
	line(a+510,b+135,a+510,b+130);
	line(a+510,b+130,a+515,b+130);
	line(a+515,b+130,a+515,b+135);
		//right side
	line(a+515,b+135,a+520,b+135);
	line(a+520,b+135,a+520,b+140);
	line(a+520,b+140,a+525,b+140);
	line(a+525,b+140,a+525,b+145);
	line(a+525,b+145,a+520,b+145);
	line(a+520,b+145,a+520,b+150);

		//base
	line(a+490,b+150,a+520,b+150);
		//leg
	rectangle(a+495,b+150,a+500,b+155);
	rectangle(a+510,b+150,a+515,b+155);
		//eyes
	circle(a+500,b+142,1);
	circle(a+510,b+142,1);
}


void draw3(int x,int y,int a,int b)
{
	outtextxy(1200,100,"BACKGROUND3");
	
	//mid cloud
	line(95,160,315,160);
	arc(120,160,70,180,25);
	arc(145,140,69,170,20);
	arc(191,121,40,180,40);
	arc(220,144,30,90,50);
	arc(265,145,36,95,25);
	arc(278,170,15,80,40);

	//small cloud
	line(990,150+60,1101,150+60);
	arc(1000,150+60,70,180,10);
	arc(1022,143+60,69,170,20);
	arc(1055,140+60,0,152,30);
	arc(1090,150+60,1,120,12);
	
	//ground
	rectangle(0,660,400,670);		//ground 1
	rectangle(515,660,800,670);		//ground 2
	rectangle(880,660,1366,670);	//ground 3

	//log
	line(200,600,200,660);		//verticle l
	line(200,600,205,595);		//curve l
	line(205,595,255,595);		//horizontal
	line(255,595,260,600);		//curve r
	line(260,600,260,660);		//verticle r
	line(200,660,260,660);		//base
	
	//platform 1
	rectangle(40,515,145,525);
	
	//single block 1
	rectangle(305,500,340,535);	
	
	//pit 1
	line(400,660,400,880);	//left
	line(515,660,515,880);	//right	
	
	//double block 1
	rectangle(405,435,475,470);
	line(440,435,440,470);
	
	//4 blocks
	rectangle(540,370,680,405);
	rectangle(575,370,610,405);
	line(645,370,645,405);
	
	//single block 2
	//rectangle(540,550,575,585);

	//big blocks
		//left
	rectangle(730,625,765,660);
	rectangle(765,590,800,660);
		//right
	rectangle(915,625,950,660);
	rectangle(880,590,915,660);
	//pit 2
	line(800,660,800,880);	//left
	line(880,660,880,880);	//right	
	
	//platform 2
	rectangle(810,520,870,530);
	
		//triple block 1
	rectangle(940,495,1045,530);
	rectangle(975,495,1010,530);
	
  	//pipe
	rectangle(1140,580,1220,660);
	rectangle(1130,560,1230,580);

}
void bg3bug1(int x, int y, int a, int b)
{
		//top bug 1
	line(a-230,b-10,a-220,b-10);		//head top
		//left ear
	line(a-230,b-10,a-230,b-15);
	line(a-230,b-15,a-235,b-15);
	line(a-235,b-15,a-235,b-10);
		//left side
	line(a-235,b-10,a-240,b-10);
	line(a-240,b-10,a-240,b-5);
	line(a-240,b-5,a-245,b-5);
	line(a-245,b-5,a-245,b);
	line(a-245,b,a-240,b);
	line(a-240,b,a-240,b+3);
	
		//right ear
	line(a-220,b-10,a-220,b-15);
	line(a-220,b-15,a-215,b-15);
	line(a-215,b-15,a-215,b-10);
		//right side
	line(a-215,b-10,a-210,b-10);
	line(a-210,b-10,a-210,b-5);
	line(a-210,b-5,a-205,b-5);
	line(a-205,b-5,a-205,b);
	line(a-205,b,a-210,b);
	line(a-210,b,a-210,b+4);

		//base
	line(a-240,b+4,a-210,b+4);
		//leg
	rectangle(a-235,b+4,a-230,b+10);
	rectangle(a-220,b+4,a-215,b+10);
		//eyes
	circle(a-230,b-3,1);
	circle(a-220,b-3,1);

}
void bg3bug2(int x, int y, int a, int b)
{
		//top bug 1
	line(a-230,b-10,a-220,b-10);		//head top
		//left ear
	line(a-230,b-10,a-230,b-15);
	line(a-230,b-15,a-235,b-15);
	line(a-235,b-15,a-235,b-10);
		//left side
	line(a-235,b-10,a-240,b-10);
	line(a-240,b-10,a-240,b-5);
	line(a-240,b-5,a-245,b-5);
	line(a-245,b-5,a-245,b);
	line(a-245,b,a-240,b);
	line(a-240,b,a-240,b+3);
	
		//right ear
	line(a-220,b-10,a-220,b-15);
	line(a-220,b-15,a-215,b-15);
	line(a-215,b-15,a-215,b-10);
		//right side
	line(a-215,b-10,a-210,b-10);
	line(a-210,b-10,a-210,b-5);
	line(a-210,b-5,a-205,b-5);
	line(a-205,b-5,a-205,b);
	line(a-205,b,a-210,b);
	line(a-210,b,a-210,b+4);

		//base
	line(a-240,b+4,a-210,b+4);
		//leg
	rectangle(a-235,b+4,a-230,b+10);
	rectangle(a-220,b+4,a-215,b+10);
		//eyes
	circle(a-230,b-3,1);
	circle(a-220,b-3,1);

}


void draw4(int x, int y, int a, int b)
{
	outtextxy(1200,100,"BACKGROUND4");
	
	//mid cloud
	line(95,120,315,120);
	arc(120,120,70,180,25);
	arc(145,100,69,170,20);
	arc(191,81,40,180,40);
	arc(220,104,30,90,50);
	arc(265,105,36,95,25);
	arc(278,130,15,80,40);


	//small cloud
	line(990,150+60,1101,150+60);
	arc(1000,150+60,70,180,10);
	arc(1022,143+60,69,170,20);
	arc(1055,140+60,0,152,30);
	arc(1090,150+60,1,120,12);
	
	
	//ground and pits
	line(0,660,260,660);//first
	line(0,670,260,670);
	line(260,660,260,766);
	
	line(360,660,560,660);//second
	line(360,670,560,670);
	line(360,660,360,766);
	line(560,660,560,766);
	
	line(660,660,1000,660);//third
	line(660,670,1000,670);
	line(660,660,660,766);
	line(1000,660,1000,766);
	
	line(1175,660, 1368,660);//fourth
	line(1175,670,1368,670);
	line(1175,660,1175,766);
	
	//blocks and planks
//	rectangle(25,540,60,575);//firstthreeblocks
//	rectangle(60,540,95,575);
	rectangle(95,550,130,585);//firstblock

	 rectangle( 175,490,210,525);//secondfiveblocks
	 rectangle (210,490,245,525);
	 rectangle (245,490,280,525);
	 rectangle (280,490,315,525);
	 rectangle (315,490,350,525);
	 
	 rectangle(400,555,435,590);//third two blocks
	 rectangle(435,555,470,590);
	 
	 rectangle(585,620,635,630);//firstplank
	 
//	 rectangle(730,625,765,660);//tower
//	 rectangle(765,590,800,660);
//	 rectangle(800,590,835,660);
//	 rectangle(835,590,870,660);
//	 rectangle(870,625,905,660);

	//blocks triangular
	rectangle(725,615,770,660);
	rectangle(770,570,815,660);
	rectangle(815,525,860,660);
	line(725,615,860,615);
	line(815,570,860,570);
	
	 
	 rectangle(1050,605,1145,615);//secondplank
	 
	 //rectangle(865,465,900,500);//fourthblock
	 rectangle(900,465,935,500);
	 rectangle(935,465,970,500);
	 rectangle(970,465,1005,500);
	 rectangle(1005,465,1040,500);
	
	
	//hospital
	 rectangle(1240,580,1360,660);//groundfloor 
     rectangle(1273,540,1323,580);//upperfloor
	 line(1297,550,1297,570); //plus
	 line(1298,550,1298,570);
	 line(1299,550,1299,570); 
	 line(1288,559,1308,559);
	 line(1288,560,1308,560);
	 line(1288,561,1308,561);
	 
	 rectangle(1280,610,1320,660);//door
//	 rectangle(1250,590,1350,600);//window
//	 line(1260,590,1260,600);
//	 line(1270,590,1270,600);
//	 line(1280,590,1280,600);
//	 line(1290,590,1290,600);
//	 line(1300,590,1300,600);
//	 line(1310,590,1310,600);
//	 line(1320,590,1320,600);
//	 line(1330,590,1330,600);
//	 line(1340,590,1340,600);
	 rectangle(1250,595,1270,645);//dleftwindow
	 line(1260,595,1260,645);
	 line(1250,605,1270,605);
	 line(1250,615,1270,615);
	 line(1250,625,1270,625);
	 line(1250,635,1270,635);
	 
	 rectangle(1330,595,1350,645);//rightwindow
	 line(1340,595,1340,645);
	 line(1330,605,1350,605);
	 line(1330,615,1350,615);
	 line(1330,625,1350,625);
	 line(1330,635,1350,635);
	  
     
     //flogpole
     rectangle(1220,500,1225,660);
     circle(1223,496,4);
     line(1220,505,1190,505);
     line(1190,505,1220,535);
     
     
    
     //bug
//	 line(a+200,b+135,a+210,b+135);		//head top
//	 //left ear
//	 line(a+200,b+135,a+200,b+130);
//	 line(a+200,b+130,a+195,b+130);
//	 line(a+195,b+130,a+195,b+135);
//	  
//	  //left side
//	 line(a+195,b+135,a+190,b+135);
//	 line(a+190,b+135,a+190,b+140);
//	 line(a+190,b+140,a+185,b+140);
//	 line(a+185,b+140,a+185,b+145);
//	 line(a+185,b+145,a+190,b+145);
//	 line(a+190,b+145,a+190,b+150);
	 
	 //right ear
//	 line(a+210,b+135,a+210,b+130);
//	 line(a+210,b+130,a+215,b+130);
//	 line(a+215,b+130,a+215,b+135);
	 
	 
		//right side
//	 line(a+215,b+135,a+220,b+135);
//	 line(a+220,b+135,a+220,b+140);
//	 line(a+220,b+140,a+225,b+140);
//	 line(a+225,b+140,a+225,b+145);
//	 line(a+225,b+145,a+220,b+145);
//	 line(a+220,b+145,a+220,b+150);

//		//base
//	 line(a+190,b+150,a+220,b+150);
		//leg
//	 rectangle(a+195,b+150,a+200,b+155);
//	 rectangle(a+210,b+150,a+215,b+155);
		//eyes
 //	 circle(a+200,b+142,1);
//	 circle(a+210,b+142,1);
	
	
	//bird
		//head
	 line(a,b-300,a+10,b-300);	//top
	 line(a,b-300,a-5,b-285);	//lside
	 line(a-5,b-285,a+5,b-280);
	 line(a+10,b-300,a+15,b-285);//rside
	 line(a+15,b-285,a+5,b-280);
	    
		//left wing
	 line(a-2,b-297,a-15,b-297);
	 line(a-15,b-297,a-5,b-285);
	 line(a-15,b-297,a-25,b-285);
	 line(a-25,b-285,a-5,b-285);
	
		//right wing
	 line(a+12,b-297,a+25,b-297);
	 line(a+25,b-297,a+15,b-285);
	 line(a+25,b-297,a+35,b-285);
 	 line(a+35,b-285,a+15,b-285);
		
		//eyes
	 circle(a+2,b-293,1);	//left
	 circle(a+8,b-293,1);   //right
	 arc(a+5,b-286,190,350,2);
		
		//ears
	//left
	 line(a,b-300,a+3,b-305);
	 line(a+3,b-305,a+4,b-300);
	//right
	 line(a+10,b-300,a+7,b-305);
	 line(a+7,b-305,a+6,b-300); 
}

void drawfire(int p,int q)
{
	circle(p,q,10);
}

void instruction()
{
	
	initwindow(1368,766,"Instruction");
//	readimagefile("menubg.jpg",0,0,1366,780);
	POINT cursorPos;
	

	setcolor(8);
	setfillstyle(SLASH_FILL,8);
	rectangle(300,150,1050,600);
	
	//setfillstyle(SOLID_FILL,BLACK);
	rectangle(320,170,1030,580);
	floodfill(305,155,8);
	//floodfill(305,155,8);
//	floodfill(350,200,8);
	

	settextstyle(10,0,3);  
	outtextxy(340,180,"FOLLOW THE INSTRUCTIONS TO PLAY THE GAME:");
	outtextxy(340,215,"PRESS 'W' TO JUMP, 'A' TO MOVE BACKWARD, 'D' TO");
	outtextxy(340,240,"MOVE FORWARD,'Q' TO JUMP BACKWARD  AND 'E' TO");
	outtextxy(340,265,"JUMP FORWARD.");
	outtextxy(340,550,"Press any key to return to menu.");
		
	getch();
	maingame();
	closegraph();
}

void about()
{
	initwindow(1368,766,"About");
//	readimagefile("menubg.jpg",0,0,1366,780);
	POINT cursorPos;
	

	setcolor(8);
	setfillstyle(SLASH_FILL,8);
	rectangle(300,150,1050,600);
	
	//setfillstyle(SOLID_FILL,BLACK);
	rectangle(320,170,1030,580);
	floodfill(305,155,8);
	//floodfill(305,155,8);
//	floodfill(350,200,8);
	

	settextstyle(10,0,3);  
	outtextxy(340,180,"DEVELOPED BY:");
	outtextxy(340,215,"BIBHISHIKA DAHAL");
	outtextxy(340,240,"GANESH GOTAME");
	outtextxy(340,265,"SHREEJAN HAKUDUWAL");
	outtextxy(340,290,"SWOSTIKA SHRESTHA");
	outtextxy(340,550,"Press any key to return to menu.");
		
	getch();
	maingame();
	closegraph();
}

void playgame1()
{	
	int p,q;
	int f1=0,f2=0;
	initwindow(1366,768,"movement");
	int x=130,y=660,a=300,b=505,i=0;
	int c=a,d=b;
	int m1=a+185,m2=b+130,m3=a+130,m4=b+130;
	int n1=m1,n2=m2,n3=m3,n4=m4;
	int a1=a,b1=b;
	int r=-1;
	int coinx=400,coiny=620;
	int coinx2=600,coiny2=620;
	
	draw1(x,y,a1,b1);
	bg1bug1(a,b);
	bg1bug2(c,d);
	drawcharacter(x,y,a,b);
	bg1food(f1,f2);
	bg1food(f1,f2); coin(coinx,coiny); 
	coin(coinx2,coiny2);
	

	

	while(1)
	{
		
		if(life==0)
		{
			initwindow(1366,768,"GameOVer");
			{
				gameover();
			
			}
	
		}
	while(life!=0)
	{
		top:
		i=0;
		switch(getch())
		{	
			case 'w':	
						
						while(i!=22)
						{
							y-=5;
							cleardevice();
							draw1(x,y,a1,b1);
							drawcharacter(x,y,a,b);
							bg1bug1(a,b);
							bg1bug2(c,d);
							bg1bug2(a,b);  bg1food(f1,f2); coin(coinx,coiny);  coin(coinx2,coiny2);
							i++;
						}
						i=0;
						while(i!=22)
						{
							y+=5;
							cleardevice();
							draw1(x,y,a1,b1);
							drawcharacter(x,y,a,b);
							bg1bug1(a,b);
							bg1bug2(c,d);
							bg1bug2(a,b);  bg1food(f1,f2); coin(coinx,coiny);  coin(coinx2,coiny2);
							i++;
						}
						
						
						break;
		
			case 'e':
						
						while(i!=22)
						{
							y-=5;
							x+=2;
							cleardevice();
							draw1(x,y,a1,b1);
							drawcharacter(x,y,a,b);
							bg1bug1(a,b);
							bg1bug2(c,d);
							bg1bug2(a,b);  bg1food(f1,f2); coin(coinx,coiny);  coin(coinx2,coiny2);
							i++;
							if(x>=1368)
							{
								playgame2();
							}								
						}
						do
						{	
							//yo block ko mathi jane if
							{						
								if(( (x>200 && x<260) && y==595 ))
								{
									goto top;
								}
								else if(( (x>305 && x<375) && y==500 ))
								{
									goto top;
								}
								else if(( (x>430 && x<605) && y==435 ))
								{
									goto top;
								}
								else if(( (x>660 && x<695) && y==390 ))
								{
									goto top;
								}
								else if(( (x>750 && x<785) && y==440 ))
								{
									goto top;
								}
								else if(( (x>840 && x<875) && y==560 ))
								{
									goto top;
								}
								else if(( (x>930 && x<1000) && y==530 ))
								{
									goto top;
								}
								else if(( (x>1090 && x<1190) && y==560 ))
								{
									goto top;
								}
							}
							y+=5;
							x+=1;
							cleardevice();
							draw1(x,y,a1,b1);
							bg1bug1(a,b);
							bg1bug2(c,d);
							drawcharacter(x,y,a,b);
							bg1bug2(a,b);  bg1food(f1,f2); coin(coinx,coiny);  coin(coinx2,coiny2);
							delay(3);
							
							//yo bug sanga thokda ko if
							if( ((x>m1 && x<m1+45) && (y>630 && y<665) ) || ( (x>m2 && x<m2+45) && (y>630 && y<665) ) )
							{
								x=70;
								y=660;
								life--;
								cleardevice();
								draw1(x,y,a1,b1);
								bg1bug1(a,b);
								bg1bug2(c,d);
								drawcharacter(x,y,a,b);
								bg1bug2(a,b);  bg1food(f1,f2); coin(coinx,coiny);  coin(coinx2,coiny2);								
								goto top;
							}
							
							//yo life ma thokda ko if
							if( (x>f1+680 && x<f1+720) && (y<670 && y>620))
							{
								life+=1;
								do
								{
									y+=5;
									x+=1;
									cleardevice();
									draw1(x,y,a1,b1);
									bg1bug1(a,b);
									bg1bug2(c,d);
									drawcharacter(x,y,a,b);
									bg1bug2(a,b);  bg1food(f1,f2); coin(coinx,coiny);  coin(coinx2,coiny2);
									delay(3);
								}while(y<660);
								f1=1360;
								f2=800;
																
								goto top;
							}
							
							//yo if next background ko lagi
							if(x>=1368)
							{
								playgame2();
							}
							//yo first coin ma thokda ko if
							if( ((x>coinx-15 && x<coinx+20) && (y>600 && y<630) ))
							{	
								coinx=1500;
								coiny=1000;
								score=score+100;
								do
								{
									y+=5;
									x+=1;
									cleardevice();
									draw1(x,y,a1,b1);
									bg1bug1(a,b);
									bg1bug2(c,d);
									drawcharacter(x,y,a,b);
									bg1bug2(a,b);  bg1food(f1,f2); coin(coinx,coiny);  coin(coinx2,coiny2);
									delay(3);
								}while(y<660);
								
																
								goto top;
							}
							
							//yo second coin
							if( (x>coinx2-15 && x<coinx2+20) && (y>600 && y<660))
							{	
								coinx2=1500;
								coiny2=1000;
								score=score+100;
								do
								{
									y+=5;
									x+=1;
									cleardevice();
									draw1(x,y,a1,b1);
									bg1bug1(a,b);
									bg1bug2(c,d);
									drawcharacter(x,y,a,b);
									bg1bug2(a,b);  bg1food(f1,f2); coin(coinx,coiny);  coin(coinx2,coiny2);
									delay(3);
								}while(y<660);
								
																
								goto top;
							}							
														
						}while(y<660);
					  	
						break;
						
			case 'q':
						if(x<50)
						{
							cleardevice();
							draw1(x,y,a1,b1);
							bg1bug1(a,b);
							bg1bug2(c,d);
							drawcharacterleft(x,y,a,b);
							bg1bug2(a,b);  bg1food(f1,f2); coin(coinx,coiny);  coin(coinx2,coiny2);
						}
						
							while(i!=22)
							{		
								y-=5;
								x-=2;
								cleardevice();
								draw1(x,y,a1,b1);
								bg1bug1(a,b);
								bg1bug2(c,d);
								drawcharacterleft(x,y,a,b);
								bg1bug2(a,b);  bg1food(f1,f2); coin(coinx,coiny);  coin(coinx2,coiny2);
								i++;
							}
							
							do
							{
								{						
															
									if(( (x>200 && x<260) && y==595 ))
									{
										goto top;
									}
									else if(( (x>305 && x<375) && y==500 ))
									{
										goto top;
									}
									else if(( (x>430 && x<605) && y==435 ))
									{
										goto top;
									}
									else if(( (x>660 && x<695) && y==390 ))
									{
										goto top;
									}
									else if(( (x>750 && x<785) && y==440 ))
									{
										goto top;
									}
									else if(( (x>840 && x<875) && y==560 ))
									{
										goto top;
									}
									else if(( (x>930 && x<1000) && y==530 ))
									{
										goto top;
									}
									else if(( (x>1090 && x<1190) && y==560 ))
									{
										goto top;
									}
							
								}
								y+=5;
								x-=1;
								cleardevice();
								draw1(x,y,a1,b1);
								bg1bug1(a,b);
								bg1bug2(c,d);
								drawcharacterleft(x,y,a,b);
								bg1bug2(a,b);  bg1food(f1,f2); coin(coinx,coiny);  coin(coinx2,coiny2);
								delay(3);
								
								//yo bug sanga thokda ko if
								if( ((x>m1 && x<m1+45) && (y>630 && y<665) ) || ( (x>m2 && x<m2+45) && (y>630 && y<665) ) )
								{
									x=70;
									y=660;	
									life--;							
									cleardevice();
									draw1(x,y,a1,b1);
									bg1bug1(a,b);
									bg1bug2(c,d);
									drawcharacter(x,y,a,b);
									bg1bug2(a,b);  bg1food(f1,f2); coin(coinx,coiny);  coin(coinx2,coiny2);
									goto top;
								}
								
								//yo life ma thokda ko if
								if( (x>f1+680 && x<f1+720) && (y<670 && y>620))
								{
									life+=1;
									do
									{
										y+=5;
										x-=1;
										cleardevice();
										draw1(x,y,a1,b1);
										bg1bug1(a,b);
										bg1bug2(c,d);
										drawcharacter(x,y,a,b);
										bg1bug2(a,b);  bg1food(f1,f2); coin(coinx,coiny);  coin(coinx2,coiny2);									
										delay(3);
									}while(y<660);
									f1=1360;
									f2=800;
																	
									goto top;
								}
								
							
							}while(y<660);
						
						break;
									
			case 'a':	
							//yo block ma thokda ko if
							if( ((x>200 && x<260) && y==660) || ((x>840 && x<875)&&y==660) || ((x>1100 && x<1180) && y==660) )
							{
								goto top;
							}
							else
							{
							
								x=x-10;
								cleardevice();
								draw1(x,y,a1,b1);
								bg1bug1(a,b);
								bg1bug2(c,d);
								drawcharacterleft(x,y,a,b);
								bg1bug2(a,b);  bg1food(f1,f2); coin(coinx,coiny);  coin(coinx2,coiny2);
								
								//yo block bata khasne if
								if((x<180 && y==595) || (x<285 && y==500) ||  (x<410 && y==435) || (x<640 && y==390) || (x<730 && y==440) || (x<820 && y==560) || (x<910 && y==530) || ( (x<1070 && x>1000) && y==560))
							 	{
									do
									{
										y+=5;
										cleardevice();
										draw1(x,y,a1,b1);
										bg1bug1(a,b);
										bg1bug2(c,d);
										drawcharacterleft(x,y,a,b);
										bg1bug2(a,b);  bg1food(f1,f2); coin(coinx,coiny);  coin(coinx2,coiny2);
									}while(y<660);																
								}	
								
								//yo bug sanga thokda ko if
								if( ((x>m1 && x<m1+45) && (y>630 && y<665) ) || ( (x>m2 && x<m2+45) && (y>630 && y<665) ) )
								{
									x=70;
									y=660;	
									life--;							
									cleardevice();
									draw1(x,y,a1,b1);
									bg1bug1(a,b);
									bg1bug2(c,d);
									drawcharacter(x,y,a,b);
									bg1bug2(a,b);  bg1food(f1,f2); coin(coinx,coiny);  coin(coinx2,coiny2);
									goto top;
								}
								
								//yo life ma thokda ko if
								if( (x>f1+680 && x<f1+720) && (y<670 && y>620))
								{
									life+=1;
									cleardevice();
									draw1(x,y,a1,b1);
									bg1bug1(a,b);
									bg1bug2(c,d);
									drawcharacter(x,y,a,b);
									bg1bug2(a,b);  bg1food(f1,f2); coin(coinx,coiny);  coin(coinx2,coiny2);
									f1=1360;
									f2=800;																
									goto top;
								}
																
							}
						break;
				
			case 'd':		
						//yo block ma thokne if
						if( ((x>200 && x<260) && y==660) || ((x>840 && x<875)&&y==660) || ((x>1100 && x<1180) && y==660) )
						{
							goto top;
						}
						else
						{																																				
							x=x+10;
							cleardevice();
							draw1(x,y,a1,b1);
							bg1bug1(a,b);
							bg1bug2(c,d);
							drawcharacter(x,y,a,b);
							bg1bug2(a,b);  bg1food(f1,f2); coin(coinx,coiny);  coin(coinx2,coiny2);
							 
							//yo block bata khasne if 
							if((x>285 && y==595) || (x>400 && y==500) ||  (x>630 && y==435) || (x>720 && y==390) || (x>810 && y==440) || ( (x>900 && x<1090) && y==560) || (x>1025 && y==530) || (x>1215 && y==560))
							{
								do
								{			
									y+=5;
									cleardevice();
									draw1(x,y,a1,b1);
									bg1bug1(a,b);
									bg1bug2(c,d);
									drawcharacter(x,y,a,b);
									bg1bug2(a,b);  bg1food(f1,f2); coin(coinx,coiny);  coin(coinx2,coiny2);
								}while(y<660);
							
							}
							
							//yo bug sanga thokda ko if
							if( ((x>m1 && x<m1+45) && (y>630 && y<665) ) || ( (x>m2 && x<m2+45) && (y>630 && y<665) ) )
								{
									x=70;
									y=660;	
									life--;							
									cleardevice();
									draw1(x,y,a1,b1);
									bg1bug1(a,b);
									bg1bug2(c,d);
									drawcharacter(x,y,a,b);
									bg1bug2(a,b);  bg1food(f1,f2); coin(coinx,coiny);  coin(coinx2,coiny2);
									goto top;
								}
							
							//yo life ma thokda ko if
							if( (x>f1+680 && x<f1+720) && (y<670 && y>620))
							{		
								life+=1;							
								cleardevice();
								draw1(x,y,a1,b1);
								bg1bug1(a,b);
								bg1bug2(c,d);
								drawcharacter(x,y,a,b);
								bg1bug2(a,b);  bg1food(f1,f2); coin(coinx,coiny);  coin(coinx2,coiny2);
								f1=1360;
								f2=800;															
								goto top;
							}
							if(x>=1368)
							{
								playgame2();
							}	
							
							//yo first coin ma thokda ko if
							if ((x>coinx-15 && x<coinx+20) && (y==660 ))
							{	
								coinx=1500;
								coiny=1000;
								score=score+100;
								
									cleardevice();
									draw1(x,y,a1,b1);
									bg1bug1(a,b);
									bg1bug2(c,d);
									drawcharacter(x,y,a,b);
									bg1food(f1,f2); coin(coinx,coiny);  coin(coinx2,coiny2);								
																
								goto top;
							}
							
							//yo second coin
							if( (x>coinx2-15 && x<coinx2+20) && (y=660))
							{	
								coinx2=1500;
								coiny2=1000;
								score=score+100;

									cleardevice();
									draw1(x,y,a1,b1);
									bg1bug1(a,b);
									bg1bug2(c,d);
									drawcharacter(x,y,a,b);
									bg1bug2(a,b);  bg1food(f1,f2); coin(coinx,coiny);  coin(coinx2,coiny2);								
																
								goto top;
							}		
						}
						 break; 
						 
			case '1':	
						p=x+10;
						q=y-30;
						do
						{
							cleardevice();
		 					draw1(x,y,a1,b1);
		 					bg1bug1(a,b);
							bg1bug2(c,d);
							drawcharacter(x,y,a,b);
							bg1bug2(a,b);  bg1food(f1,f2); coin(coinx,coiny);  coin(coinx2,coiny2);
							drawfire(p,q);
		 					p=p+10;	
		 					delay(1);
		 					
		 					//yo first bug marne if
							if( (p>m1 && p<m1+45))
								{	
									int t=0;
									do
									{
										a= a + 5 * r;
										b=b+5*r;
										r= -r;																																
										cleardevice();
										draw1(x,y,a1,b1);
										bg1bug1(a,b);										
										bg1bug2(c,d);
										drawcharacter(x,y,a,b);
										bg1bug2(a,b);  bg1food(f1,f2); coin(coinx,coiny);  coin(coinx2,coiny2);
										delay(10);
										t=t+1;
									}while(t<15);
									a=1400;
									b=50;
									cleardevice();
									draw1(x,y,a1,b1);
									bg1bug2(c,d);
									m1=a+85;
									m3=b+10;
									drawcharacter(x,y,a,b);
									bg1bug2(a,b);  bg1food(f1,f2); coin(coinx,coiny);  coin(coinx2,coiny2);
									
									goto top;
								}
								
							//yo second bug marne		
							if( (p>m2 && p<m2+45) )
								{
									int t=0;
									do
									{
										c= c + 5 * r;
										d=d+5*r;
										r= -r;																																
										cleardevice();
										draw1(x,y,a1,b1);
										bg1bug1(a,b);										
										bg1bug2(c,d);
										drawcharacter(x,y,a,b);
										bg1bug2(a,b);  bg1food(f1,f2); coin(coinx,coiny);  coin(coinx2,coiny2);
										delay(10);
										t=t+1;
									}while(t<15);
									c=1400;
									d=50;																		
									cleardevice();
									draw1(x,y,a1,b1);
									bg1bug1(a,b);
									m2=c+130;
									m4=d+10;										
									drawcharacter(x,y,a,b);
									bg1bug2(a,b);  bg1food(f1,f2); coin(coinx,coiny);  coin(coinx2,coiny2);
									goto top;
								}			 					
		 					
						}while(p<=1366);
						break;
			case '2':	
						p=x+10;
						q=y-30;
						do
						{
							cleardevice();
		 					draw1(x,y,a1,b1);
		 					bg1bug1(a,b);										
							bg1bug2(c,d);
							drawcharacterleft(x,y,a,b);
							bg1bug2(a,b);  bg1food(f1,f2); coin(coinx,coiny);  coin(coinx2,coiny2);
							drawfire(p,q);					
		 					p=p-10;	
		 					delay(1);
		 					
		 				//yo first bug marne if
							if((p>m1 && p<m1+45))
								{	
									int t=0;
									do
									{
										a= a + 5 * r;
										b=b+5*r;
										r= -r;																																
										cleardevice();
										draw1(x,y,a1,b1);
										bg1bug1(a,b);										
										bg1bug2(c,d);
										drawcharacter(x,y,a,b);
										bg1bug2(a,b);  bg1food(f1,f2); coin(coinx,coiny);  coin(coinx2,coiny2);
										delay(10);
										t=t+1;
									}while(t<15);
									a=1200;
									b=50;
									cleardevice();
									draw1(x,y,a1,b1);
									bg1bug2(c,d);
									m1=a+85;
									m3=b+10;
									drawcharacter(x,y,a,b);
									bg1bug2(a,b);  bg1food(f1,f2); coin(coinx,coiny);  coin(coinx2,coiny2);
									goto top;
								}
								
							//yo second bug marne		
							if( (p>m2 && p<m2+45))
								{
									int t=0;
									do
									{
										c= c + 5 * r;
										d=d+5*r;
										r= -r;																																
										cleardevice();
										draw1(x,y,a1,b1);
										bg1bug1(a,b);										
										bg1bug2(c,d);
										drawcharacter(x,y,a,b);
										bg1bug2(a,b);  bg1food(f1,f2); coin(coinx,coiny);  coin(coinx2,coiny2);
										delay(10);
										t=t+1;
									}while(t<15);
									c=1260;
									d=50;																		
									cleardevice();
									draw1(x,y,a1,b1);
									bg1bug1(a,b);
									m2=c+485;
									m4=d+10;										
									drawcharacter(x,y,a,b);
									bg1bug2(a,b);  bg1food(f1,f2); coin(coinx,coiny);  coin(coinx2,coiny2);
									goto top;
								}
						}while(p>0);
						break;
								
			case '-':
						maingame();
						break;	
			//default:
	
		}//Closing of switch
		
	}//closing of while(life!=0)
	}//closing of while(1)
}



void playgame2()
{	
	initwindow(1366,768,"movement");
	int x=40,y=660,a=300,b=505,i=0,p,q;
	int m1=a+85,m2=a+485,m3=b+130, m4=b+130;
	int c=a,d=b;
	int r=-1,t=0;
	int n1=m1,n2=m2,n3=m3,n4=m4;
	int coinx=x,coiny=y;
	int coinx2=x,coiny2=y;
	draw2(x,y,a,b); 
	coin(coinx+250,coiny-180);
	coin(coinx2+820,coiny2-40);  
	
	bg2bug1(x,y,a,b);
	bg2bug2(x,y,a,b);
	drawcharacter(x,y,a,b);
	while(1)
	{	
		top2:
		if(life==0)
		{
			initwindow(1366,768,"GameOVer");
			{
				gameover();
			}
		}
		
		i=0;
		switch(getch())
		{
			case 'w':	
						
						while(i!=22)
						{
							y-=5;
							cleardevice();
							draw2(x,y,a,b); coin(coinx+250,coiny-180); coin(coinx2+820,coiny2-40); 
							drawcharacter(x,y,a,b);
							bg2bug1(x,y,a,b);
							bg2bug2(x,y,c,d);
							i++;
						}
						i=0;
						while(i!=22)
						{
							y+=5;
							cleardevice();
							draw2(x,y,a,b); coin(coinx+250,coiny-180); coin(coinx2+820,coiny2-40); 
							drawcharacter(x,y,a,b);
							bg2bug1(x,y,a,b);
							bg2bug2(x,y,c,d);
							i++;
						}
						
						
						break;
		
			case 'e':
						
						while(i!=22)
						{
							y-=5;
							x+=2;
							cleardevice();
							draw2(x,y,a,b); coin(coinx+250,coiny-180); coin(coinx2+820,coiny2-40); 
							drawcharacter(x,y,a,b);
							bg2bug1(x,y,a,b);
							bg2bug2(x,y,c,d);
							i++;
							if(x>=1368)
							{
								playgame2();
							}	
							
						}
						do
						{	
							//yo block ko mathi jane if
							{						
								if(( (x>80 && x<135) && y==575 ))
								{
									goto top2;
								}
								else if(( (x>185 && x<340) && y==525 ))
								{
									goto top2;
								}
								else if(( (x>390 && x<440) && y==465 ))
								{
									goto top2;
								}
								else if(( (x>490 && x<605) && y==560 ))
								{
									goto top2;
								}
								else if(( (x>655 && x<740) && y==495 ))
								{
									goto top2;
								}
								else if(( (x>790 && x<840) && y==430 ))
								{
									goto top2;
								}
								else if(( (x>890 && x<1010) && y==530 ))
								{
									goto top2;
								}
								else if(( (x>1060 && x<1135) && y==595 ))
								{
									goto top2;
								}
							}
							y+=5;
							x+=1;
							cleardevice();
							draw2(x,y,a,b); coin(coinx+250,coiny-180); coin(coinx2+820,coiny2-40); 
							bg2bug1(x,y,a,b);
							bg2bug2(x,y,c,d);
							drawcharacter(x,y,a,b);
							delay(3);
							
							//yo bug sanga thokda ko if
							if( ((x>m1 && x<m1+45) && (y>m3 && y<665) ) || ( (x>m2 && x<m2+45) && (y>m4 && y<665) ) )
							{
								x=70;
								y=660;
								life--;
								cleardevice();
								draw2(x,y,a,b); coin(coinx+250,coiny-180); coin(coinx2+820,coiny2-40); 
								bg2bug1(x,y,a,b);
								bg2bug2(x,y,c,d);
								drawcharacter(x,y,a,b);
								goto top2;
							}
							
							//yo creavase ma khasne if
							if ((x>880 && x<1015) && (y>650 && y<670) )
							{
								do
								{
									y+=5;
									x+=1;
									cleardevice();
									draw2(x,y,a,b); coin(coinx+250,coiny-180); coin(coinx2+820,coiny2-40); 
									drawcharacter(x,y,a,b);
									bg2bug1(x,y,a,b);
									bg2bug2(x,y,c,d);
									delay(3);
								}while(y<800);
								
								x=70;
								y=660;
																
								cleardevice();
								draw2(x,y,a,b); coin(coinx+250,coiny-180); coin(coinx2+820,coiny2-40); 
								bg2bug1(x,y,a,b);
								bg2bug2(x,y,c,d);
								drawcharacter(x,y,a,b);
								life--;
								goto top2;
							}
							
							//yo first coin ma thokda ko if
							if( ((x>coinx+250-15 && x<coinx+250+40) && (y>480 && y<520) ))
							{	
								coinx=1500;
								coiny=1000;
								score=score+100;
								do
								{
									y+=5;
									x+=1;
									cleardevice();
									draw2(x,y,a,b); coin(coinx+250,coiny-180); coin(coinx2+820,coiny2-40); 
									bg2bug1(x,y,a,b);
									bg2bug2(x,y,c,d);
									drawcharacter(x,y,a,b);
									delay(3);
								}while(y<525);
								
																
								goto top2;
							}
							
							//yo second coin
							if( (x>coinx2+820-15 && x<coinx2+820+20) && (y>620 && y<660))
							{	
								coinx2=1500;
								coiny2=1000;
								score=score+100;
								do
								{
									y+=5;
									x+=1;
									cleardevice();
									draw2(x,y,a,b); 
									coin(coinx+250,coiny-180); 
									coin(coinx2+820,coiny2-40); 
									bg2bug1(x,y,a,b);
									bg2bug2(x,y,c,d);
									drawcharacter(x,y,a,b);
									delay(3);
								}while(y<660);
								
								if(x>=1368)
								{
									playgame3();
								}	
																
								goto top2;
							}
							
							
						}while(y<660);
					  	
						break;
						
			case 'q':
						if(x<50)
						{
							cleardevice();
							draw2(x,y,a,b); coin(coinx+250,coiny-180); coin(coinx2+820,coiny2-40); 
							bg2bug1(x,y,a,b);
							bg2bug2(x,y,c,d);
							drawcharacterleft(x,y,a,b);
						}
						
							while(i!=22)
							{		
								y-=5;
								x-=2;
								cleardevice();
								draw2(x,y,a,b); coin(coinx+250,coiny-180); coin(coinx2+820,coiny2-40); 
								bg2bug1(x,y,a,b);
								bg2bug2(x,y,c,d);
								drawcharacterleft(x,y,a,b);
								i++;
							}
							
							do
							{
								if(( (x>80 && x<135) && y==575 ))
								{
									goto top2;
								}
								else if(( (x>170 && x<325) && y==525 ))
								{
									goto top2;
								}
								else if(( (x>375 && x<425) && y==465 ))
								{
									goto top2;
								}
								else if(( (x>475 && x<590) && y==560 ))
								{
									goto top2;
								}
								else if(( (x>640 && x<725) && y==495 ))
								{
									goto top2;
								}
								else if(( (x>775 && x<825) && y==430 ))
								{
									goto top2;
								}
								else if(( (x>875 && x<995) && y==530 ))
								{
									goto top2;
								}
								else if(( (x>1045 && x<1120) && y==595 ))
								{
									goto top2;
								}
								y+=5;
								x-=1;
								cleardevice();
								draw2(x,y,a,b); coin(coinx+250,coiny-180); coin(coinx2+820,coiny2-40); 
								bg2bug1(x,y,a,b);
								bg2bug2(x,y,c,d);
								drawcharacterleft(x,y,a,b);
								delay(3);
								
								//yo bug sanga thokda ko if
								if( ((x>m1 && x<m1+45) && (y>m3 && y<665) ) || ( (x>m2 && x<m2+45) && (y>m4 && y<665) ) )
								{
									x=70;
									y=660;								
									cleardevice();
									draw2(x,y,a,b); coin(coinx+250,coiny-180); coin(coinx2+820,coiny2-40); 
									bg2bug1(x,y,a,b);
									bg2bug2(x,y,c,d);
									drawcharacter(x,y,a,b);
									life--;
									goto top2;
								}
								
								//creavase ma khasne if
								if ((x>880 && x<1015) && (y>650 && y<670) )
								{
									do
									{
										y+=5;
										x-=1;
										cleardevice();
										draw2(x,y,a,b); coin(coinx+250,coiny-180); coin(coinx2+820,coiny2-40); 
										bg2bug1(x,y,a,b);
										bg2bug2(x,y,c,d);
										drawcharacterleft(x,y,a,b);
										delay(3);
									}while(y<800);
								
									x=70;
									y=660;		
									life--;						
									cleardevice();
									draw2(x,y,a,b); coin(coinx+250,coiny-180); coin(coinx2+820,coiny2-40); 
									bg2bug1(x,y,a,b);
									bg2bug2(x,y,c,d);
									drawcharacter(x,y,a,b);
									goto top2;
								}
								
								//yo coin ma thokda ko if
								if( ((x>coinx+250-35 && x<coinx+250+20) && (y>480 && y<520) ))
								{	
									coinx=1500;
									coiny=1000;
									score=score+100;
									do
									{
										y+=5;
										x-=1;
										cleardevice();
										draw2(x,y,a,b); coin(coinx+250,coiny-180); coin(coinx2+820,coiny2-40); 
										bg2bug1(x,y,a,b);
										bg2bug2(x,y,c,d);
										drawcharacterleft(x,y,a,b);
										delay(3);
									}while(y<525);
									
																	
									goto top2;
								}
							}while(y<660);
						
						break;
									
			case 'a':	
							//yo block ma thokda ko if
							if( ((x>80 && x<130) && y==660) || ((x>500 && x<590)&&y==660) || ((x>1050 && x<1130) && y==660) )
							{
								goto top2;
							}
							else
							{
							
								x=x-10;
								cleardevice();
								draw2(x,y,a,b); coin(coinx+250,coiny-180); coin(coinx2+820,coiny2-40); 
								bg2bug1(x,y,a,b);
								bg2bug2(x,y,c,d);
								drawcharacterleft(x,y,a,b);
								
								//yo block bata khasne if
								if((x<55 && y==575) || (x<165 && y==525) ||  (x<360 && y==465) || (x<470 && y==560) || (x<630 && y==495) || (x<770 && y==430) || (x<870 && y==530) || (x<1040 && y==595))
							 	{
									do
									{
										y+=5;
										cleardevice();
										draw2(x,y,a,b); coin(coinx+250,coiny-180); coin(coinx2+820,coiny2-40); 
										bg2bug1(x,y,a,b);
										bg2bug2(x,y,c,d);
										drawcharacterleft(x,y,a,b);
									}while(y<660);																
								}	
								
								//yo bug sanga thokda ko if
								if( ((x>m1 && x<m1+45) && (y>m3 && y<665) ) || ( (x>m2 && x<m2+45) && (y>m4 && y<665) ) )
								{
									x=70;
									y=660;	
									life--;							
									cleardevice();
									draw2(x,y,a,b); coin(coinx+250,coiny-180); coin(coinx2+820,coiny2-40); 
									bg2bug1(x,y,a,b);
									bg2bug2(x,y,c,d);
									drawcharacter(x,y,a,b);
									goto top2;
								}
								
								//yo creavase ma khasne if
								if ((x>880 && x<1000) && (y>650 && y<670) )
								{
									do
									{
										y+=5;
										x-=1;
										cleardevice();
										draw2(x,y,a,b); coin(coinx+250,coiny-180); coin(coinx2+820,coiny2-40); 
										bg2bug1(x,y,a,b);
										bg2bug2(x,y,c,d);
										drawcharacterleft(x,y,a,b);
										delay(3);
									}while(y<800);
								
									x=70;
									y=660;		
									life--;						
									cleardevice();
									draw2(x,y,a,b); coin(coinx+250,coiny-180); coin(coinx2+820,coiny2-40); 
									bg2bug1(x,y,a,b);
									bg2bug2(x,y,c,d);
									drawcharacter(x,y,a,b);
									goto top2;
								}
							}
						break;
				
			case 'd':		
						//yo block ma thokne if
						if(((x<600 && x>490) && y==660) || ((x>80 && x<120) && y==660) || ((x>1050 && x<1120) && y==660) )
						{
							goto top2;
						}
						else
						{																																				
							x=x+10;
							cleardevice();
							draw2(x,y,a,b); coin(coinx+250,coiny-180); coin(coinx2+820,coiny2-40); 
							bg2bug1(x,y,a,b);
							bg2bug2(x,y,c,d);
							drawcharacter(x,y,a,b);
							 
							//yo block bata khasne if 
							if((x>160 && y==575) || (x>355 && y==525) ||  (x>455 && y==465) || (x>620 && y==560) || (x>755 && y==495) || (x>855 && y==430) || (x>1025 && y==530) || (x>1150 && y==595))
							{
								do
								{			
									y+=5;
									cleardevice();
									draw2(x,y,a,b); coin(coinx+250,coiny-180); coin(coinx2+820,coiny2-40); 
									bg2bug1(x,y,a,b);
									bg2bug2(x,y,c,d);
									drawcharacter(x,y,a,b);
								}while(y<660);
							
							}
							
							//yo bug sanga thokda ko if
							if( ((x>m1 && x<m1+45) && (y>m3 && y<665) ) || ( (x>m2 && x<m2+45) && (y>m4 && y<665) ) )
								{
									x=70;
									y=660;		
									life--;						
									cleardevice();
									draw2(x,y,a,b); 
									coin(coinx+250,coiny-180); coin(coinx2+820,coiny2-40); 
									bg2bug1(x,y,a,b);
									bg2bug2(x,y,c,d);
									drawcharacter(x,y,a,b);
									goto top2;
								}
								
							//yo creavase ma khasne if
							if ((x>895 && x<1015) && (y>650 && y<670) )
								{
									do
									{
										y+=5;
										x+=1;
										cleardevice();
										draw2(x,y,a,b); coin(coinx+250,coiny-180); coin(coinx2+820,coiny2-40); 
										bg2bug1(x,y,a,b);
										bg2bug2(x,y,c,d);
										drawcharacter(x,y,a,b);
										delay(3);
									}while(y<800);
								
									x=70;
									y=660;	
									life--;							
									cleardevice();
									draw2(x,y,a,b); coin(coinx+250,coiny-180); coin(coinx2+820,coiny2-40); 
									bg2bug1(x,y,a,b);
									bg2bug2(x,y,c,d);
									drawcharacter(x,y,a,b);
									goto top2;
								}
							//first coin khane
							if( ((x>coinx+250-15 && x<coinx+250+20) && (y==525) ))
							{
								coinx=coinx+1500;
								coiny=coiny+500;
								score=score+100;
								cleardevice();
								draw2(x,y,a,b);
								coin(coinx+250,coiny-180); 
								coin(coinx2+820,coiny2-40); 
								bg2bug1(x,y,a,b);
								bg2bug2(x,y,c,d);
								drawcharacter(x,y,a,b);
							}	
							
							//second coin khane							
							if((x>coinx2+820-15 && x<coinx2+820+20) && (y==660))
							{
								coinx2=coinx2+1500;
								coiny2=coiny2+500;
								score=score+100;
								cleardevice();
								draw2(x,y,a,b);
								coin(coinx+250,coiny-180); 
								coin(coinx2+820,coiny2-40); 
								bg2bug1(x,y,a,b);
								bg2bug2(x,y,c,d);
								drawcharacter(x,y,a,b);
							}	
							
							if(x>=1368)
							{
								playgame3();
							}	
						}
						 break; 
			case '1':	
						p=x+10;
						q=y-30;
						do
						{
							cleardevice();
		 					draw2(x,y,a,b); coin(coinx+250,coiny-180); coin(coinx2+820,coiny2-40); 
		 					bg2bug1(x,y,a,b);
							bg2bug2(x,y,c,d);
							drawcharacter(x,y,a,b);
							drawfire(p,q);
		 					p=p+10;	
		 					delay(1);
		 					
		 					//yo first bug marne if
							if( (p>m1 && p<m1+45))
								{	
									do
									{
										a= a + 5 * r;
										b=b+5*r;
										r= -r;																																
										cleardevice();
										draw2(x,y,a,b); coin(coinx+250,coiny-180); coin(coinx2+820,coiny2-40); 
										bg2bug1(x,y,a,b);										
										bg2bug2(x,y,c,d);
										drawcharacter(x,y,a,b);
										delay(10);
										t=t+1;
									}while(t<15);
									a=1400;
									b=50;
									cleardevice();
									draw2(x,y,a,b); coin(coinx+250,coiny-180); coin(coinx2+820,coiny2-40); 
									bg2bug2(x,y,c,d);
									m1=a+85;
									m3=b+485;
									drawcharacter(x,y,a,b);
									
									goto top2;
								}
								
							//yo second bug marne		
							if( (p>m2 && p<m2+45) )
								{
									do
									{
										c= c + 5 * r;
										d=d+5*r;
										r= -r;																																
										cleardevice();
										draw2(x,y,a,b); coin(coinx+250,coiny-180); coin(coinx2+820,coiny2-40); 
										bg2bug1(x,y,a,b);										
										bg2bug2(x,y,c,d);
										drawcharacter(x,y,a,b);
										delay(10);
										t=t+1;
									}while(t<15);
									c=1400;
									d=50;																		
									cleardevice();
									draw2(x,y,a,b); coin(coinx+250,coiny-180); coin(coinx2+820,coiny2-40); 
									bg2bug1(x,y,a,b);
									m2=c+130;
									m4=d+130;										
									drawcharacter(x,y,a,b);
									goto top2;
								}			 					
		 					
						}while(p<=1366);
						break;
			case '2':	
						p=x+10;
						q=y-30;
						do
						{
							cleardevice();
		 					draw2(x,y,a,b); coin(coinx+250,coiny-180); coin(coinx2+820,coiny2-40); 
		 					bg2bug1(x,y,a,b);										
							bg2bug2(x,y,c,d);
							drawcharacterleft(x,y,a,b);
							drawfire(p,q);					
		 					p=p-10;	
		 					delay(1);
		 					
		 				//yo first bug marne if
							if((p>m1 && p<m1+45))
								{	
									do
									{
										a= a + 5 * r;
										b=b+5*r;
										r= -r;																																
										cleardevice();
										draw2(x,y,a,b); coin(coinx+250,coiny-180); coin(coinx2+820,coiny2-40); 
										bg2bug1(x,y,a,b);										
										bg2bug2(x,y,c,d);
										drawcharacterleft(x,y,a,b);
										delay(10);
										t=t+1;
									}while(t<15);
									a=1400;
									b=50;
									cleardevice();
									draw2(x,y,a,b); coin(coinx+250,coiny-180); coin(coinx2+820,coiny2-40); 
									bg2bug2(x,y,c,d);
									m1=a+85;
									m2=a+485;
									m3=b+130;
									m4=b+130;
									drawcharacterleft(x,y,a,b);
									goto top2;
								}
								
							//yo second bug marne		
							if( (p>m2 && p<m2+45))
								{
									do
									{
										c= c + 5 * r;
										d=d+5*r;
										r= -r;																																
										cleardevice();
										draw2(x,y,a,b); coin(coinx+250,coiny-180); coin(coinx2+820,coiny2-40); 
										bg2bug1(x,y,a,b);										
										bg2bug2(x,y,c,d);
										drawcharacter(x,y,a,b);
										delay(10);
										t=t+1;
									}while(t<15);
									c=1460;
									d=50;																		
									cleardevice();
									draw2(x,y,a,b); coin(coinx+250,coiny-180); coin(coinx2+820,coiny2-40); 
									bg2bug1(x,y,a,b);
									m1=a+85;
									m2=a+485;
									m3=b+130;
									m4=b+130;										
									drawcharacter(x,y,a,b);
									goto top2;
								}
						}while(p>0);
						break;		
				
				case '-':
						exit(0);
						break;	
			//default:		
	}
		
	}
}

void playgame3()
{
	int p,q;
	initwindow(1366,768,"movement");
	int x=30,y=515,a=300,b=505,i=0;
	int c=a,d=b;
	int a1=a,b1=b;
	int r=-1,t=0;
	int coinx3=x,coiny3=620;
	int coinx4=x,coiny4=620;
	draw3(x,y,a1,b1);
	coin(coinx3+330,coiny3);
	coin(coinx4+620,coiny4-290);
	drawcharacter(x,y,a,b);
	bg3bug1(x,y,a,b);
	bg1bug2(a,b);
	
	

	while(1)
	{	
		if(life==0)
		{
			initwindow(1366,768,"GameOVer");
			{
				gameover();
			
			}
	
		}
		while(life!=0)
		{
			top3:
			i=0;
			switch(getch())
			{	
				case 'w':	
						
						while(i!=22)
						{
							y-=5;
							cleardevice();
							draw3(x,y,a1,b1);
							coin(coinx3+330,coiny3);
							coin(coinx4+620,coiny4-290);
							drawcharacter(x,y,a,b); 
							bg3bug1(x,y,a,b);
							bg1bug2(a,b);
							i++;
						}
						i=0;
						while(i!=22)
						{
							y+=5;
							cleardevice();
							draw3(x,y,a1,b1);
							coin(coinx3+330,coiny3);
							coin(coinx4+620,coiny4-290);
							drawcharacter(x,y,a,b); 
							bg3bug1(x,y,a,b);
							bg1bug2(a,b);
							i++;
						}
						
						
						break;
		
				case 'e':
						
						while(i!=22)
						{
							y-=5;
							x+=2;
							cleardevice();
							draw3(x,y,a1,b1);
							coin(coinx3+330,coiny3);
							coin(coinx4+620,coiny4-290);
							drawcharacter(x,y,a,b); 
							bg3bug1(x,y,a,b);
							bg1bug2(a,b);
							i++;
							if(x>=1368)
							{
								playgame4();
							}								
						}
						do 
						{
							//block mathi jane block
							{
								if(((x>15) && (x<170)) && y==515)
									goto top3;
								else if((x>175 && x<285) && y==595)
									goto top3;
								else if((x>280 && x<365) && y==500)
									goto top3;
								else if((x>380 && x<500) && y==435)
									goto top3;
								else if((x>515 && x<705) && y==370)
									goto top3;
								else if((x>705 && x<765) && y==625)
									goto top3;
								else if((x>740 && x<615) && y==590)
									goto top3;
								else if((x>785 && x<895) && y==520)
									goto top3;
								else if((x>855 && x<615) && y==590)
					    			goto top3;
					    		else if((x>915 && x<975) && y==625)
					    			goto top3;
					    		else if((x>915 && x<1070) && y==495)
					    			goto top3;
					    		else if((x>1105 && x<1255) && y==560)
					    			goto top3;
					    	}
							y+=5;
							x+=1;
							cleardevice();
							draw3(x,y,a1,b1);
							coin(coinx3+330,coiny3);
							coin(coinx4+620,coiny4-290);
							drawcharacter(x,y,a,b); 
							bg3bug1(x,y,a,b);
							bg1bug2(a,b);
							delay(3);
							
							//creavase bata khasne
							if(((x>420 && x<515) && (y>650 && y<670)) || ((x>820 && x<880) && (y>650 && y<670)))
							{
								do
								{
									y+=5;
									x+=1;
									cleardevice();
									draw3(x,y,a1,b1);
									coin(coinx3+330,coiny3);
									coin(coinx4+620,coiny4-290);
									drawcharacter(x,y,a,b); 
									bg3bug1(x,y,a,b);
									bg1bug2(a,b);
									delay(3);
								}while(y<800);
								
								x=70;
								y=660; life--;								
								cleardevice();
								draw3(x,y,a1,b1);
								coin(coinx3+330,coiny3);
								coin(coinx4+620,coiny4-290);
								drawcharacter(x,y,a,b); 
								bg3bug1(x,y,a,b);
								bg1bug2(a,b);
								goto top3;
							}	
							
							//yo bug sanga thokda ko if
							if( ((x>50 && x<80) && (y<520 && y>480)) || ((x>640 && x<670) && (y<670 && y>640))  )
								{
									x=30;
									y=515;		
									life--;						
									cleardevice();
									draw3(x,y,a,b); 
									draw3(x,y,a1,b1);
									coin(coinx3+330,coiny3);
									coin(coinx4+620,coiny4-290);
									bg3bug1(x,y,a,b);
									bg1bug2(a,b);
									drawcharacter(x,y,a,b);
									goto top3;
								}
							
							//yo first coin ma thokda ko if
							if( ((x>coinx3+330-15 && x<coinx3+330+40) && (y>620 && y<660) ))
							{	
								coinx3=1500;
								coiny3=1000;
								score=score+100;
								do
								{
									y+=5;
									x+=1;
									cleardevice();
									draw3(x,y,a1,b1);
									coin(coinx3+330,coiny3);
									coin(coinx4+620,coiny4-290);
									bg3bug1(x,y,a,b);
									bg1bug2(a,b);
									drawcharacter(x,y,a,b);
									delay(3);
								}while(y<660);
								
																
								goto top3;
							}
							
							//yo second coin
							if( (x>coinx4+620-15 && x<coinx4+620+20) && (y>330 && y<370))
							{	
								coinx4=1500;
								coiny4=1000;
								score=score+100;
								do
								{
									y+=5;
									x+=1;
									cleardevice();
									draw3(x,y,a1,b1); 
									coin(coinx3+330,coiny3);
									coin(coinx4+620,coiny4-290); 
									bg3bug1(x,y,a,b);
									bg1bug2(a,b);
									drawcharacter(x,y,a,b);
									delay(3);
								}while(y<370);
								
																
								goto top3;
							}
						}while(y<660);
						break;
						
				case 'q':
				
						if(x<50)
						{
							cleardevice();
							draw3(x,y,a1,b1);
							coin(coinx3+330,coiny3);
							coin(coinx4+620,coiny4-290);
							drawcharacterleft(x,y,a,b); 
							bg3bug1(x,y,a,b);
							bg1bug2(a,b);
						}
						
						while(i!=22)
							{		
								y-=5;
								x-=2;
								cleardevice();
								draw3(x,y,a1,b1);
								coin(coinx3+330,coiny3);
								coin(coinx4+620,coiny4-290);
								drawcharacterleft(x,y,a,b); 
								bg3bug1(x,y,a,b);
								bg1bug2(a,b);
								i++;
							}
						do 
						{
							//block mathi jane if
							{
								if(((x>15) && (x<170)) && y==515)
									goto top3;
								else if((x>175 && x<285) && y==595)
									goto top3;
								else if((x>280 && x<365) && y==500)
									goto top3;
								else if((x>380 && x<500) && y==435)
									goto top3;
								else if((x>515 && x<705) && y==370)
									goto top3;
								else if((x>705 && x<765) && y==625)
									goto top3;
								else if((x>740 && x<615) && y==590)
									goto top3;
								else if((x>785 && x<895) && y==520)
									goto top3;
								else if((x>855 && x<615) && y==590)
					    			goto top3;
					    		else if((x>915 && x<975) && y==625)
					    			goto top3;
					    		else if((x>915 && x<1070) && y==495)
					    			goto top3;
					    		else if((x>1105 && x<1255) && y==560)
					    			goto top3;
					    	}
							y+=5;
							x-=1;
							cleardevice();
							draw3(x,y,a1,b1);
							coin(coinx3+330,coiny3);
							coin(coinx4+620,coiny4-290);
							drawcharacterleft(x,y,a,b); 
							bg3bug1(x,y,a,b);
							bg1bug2(a,b);
							delay(3);
							
							//creavase bata khasne
							if(((x>400 && x<515) && (y>650 && y<670)) || ((x>800 && x<880) && (y>650 && y<670)))
							{
								do
								{
									y+=5;
									x-=1; 
									cleardevice();
									draw3(x,y,a1,b1);
									coin(coinx3+330,coiny3);
									coin(coinx4+620,coiny4-290);
									drawcharacterleft(x,y,a,b); 
									bg3bug1(x,y,a,b);
									bg1bug2(a,b);
									delay(3);
								}while(y<800);
								
								x=70;
								y=660;	life--;							
								cleardevice();
								draw3(x,y,a1,b1);
								coin(coinx3+330,coiny3);
								coin(coinx4+620,coiny4-290);
								drawcharacterleft(x,y,a,b); 
								bg3bug1(x,y,a,b);
								bg1bug2(a,b);
								goto top3;
							}
						}while(y<660);
						
						//yo bug sanga thokda ko if
							if( ((x>50 && x<80) && (y<520 && y>480)) || ((x>640 && x<670) && (y<670 && y>640))  )
								{
									x=30;
									y=515;		
									life--;						
									cleardevice();
									draw3(x,y,a,b); 
									draw3(x,y,a1,b1);
									coin(coinx3+330,coiny3);
									coin(coinx4+620,coiny4-290);
									bg3bug1(x,y,a,b);
									bg1bug2(a,b);
									drawcharacter(x,y,a,b);
									goto top3;
								}
							
						
						 
						break;
						
				case 'a':
							//block ma thokkine if
						if(((x>200 && x<260) && y==660) || ((x>730 && x<765) && y==660) || ((x>765 && x<800) && y==625) || ((x>880 && x<915) && y==625) || ((x>915 && x<950) && y==660) || ((x>1130 && x<1230) && y==660))
						{
							goto top3;
						}
						else
						{
							x=x-10;
							cleardevice();
							draw3(x,y,a1,b1);
							coin(coinx3+330,coiny3);
							coin(coinx4+620,coiny4-290);
							drawcharacterleft(x,y,a,b); 
							bg3bug1(x,y,a,b);
							bg1bug2(a,b);
								
							//block bata khasne if
							if((x<15 && y==515) || (x<175 && y==595) || (x<280 && y==500) || (x<380 && y==435) || (x<515 && y==370) || (x<705 && y==625) || (x<740 && y==590) || (x<785 && y==520) || (x<915 && y==495) || (x<1105 && y==560))
							{
								do
								{
									y+=5;
									cleardevice();
									draw3(x,y,a1,b1);
									coin(coinx3+330,coiny3);
									coin(coinx4+620,coiny4-290);
									drawcharacterleft(x,y,a,b); 
									bg3bug1(x,y,a,b);
									bg1bug2(a,b);
								}while(y<660);
							}
							
							//yo bug sanga thokda ko if
							if( ((x>50 && x<80) && (y<520 && y>480)) || ((x>640 && x<670) && (y<670 && y>640))  )
								{
									x=30;
									y=515;		
									life--;						
									cleardevice();
									draw3(x,y,a,b); 
									draw3(x,y,a1,b1);
									coin(coinx3+330,coiny3);
									coin(coinx4+620,coiny4-290);
									bg3bug1(x,y,a,b);
									bg1bug2(a,b);
									drawcharacter(x,y,a,b);
									goto top3;
								}
							
							
							//creavase bata khasne
							if(((x>400 && x<515) && (y>650 && y<670)) || ((x>800 && x<880) && (y>650 && y<670)))
							{
								do
								{
									y+=5;
									x-=1; 
									cleardevice();
									draw3(x,y,a1,b1);
									coin(coinx3+330,coiny3);
									coin(coinx4+620,coiny4-290);
									drawcharacterleft(x,y,a,b); 
									bg3bug1(x,y,a,b);
									bg1bug2(a,b);
									delay(3);
								}while(y<800);
								
								x=70;
								y=660;	 life--;							
								cleardevice();
								draw3(x,y,a1,b1);
								coin(coinx3+330,coiny3);
								coin(coinx4+620,coiny4-290);
								drawcharacterleft(x,y,a,b); 
								bg3bug1(x,y,a,b);
								bg1bug2(a,b);
								goto top3;
							} 
						}
							
						break;
			
		    	case 'd':
		    				//block ma thokkine if
							if(((x>200 && x<260) && y==660) || ((x>730 && x<765) && y==660) || ((x>765 && x<800) && y==625) || ((x>880 && x<915) && y==625) || ((x>915 && x<950) && y==660) || ((x>1130 && x<1230) && y==660))
							{
								goto top3;
							}
							else
							{
							x=x+10;
							cleardevice();
							draw3(x,y,a1,b1);
							coin(coinx3+330,coiny3);
							coin(coinx4+620,coiny4-290);
							drawcharacter(x,y,a,b); 
							bg3bug1(x,y,a,b);
							bg1bug2(a,b);	
						
							//block bata khasne if
							if(((x>170 && y==515) || (x>285 && y==595) || (x>365 && y==500) || (x>500 && y==470) ||(x>705 && y==370) || (x>895 && y==520)|| (x>940 && y==590) || (x>975 && y==625) || (x>1070 && y==495) || (x>1255 && y==560)))
							{
								do
								{			
									y+=5;
									cleardevice();
									draw3(x,y,a1,b1);
									coin(coinx3+330,coiny3);
									coin(coinx4+620,coiny4-290);
									drawcharacter(x,y,a,b); 
									bg3bug1(x,y,a,b);
									bg1bug2(a,b);
								}while(y<660);
							}
							
							//creavase bata khasne
							if(((x>400 && x<515) && (y>650 && y<670)) || ((x>800 && x<880) && (y>650 && y<670)))
							{
								do
								{
									y+=5;
									x+=1;
									cleardevice();
									draw3(x,y,a1,b1);
									coin(coinx3+330,coiny3);
									coin(coinx4+620,coiny4-290);
									drawcharacter(x,y,a,b); 
									bg3bug1(x,y,a,b);
									bg1bug2(a,b);
									delay(3);
								}while(y<800);
								
								x=70;
								y=660;	life--;							
								cleardevice();
								draw3(x,y,a1,b1);
								coin(coinx3+330,coiny3);
								coin(coinx4+620,coiny4-290);
								drawcharacter(x,y,a,b); 
								bg3bug1(x,y,a,b);
								bg1bug2(a,b);
								goto top3;
							} 
							
							//yo bug sanga thokda ko if
							if( ((x>50 && x<80) && (y<520 && y>480)) || ((x>640 && x<670) && (y<670 && y>640))  )
								{
									x=30;
									y=515;		
									life--;						
									cleardevice();
									draw3(x,y,a,b); 
									draw3(x,y,a1,b1);
									coin(coinx3+330,coiny3);
									coin(coinx4+620,coiny4-290);
									bg3bug1(x,y,a,b);
									bg1bug2(a,b);
									drawcharacter(x,y,a,b);
									goto top3;
								}
							
							//first coin khane
							if( ((x>coinx3+330-15 && x<coinx3+330+20) && (y==660) ))
							{
								coinx3=coinx3+1500;
								coiny3=coiny3+500;
								score=score+100;
								
								cleardevice();
								draw3(x,y,a1,b1);
								coin(coinx3+330,coiny3); 
								coin(coinx4+620,coiny4-290); 
								bg3bug1(x,y,a,b);
								bg1bug2(a,b);
								drawcharacter(x,y,a,b);
							}	
							
							//second coin khane							
							if((x>coinx4+620-15 && x<coinx4+620+20) && (y==370))
							{
								coinx4=coinx4+1500;
								coiny4=coiny4+500;
								score=score+100;
								
								cleardevice();
								draw3(x,y,a1,b1);
								coin(coinx3+330,coiny3); 
								coin(coinx4+620,coiny4-290); 
								bg3bug1(x,y,a,b);
								bg1bug2(a,b);
								drawcharacter(x,y,a,b);
							}	
							
							if(x>=1368)
							{
								playgame4();
							}
						}
						break;
				case '1':	
						p=x+10;
						q=y-30;
						do
						{
							draw3(x,y,a1,b1);
							coin(coinx3+330,coiny3); 
							coin(coinx4+620,coiny4-290); 
							bg3bug1(x,y,a,b);								
							bg3bug1(x,y,a,b);
							drawcharacter(x,y,a,b);
							drawfire(p,q);
		 					p=p+10;	
		 					delay(1);
		 					
		 					//yo first bug marne if
							if( (p>60 && p<60+45))
								{	
									do
									{
										a= a + 5 * r;
										b=b+5*r;
										r= -r;																																
										cleardevice();
										draw3(x,y,a,b);
										coin(coinx3+330,coiny3); 
										coin(coinx4+620,coiny4-290); 
										bg3bug1(x,y,a,b);
										bg1bug2(a,b); drawcharacter(x,y,a,b);
										delay(10);
										t=t+1;
									}while(t<15);
									a=1400;
									b=50;
									cleardevice();
										draw3(x,y,a,b);
										coin(coinx3+330,coiny3); 
										coin(coinx4+620,coiny4-290); 
										bg3bug1(x,y,a,b);
										bg1bug2(a,b); drawcharacter(x,y,a,b);
									
									goto top3;
								}
								
							//yo second bug marne		
							if( (p>400 && p<400+45) )
								{
									do
									{
										c= c + 5 * r;
										d=d+5*r;
										r= -r;																																
										cleardevice();
										draw3(x,y,a,b);
										coin(coinx3+330,coiny3); 
										coin(coinx4+620,coiny4-290); 
										bg3bug1(x,y,a,b);
										bg1bug2(a,b); drawcharacter(x,y,a,b);
										delay(10);
										t=t+1;
									}while(t<15);
									c=1400;
									d=50;																		
									cleardevice();
										draw3(x,y,a,b);
										coin(coinx3+330,coiny3); 
										coin(coinx4+620,coiny4-290); 
										bg3bug1(x,y,a,b);
										bg1bug2(a,b); drawcharacter(x,y,a,b);
									goto top3;
								}			 					
		 					
						}while(p<=1366);
						break;
			case '2':	
						p=x+10;
						q=y-30;
						do
						{
							cleardevice();
							draw3(x,y,a,b);
							coin(coinx3+330,coiny3); 
							coin(coinx4+620,coiny4-290); 
							bg3bug1(x,y,a,b);
							bg1bug2(a,b); 
							drawcharacterleft(x,y,a,b);
							drawfire(p,q);					
		 					p=p-10;	
		 					delay(1);
		 					
		 				//yo first bug marne if
							if( (p>60 && p<60+45))
								{	
									do
									{
										a= a + 5 * r;
										b=b+5*r;
										r= -r;																																
										cleardevice();
										draw3(x,y,a,b);
										coin(coinx3+330,coiny3); 
										coin(coinx4+620,coiny4-290); 
										bg3bug1(x,y,a,b);
										bg1bug2(a,b); 
										drawcharacterleft(x,y,a,b);
										delay(10);
										t=t+1;
									}while(t<15);
									a=1400;
									b=50;
									cleardevice();
									draw3(x,y,a,b);
									coin(coinx3+330,coiny3); 
									coin(coinx4+620,coiny4-290); 
									bg3bug1(x,y,a,b);
									bg1bug2(a,b); 
									drawcharacterleft(x,y,a,b);
									drawcharacterleft(x,y,a,b);
									goto top3;
								}
								
							//yo second bug marne		
							if( (p>400 && p<400+45) )
								{
									do
									{
										c= c + 5 * r;
										d=d+5*r;
										r= -r;																																
										cleardevice();
										draw3(x,y,a,b);
										coin(coinx3+330,coiny3); 
										coin(coinx4+620,coiny4-290); 
										bg3bug1(x,y,a,b);
										bg1bug2(a,b); 
										drawcharacterleft(x,y,a,b);
										delay(10);
										t=t+1;
									}while(t<15);
									c=1460;
									d=50;																		
									cleardevice();
									draw3(x,y,a,b);
									coin(coinx3+330,coiny3); 
									coin(coinx4+620,coiny4-290); 
									bg3bug1(x,y,a,b);
									bg1bug2(a,b); 
									drawcharacterleft(x,y,a,b);									
									//bg3bug1(x,y,a,b);
									goto top3;
								}
							}while(p>0);
			case '-':
				exit(0);
						break;		  			
			}
		}
	}
}


void playgame4()
{
	int p,q;
	initwindow(1366,768,"movement");
	int x=40,y=660,a=300,b=505,i=0;
	int c=a,d=b;
	int m1=a+185,m2=b+130,m3=a+130,m4=b+130;
	int n1=m1,n2=m2,n3=m3,n4=m4;
	int a1=a,b1=b;
	int r=-1;
	draw4(x,y,a1,b1);
	drawcharacter(x,y,a,b);
	

	while(1)
	{	
		if(life==0)
		{
			initwindow(1366,768,"GameOVer");
			{
				outtextxy(100,100,"GAMEOVER");
				delay(1000);
				exit(0);
			}
	
		}
		while(life!=0)
		{
			top4:
			i=0;
			switch(getch())
			{	
				case 'w':	
						
						while(i!=22)
						{
							y-=5;
							cleardevice();
							draw4(x,y,a1,b1);
							drawcharacter(x,y,a,b);
							i++;
						}
						i=0;
						while(i!=22)
						{
							y+=5;
							cleardevice();
							draw4(x,y,a1,b1);
							drawcharacter(x,y,a,b);
							i++;
						}
						
						
						break;
		
				case 'e':
						
						while(i!=22)
						{
							y-=5;
							x+=2;
							cleardevice();
							draw4(x,y,a1,b1);
							drawcharacter(x,y,a,b);
							i++;
						//	if(x>=1368)
						//	{
						//		playgame4();
						//	}								
						}
						do 
						{
								//block mathi jane block
							{
								if(((x>95) && (x<130)) && y==550)
									goto top4;
								else if((x>175 && x<350) && y==490)
									goto top4;
								else if((x>400 && x<470) && y==555)
									goto top4;
								else if((x>585 && x<635) && y==620)
									goto top4;
								else if((x>725 && x<770) && y==615)
									goto top4;
								else if((x>770 && x<815) && y==570)
									goto top4;
								else if((x>815 && x<860) && y==525)
									goto top4;
								else if((x>1050 && x<1145) && y==605)
									goto top4;
								else if((x>900 && x<1040) && y==465)
					    			goto top4;
					    	}
							y+=5;
							x+=1;
							cleardevice();
							draw4(x,y,a1,b1);
							drawcharacter(x,y,a,b);
							delay(3);
							
							//creavase bata khasne
							if(((x>285 && x<335) && (y>650 && y<670)) || ((x>585 && x<635) && (y>650 && y<670)) || ((x>1025 && x<1150) && (y>650 && y<670)))
							{
								do
								{
									y+=5;
									x+=1;
									cleardevice();
									draw4(x,y,a,b);
									drawcharacter(x,y,a,b);
									delay(3);
								}while(y<800);
								
								x=70;
								y=660;	life--;							
								cleardevice();
								draw4(x,y,a,b);
								drawcharacter(x,y,a,b);
								goto top4;
							}	
						}while(y<660);
						break;
						
				case 'q':
				
						if(x<50)
						{
							cleardevice();
							draw4(x,y,a1,b1);
							drawcharacterleft(x,y,a,b);
						}
						
						while(i!=22)
							{		
								y-=5;
								x-=2;
								cleardevice();
								draw4(x,y,a1,b1);
								drawcharacterleft(x,y,a,b);
								i++;
							}
						do 
						{
							//block mathi jane block
							{
								if(((x>95) && (x<130)) && y==550)
									goto top4;
								else if((x>175 && x<350) && y==490)
									goto top4;
								else if((x>400 && x<470) && y==555)
									goto top4;
								else if((x>585 && x<635) && y==620)
									goto top4;
								else if((x>725 && x<770) && y==615)
									goto top4;
								else if((x>770 && x<815) && y==570)
									goto top4;
								else if((x>815 && x<860) && y==525)
									goto top4;
								else if((x>1050 && x<1145) && y==605)
									goto top4;
								else if((x>900 && x<1040) && y==465)
					    			goto top4;	
					    	}
							y+=5;
							x-=1;
							cleardevice();
							draw4(x,y,a1,b1);
							drawcharacterleft(x,y,a,b);
							delay(3);
							
							//creavase bata khasne
							if(((x>285 && x<335) && (y>650 && y<670)) || ((x>585 && x<635) && (y>650 && y<670)) || ((x>1025 && x<1150) && (y>650 && y<670)))
							{
								do
								{
									y+=5;
									x-=1;
									cleardevice();
									draw4(x,y,a,b);
									drawcharacterleft(x,y,a,b);
									delay(3);
								}while(y<800);
								
								x=70;
								y=660;	life--;							
								cleardevice();
								draw4(x,y,a,b);
								drawcharacterleft(x,y,a,b);
								goto top4;
							}
						}while(y<660);
						 
						break;
						
				case 'a':
							//block ma thokkine if
						if(((x>95 && x<130) && y==660) || ((x>400 && x<470) && y==660) || ((x>725 && x<770) && y==660) || ((x>770 && x<815) && y==615) || ((x>815 && x<860) && y==570) || ((x>725 && x<860) && y==660))
						{
							goto top4;
						}
						else
						{
							x=x-10;
							cleardevice();
							draw4(x,y,a1,b1);
							drawcharacterleft(x,y,a,b);
								
							//block bata khasne if
							if((x<70 && y==550) || (x<150 && y==490) || (x<375 && y==555) || (x<560 && y==620) || (x<700 && y==615) || (x<745 && y==570) || (x<790 && y==525) || (x<875 && y==465) || (x<1025 && y==605))
							{
								do
								{
									y+=5;
									cleardevice();
									draw4(x,y,a1,b1);
									drawcharacterleft(x,y,a,b);
								}while(y<660);
							}
							
							//creavase bata khasne
							if(((x>285 && x<335) && (y>650 && y<670)) || ((x>585 && x<635) && (y>650 && y<670)) || ((x>1025 && x<1150) && (y>650 && y<670)))
							{
								do
								{
									y+=5;
									x-=1;	life--;
									cleardevice();
									draw4(x,y,a,b);
									drawcharacterleft(x,y,a,b);
									delay(3);
								}while(y<800);
								
								x=70;
								y=660;								
								cleardevice();
								draw4(x,y,a,b);
								drawcharacterleft(x,y,a,b);
								goto top4;
							} 
						}
							
						break;
			
		    	case 'd':
		    				//block ma thokkine if
						if(((x>95 && x<130) && y==660) || ((x>400 && x<470) && y==660) || ((x>725 && x<770) && y==660) || ((x>770 && x<815) && y==615) || ((x>815 && x<860) && y==570) || ((x>725 && x<860) && y==660))
						{
							goto top4;
						}
						else
						{
							x=x+10;
							cleardevice();
							draw4(x,y,a1,b1);
							drawcharacter(x,y,a,b);	
						
							//block bata khasne if
							if(((x>155 && y==550) || (x>375 && y==490) || (x>495 && y==555) || (x>660 && y==620) ||(x>885 && y==525) || (x>1065 && y==465)|| (x>1170 && y==605)))
							{
								do
								{			
									y+=5;
									cleardevice();
									draw4(x,y,a1,b1);
									drawcharacter(x,y,a,b);
								}while(y<660);
							}
							
							//creavase bata khasne
							if(((x>285 && x<335) && (y>650 && y<670)) || ((x>585 && x<635) && (y>650 && y<670)) || ((x>1025 && x<1150) && (y>650 && y<670)))
							{
								do
								{
									y+=5;
									x+=1;	life--;
									cleardevice();
									draw4(x,y,a,b);
									drawcharacter(x,y,a,b);
									delay(3);
								}while(y<800);
								
								x=70;
								y=660;								
								cleardevice();
								draw4(x,y,a,b);
								drawcharacter(x,y,a,b);
								goto top4;
							} 
							//if(x>=1368)
							//{
							//	playgame4();
							//}
						}
						break;
						
				case '-':
						exit(0);
						break;		  			
			}
		}
	}
}


void maingame()
{
	initwindow(1366,768,"menu");
	top:
	int page=0;
	POINT cursorPos;
	while(1)
	{
		setactivepage(page);
		setvisualpage(1-page);
		cleardevice();
		GetCursorPos(&cursorPos);
		setcolor(8);          //8=grey
		setfillstyle(SOLID_FILL,8);
		//circle(cursorPos.x,cursorPos.y,20);
		//floodfill(cursorPos.x,cursorPos.y,8);
		menu();
		if(GetAsyncKeyState(VK_LBUTTON))
		{
			if(((cursorPos.x)<850 && (cursorPos.x)>500) && ((cursorPos.y)<550 && (cursorPos.y)>500))
				{
					exit(0);
				}
		//break;
		}
		
		if(GetAsyncKeyState(VK_LBUTTON))	
			{
				if(((cursorPos.x)<850 && (cursorPos.x)>500) && ((cursorPos.y)<295 && (cursorPos.y)>245))
				{
					playgame1();
				//	playgame2();
				//	playgame3();
				//	playgame4();
				}
			}
		
	if(GetAsyncKeyState(VK_LBUTTON))	
			{
				if(((cursorPos.x)<850 && (cursorPos.x)>500) && ((cursorPos.y)<380 && (cursorPos.y)>330))
				{
					instruction();
				}
			}
			
	if(GetAsyncKeyState(VK_LBUTTON))	
			{
				if(((cursorPos.x)<850 && (cursorPos.x)>500) && ((cursorPos.y)<465 && (cursorPos.y)>415))
				{
					about();
				}
			}
		page=1-page;
	}
	
	getch();

}

int main()
{
	//loadingpage();
	maingame();

}
