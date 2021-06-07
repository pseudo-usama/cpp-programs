#include <fstream.h>
	#include <math.h>
	#include <ctype.h>
	#include <time.h>
	#include <stdio.h>
	#include <process.h>
	#include <conio.h>
	#include <graphics.h>
	#include <string.h>
	#include <dos.h>
	#define BAR 0
	#define THORN 1
	#define ENEMY 2
	#define GEM 3
	int height = 47, noene[10], firestat = 0, health = 9, life = 3, nogem[10], noruby[10], stat, rpass[10], lpass[10], door[10];
	int nomovbase[10], curmov, eltime, noscore, nobase[10] = { 0 }, level = 1, curbase = 0, nothorn[10], chhealth, lifeup;
	int gdir, throughr, throughl, throughdoor, ofnog[10], ofnor[10], ofnoe[10], ofnogem[10], ofnoruby[10];
	int ofnoene[10], stage, post = 1, hdir = 1, blano, tcont, bullx, bully, excuse = 1, gameloaded = 0, recordno = 0;
	char filedir[] = "d:\\ninja.thg"; //save file directory
	char curtime[10]; //store the current time
	time_t ctim, otim; //time variables to perform time operations
	//prototypes
	void save();
	void drawborder(int, int);
	void thgthorn(int, int, int);
	void thgmovbar(int, int, int, int, int, int, int, int, int);
	void hithero(int, int, int, int);
	void heroclose(int, int);
	void drawruby(int, int, int, int, int);
	void enemyclose(int, int, int, int);
	void drawgem(int, int, int, int, int);
	void redrawplats();
	void drawhero(int, int, int, int);
	void erasehero(int, int, int, int);
	int gameover(int);
	void thgenemy(int, int, int, int, int);
	void load();
	void thgtxt(int, int, char*);
	void success(int);
	void logo();
	void drawdoor(int);
	void drawene(int, int, int);
	void drawgun(int, int, int, int);
	void mainmenu();
	void start();
	void options();
	void password();
	void highscore();
	void help();
	void border();
	void name();
	void loadninja();
	void credits();
	void control();
	void plat(int, int, int, int);
	int quit();
	void thgdrawcur(int, int, int, int);
	//class declarations
	class thgkey //to store the controlls
	    {
	public:
	    char left, right, up, shoot;
	    thgkey()
	    {
	        right = 77;
	        left = 75;
	        up = 72;
	        shoot = ' ';
	    }
	    void reset()
	    {
	        right = 77;
	        left = 75;
	        up = 72;
	        shoot = ' ';
	    }
	} keys;
	struct {
	    int x, y, n;
	} thorn[10][20];
	struct thg_score {
	    char name[30];
	    int score, stage, level;
	} score;
	struct thg_base {
	    int x1;
	    int y1;
	    int x2;
	    int y2;
	} base[10][20];
	struct thg_movbase {
	    int x1;
	    int y1;
	    int x2;
	    int y2;
	    int dir, len, curdir, sx, sy, speed;
	} movbase[10][20];
	struct thg_gem {
	    int x;
	    int y;
	    int flag;
	    int moveid;
	    int scope;
	} gems[10][20];
	struct thg_ruby {
	    int x;
	    int y;
	    int flag;
	    int moveid;
	    int scope;
	} rubys[10][20];
	struct thg_enemy {
	    int x;
	    int y;
	    int bullx;
	    int bully;
	    int bulldir;
	    int stat;
	    int firestat;
	    int jumpstat;
	    int bullfired;
	    int moveid;
	    int dirchange;
	    int scope;
	    int blano;
	} ens[10][20];
	/////////////////////////////////////////////////////////////*
	//*//////////////////////// START/////////////////////*
	void main()
	{
	int gdriver = DETECT,gmode;
	initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
	
	    setgraphbufsize(2000);
	    logo();
	    mainmenu();
	}
	///////////////////////////////
	void drawgun(int x, int y, int s, int menu)
	{
	    if (s) {
	        setfillstyle(1, 8);
	        bar(x + 72, y - 15, x + 265, y - 10);
	        bar(x + 69, y - 14, x + 75, y + 18);
	        bar(x + 70, y + 19, x + 265, y + 23);
	        bar(x + 265, y - 14, x + 271, y + 22);
	        char pa[] = { 0x3a, 0xb456 };
	        setfillpattern(pa, 8);
	        bar(x + 70, y - 14, x + 265, y - 10);
	        bar(x + 70, y - 14, x + 75, y + 18);
	        bar(x + 70, y + 18, x + 265, y + 22);
	        bar(x + 265, y - 14, x + 270, y + 22);
	        for (int i = 300;;) {
	            delay(5);
	            if (kbhit())
	                break;
	            setfillstyle(9, 4);
	            bar(x + 75, y - 10, x + 265, y + 18);
	            i--;
	            setcolor(WHITE);
	            if (menu == 1) {
	                if (y == 200) {
	                    outtextxy(i, y, "START");
	                    if (i <= 290)
	                        break;
	                }
	                else if (y == 250) {
	                    outtextxy(i, y, "OPTIONS");
	                    if (i <= 283)
	                        break;
	                }
	                else if (y == 300) {
	                    outtextxy(i, y, "HIGHSCORE");
	                    if (i <= 290)
	                        break;
	                }
	                else if (y == 350) {
	                    outtextxy(i, y, "HELP");
	                    if (i <= 290)
	                        break;
	                }
	                else if (y == 400) {
	                    outtextxy(i, y, "EXIT");
	                    if (i <= 280)
	                        break;
	                }
	            }
	            else if (menu == 2) {
	                if (y == 200) {
	                    outtextxy(i, y, "LOAD");
	                    if (i <= 280)
	                        break;
	                }
	                else if (y == 250) {
	                    outtextxy(i, y, "CONTROL");
	                    if (i <= 283)
	                        break;
	                }
	                else if (y == 300) {
	                    outtextxy(i, y, "CREDITS");
	                    if (i <= 280)
	                        break;
	                }
	                else if (y == 350) {
	                    outtextxy(i, y, "PASSWORD");
	                    if (i <= 290)
	                        break;
	                }
	                else if (y == 400) {
	                    outtextxy(i, y, "BACK");
	                    if (i <= 280)
	                        break;
	                }
	            }
	        }
	        if (kbhit()) {
	            setfillstyle(9, 4);
	            bar(x + 75, y - 10, x + 265, y + 18);
	            setcolor(WHITE);
	            if (menu == 1) {
	                if (y == 200)
	                    outtextxy(300, y, "START");
	                else if (y == 250)
	                    outtextxy(300, y, "OPTIONS");
	                else if (y == 300)
	                    outtextxy(300, y, "HIGHSCORE");
	                else if (y == 350)
	                    outtextxy(300, y, "HELP");
	                else if (y == 400)
	                    outtextxy(300, y, "EXIT");
	            }
	            else if (menu == 2) {
	                if (y == 200)
	                    outtextxy(300, y, "LOAD");
	                else if (y == 250)
	                    outtextxy(300, y, "CONTROL");
	                else if (y == 300)
	                    outtextxy(300, y, "CREDITS");
	                else if (y == 350)
	                    outtextxy(300, y, "PASSWORD");
	                else if (y == 400)
	                    outtextxy(300, y, "BACK");
	            }
	        }
	    }
	    else {
	        setfillstyle(9, 4);
	        bar(x + 70, y - 15, x + 265, y - 10);
	        bar(x + 69, y - 14, x + 75, y + 18);
	        bar(x + 70, y + 18, x + 265, y + 23);
	        bar(x + 265, y - 14, x + 271, y + 22);
	    }
	}
	
	void erasehero(int x, int y, int a, int dir) //erasing hero
	{
	    setfillstyle(1, BLACK);
	    setcolor(BLACK);
	    if (dir) {
	        int cap[] = { x + 0, y + 10, x + 9, y + 7, x + 14, y + 0, x + 9, y + 3, x + 7, y + 0, x + 4, y + 5, x + 0, y + 10 };
	        int headr[] = { x + 4, y + 8, x + 4, y + 15, x + 8, y + 18, x + 8, y + 14, x + 10, y + 13, x + 10, y + 5 };
	        int sca[] = { x + 8, y + 18, x + 4, y + 20, x + 8, y + 19, x + 10, y + 20, x + 9, y + 19 };
	        int lha[] = { x + 5, y + 21, x + 5, y + 25, x + 10, y + 30, x + 12, y + 29, x + 8, y + 25, x + 8, y + 20 };
	        int rleg[] = { x + 5, y + 47, x + 8, y + 48, x + 9, y + 35, x + 5, y + 47 };
	        int lleg[] = { x + 9, y + 35, x + 13, y + 47, x + 15, y + 46, x + 12, y + 35, x + 9, y + 35 };
	        int body[] = { x + 6, y + 25, x + 7, y + 35, x + 10, y + 35, x + 10, y + 21, x + 6, y + 25 };
	        int lh2[] = { x + 5, y + 21, x + 5, y + 25, x + 6, y + 39, x + 5, y + 29, x + 6, y + 25, x + 6, y + 20 };
	        int rl2[] = { x + 7, y + 35, x + 7, y + 45, x + 9, y + 49, x + 8, y + 35, x + 7, y + 35 };
	        int ll2[] = { x + 9, y + 35, x + 10, y + 47, x + 12, y + 46, x + 10, y + 35, x + 9, y + 35 };
	        int mskr[] = { x + 4, y + 9, x + 11, y + 7, x + 11, y + 12, x + 4, y + 12 };
	        if (a % 7 < 4) {
	            fillpoly(7, cap);
	            fillpoly(6, headr);
	            fillpoly(5, body);
	            fillpoly(6, lha);
	            fillpoly(4, rleg);
	            fillpoly(5, lleg);
	            fillpoly(5, sca);
	            fillpoly(4, mskr);
	        }
	        else {
	            fillpoly(7, cap);
	            fillpoly(6, headr);
	            fillpoly(5, body);
	            fillpoly(6, lh2);
	            fillpoly(5, rl2);
	            fillpoly(5, ll2);
	            fillpoly(5, sca);
	            fillpoly(4, mskr);
	        }
	    }
	    else {
	        int cap[] = { x + 5, y + 10, x + 0, y + 0, x + 5, y + 5, x + 10, y + 0, x + 10, y + 5, x + 15, y + 10, x + 10, y + 10, x + 5, y + 7 };
	        int headr[] = { x + 4, y + 5, x + 4, y + 14, x + 7, y + 16, x + 7, y + 18, x + 10, y + 13, x + 10, y + 5 };
	        int sca[] = { x + 8, y + 18, x + 4, y + 20, x + 8, y + 19, x + 10, y + 20, x + 9, y + 19 };
	        int lha[] = { x + 10, y + 21, x + 10, y + 25, x + 5, y + 30, x + 3, y + 29, x + 7, y + 25, x + 7, y + 20 };
	        int rleg[] = { x + 5, y + 47, x + 8, y + 48, x + 9, y + 35, x + 5, y + 47 };
	        int lleg[] = { x + 8, y + 35, x + 12, y + 47, x + 14, y + 46, x + 11, y + 35, x + 8, y + 35 };
	        int body[] = { x + 5, y + 25, x + 6, y + 35, x + 9, y + 35, x + 9, y + 21, x + 5, y + 25 };
	        int lh2[] = { x + 5, y + 21, x + 5, y + 25, x + 6, y + 39, x + 5, y + 29, x + 6, y + 25, x + 6, y + 20 };
	        int rl2[] = { x + 6, y + 35, x + 5, y + 45, x + 7, y + 49, x + 8, y + 35, x + 5, y + 35 };
	        int ll2[] = { x + 9, y + 35, x + 9, y + 47, x + 11, y + 46, x + 9, y + 35, x + 9, y + 35 };
	        int mskl[] = { x + 11, y + 9, x + 4, y + 7, x + 4, y + 12, x + 11, y + 12 };
	        if (a % 7 < 4) {
	            fillpoly(6, headr);
	            fillpoly(8, cap);
	            fillpoly(5, body);
	            fillpoly(6, lha);
	            fillpoly(4, rleg);
	            fillpoly(5, lleg);
	            fillpoly(5, sca);
	            fillpoly(4, mskl);
	        }
	        else {
	            fillpoly(6, headr);
	            fillpoly(8, cap);
	            fillpoly(5, body);
	            fillpoly(6, lh2);
	            fillpoly(5, rl2);
	            fillpoly(5, ll2);
	            fillpoly(5, sca);
	            fillpoly(4, mskl);
	        }
	    }
	}
	void drawhero(int x, int y, int a, int dir) //drawing the hero
	{
	    if (dir) {
	        int cap[] = { x + 0, y + 10, x + 9, y + 7, x + 14, y + 0, x + 9, y + 3, x + 7, y + 0, x + 4, y + 5, x + 0, y + 10 };
	        int headr[] = { x + 4, y + 8, x + 4, y + 15, x + 8, y + 18, x + 8, y + 14, x + 10, y + 13, x + 10, y + 5 };
	        int sca[] = { x + 8, y + 18, x + 4, y + 20, x + 8, y + 19, x + 10, y + 20, x + 9, y + 19 };
	        int lha[] = { x + 5, y + 21, x + 5, y + 25, x + 10, y + 30, x + 12, y + 29, x + 8, y + 25, x + 8, y + 20 };
	        int rleg[] = { x + 5, y + 47, x + 8, y + 48, x + 9, y + 35, x + 5, y + 47 };
	        int lleg[] = { x + 9, y + 35, x + 13, y + 47, x + 15, y + 46, x + 12, y + 35, x + 9, y + 35 };
	        int body[] = { x + 6, y + 25, x + 7, y + 35, x + 10, y + 35, x + 10, y + 21, x + 6, y + 25 };
	        int lh2[] = { x + 5, y + 21, x + 5, y + 25, x + 6, y + 39, x + 5, y + 29, x + 6, y + 25, x + 6, y + 20 };
	        int rl2[] = { x + 7, y + 35, x + 7, y + 45, x + 9, y + 49, x + 8, y + 35, x + 7, y + 35 };
	        int ll2[] = { x + 9, y + 35, x + 10, y + 47, x + 12, y + 46, x + 10, y + 35, x + 9, y + 35 };
	        int mskr[] = { x + 4, y + 9, x + 11, y + 7, x + 11, y + 12, x + 4, y + 12 };
	        if (a % 7 < 4) {
	            setfillstyle(1, 8);
	            fillpoly(7, cap);
	            setfillstyle(1, 7);
	            fillpoly(6, headr);
	            fillpoly(5, body);
	            setfillstyle(6, 8);
	            fillpoly(6, lha);
	            fillpoly(4, rleg);
	            fillpoly(5, lleg);
	            setfillstyle(1, RED);
	            fillpoly(5, sca);
	            setfillstyle(6, 8);
	            fillpoly(4, mskr);
	        }
	        else {
	            setfillstyle(1, 8);
	            fillpoly(7, cap);
	            setfillstyle(1, 7);
	            fillpoly(6, headr);
	            fillpoly(5, body);
	            setfillstyle(6, 8);
	            fillpoly(6, lh2);
	            fillpoly(5, rl2);
	            fillpoly(5, ll2);
	            setfillstyle(1, RED);
	            fillpoly(5, sca);
	            setfillstyle(6, 8);
	            fillpoly(4, mskr);
	        }
	    }
	    else {
	        int cap[] = { x + 5, y + 10, x + 0, y + 0, x + 5, y + 5, x + 10, y + 0, x + 10, y + 5, x + 15, y + 10, x + 10, y + 10, x + 5, y + 7 };
	        int headr[] = { x + 4, y + 5, x + 4, y + 14, x + 7, y + 16, x + 7, y + 18, x + 10, y + 13, x + 10, y + 5 };
	        int sca[] = { x + 8, y + 18, x + 4, y + 20, x + 8, y + 19, x + 10, y + 20, x + 9, y + 19 };
	        int lha[] = { x + 10, y + 21, x + 10, y + 25, x + 5, y + 30, x + 3, y + 29, x + 7, y + 25, x + 7, y + 20 };
	        int rleg[] = { x + 5, y + 47, x + 8, y + 48, x + 9, y + 35, x + 5, y + 47 };
	        int lleg[] = { x + 8, y + 35, x + 12, y + 47, x + 14, y + 46, x + 11, y + 35, x + 8, y + 35 };
	        int body[] = { x + 5, y + 25, x + 6, y + 35, x + 9, y + 35, x + 9, y + 21, x + 5, y + 25 };
	        int lh2[] = { x + 5, y + 21, x + 5, y + 25, x + 6, y + 39, x + 5, y + 29, x + 6, y + 25, x + 6, y + 20 };
	        int rl2[] = { x + 6, y + 35, x + 5, y + 45, x + 7, y + 49, x + 8, y + 35, x + 5, y + 35 };
	        int ll2[] = { x + 9, y + 35, x + 9, y + 47, x + 11, y + 46, x + 9, y + 35, x + 9, y + 35 };
	        int mskl[] = { x + 11, y + 9, x + 4, y + 7, x + 4, y + 12, x + 11, y + 12 };
	        if (a % 7 < 4) {
	            setfillstyle(1, 8);
	            fillpoly(8, cap);
	            setfillstyle(1, 7);
	            fillpoly(6, headr);
	            fillpoly(5, body);
	            setfillstyle(6, 8);
	            fillpoly(6, lha);
	            fillpoly(4, rleg);
	            fillpoly(5, lleg);
	            setfillstyle(1, RED);
	            fillpoly(5, sca);
	            setfillstyle(6, 8);
	            fillpoly(4, mskl);
	        }
	        else {
	            setfillstyle(1, 8);
	            fillpoly(8, cap);
	            setfillstyle(1, 7);
	            fillpoly(6, headr);
	            fillpoly(5, body);
	            setfillstyle(6, 8);
	            fillpoly(6, lh2);
	            fillpoly(5, rl2);
	            fillpoly(5, ll2);
	            setfillstyle(1, RED);
	            fillpoly(5, sca);
	            setfillstyle(6, 8);
	            fillpoly(4, mskl);
	        }
	    }
	}
	void drawene(int x, int y, int dir) //drawing the enemy at x,y in dir direction
	{
	    setcolor(BLACK);
	    if (dir) {
	        int cap[] = { x + 0, y + 10, x + 9, y + 7, x + 14, y + 0, x + 9, y + 3, x + 7, y + 0, x + 4, y + 5, x + 0, y + 10 };
	        int headr[] = { x + 4, y + 8, x + 4, y + 15, x + 8, y + 18, x + 8, y + 14, x + 10, y + 13, x + 10, y + 5 };
	        int sca[] = { x + 8, y + 18, x + 4, y + 20, x + 8, y + 19, x + 10, y + 20, x + 9, y + 19 };
	        int lha[] = { x + 5, y + 21, x + 5, y + 25, x + 10, y + 30, x + 12, y + 29, x + 8, y + 25, x + 8, y + 20 };
	        int rleg[] = { x + 5, y + 47, x + 8, y + 48, x + 9, y + 35, x + 5, y + 47 };
	        int lleg[] = { x + 9, y + 35, x + 13, y + 47, x + 15, y + 46, x + 12, y + 35, x + 9, y + 35 };
	        int body[] = { x + 6, y + 25, x + 7, y + 35, x + 10, y + 35, x + 10, y + 21, x + 6, y + 25 };
	        setfillstyle(1, 8);
	        fillpoly(7, cap);
	        setfillstyle(1, 7);
	        fillpoly(6, headr);
	        fillpoly(5, body);
	        setfillstyle(6, 8);
	        fillpoly(6, lha);
	        fillpoly(4, rleg);
	        fillpoly(5, lleg);
	        setfillstyle(1, RED);
	        fillpoly(5, sca);
	    }
	    else {
	        int cap[] = { x + 5, y + 10, x + 0, y + 0, x + 5, y + 5, x + 10, y + 0, x + 10, y + 5, x + 15, y + 10, x + 10, y + 10, x + 5, y + 7 };
	        int headr[] = { x + 4, y + 5, x + 4, y + 14, x + 7, y + 16, x + 7, y + 18, x + 10, y + 13, x + 10, y + 5 };
	        int sca[] = { x + 8, y + 18, x + 4, y + 20, x + 8, y + 19, x + 10, y + 20, x + 9, y + 19 };
	        int lha[] = { x + 10, y + 21, x + 10, y + 25, x + 5, y + 30, x + 3, y + 29, x + 7, y + 25, x + 7, y + 20 };
	        int rleg[] = { x + 5, y + 47, x + 8, y + 48, x + 9, y + 35, x + 5, y + 47 };
	        int lleg[] = { x + 8, y + 35, x + 12, y + 47, x + 14, y + 46, x + 11, y + 35, x + 8, y + 35 };
	        int body[] = { x + 5, y + 25, x + 6, y + 35, x + 9, y + 35, x + 9, y + 21, x + 5, y + 25 };
	        setfillstyle(1, 8);
	        fillpoly(6, headr);
	        setfillstyle(1, 7);
	        fillpoly(8, cap);
	        fillpoly(5, body);
	        setfillstyle(6, 8);
	        fillpoly(6, lha);
	        fillpoly(4, rleg);
	        fillpoly(5, lleg);
	        setfillstyle(1, RED);
	        fillpoly(5, sca);
	    }
	}
	char* controllval(char a) //fn to return the name of char a
	{
	    if (a == 13)
	        return "Enter";
	    else if (a == ' ')
	        return "Space";
	    else if (a == 9)
	        return "Tab";
	    else if (a == 8)
	        return "Backspace";
	    else if (a == 80)
	        return "Down key";
	    else if (a == 72)
	        return "Up key";
	    else if (a == 75)
	        return "Left key";
	    else if (a == 77)
	        return "Right key";
	    else
	        return NULL;
	}
	//////////////////////////////////////////////////////////////////////////
	void thgtxt(int x, int y, char* a) //to create a txt efect at x,y
	{
	    int col = getcolor(), t = 0;
	    int width = textwidth("A"), height = textheight("A");
	    char buf[2] = " \n";
	    for (int i = 0; a[i]; i++) {
	        buf[0] = a[i];
	        if (buf[0] == 'i')
	            t = width / 3;
	        else if (buf[0] == 'I')
	            t = width / 4.0;
	        else
	            t = 0;
	        for (int tx = x + width * i + width / 2.0 + t, ty = y - 2 * height; tx > x + width * i + t && ty < y + height;) {
	            setcolor(BLACK);
	            outtextxy(tx, ty, buf);
	            tx -= 2;
	            ty += 2;
	            setcolor(col);
	            outtextxy(tx, ty, buf);
	            delay(10);
	        }
	    }
	}
	//Print the credits
	void credits()
	{
	    cleardevice();
	    border();
	    settextstyle(4, 0, 4);
	    int hx = 300, hy = 100, i = 0;
	    while (hy > -300) {
	        delay(13);
	        setcolor(0);
	        arc(hx, hy, 0, 180, 6);
	        arc(hx + 20, hy, 0, 180, 6);
	        line(hx - 6, hy, hx - 8, hy + 60);
	        line(hx + 26, hy, hx + 28, hy + 60);
	        arc(hx - 256, hy + 20, 340, 0, 250);
	        arc(hx + 276, hy + 20, 180, 200, 250);
	        arc(hx - 40, hy + 100, 300, -5, 20);
	        arc(hx + 60, hy + 100, 185, 230, 20);
	        arc(hx - 22, hy + 162, 100, 160, 45);
	        arc(hx + 41, hy + 160, 20, 80, 45);
	        arc(hx - 85, hy + 145, 300, -5, 20);
	        arc(hx + 104, hy + 144, 185, 240, 20);
	        arc(hx - 115, hy + 105, 280, -50, 70);
	        arc(hx + 135, hy + 105, 230, 260, 70);
	        line(hx - 102, hy + 173, hx - 210, hy + 192);
	        line(hx + 122, hy + 173, hx + 230, hy + 192);
	        line(hx - 200, hy + 263, hx - 40, hy + 223); //lower hand
	        line(hx + 220, hy + 263, hx + 60, hy + 223); //lower hand
	        arc(hx + 6, hy + 8, 0, 180, 5); //ind
	        arc(hx + 14, hy + 8, 0, 180, 5); //ind
	        line(hx + 1, hy + 8, hx - 2, hy + 60); //ind
	        line(hx + 21, hy + 8, hx + 23, hy + 60); //ind
	        arc(hx - 251, hy + 20, 345, 0, 250); //ind
	        arc(hx + 271, hy + 20, 180, 195, 250); //ind
	        arc(hx - 50, hy + 165, 280, -5, 60); //lower bump
	        arc(hx + 70, hy + 165, 185, 260, 60); //lower bump
	        arc(hx, hy + 115, 0, 180, 9); //thumb
	        arc(hx + 20, hy + 115, 0, 180, 9); //thumb
	        line(hx - 10, hy + 115, hx - 13, hy + 140);
	        line(hx + 29, hy + 115, hx + 31, hy + 140);
	        arc(hx - 32, hy + 140, 300, -5, 20);
	        arc(hx + 52, hy + 140, 185, 230, 20);
	        setcolor(WHITE);
	        hy -= 3;
	        arc(hx, hy, 0, 180, 6);
	        arc(hx + 20, hy, 0, 180, 6);
	        line(hx - 6, hy, hx - 8, hy + 60);
	        line(hx + 26, hy, hx + 28, hy + 60);
	        arc(hx - 256, hy + 20, 340, 0, 250);
	        arc(hx + 276, hy + 20, 180, 200, 250);
	        arc(hx - 40, hy + 100, 300, -5, 20);
	        arc(hx + 60, hy + 100, 185, 230, 20);
	        arc(hx - 22, hy + 162, 100, 160, 45);
	        arc(hx + 41, hy + 160, 20, 80, 45);
	        arc(hx - 85, hy + 145, 300, -5, 20);
	        arc(hx + 104, hy + 144, 185, 240, 20);
	        arc(hx - 115, hy + 105, 280, -50, 70);
	        arc(hx + 135, hy + 105, 230, 260, 70);
	        line(hx - 102, hy + 173, hx - 210, hy + 192);
	        line(hx + 122, hy + 173, hx + 230, hy + 192);
	        line(hx - 200, hy + 263, hx - 40, hy + 223); //lower hand
	        line(hx + 220, hy + 263, hx + 60, hy + 223); //lower hand
	        arc(hx + 6, hy + 8, 0, 180, 5); //ind
	        arc(hx + 14, hy + 8, 0, 180, 5); //ind
	        line(hx + 1, hy + 8, hx - 2, hy + 60); //ind
	        line(hx + 21, hy + 8, hx + 23, hy + 60); //ind
	        arc(hx - 251, hy + 20, 345, 0, 250); //ind
	        arc(hx + 271, hy + 20, 180, 195, 250); //ind
	        arc(hx - 50, hy + 165, 280, -5, 60); //lower bump
	        arc(hx + 70, hy + 165, 185, 260, 60); //lower bump
	        arc(hx, hy + 115, 0, 180, 9); //thumb
	        arc(hx + 20, hy + 115, 0, 180, 9); //thumb
	        line(hx - 10, hy + 115, hx - 13, hy + 140);
	        line(hx + 29, hy + 115, hx + 31, hy + 140);
	        arc(hx - 32, hy + 140, 300, -5, 20);
	        arc(hx + 52, hy + 140, 185, 230, 20);
	        if (i == 0) {
	            setcolor(GREEN);
	            thgtxt(50, 450, "OUR SINCERE THANKS TO");
	            setcolor(RED);
	            thgtxt(50, 450, "OUR SINCERE THANKS TO");
	            setcolor(GREEN);
	            thgtxt(100, 480, "MS. UMA ARTHI");
	            delay(2000);
	            setcolor(0);
	            thgtxt(100, 480, "MS. UMA ARTHI");
	            setcolor(GREEN);
	            thgtxt(100, 480, "MS. UDHAYAKUMARI");
	            delay(2000);
	            setcolor(0);
	            thgtxt(100, 480, "MS. UDHAYAKUMARI");
	            setcolor(0);
	            thgtxt(50, 450, "OUR SINCERE THANKS TO");
	            setcolor(GREEN);
	            thgtxt(100, 450, "THANK YOU ALL !!");
	        }
	        i++;
	    } //while ended
	    setcolor(0);
	    thgtxt(100, 450, "THANK YOU ALL !!");
	}
	void border()
	{
	    for (int t = 0; t < getmaxx(); t++) //border
	    {
	        setfillstyle(t % 10, 8);
	        if (!lpass[level])
	            bar(0, t, 5, t + 4);
	        if (!rpass[level])
	            bar(getmaxx() - 5, t, getmaxx(), t + 4);
	        bar(getmaxx() - t, 0, getmaxx() - t - 5, 5);
	        bar(getmaxx() - t, getmaxy(), getmaxx() - t - 5, getmaxy() - 5);
	    }
	}
	///////////////////////////////////////////////////////////////////////////
	void logo()
	{
	    getch();
	    setcolor(WHITE);
	    settextstyle(1, 0, 4);
	    thgtxt(130, 60, "C++ Project 2011");
	    setcolor(BROWN);
	    settextstyle(1, 0, 4);
	    thgtxt(140, 150, "THIAGESH");
	    thgtxt(230, 190, "AND");
	    thgtxt(280, 220, "RAUNAQ");
	    setcolor(WHITE);
	    settextstyle(4, 0, 4);
	    delay(200);
	    outtextxy(getmaxx() / 2 - 140, 260, "NINJA");
	    outtextxy(getmaxx() / 2 - 80, 320, "ASSASSIN");
	    delay(200);
	    for (int x = -300, y = 0; x < 0 / 2;) {
	        delay(1);
	        setcolor(BLACK);
	        setfillstyle(1, BLACK);
	        line(x + 170, y + 300, x + 410, y + 300);
	        arc(x + 410, y + 309, 50, 90, 8);
	        line(x + 430, y + 320, x + 415, y + 302);
	        line(x + 170, y + 320, x + 430, y + 320);
	        rectangle(x + 170, y + 270, x + 160, y + 340);
	        bar(x + 100, y + 303, x + 160, y + 315);
	        x++;
	        setcolor(WHITE);
	        setfillstyle(1, WHITE);
	        char pa[] = { 0x3a, 0xb4d56 };
	        setfillpattern(pa, WHITE);
	        line(x + 170, y + 300, x + 410, y + 300);
	        arc(x + 410, y + 309, 50, 90, 8);
	        line(x + 430, y + 320, x + 415, y + 302);
	        line(x + 170, y + 320, x + 430, y + 320);
	        rectangle(x + 170, y + 270, x + 160, y + 340);
	        bar(x + 100, y + 303, x + 160, y + 315);
	    }
	    getch();
	    int i = 0, by = 302, falli = 10;
	    while (1) {
	        setfillstyle(1, RED);
	        if (i < 250) //blooding the katana
	        {
	            delay(1);
	            if (i >= 234)
	                by += 2;
	            bar(i + 170, by, i + 180, 318);
	            i += 2;
	        }
	        if (falli < 190 && i >= 250) //blood falling
	        {
	            setfillstyle(1, BLACK);
	            setcolor(BLACK);
	            fillellipse(430, falli + 320, 3, 5);
	            falli++;
	            setfillstyle(1, RED);
	            setcolor(RED);
	            fillellipse(430, falli + 320, 3, 5);
	            setfillstyle(1, RED);
	        }
	        else
	            falli = 10;
	        if (kbhit() && i >= 250) {
	            getch();
	            break;
	        };
	        delay(5);
	    }
	}
	void bullet(int x, int y, int p)
	{
	    if (p) {
	        setfillstyle(1, 6);
	        setcolor(6);
	    }
	    else {
	        setfillstyle(1, BLACK);
	        setcolor(BLACK);
	    }
	    bar(x + 0, y + 5, x + 3, y + 15);
	    pieslice(x + 2, y + 4, 0, 180, 1);
	}
	void mainmenu()
	{
	    fflush(stdin);
	    int y = 200;
	first:
	    setfillstyle(9, 4);
	    bar(0, 0, getmaxx(), getmaxy());
	    for (int i = 0; i < getmaxy(); i++) {
	        setfillstyle(i % 10, 8);
	        bar(0, i, 5, i + 4);
	        bar(getmaxx() - 5, i, getmaxx(), i + 4);
	        bar(i + 2, 0, i + 5, 5);
	        bar(getmaxx() - i, 0, getmaxx() - i - 5, 5);
	        bar(i + 2, getmaxy(), i + 5, getmaxy() - 5);
	        bar(getmaxx() - i, getmaxy(), getmaxx() - i - 5, getmaxy() - 5);
	    }
	    setcolor(WHITE);
	    settextstyle(1, 0, 4);
	    settextjustify(1, 1);
	    outtextxy(300, 100, "NINJA ASSASSIN");
	    outtextxy(300, 200, "START");
	    outtextxy(300, 250, "OPTIONS");
	    outtextxy(300, 300, "HIGHSCORE");
	    outtextxy(300, 350, "HELP");
	    outtextxy(300, 400, "EXIT");
	    char key;
	    do {
	        settextstyle(1, 0, 4);
	        drawgun(130, y, 1, 1);
	        key = getch();
	        drawgun(130, y, 0, 1);
	        if (key == 80) //down
	        {
	            if (y < 400)
	                y += 50;
	            else
	                y = 200;
	        }
	        else if (key == 72) //UP
	        {
	            if (y > 200)
	                y -= 50;
	            else
	                y = 400;
	        }
	        else if (key == 13) //Enter key
	        {
	            if (y == 200) {
	                tcont = 0;
	                if (!gameloaded)
	                    name();
	                life = 3;
	                start();
	                goto first;
	            }
	            else if (y == 250) {
	                options();
	                goto first;
	            }
	            else if (y == 300) {
	                highscore();
	                goto first;
	            }
	            else if (y == 350) {
	                help();
	                goto first;
	            }
	            else if (y == 400) {
	                if (quit())
	                    exit(0);
	                goto first;
	            }
	        }
	    } while (1);
	}
	//Draws the gun for the menu
	int quit()
	{
	    if (gameover(0))
	        return 0;
	    return 1;
	}
	void load()
	{
	    cleardevice();
	    setfillstyle(1, WHITE);
	    setcolor(WHITE);
	    outtextxy(270, 200, "Loading...");
	    line(170, 300, 410, 300);
	    arc(410, 309, 50, 90, 8);
	    line(430, 320, 415, 302);
	    line(170, 320, 430, 320);
	    rectangle(170, 270, 160, 340);
	    bar(100, 303, 160, 315);
	    delay(600);
	    setfillstyle(1, RED);
	    for (int i = 0, y = 302; i < 250; i += 2) {
	        delay(10);
	        if (i >= 234)
	            y += 2;
	        bar(i + 170, y, i + 180, 318);
	    }
	    delay(500);
	}
	//////////////////////////////////////////////////////////////////////////
	void options()
	{
	    int y = 200;
	first:
	    cleardevice();
	    setfillstyle(9, 4);
	    bar(0, 0, getmaxx(), getmaxy());
	    border();
	    setcolor(WHITE);
	    settextstyle(1, 0, 4);
	    settextjustify(1, 1);
	    outtextxy(300, 100, "NINJA ASSASSIN");
	    outtextxy(300, 200, "LOAD");
	    outtextxy(300, 250, "CONTROLS");
	    outtextxy(300, 300, "CREDITS");
	    outtextxy(300, 350, "PASSWORD");
	    outtextxy(300, 400, "BACK");
	    char key;
	    do {
	        settextstyle(1, 0, 4);
	        drawgun(130, y, 1, 2);
	        key = getch();
	        drawgun(130, y, 0, 2);
	        if (key == 80) //down
	        {
	            if (y < 400)
	                y += 50;
	            else
	                y = 200;
	        }
	        else if (key == 72) //UP
	        {
	            if (y > 200)
	                y -= 50;
	            else
	                y = 400;
	        }
	        else if (key == 13) //Enter key
	        {
	            if (y == 200) {
	                loadninja();
	                goto first;
	            }
	            else if (y == 250) {
	                control();
	                goto first;
	            }
	            else if (y == 300) {
	                credits();
	                goto first;
	            }
	            else if (y == 350) {
	                password();
	                goto first;
	            }
	            else if (y == 400)
	                break;
	        }
	    } while (1);
	}
	///////////////////////////////////////////////////////////////////////////
	void plat(int x1, int y1, int l, int w)
	{
	    base[level][curbase].x1 = x1;
	    base[level][curbase].y1 = y1;
	    base[level][curbase].x2 = x1 + l;
	    base[level][curbase].y2 = y1 + w;
	    curbase++;
	    nobase[level]++;
	}
	void redrawplats()
	{
	    setcolor(BLACK);
	    setfillstyle(1, 8);
	    for (int j = 0; j < nothorn[level]; j++)
	        for (int i = 0; i < thorn[level][j].n; i++) {
	            int poly[] = { thorn[level][j].x + 0 + 8 * i, thorn[level][j].y + 10, thorn[level][j].x + 2 + 8 * i, thorn[level][j].y + 0,
	                thorn[level][j].x + 4 + 8 * i, thorn[level][j].y + 10, thorn[level][j].x + 6 + 8 * i, thorn[level][j].y + 3,
	                thorn[level][j].x + 8 + 8 * i, thorn[level][j].y + 10 };
	            fillpoly(5, poly);
	        }
	    setcolor(BLACK);
	    for (i = 0; i < nobase[level]; i++) {
	        if (i != nobase[level] - 1 && i != nobase[level] - 2) {
	            setfillstyle(1, BROWN);
	            bar(base[level][i].x1, base[level][i].y1, base[level][i].x2, base[level][i].y2);
	        }
	        char patt[] = { 0x95765, 0xabc214, 0x34723, 0xa3456 };
	        setfillpattern(patt, BROWN);
	        if (i == nobase[level] - 1 || i == nobase[level] - 2)
	            setfillpattern(patt, 8);
	        bar(base[level][i].x1, base[level][i].y1, base[level][i].x2, base[level][i].y2 - (base[level][i].y2 - base[level][i].y1) / 3);
	    }
	    for (i = 0; i < noene[level]; i++) {
	        if (ens[level][i].stat)
	            drawene(ens[level][i].x, ens[level][i].y, ens[level][i].bulldir);
	    }
	    if (door[level] && !stat)
	        drawdoor(door[level]);
	}
	void thgenemy(int x, int y, int dir, int level, int no)
	{
	    if (!ens[level][no].scope || ens[level][no].scope && ens[level][no].stat) {
	        drawene(x, y, dir);
	        ens[level][no].x = x;
	        ens[level][no].y = y;
	        ens[level][no].bulldir = dir;
	        ens[level][no].firestat = 0;
	        ens[level][no].stat = 1;
	        ens[level][no].moveid = -1;
	        ens[level][no].scope = 1;
	        noene[level]++;
	    }
	}
	//////////////////////////////Game over//////////////////////////////
	int gameover(int a)
	{
	    border();
	    setcolor(BLACK);
	    setfillstyle(8, 8);
	    bar(getmaxx() / 2 - 120, getmaxy() / 2 - 50, getmaxx() / 2 + 120, getmaxy() / 2 + 50);
	    setcolor(BLACK);
	    setfillstyle(8, BLACK);
	    bar(getmaxx() / 2 - 110, getmaxy() / 2 - 40, getmaxx() / 2 + 110, getmaxy() / 2 + 40);
	    setcolor(RED);
	    settextstyle(1, 0, 2);
	    if (a)
	        outtextxy(getmaxx() / 2 - 46, getmaxy() / 2 - 35, "GAME OVER");
	    settextstyle(1, 0, 1);
	    setcolor(WHITE);
	    if (a) {
	        outtextxy(getmaxx() / 2 + 50, getmaxy() / 2 - 35, "TIME UP");
	        outtextxy(getmaxx() / 2, getmaxy() / 2, "Goto to Menu(Y/N)");
	        int i = 0;
	        setcolor(BLACK);
	        setfillstyle(1, BLACK);
	        for (int xa = getmaxx() - 110, ya = 10; i < 9; i++, xa += 6) {
	            bar(xa + 0, ya + 0, xa + 5, ya + 10);
	            bar(xa + 0, ya + 0, xa + 4, ya + 9);
	        }
	    }
	    else
	        outtextxy(getmaxx() / 2, getmaxy() / 2, "Want to Quit(Y/N)");
	    strcpy(score.name, score.name);
	    while (1) {
	        char key = getch();
	        if (key == 'Y' || key == 'y') {
	            return 0;
	        }
	        if (key == 'n' || key == 'N')
	            break;
	    }
	    return 1;
	}
	//////////////////GEM////////////////////////////
	void drawgem(int x, int y, int level, int no, int p) //drawing the gem at x,y
	{
	    if (!gems[level][no].scope || gems[level][no].scope && gems[level][no].flag) {
	        gems[level][no].scope = 1;
	        int poly[10] = { x + 5, y + 0, x + 10, y + 5, x + 5, y + 15, x + 0, y + 5, x + 5, y + 0 };
	        if (p == 7) {
	            setcolor(BLACK);
	            setfillstyle(1, BLACK);
	            fillpoly(5, poly);
	            return;
	        }
	        if (p == 8) {
	            setcolor(BLACK);
	            setfillstyle(1, YELLOW);
	            fillpoly(5, poly);
	            return;
	        }
	        if (!p) {
	            gems[level][no].flag = 0;
	            setcolor(BLACK);
	            setfillstyle(1, BLACK);
	            fillpoly(5, poly);
	            ofnog[stage]++;
	            score.score += 50;
	            return;
	        }
	        gems[level][nogem[level]].x = x;
	        gems[level][nogem[level]].y = y;
	        gems[level][nogem[level]].flag = 1;
	        gems[level][nogem[level]].moveid = -1;
	        nogem[level]++;
	        setfillstyle(1, YELLOW);
	        fillpoly(5, poly);
	    }
	}
	//////////////////RUBY////////////////////////////
	void drawruby(int x, int y, int level, int no, int p) //drawig ruby at x,y
	{
	    if (!rubys[level][no].scope || rubys[level][no].scope && rubys[level][no].flag) {
	        rubys[level][no].scope = 1;
	        int poly[10] = { x + 5, y + 0, x + 10, y + 5, x + 5, y + 15, x + 0, y + 5, x + 5, y + 0 };
	        if (p == 7) {
	            setcolor(BLACK);
	            setfillstyle(1, BLACK);
	            fillpoly(5, poly);
	            return;
	        }
	        else if (p == 8) {
	            setcolor(BLACK);
	            setfillstyle(1, RED);
	            fillpoly(5, poly);
	            return;
	        }
	        if (!p) {
	            rubys[level][no].flag = 0;
	            setcolor(BLACK);
	            setfillstyle(1, BLACK);
	            fillpoly(5, poly);
	            ofnor[stage]++;
	            score.score += 50;
	            return;
	        }
	        rubys[level][noruby[level]].x = x;
	        rubys[level][noruby[level]].y = y;
	        rubys[level][noruby[level]].flag = 1;
	        rubys[level][noruby[level]].moveid = -1;
	        noruby[level]++;
	        setcolor(BLACK);
	        setfillstyle(1, RED);
	        fillpoly(5, poly);
	    }
	}
	void enemyclose(int level, int no, int x, int y) //when enemy is hit
	{
	    score.score += 100;
	    y++; //simply
	    for (int t = 0; t < 10; t++) {
	        delay(10);
	        erasehero(ens[level][no].x, ens[level][no].y, 9, ens[level][no].bulldir);
	        if (ens[level][no].x < x)
	            ens[level][no].x -= 5;
	        else
	            ens[level][no].x += 5;
	        drawene(ens[level][no].x, ens[level][no].y, ens[level][no].bulldir);
	    }
	    for (int i = 50; i > 0;) {
	        setcolor(RED);
	        setfillstyle(1, RED);
	        pieslice(ens[level][no].x, ens[level][no].y, 0, 360, i);
	        delay(5);
	        setfillstyle(1, BLACK);
	        setcolor(BLACK);
	        pieslice(ens[level][no].x, ens[level][no].y, 0, 360, i);
	        i--;
	    }
	    firestat = 0;
	    ens[level][no].stat = 0;
	    setcolor(BLACK);
	    setfillstyle(1, BLACK);
	    int blaze[][8] = { { ens[level][no].bullx + 0, ens[level][no].bully + 4,
	                           ens[level][no].bullx + 4, ens[level][no].bully + 0, ens[level][no].bullx + 8,
	                           ens[level][no].bully + 4, ens[level][no].bullx + 4, ens[level][no].bully + 3 },
	        { ens[level][no].bullx + 1, ens[level][no].bully + 2, ens[level][no].bullx + 4,
	            ens[level][no].bully + 0, ens[level][no].bullx + 8, ens[level][no].bully + 6,
	            ens[level][no].bullx + 5, ens[level][no].bully + 3 },
	        { ens[level][no].bullx + 0, ens[level][no].bully + 0, ens[level][no].bullx + 5,
	            ens[level][no].bully + 4, ens[level][no].bullx + 3, ens[level][no].bully + 8,
	            ens[level][no].bullx + 3, ens[level][no].bully + 4 },
	        { ens[level][no].bullx + 6, ens[level][no].bully + 0, ens[level][no].bullx + 4,
	            ens[level][no].bully + 5, ens[level][no].bullx + 0, ens[level][no].bully + 5,
	            ens[level][no].bullx + 3, ens[level][no].bully + 3 },
	        { ens[level][no].bullx + 7, ens[level][no].bully + 0, ens[level][no].bullx + 4,
	            ens[level][no].bully + 4, ens[level][no].bullx + 0, ens[level][no].bully + 1,
	            ens[level][no].bullx + 3, ens[level][no].bully + 3 },
	        { ens[level][no].bullx + 3, ens[level][no].bully + 0, ens[level][no].bullx + 0,
	            ens[level][no].bully + 4, ens[level][no].bullx + 3, ens[level][no].bully + 7,
	            ens[level][no].bullx + 2, ens[level][no].bully + 3 },
	        { ens[level][no].bullx + 7, ens[level][no].bully + 3, ens[level][no].bullx + 4,
	            ens[level][no].bully + 0, ens[level][no].bullx + 0, ens[level][no].bully + 5,
	            ens[level][no].bullx + 2, ens[level][no].bully + 2 } };
	    fillpoly(4, blaze[ens[level][no].blano]);
	    int blaz[][8] = { { bullx + 0, bully + 4, bullx + 4, bully + 0, bullx + 8, bully + 4, bullx + 4,
	                          bully + 3 },
	        { bullx + 1, bully + 2, bullx + 4, bully + 0, bullx + 8, bully + 6, bullx + 5, bully + 3 },
	        { bullx + 0, bully + 0, bullx + 5, bully + 4, bullx + 3, bully + 8, bullx + 3, bully + 4 },
	        { bullx + 6, bully + 0, bullx + 4, bully + 5, bullx + 0, bully + 5, bullx + 3, bully + 3 },
	        { bullx + 7, bully + 0, bullx + 4, bully + 4, bullx + 0, bully + 1, bullx + 3, bully + 3 },
	        { bullx + 3, bully + 0, bullx + 0, bully + 4, bullx + 3, bully + 7, bullx + 2, bully + 3 },
	        { bullx + 7, bully + 3, bullx + 4, bully + 0, bullx + 0, bully + 5, bullx + 2, bully + 2 } };
	    setcolor(BLACK);
	    setfillstyle(1, BLACK);
	    fillpoly(4, blaz[blano]);
	}
	void heroclose(int x, int y) //when hero closed
	{
	    for (int i = 50; i > 0;) {
	        setcolor(i % 50);
	        setfillstyle(1, RED);
	        pieslice(x, y, 0, 360, i);
	        delay(5);
	        setfillstyle(1, BLACK);
	        setcolor(BLACK);
	        pieslice(x, y, 0, 360, i);
	        i--;
	    }
	    firestat = 0;
	    setcolor(BLACK);
	    setfillstyle(1, BLACK);
	    int blaz[][8] = { { bullx + 0, bully + 4, bullx + 4, bully + 0, bullx + 8, bully + 4, bullx + 4,
	                          bully + 3 },
	        { bullx + 1, bully + 2, bullx + 4, bully + 0, bullx + 8, bully + 6, bullx + 5, bully + 3 },
	        { bullx + 0, bully + 0, bullx + 5, bully + 4, bullx + 3, bully + 8, bullx + 3, bully + 4 },
	        { bullx + 6, bully + 0, bullx + 4, bully + 5, bullx + 0, bully + 5, bullx + 3, bully + 3 },
	        { bullx + 7, bully + 0, bullx + 4, bully + 4, bullx + 0, bully + 1, bullx + 3, bully + 3 },
	        { bullx + 3, bully + 0, bullx + 0, bully + 4, bullx + 3, bully + 7, bullx + 2, bully + 3 },
	        { bullx + 7, bully + 3, bullx + 4, bully + 0, bullx + 0, bully + 5, bullx + 2, bully + 2 } };
	    fillpoly(4, blaz[blano]);
	}
	////////////////////////////////////////
	void hithero(int level, int no, int x, int y) //when hero is hit
	{
	    setcolor(BLACK);
	    setfillstyle(1, BLACK);
	    int blaze[][8] = { { ens[level][no].bullx + 0, ens[level][no].bully + 4,
	                           ens[level][no].bullx + 4, ens[level][no].bully + 0, ens[level][no].bullx + 8,
	                           ens[level][no].bully + 4, ens[level][no].bullx + 4, ens[level][no].bully + 3 },
	        { ens[level][no].bullx + 1, ens[level][no].bully + 2, ens[level][no].bullx + 4,
	            ens[level][no].bully + 0, ens[level][no].bullx + 8, ens[level][no].bully + 6,
	            ens[level][no].bullx + 5, ens[level][no].bully + 3 },
	        { ens[level][no].bullx + 0, ens[level][no].bully + 0, ens[level][no].bullx + 5,
	            ens[level][no].bully + 4, ens[level][no].bullx + 3, ens[level][no].bully + 8,
	            ens[level][no].bullx + 3, ens[level][no].bully + 4 },
	        { ens[level][no].bullx + 6, ens[level][no].bully + 0, ens[level][no].bullx + 4,
	            ens[level][no].bully + 5, ens[level][no].bullx + 0, ens[level][no].bully + 5,
	            ens[level][no].bullx + 3, ens[level][no].bully + 3 },
	        { ens[level][no].bullx + 7, ens[level][no].bully + 0, ens[level][no].bullx + 4,
	            ens[level][no].bully + 4, ens[level][no].bullx + 0, ens[level][no].bully + 1,
	            ens[level][no].bullx + 3, ens[level][no].bully + 3 },
	        { ens[level][no].bullx + 3, ens[level][no].bully + 0, ens[level][no].bullx + 0,
	            ens[level][no].bully + 4, ens[level][no].bullx + 3, ens[level][no].bully + 7,
	            ens[level][no].bullx + 2, ens[level][no].bully + 3 },
	        { ens[level][no].bullx + 7, ens[level][no].bully + 3, ens[level][no].bullx + 4,
	            ens[level][no].bully + 0, ens[level][no].bullx + 0, ens[level][no].bully + 5,
	            ens[level][no].bullx + 2, ens[level][no].bully + 2 } };
	    fillpoly(4, blaze[ens[level][no].blano]);
	    ens[level][no].firestat = 0;
	    int xa = getmaxx() - 110, ya = 10;
	    for (int i = 0; i < health; i++, xa += 6) {
	        setcolor(BLACK);
	        setfillstyle(1, BLACK);
	        bar(xa + 0, ya + 0, xa + 5, ya + 10);
	        bar(xa + 0, ya + 0, xa + 4, ya + 9);
	    }
	    xa = getmaxx() - 300, ya = 0;
	    health -= chhealth;
	    chhealth = 0;
	    if (health <= 0) {
	        life--;
	        health = 9;
	        heroclose(x, y);
	        excuse = 1;
	    }
	    ///////////////////HEALTH LOGO/////////////
	    for (i = 0, xa = getmaxx() - 110, ya = 10; i < health; i++, xa += 6) {
	        setcolor(WHITE);
	        setfillstyle(1, 9);
	        bar(xa + 0, ya + 0, xa + 5, ya + 10);
	        setfillstyle(1, 4);
	        bar(xa + 0, ya + 0, xa + 4, ya + 9);
	    }
	    setcolor(BLACK);
	}
	/////////////////////////////////////////////////
	void drawdoor(int a) //drawing the door
	{
	    if (a)
	        door[level] = a;
	    if (a == 1) {
	        setcolor(BLACK);
	        setfillstyle(1, YELLOW);
	        bar(0, getmaxy() - 60, 5, getmaxy());
	        setfillstyle(1, MAGENTA);
	        setcolor(MAGENTA);
	        fillellipse(3, getmaxy() - 35, 2, 3);
	    }
	    else if (a == 2) {
	        setcolor(BLACK);
	        setfillstyle(1, YELLOW);
	        bar(getmaxx() - 5, getmaxy() - 60, getmaxx(), getmaxy());
	        setfillstyle(1, MAGENTA);
	        setcolor(MAGENTA);
	        fillellipse(getmaxx() - 3, getmaxy() - 35, 2, 3);
	    }
	    else {
	        setcolor(BLACK);
	        setfillstyle(1, BLACK);
	        if (door[level] == 1) {
	            bar(0, getmaxy() - 60, 5, getmaxy());
	            fillellipse(1, getmaxy() - 30, 2, 4);
	        }
	        else {
	            bar(getmaxx() - 5, getmaxy() - 60, getmaxx(), getmaxy());
	            fillellipse(1, getmaxy() - 30, 2, 4);
	        }
	    }
	}
	/////////////////MOVING BARS/////////////////////////
	//////////////////////
	void thgmovbar(int x1, int y1, int breath, int height, int level, int no, int dir, int len, int speed)
	{
	    movbase[level][no].sx = x1;
	    movbase[level][no].sy = y1;
	    movbase[level][no].x1 = x1;
	    movbase[level][no].y1 = y1;
	    movbase[level][no].x2 = x1 + breath;
	    movbase[level][no].y2 = y1 + height;
	    movbase[level][no].dir = dir;
	    movbase[level][no].len = len;
	    movbase[level][no].speed = speed;
	    nomovbase[level]++;
	    bar(x1, y1, x1 + breath, y1 + height);
	    curmov = -1;
	}
	/////////////////////////////////////////////
	void thgthorn(int x, int y, int n)
	{
	    setcolor(BLACK);
	    setfillstyle(1, 8);
	    for (int i = 0; i < n; i++) {
	        int poly[] = { x + 0 + 8 * i, y + 10, x + 2 + 8 * i, y + 0, x + 4 + 8 * i, y + 10, x + 6 + 8 * i, y + 3, x + 8 + 8 * i, y + 10 };
	        fillpoly(5, poly);
	    }
	    thorn[level][nothorn[level]].x = x;
	    thorn[level][nothorn[level]].y = y;
	    thorn[level][nothorn[level]].n = n;
	    nothorn[level]++;
	}
	/////////////////////////////////////////////////////////////*
	//*                          START                           *
	void start()
	{ //initiallizing
	    for (int clr = 0; clr < 10; clr++)
	        for (int cl = 0; cl < 10; cl++) {
	            ens[clr][cl].scope = 0;
	            gems[clr][cl].scope = 0;
	            rubys[clr][cl].scope = 0;
	            ofnog[clr] = 0;
	            ofnor[clr] = 0;
	            ofnoe[clr] = 0;
	        }
	    load();
	    int x = 100, y = 300, wlkdir = 1, excnt = 0;
	    excuse = 1;
	    do {
	        cleardevice();
	        if (level == 1) {
	            stat = 0;
	            nothorn[level] = 0;
	            nobase[level] = 0;
	            curbase = 0;
	            plat(20, 250, 120, 10);
	            plat(200, 320, 100, 10);
	            plat(400, 350, 130, 15);
	            plat(300, 400, 100, 20);
	            plat(180, 170, 100, 10);
	            plat(320, 130, 100, 10);
	            plat(0, 33, getmaxx(), 5);
	            plat(0, getmaxy() - 10, getmaxx(), getmaxy());
	            drawgem(70, 235, level, 0, 1);
	            drawruby(370, 115, level, 0, 1);
	            drawdoor(2);
	            if (!tcont)
	                eltime = 50;
	            ofnoruby[stage] = 1;
	            ofnogem[stage] = 1;
	        }
	        if (level == 2) {
	            stat = 0;
	            nothorn[level] = 0;
	            nobase[level] = 0;
	            noruby[level] = 0;
	            nogem[level] = 0;
	            curbase = 0;
	            plat(300, 200, 100, 10);
	            plat(70, 280, 100, 10);
	            plat(300, 350, 130, 15);
	            plat(200, 400, 100, 20);
	            plat(400, 270, 100, 20);
	            plat(530, 190, 50, 10);
	            plat(0, 33, getmaxx(), 5);
	            plat(0, getmaxy() - 10, getmaxx(), getmaxy());
	            drawgem(120, 195, level, 0, 1);
	            thgenemy(540, 190 - height, 0, level, 0);
	            if (!tcont)
	                eltime = 50;
	            rpass[level] = 1;
	            ofnoene[stage] = 2;
	            ofnogem[stage] = 2;
	            ofnoruby[stage] = 0;
	        }
	        if (level == 3) {
	            stat = 0;
	            nothorn[level] = 0;
	            nobase[level] = 0;
	            nogem[level] = 0;
	            noruby[level] = 0;
	            curbase = 0;
	            plat(100, 100, 400, 10);
	            plat(400, 480, 100, 10);
	            plat(300, 350, 130, 15);
	            plat(200, 400, 100, 20);
	            plat(400, 270, 100, 20);
	            plat(530, 190, 50, 10);
	            plat(10, 300, 30, 10);
	            plat(0, 33, getmaxx(), 5);
	            plat(0, getmaxy() - 10, getmaxx(), getmaxy());
	            drawgem(120, 195, level, 0, 1);
	            drawgem(140, 215, level, 1, 1);
	            drawgem(160, 225, level, 2, 1);
	            drawgem(180, 235, level, 3, 1);
	            drawgem(200, 255, level, 4, 1);
	            drawgem(220, 275, level, 5, 1);
	            thgenemy(540, 190 - height, 0, level, 0);
	            thgenemy(20, 300 - height, 1, level, 1);
	            if (!tcont)
	                eltime = 50;
	            lpass[level] = 1;
	            drawdoor(2);
	            ofnoene[stage] = 2;
	            ofnogem[stage] = 7;
	            ofnoruby[stage] = 0;
	        }
	        if (level == 4) {
	            stat = 0;
	            nomovbase[level] = 0;
	            nothorn[level] = 0;
	            nobase[level] = 0;
	            nogem[level] = 0;
	            noruby[level] = 0;
	            curbase = 0;
	            thgmovbar(100, getmaxy() - 180, 100, 10, level, 0, 0, 100, 1);
	            thgmovbar(500, 200, 90, 10, level, 1, 1, 30, 2);
	            thgmovbar(300, 200, 50, 10, level, 2, 1, 70, 3);
	            plat(getmaxx() - 60, 250, 100, 10);
	            drawgem(400, 100, level, 0, 1);
	            thgthorn(100, getmaxy() - 20, 70);
	            plat(0, 33, getmaxx(), 5);
	            plat(0, getmaxy() - 10, getmaxx(), getmaxy());
	            if (!tcont)
	                eltime = 50;
	            rpass[level] = 1;
	            drawdoor(0);
	            ofnoene[stage] = 1;
	            ofnogem[stage] = 1;
	            ofnoruby[stage] = 1;
	        }
	        if (level == 5) {
	            stat = 0;
	            nomovbase[level] = 0;
	            nothorn[level] = 0;
	            nobase[level] = 0;
	            nogem[level] = 0;
	            noruby[level] = 0;
	            curbase = 0;
	            curmov = 0;
	            thgmovbar(150, getmaxy() - 200, 90, 10, level, 0, 0, 120, 2);
	            thgmovbar(330, getmaxy() - 150, 90, 10, level, 1, 1, 70, 2);
	            thgmovbar(500, getmaxy() - 220, 90, 10, level, 2, 0, 70, 2);
	            drawruby(350, getmaxy() - 165, level, 0, 1);
	            rubys[level][0].moveid = 1;
	            thgenemy(510, getmaxy() - 220 - height, 0, level, 0);
	            plat(0, 250, 100, 10);
	            ens[level][0].moveid = 2;
	            thgthorn(0, getmaxy() - 20, 67);
	            plat(0, 33, getmaxx(), 5);
	            plat(0, getmaxy() - 10, getmaxx(), getmaxy());
	            if (!tcont)
	                eltime = 50;
	            lpass[level] = 1;
	            drawdoor(2);
	            ofnoene[stage] = 1;
	            ofnogem[stage] = 1;
	            ofnoruby[stage] = 1;
	        }
	        if (level == 6) {
	            stat = 0;
	            nomovbase[level] = 0;
	            nothorn[level] = 0;
	            nobase[level] = 0;
	            nogem[level] = 0;
	            noruby[level] = 0;
	            curbase = 0;
	            curmov = 0;
	            thgmovbar(getmaxx() / 2 - 90, getmaxy() / 2 + 40, 200, 10, level, 0, 0, getmaxy() / 2 - 70, 3);
	            plat(0, 100, 120, 10);
	            thgenemy(20, 100 - height, 1, level, 0);
	            plat(0, 200, 150, 10);
	            thgenemy(20, 200 - height, 1, level, 1);
	            plat(0, 300, 160, 10);
	            thgenemy(20, 300 - height, 1, level, 2);
	            plat(getmaxx() - 120, 100, 120, 10);
	            thgenemy(getmaxx() - 30, 100 - height, 0, level, 3);
	            plat(getmaxx() - 150, 200, 150, 10);
	            thgenemy(getmaxx() - 50, 200 - height, 0, level, 4);
	            plat(getmaxx() - 160, 300, 160, 10);
	            thgenemy(getmaxx() - 60, 300 - height, 0, level, 5);
	            drawgem(75, getmaxy() - 295, level, 0, 1);
	            drawruby(90, getmaxy() - 195, level, 0, 1);
	            drawruby(getmaxx() - 75, getmaxy() - 295, level, 1, 1);
	            drawgem(getmaxx() - 90, getmaxy() - 195, level, 1, 1);
	            plat(0, 33, getmaxx(), 5); //
	            plat(0, getmaxy() - 10, getmaxx(), getmaxy()); //
	            if (!tcont)
	                eltime = 50;
	            rpass[level] = 0;
	            lpass[level] = 0;
	            drawdoor(2);
	            ofnoene[stage] = 6;
	            ofnogem[stage] = 2;
	            ofnoruby[stage] = 2;
	        }
	        if (level == 7) //7
	        {
	            stat = 0;
	            nomovbase[level] = 0;
	            nothorn[level] = 0;
	            nobase[level] = 0;
	            nogem[level] = 0;
	            noruby[level] = 0;
	            curbase = 0;
	            curmov = 0;
	            thgmovbar(300, getmaxy() / 2, 100, 10, level, 0, 1, 100, 2);
	            thgmovbar(200, getmaxy() / 2 + 100, 100, 10, level, 1, 1, 100, 1);
	            thgmovbar(450, getmaxy() / 2 + 130, 100, 10, level, 2, 0, 20, 1);
	            thgmovbar(30, getmaxy() / 2, 100, 10, level, 3, 0, 30, 1);
	            thgmovbar(500, getmaxy() / 2 - 50, 100, 10, level, 4, 0, 50, 1);
	            thgenemy(330, getmaxy() / 2 - height, 0, level, 0);
	            thgenemy(240, getmaxy() / 2 + 100 - height, 1, level, 1);
	            thgenemy(590, getmaxy() / 2 - 150 - height, 0, level, 2);
	            ens[level][0].moveid = 0;
	            ens[level][1].moveid = 1;
	            plat(540, getmaxy() / 2 - 150, getmaxx() - 540, 10);
	            plat(0, 33, getmaxx(), 5); //
	            plat(0, getmaxy() - 10, getmaxx(), getmaxy()); //
	            if (!tcont)
	                eltime = 50;
	            rpass[level] = 1;
	            ofnoene[stage] = 6;
	            ofnogem[stage] = 2;
	            ofnoruby[stage] = 2;
	        }
	        if (level == 8) //8
	        {
	            stat = 0;
	            nomovbase[level] = 0;
	            nothorn[level] = 0;
	            nobase[level] = 0;
	            nogem[level] = 0;
	            noruby[level] = 0;
	            curbase = 0;
	            curmov = 0;
	            thgmovbar(300, getmaxy() / 2 + 30, 100, 10, level, 0, 1, 120, 1);
	            thgmovbar(250, getmaxy() / 2 - 70, 100, 10, level, 1, 1, 40, 1);
	            thgmovbar(450, getmaxy() / 2 - 70, 100, 10, level, 2, 1, 40, 1);
	            thgenemy(260, getmaxy() / 2 - 70 - height, 1, level, 0);
	            thgenemy(460, getmaxy() / 2 - 70 - height, 0, level, 1);
	            drawruby(280, getmaxy() / 2 - 95, level, 0, 1);
	            drawruby(480, getmaxy() / 2 - 95, level, 1, 1);
	            drawgem(340, getmaxy() / 2 - 170, level, 0, 1);
	            rubys[level][0].moveid = 2;
	            rubys[level][1].moveid = 1;
	            ens[level][0].moveid = 2;
	            ens[level][1].moveid = 1;
	            plat(0, getmaxy() / 2 - 150, 140, 10);
	            plat(0, 33, getmaxx(), 5); //
	            plat(0, getmaxy() - 10, getmaxx(), getmaxy()); //
	            drawdoor(2);
	            if (!tcont)
	                eltime = 50;
	            lpass[level] = 1;
	            ofnoene[stage] = 5;
	            ofnogem[stage] = 2;
	            ofnoruby[stage] = 2;
	        }
	        char ch;
	        int jumpflag = 0, jumpcnt = 0, jumpup = 0, bulldir, b = 0, statchange = 1, bflag = 0;
	        hithero(level, 0, x, y);
	        //game loop
	        border();
	        do {
	            ctim = time(NULL);
	            if (statchange) //display the player name etc
	            {
	                setcolor(BLACK);
	                setfillstyle(1, BLACK);
	                bar(getmaxx() - 200, 10, getmaxx() - 190, 30);
	                bar(getmaxx() - 310, 10, getmaxx() - 260, 30);
	                char buf[20] = "Life : ";
	                buf[7] = life + 48;
	                buf[8] = '\0';
	                setcolor(WHITE);
	                settextstyle(1, 0, 1);
	                outtextxy(getmaxx() - 220, 10, buf);
	                outtextxy(getmaxx() - 145, 10, "Health");
	                outtextxy(getmaxx() - 330, 10, "Score");
	                sprintf(buf, "%d", score.score);
	                outtextxy(getmaxx() - 280, 10, buf);
	                int xa = getmaxx() - 110, ya = 10;
	                for (int i = 0; i < health; i++, xa += 6) {
	                    setcolor(BLACK);
	                    setfillstyle(1, BLACK);
	                    bar(xa + 0, ya + 0, xa + 5, ya + 10);
	                    bar(xa + 0, ya + 0, xa + 4, ya + 9);
	                }
	                health -= chhealth;
	                chhealth = 0;
	                if (health <= 0) {
	                    life--;
	                    health = 9;
	                    lifeup = 1;
	                    heroclose(x, y);
	                    excuse = 1;
	                    break;
	                }
	                ////////////////////////////////////////////////////////
	                /////////////////////////////////////////////////
	                for (i = 0, xa = getmaxx() - 110, ya = 10; i < health; i++, xa += 6) {
	                    setcolor(WHITE);
	                    setfillstyle(1, 9);
	                    bar(xa + 0, ya + 0, xa + 5, ya + 10);
	                    setfillstyle(1, 4);
	                    bar(xa + 0, ya + 0, xa + 4, ya + 9);
	                }
	                setfillstyle(1, BLACK);
	                setcolor(RED);
	                settextstyle(1, 0, 1);
	                bar(5, 5, getmaxx() - 400, 100);
	                if (ofnogem[stage] == ofnog[stage] && ofnoruby[stage] == ofnor[stage]) {
	                    setfillstyle(1, BLACK);
	                    setcolor(RED);
	                    settextstyle(1, 0, 1);
	                    bar(5, 5, getmaxx() - 400, 100);
	                    stat = 1;
	                    outtextxy(200, 20, "Level clear");
	                    drawdoor(0);
	                }
	                else {
	                    sprintf(buf, "level %d", stage + 1);
	                    outtextxy(200, 20, buf);
	                }
	                setcolor(BLACK);
	                setfillstyle(1, BLACK);
	                bar(10, 10, 100, 29);
	                setcolor(WHITE);
	                setfillstyle(1, WHITE);
	                settextstyle(1, 0, 1);
	                outtextxy(75, 15, score.name);
	                statchange = 0;
	            }
	            delay(20);
	            redrawplats();
	            ////when colliding
	            for (int t = 0; t < noene[level]; t++) {
	                if (!ens[level][t].stat)
	                    continue;
	                if (x + 20 > ens[level][t].x && x < ens[level][t].x + 20 && y > ens[level][t].y
	                    && y < ens[level][t].y + height) {
	                    life--;
	                    health = 9;
	                    statchange = 1;
	                    chhealth = 0;
	                    heroclose(x, y);
	                    enemyclose(level, t, x, y);
	                    excuse = 1;
	                    ens[level][t].stat = 0;
	                }
	            }
	            if (y > getmaxy()) {
	                erasehero(x, y, post, hdir);
	                heroclose(x, y);
	                excuse = 1;
	            } //hero out
	            if (excuse) {
	                if (excnt == 0) {
	                    erasehero(x, y, post, hdir);
	                    x = 10;
	                    y = getmaxy() - 100;
	                    post = 0;
	                    hdir = 1;
	                }
	                if (excnt % 5 == 0)
	                    erasehero(x, y, post, hdir);
	                if (excnt % 5 == 10)
	                    drawhero(x, y, post, hdir);
	                excnt++;
	                if (excnt > 2) {
	                    excuse = 0;
	                    excnt = 0;
	                }
	            }
	            //for moving gems,rubys,on mov base
	            for (t = 0; t < nogem[level]; t++) {
	                if (gems[level][t].moveid >= 0 && gems[level][t].flag) {
	                    if (movbase[level][gems[level][t].moveid].dir) {
	                        if (movbase[level][gems[level][t].moveid].curdir) {
	                            drawgem(gems[level][t].x, gems[level][t].y, level, t, 7);
	                            gems[level][t].x += movbase[level][t].speed;
	                            drawgem(gems[level][t].x, gems[level][t].y, level, t, 8);
	                        }
	                        else {
	                            drawgem(gems[level][t].x, gems[level][t].y, level, t, 7);
	                            gems[level][t].x -= movbase[level][t].speed;
	                            drawgem(gems[level][t].x, gems[level][t].y, level, t, 8);
	                        }
	                    }
	                    else if (movbase[level][gems[level][t].moveid].curdir) {
	                        drawgem(gems[level][t].x, gems[level][t].y, level, t, 7);
	                        gems[level][t].y += movbase[level][t].speed;
	                        drawgem(gems[level][t].x, gems[level][t].y, level, t, 8);
	                    }
	                    else {
	                        drawgem(gems[level][t].x, gems[level][t].y, level, t, 7);
	                        gems[level][t].y -= movbase[level][t].speed;
	                        drawgem(gems[level][t].x, gems[level][t].y, level, t, 8);
	                    }
	                }
	            }
	            for (t = 0; t < noruby[level]; t++) //moving ruby
	            {
	                if (rubys[level][t].moveid >= 0 && rubys[level][t].flag) {
	                    if (movbase[level][rubys[level][t].moveid].dir) {
	                        if (movbase[level][rubys[level][t].moveid].curdir) {
	                            drawruby(rubys[level][t].x, rubys[level][t].y, level, t, 7);
	                            rubys[level][t].x += movbase[level][t].speed;
	                            drawruby(rubys[level][t].x, rubys[level][t].y, level, t, 8);
	                        }
	                        else {
	                            drawruby(rubys[level][t].x, rubys[level][t].y, level, t, 7);
	                            rubys[level][t].x -= movbase[level][t].speed;
	                            drawruby(rubys[level][t].x, rubys[level][t].y, level, t, 8);
	                        }
	                    }
	                    else if (movbase[level][rubys[level][t].moveid].curdir) {
	                        drawruby(rubys[level][t].x, rubys[level][t].y, level, t, 7);
	                        rubys[level][t].y++;
	                        drawruby(rubys[level][t].x, rubys[level][t].y, level, t, 8);
	                    }
	                    else {
	                        drawruby(rubys[level][t].x, rubys[level][t].y, level, t, 7);
	                        rubys[level][t].y--;
	                        drawruby(rubys[level][t].x, rubys[level][t].y, level, t, 8);
	                    }
	                }
	            }
	            for (t = 0; t < noene[level]; t++) //moving enemy
	            {
	                if (ens[level][t].moveid >= 0 && ens[level][t].stat) {
	                    if (movbase[level][ens[level][t].moveid].dir) {
	                        if (movbase[level][ens[level][t].moveid].curdir) {
	                            erasehero(ens[level][t].x, ens[level][t].y, 9, ens[level][t].bulldir);
	                            ens[level][t].x += movbase[level][t].speed;
	                            drawene(ens[level][t].x, ens[level][t].y, ens[level][t].bulldir);
	                        }
	                        else {
	                            erasehero(ens[level][t].x, ens[level][t].y, 9, ens[level][t].bulldir);
	                            ens[level][t].x -= movbase[level][t].speed;
	                            drawene(ens[level][t].x, ens[level][t].y, ens[level][t].bulldir);
	                        }
	                    }
	                    else if (movbase[level][ens[level][t].moveid].curdir) {
	                        erasehero(ens[level][t].x, ens[level][t].y, 9, ens[level][t].bulldir);
	                        ens[level][t].y += movbase[level][t].speed;
	                        drawene(ens[level][t].x, ens[level][t].y, ens[level][t].bulldir);
	                    }
	                    else {
	                        erasehero(ens[level][t].x, ens[level][t].y, 9, ens[level][t].bulldir);
	                        ens[level][t].y -= movbase[level][t].speed;
	                        drawene(ens[level][t].x, ens[level][t].y, ens[level][t].bulldir);
	                    }
	                }
	            }
	            //for thorning the hero
	            for (t = 0; t < nothorn[level]; t++) {
	                if (x < thorn[level][t].x + thorn[level][t].n * 8 && x + 20 > thorn[level][t].x && thorn[level][t].y + 10 > y && thorn[level][t].y < y + height) {
	                    if (wlkdir) {
	                        erasehero(x, y, post, hdir);
	                        x -= 5;
	                        drawhero(x, y, post, hdir);
	                    }
	                    else {
	                        erasehero(x, y, post, hdir);
	                        x += 5;
	                        drawhero(x, y, post, hdir);
	                    }
	                    chhealth = 1;
	                    statchange = 1;
	                }
	            }
	            //for moving the mov base
	            for (t = 0; t < nomovbase[level]; t++) {
	                if (movbase[level][t].dir) {
	                    setcolor(BLACK);
	                    setfillstyle(1, BLACK);
	                    bar(movbase[level][t].x1, movbase[level][t].y1, movbase[level][t].x2,
	                        movbase[level][t].y2);
	                    if (movbase[level][t].curdir) {
	                        movbase[level][t].x1 += movbase[level][t].speed;
	                        movbase[level][t].x2 += movbase[level][t].speed;
	                        if (movbase[level][t].x1 - movbase[level][t].sx >= movbase[level][t].len)
	                            movbase[level][t].curdir = 0;
	                    }
	                    else {
	                        movbase[level][t].x1 -= movbase[level][t].speed;
	                        movbase[level][t].x2 -= movbase[level][t].speed;
	                        if (movbase[level][t].sx - movbase[level][t].x1 >= movbase[level][t].len)
	                            movbase[level][t].curdir = 1;
	                    }
	                    setcolor(BLACK);
	                    setfillstyle(1, BROWN);
	                    bar(movbase[level][t].x1, movbase[level][t].y1, movbase[level][t].x2,
	                        movbase[level][t].y2);
	                }
	                else {
	                    setcolor(BLACK);
	                    setfillstyle(1, BLACK);
	                    bar(movbase[level][t].x1, movbase[level][t].y1, movbase[level][t].x2,
	                        movbase[level][t].y2);
	                    if (movbase[level][t].curdir) {
	                        movbase[level][t].y1 += movbase[level][t].speed;
	                        movbase[level][t].y2 += movbase[level][t].speed;
	                        if (movbase[level][t].y1 - movbase[level][t].sy >= movbase[level][t].len)
	                            movbase[level][t].curdir = 0;
	                    }
	                    else {
	                        movbase[level][t].y1 -= movbase[level][t].speed;
	                        movbase[level][t].y2 -= movbase[level][t].speed;
	                        if (movbase[level][t].sy - movbase[level][t].y1 >= movbase[level][t].len)
	                            movbase[level][t].curdir = 1;
	                    }
	                    setcolor(BLACK);
	                    setfillstyle(1, BROWN);
	                    bar(movbase[level][t].x1, movbase[level][t].y1, movbase[level][t].x2,
	                        movbase[level][t].y2);
	                }
	            }
	            //for moving the the hero on mov base
	            if (curmov >= 0) //making hero to fall when he oversteps
	            {
	                if (x > movbase[level][curmov].x2 || x + 20 < movbase[level][curmov].x1) {
	                    jumpflag = 1;
	                    jumpup = 0;
	                    curmov = -1;
	                }
	                if (movbase[level][curmov].dir) //moving
	                {
	                    erasehero(x, y, post, hdir);
	                    if (movbase[level][curmov].curdir)
	                        x += movbase[level][curmov].speed;
	                    else
	                        x -= movbase[level][curmov].speed;
	                    drawhero(x, y, post, hdir);
	                }
	                else {
	                    erasehero(x, y, post, hdir);
	                    if (movbase[level][curmov].curdir)
	                        y += movbase[level][curmov].speed;
	                    else
	                        y -= movbase[level][curmov].speed;
	                    drawhero(x, y, post, hdir);
	                }
	            }
	            //for hero taking the ruby and gems
	            for (t = 0; t < nogem[level]; t++) {
	                if (gems[level][t].flag)
	                    if (x > gems[level][t].x - 20 && x < gems[level][t].x + 20 && gems[level][t].y < y + height
	                        && gems[level][t].y + 5 > y) {
	                        drawgem(gems[level][t].x, gems[level][t].y, level, t, 0);
	                        statchange = 1;
	                        score.score += 50;
	                    }
	            }
	            for (t = 0; t < noruby[level]; t++) {
	                if (rubys[level][t].flag)
	                    if (x > rubys[level][t].x - 20 && x < rubys[level][t].x + 20 && rubys[level][t].y < y + height && rubys[level][t].y > y) {
	                        drawruby(rubys[level][t].x, rubys[level][t].y, level, t, 0);
	                        statchange = 1;
	                        score.score += 100;
	                    }
	            }
	            //for detecting hero by the enemy
	            for (t = 0; t < noene[level]; t++) {
	                if (!ens[level][t].stat)
	                    continue;
	                if (y < ens[level][t].y + height + 20 && y > ens[level][t].y - 20) //vertically near
	                { ///////change dir of ene
	                    if (x < ens[level][t].x && ens[level][t].bulldir || x > ens[level][t].x && !ens[level][t].bulldir) {
	                        erasehero(ens[level][t].x, ens[level][t].y, 9, ens[level][t].bulldir);
	                        ens[level][t].bulldir = !ens[level][t].bulldir;
	                        drawene(ens[level][t].x, ens[level][t].y, ens[level][t].bulldir);
	                    }
	                    ///////fire
	                    if (!ens[level][t].firestat) {
	                        ens[level][t].bully = ens[level][t].y + height / 2;
	                        ens[level][t].bullx = ens[level][t].x;
	                        if (x < ens[level][t].x)
	                            ens[level][t].bullfired = 0;
	                        else
	                            ens[level][t].bullfired = 1;
	                    }
	                    ens[level][t].firestat = 1;
	                }
	            } //end of dor
	            //for firing bullet of the hero
	            if (firestat) {
	                {
	                    int blaz[][8] = { { bullx + 0, bully + 4, bullx + 4, bully + 0, bullx + 8, bully + 4,
	                                          bullx + 4, bully + 3 },
	                        { bullx + 1, bully + 2, bullx + 4, bully + 0, bullx + 8, bully + 6,
	                            bullx + 5, bully + 3 },
	                        { bullx + 0, bully + 0, bullx + 5, bully + 4, bullx + 3, bully + 8,
	                            bullx + 3, bully + 4 },
	                        { bullx + 6, bully + 0, bullx + 4, bully + 5, bullx + 0, bully + 5,
	                            bullx + 3, bully + 3 },
	                        { bullx + 7, bully + 0, bullx + 4, bully + 4, bullx + 0, bully + 1,
	                            bullx + 3, bully + 3 },
	                        { bullx + 3, bully + 0, bullx + 0, bully + 4, bullx + 3, bully + 7,
	                            bullx + 2, bully + 3 },
	                        { bullx + 7, bully + 3, bullx + 4, bully + 0, bullx + 0, bully + 5,
	                            bullx + 2, bully + 2 } };
	                    setcolor(BLACK);
	                    setfillstyle(1, BLACK);
	                    fillpoly(4, blaz[blano]);
	                }
	                if (bulldir)
	                    bullx += 8;
	                else
	                    bullx -= 8;
	                setfillstyle(1, WHITE);
	                blano++;
	                if (blano == 6)
	                    blano = 0;
	                {
	                    int blaz[][8] = { { bullx + 0, bully + 4, bullx + 4, bully + 0, bullx + 8, bully + 4,
	                                          bullx + 4, bully + 3 },
	                        { bullx + 1, bully + 2, bullx + 4, bully + 0, bullx + 8, bully + 6,
	                            bullx + 5, bully + 3 },
	                        { bullx + 0, bully + 0, bullx + 5, bully + 4, bullx + 3, bully + 8,
	                            bullx + 3, bully + 4 },
	                        { bullx + 6, bully + 0, bullx + 4, bully + 5, bullx + 0, bully + 5,
	                            bullx + 3, bully + 3 },
	                        { bullx + 7, bully + 0, bullx + 4, bully + 4, bullx + 0, bully + 1,
	                            bullx + 3, bully + 3 },
	                        { bullx + 3, bully + 0, bullx + 0, bully + 4, bullx + 3, bully + 7,
	                            bullx + 2, bully + 3 },
	                        { bullx + 7, bully + 3, bullx + 4, bully + 0, bullx + 0, bully + 5,
	                            bullx + 2, bully + 2 } };
	                    fillpoly(4, blaz[blano]);
	                }
	                if (bullx > getmaxx() + 3 || bullx < -3)
	                    firestat = 0;
	                //if d bullet hits d enemy
	                for (t = 0; t < noene[level]; t++) {
	                    if (!ens[level][t].stat)
	                        continue;
	                    if (bullx > ens[level][t].x && bullx < ens[level][t].x + 20
	                        && bully > ens[level][t].y && bully < ens[level][t].y + height) {
	                        enemyclose(level, t, x, y);
	                        statchange = 1;
	                    }
	                }
	            }
	            //Checking the landing plat
	            if (jumpflag) {
	                for (int t = 0; t < nobase[level]; t++) {
	                    if (jumpup) //when d hero hits his head in the plat
	                        if (y - 3 < base[level][t].y2 && y + 3 > base[level][t].y2
	                            && x + 10 > base[level][t].x1 && x + 12 < base[level][t].x2)
	                            jumpup = 0;
	                    if (y + height < base[level][t].y1 + 3 && y + height > base[level][t].y1 - 3
	                        && x + 10 > base[level][t].x1 && x + 3 < base[level][t].x2 && !jumpup) //landed on base
	                    {
	                        jumpflag = 0;
	                        curbase = t;
	                    }
	                }
	                for (t = 0; t < nomovbase[level]; t++) //checkingif hero lands onthe moving base
	                {
	                    if (jumpup) //when d hero hits his head in the plat
	                        if (y - 3 < movbase[level][t].y2 && y + 3 > movbase[level][t].y2
	                            && x + 10 > movbase[level][t].x1 && x + 12 < movbase[level][t].x2)
	                            jumpup = 0;
	                    if (y + height < movbase[level][t].y1 + 7 && y + height > movbase[level][t].y1 - 7
	                        && x + 10 > movbase[level][t].x1 && x + 3 < movbase[level][t].x2 && !jumpup) { //landed onbase
	                        jumpflag = 0;
	                        curbase = -1;
	                        curmov = t;
	                    }
	                }
	            }
	            else if (x + 12 < base[level][curbase].x1 || x + 4 > base[level][curbase].x2 && curbase >= 0) //when d hero steps out of d plat
	            {
	                jumpflag = 1;
	                jumpup = 0;
	                if (curmov >= 0)
	                    curmov = -1;
	            }
	            //for firing bullet of d enemy
	            for (t = 0; t < noene[level]; t++) {
	                if (!ens[level][t].stat)
	                    continue;
	                if (ens[level][t].firestat) {
	                    setcolor(BLACK);
	                    setfillstyle(1, BLACK);
	                    {
	                        int blaze[][8] = { { ens[level][t].bullx + 0, ens[level][t].bully + 4,
	                                               ens[level][t].bullx + 4, ens[level][t].bully + 0, ens[level][t].bullx + 8,
	                                               ens[level][t].bully + 4, ens[level][t].bullx + 4, ens[level][t].bully + 3 },
	                            { ens[level][t].bullx + 1, ens[level][t].bully + 2, ens[level][t].bullx + 4,
	                                ens[level][t].bully + 0, ens[level][t].bullx + 8, ens[level][t].bully + 6,
	                                ens[level][t].bullx + 5, ens[level][t].bully + 3 },
	                            { ens[level][t].bullx + 0,
	                                ens[level][t].bully + 0, ens[level][t].bullx + 5, ens[level][t].bully + 4,
	                                ens[level][t].bullx + 3, ens[level][t].bully + 8, ens[level][t].bullx + 3,
	                                ens[level][t].bully + 4 },
	                            { ens[level][t].bullx + 6, ens[level][t].bully + 0,
	                                ens[level][t].bullx + 4, ens[level][t].bully + 5, ens[level][t].bullx + 0,
	                                ens[level][t].bully + 5, ens[level][t].bullx + 3, ens[level][t].bully + 3 },
	                            { ens[level][t].bullx + 7, ens[level][t].bully + 0, ens[level][t].bullx + 4,
	                                ens[level][t].bully + 4, ens[level][t].bullx + 0, ens[level][t].bully + 1,
	                                ens[level][t].bullx + 3, ens[level][t].bully + 3 },
	                            { ens[level][t].bullx + 3,
	                                ens[level][t].bully + 0, ens[level][t].bullx + 0, ens[level][t].bully + 4,
	                                ens[level][t].bullx + 3, ens[level][t].bully + 7, ens[level][t].bullx + 2,
	                                ens[level][t].bully + 3 },
	                            { ens[level][t].bullx + 7, ens[level][t].bully + 3,
	                                ens[level][t].bullx + 4, ens[level][t].bully + 0, ens[level][t].bullx + 0,
	                                ens[level][t].bully + 5, ens[level][t].bullx + 2, ens[level][t].bully + 2 } };
	                        fillpoly(4, blaze[ens[level][t].blano]);
	                    }
	                    if (ens[level][t].bullfired)
	                        ens[level][t].bullx += 8;
	                    else
	                        ens[level][t].bullx -= 8;
	                    setfillstyle(1, 8);
	                    ens[level][t].blano++;
	                    if (ens[level][t].blano == 6)
	                        ens[level][t].blano = 0;
	                    {
	                        int blaze[][8] = { { ens[level][t].bullx + 0, ens[level][t].bully + 4,
	                                               ens[level][t].bullx + 4, ens[level][t].bully + 0, ens[level][t].bullx + 8,
	                                               ens[level][t].bully + 4, ens[level][t].bullx + 4, ens[level][t].bully + 3 },
	                            { ens[level][t].bullx + 1, ens[level][t].bully + 2, ens[level][t].bullx + 4,
	                                ens[level][t].bully + 0, ens[level][t].bullx + 8, ens[level][t].bully + 6,
	                                ens[level][t].bullx + 5, ens[level][t].bully + 3 },
	                            { ens[level][t].bullx + 0, ens[level][t].bully + 0,
	                                ens[level][t].bullx + 5, ens[level][t].bully + 4, ens[level][t].bullx + 3,
	                                ens[level][t].bully + 8, ens[level][t].bullx + 3, ens[level][t].bully + 4 },
	                            { ens[level][t].bullx + 6, ens[level][t].bully + 0, ens[level][t].bullx + 4,
	                                ens[level][t].bully + 5, ens[level][t].bullx + 0, ens[level][t].bully + 5,
	                                ens[level][t].bullx + 3, ens[level][t].bully + 3 },
	                            { ens[level][t].bullx + 7, ens[level][t].bully + 0, ens[level][t].bullx + 4,
	                                ens[level][t].bully + 4, ens[level][t].bullx + 0, ens[level][t].bully + 1,
	                                ens[level][t].bullx + 3, ens[level][t].bully + 3 },
	                            { ens[level][t].bullx + 3, ens[level][t].bully + 0, ens[level][t].bullx + 0,
	                                ens[level][t].bully + 4, ens[level][t].bullx + 3, ens[level][t].bully + 7,
	                                ens[level][t].bullx + 2, ens[level][t].bully + 3 },
	                            { ens[level][t].bullx + 7, ens[level][t].bully + 3, ens[level][t].bullx + 4,
	                                ens[level][t].bully + 0, ens[level][t].bullx + 0, ens[level][t].bully + 5,
	                                ens[level][t].bullx + 2, ens[level][t].bully + 2 } };
	                        fillpoly(4, blaze[ens[level][t].blano]);
	                    }
	                    if (ens[level][t].bullx > getmaxx() + 3 || ens[level][t].bullx < 0)
	                        ens[level][t].firestat = 0;
	                    //if d bullet hits the hero
	                    if (ens[level][t].bullx > x && ens[level][t].bullx < x + 20
	                        && ens[level][t].bully > y && ens[level][t].bully < y + height) {
	                        jumpflag = 1;
	                        jumpup = 1;
	                        erasehero(x, y, post, hdir);
	                        y -= 20;
	                        if (x > ens[level][t].x) {
	                            hdir = 1;
	                            wlkdir = 1;
	                        }
	                        else {
	                            hdir = 0;
	                            wlkdir = 0;
	                        }
	                        drawhero(x, y, post, hdir);
	                        chhealth = 4;
	                        statchange = 1;
	                        hithero(level, t, x, y);
	                        statchange = 1;
	                    }
	                }
	            }
	            //////////////////////////////////////////////////////////
	            /////////////////  J   U   M  P
	            //JUMPING///////              J  U   M   P
	            ////////////////                         J   U   M   P
	            ///////////////////////////////////////////////////////////
	            if (jumpflag) {
	                if (lpass[level] && x < 3) {
	                    throughl = 1;
	                    break;
	                }
	                if (rpass[level] && x + 30 > getmaxx()) {
	                    throughr = 1;
	                    break;
	                }
	                erasehero(x, y, post, hdir);
	                if (!lpass[level] && x < 3) {
	                    wlkdir = 1;
	                    hdir = 1;
	                }
	                if (!rpass[level] && x + 30 > getmaxx()) {
	                    wlkdir = 0;
	                    hdir = 0;
	                }
	                setcolor(BLACK);
	                jumpcnt++;
	                if (jumpcnt > 20)
	                    jumpup = 0;
	                if (jumpup) {
	                    y -= 5;
	                    if (wlkdir)
	                        x += 3;
	                    else
	                        x -= 3;
	                    drawhero(x, y, post, hdir);
	                }
	                else {
	                    y += 5;
	                    if (wlkdir)
	                        x += 3;
	                    else
	                        x -= 3;
	                    drawhero(x, y, post, hdir);
	                }
	            }
	            if (kbhit() && !excuse) {
	                ch = getch();
	                if (ch == keys.shoot && !firestat) {
	                    firestat = 1;
	                    bulldir = hdir;
	                    bully = y + height / 2;
	                    if (hdir)
	                        bullx = x + 20;
	                    else
	                        bullx = x;
	                }
	                if (ch == 27) {
	                    if (quit()) {
	                        bflag = 1;
	                        level = 1;
	                        stage = 0;
	                        tcont = 0;
	                        gameloaded = 0;
	                        score.score = 0;
	                        return;
	                    }
	                    setcolor(BLACK);
	                    setfillstyle(1, BLACK);
	                    bar(getmaxx() / 2 - 120, getmaxy() / 2 - 50, getmaxx() / 2 + 120, getmaxy() / 2 + 50);
	                }
	                if (ch == keys.left) //LEFT
	                {
	                    if (door[level] == 1 && x <= 3 && y > getmaxy() - 70) {
	                        if (stat) {
	                            b = 1;
	                            throughdoor = 1;
	                            y = getmaxy() - 100;
	                            break;
	                        }
	                        else
	                            continue;
	                    }
	                    if (!lpass[level] && x <= 10)
	                        continue;
	                    else if (x < 3 && lpass[level]) {
	                        b = 1;
	                        throughl = 1;
	                    }
	                    if (hdir) //if the hero turns back
	                        erasehero(x, y, post, hdir);
	                    hdir = 0;
	                    wlkdir = 0;
	                    if (!jumpflag) {
	                        erasehero(x, y, post, hdir);
	                        x -= 10;
	                        post += 1;
	                        drawhero(x, y, post, hdir);
	                    }
	                }
	                if (ch == keys.right) //RIGHT
	                {
	                    if (door[level] == 2 && x + 25 > getmaxx() && y > getmaxy() - 70) {
	                        if (stat) {
	                            b = 1;
	                            throughdoor = 1;
	                            y = getmaxy() - 100;
	                            break;
	                        }
	                        else
	                            continue;
	                    }
	                    if (x + 25 > getmaxx() && !rpass[level])
	                        continue;
	                    else if (x + 25 > getmaxx() && rpass[level]) {
	                        b = 1;
	                        throughr = 1;
	                    }
	                    if (hdir == 0) //if the hero turns back
	                        erasehero(x, y, post, hdir);
	                    hdir = 1;
	                    wlkdir = 1;
	                    if (!jumpflag) {
	                        erasehero(x, y, post, hdir);
	                        x += 10;
	                        post += 1;
	                        drawhero(x, y, post, hdir);
	                    }
	                }
	                if (ch == keys.up) //UP
	                {
	                    if (!lpass[level] && x < 3)
	                        continue;
	                    if (!rpass[level] && x + 25 > getmaxx())
	                        continue;
	                    if (!jumpflag) {
	                        curmov = -1;
	                        jumpcnt = 0;
	                        jumpflag = 1;
	                        jumpup = 1;
	                    }
	                }
	            }
	            if (b) {
	                b = 0;
	                break;
	            }
	            if (difftime(ctim, otim) >= 1) {
	                eltime--;
	                setcolor(RED);
	                otim = ctim;
	                sprintf(curtime, "%d", eltime);
	                setcolor(BLACK);
	                setfillstyle(1, BLACK);
	                bar(getmaxx() - 10, 10, getmaxx() - 50, 30);
	                setcolor(WHITE);
	                outtextxy(getmaxx() - 20, 15, curtime);
	                if (eltime <= 0 || life == 0)
	                    if (gameover(1)) {
	                        life = 3;
	                        bflag = 0;
	                        level = 1;
	                        stage = 0;
	                        y = getmaxy() - 100;
	                        x = 100;
	                        tcont = 0;
	                        for (int clr = 0; clr < 10; clr++)
	                            for (int cl = 0; cl < 10; cl++) {
	                                ens[clr][cl].scope = 0;
	                                gems[clr][cl].scope = 0;
	                                rubys[clr][cl].scope = 0;
	                                ofnog[clr] = 0;
	                                ofnor[clr] = 0;
	                                ofnoe[clr] = 0;
	                            }
	                        break;
	                    }
	                    else {
	                        life = 3;
	                        bflag = 1;
	                        level = 1;
	                        stage = 0;
	                        tcont = 0;
	                        break;
	                    }
	            }
	        } while (1);
	        if (bflag) {
	            tcont = 0;
	            return;
	        }
	        if (throughdoor) {
	            level++;
	            x = 20;
	            y = getmaxy() - 100;
	            stat = 0;
	            success(stage);
	            stage++;
	            tcont = 0;
	            save();
	            load();
	        }
	        else if (throughr) {
	            level++;
	            x = 20;
	            y -= 10;
	            tcont = 1;
	        }
	        else if (throughl) {
	            y -= 10;
	            level--;
	            x = getmaxx() - 50;
	            tcont = 1;
	        }
	        throughr = 0;
	        throughl = 0;
	        throughdoor = 0;
	    } while (1);
	}
	///////////////////////////////////////////////////////////
	void drawborder(int y, int stat) //for higliting d controlz
	{
	    y -= 5;
	    int x = getmaxx() / 2 - 100;
	    char pa[] = { 0x3a, 0xb456 };
	    if (stat)
	        setfillpattern(pa, 8);
	    else
	        setfillstyle(1, 0);
	    bar(x, y, x + 200, y + 3);
	    bar(x, y, x + 2, y + 30);
	    bar(x, y + 30, x + 200, y + 28);
	    bar(x + 200, y, x + 198, y + 28);
	}
	///////////////////////////////////////////////////////////////
	void name()
	{
	    cleardevice();
	    border();
	    outtextxy(getmaxx() / 2, 200, "Enter your name...");
	    char key, name[100] = "";
	    int i = 0, x = getmaxx() / 2 - 100, y = 300;
	    setfillstyle(1, WHITE);
	    setcolor(WHITE);
	    while (1) {
	        key = getch();
	        if (key == 8 && i > 0) {
	            setcolor(BLACK);
	            setfillstyle(1, BLACK);
	            bar(x - 30, y - 30, x, y + 30);
	            x -= 20;
	            setcolor(WHITE);
	            setfillstyle(1, WHITE);
	        }
	        char buf[3];
	        buf[0] = key;
	        buf[1] = '\0';
	        if (key != 8 && i >= 0) {
	            outtextxy(x, y, buf);
	            x += 20;
	        }
	        if (isalnum(key)) {
	            name[i] = key;
	            name[i + 1] = '\0';
	            i++;
	        }
	        else if (key == 13)
	            break;
	        if (key == 8 && i > 0)
	            i--;
	    }
	    strcpy(score.name, name);
	    score.name[0] = toupper(score.name[0]);
	    score.name[14] = '\0';
	}
	////////////////////////////////////////
	void control()
	{
	    cleardevice();
	    border();
	    settextstyle(1, 0, 4);
	    setcolor(WHITE);
	    thgtxt(130, 80, "CONTROLLER SETTINGS");
	    delay(500);
	    thgtxt(100, 156, "Left  : ");
	    thgtxt(100, 206, "Right : ");
	    thgtxt(100, 256, "Jump  : ");
	    thgtxt(100, 306, "Shoot : ");
	    settextstyle(1, 0, 1);
	    setcolor(GREEN);
	    thgtxt(300, 330, "Reset");
	    thgtxt(300, 380, "Done");
	    setcolor(WHITE);
	    char* buf;
	    if (controllval(keys.shoot))
	        buf = controllval(keys.shoot);
	    else {
	        buf[0] = keys.shoot;
	        buf[1] = '\0';
	    }
	    outtextxy(getmaxx() / 2, 255, buf);
	    if (controllval(keys.left))
	        buf = controllval(keys.left);
	    else {
	        buf[0] = keys.left;
	        buf[1] = '\0';
	    }
	    outtextxy(getmaxx() / 2, 105, buf);
	    if (controllval(keys.right))
	        buf = controllval(keys.right);
	    else {
	        buf[0] = keys.right;
	        buf[1] = '\0';
	    }
	    outtextxy(getmaxx() / 2, 155, buf);
	    if (controllval(keys.up))
	        buf = controllval(keys.up);
	    else {
	        buf[0] = keys.up;
	        buf[1] = '\0';
	    }
	    outtextxy(getmaxx() / 2, 205, buf);
	    thgtxt(350, 450, "Press enter to change...");
	    char key, chkey;
	    int y = 100;
	    drawborder(y, 1);
	    while (1) {
	        key = getch();
	        if (key == 80) //if down
	        {
	            drawborder(y, 0);
	            if (y == 350)
	                y = 100;
	            else
	                y += 50;
	            drawborder(y, 1);
	        }
	        if (key == 72) //if up
	        {
	            drawborder(y, 0);
	            if (y == 100)
	                y = 350;
	            else
	                y -= 50;
	            drawborder(y, 1);
	        }
	        if (key == 13) {
	            if (y == 300) {
	                keys.reset();
	                setfillstyle(1, 0);
	                bar(getmaxx() / 2 - 100, 90, getmaxx() / 2 + 100, 280);
	                outtextxy(getmaxx() / 2, 255, "Space");
	                outtextxy(getmaxx() / 2, 105, "Left Key");
	                outtextxy(getmaxx() / 2, 155, "Right Key");
	                outtextxy(getmaxx() / 2, 205, "Up Key");
	                continue;
	            }
	            else if (y == 350)
	                break;
	        error:
	            setfillstyle(1, 0);
	            bar(getmaxx() / 2 - 96, y, getmaxx() / 2 + 96, y + 20);
	            outtextxy(getmaxx() / 2, y + 5, "Press any Key");
	            chkey = getch();
	            if (isalnum(chkey) == 0 && chkey != 9 && chkey != 13 && chkey != ' ' && chkey != 8)
	                chkey = getch();
	            if (y == 100)
	                keys.left = chkey;
	            else if (y == 150)
	                keys.right = chkey;
	            else if (y == 200)
	                keys.up = chkey;
	            else if (y == 250)
	                keys.shoot = chkey;
	            char buf[10];
	            if (isalnum(chkey)) {
	                buf[0] = chkey;
	                buf[1] = '\0';
	            }
	            if (chkey == 13)
	                strcpy(buf, "Enter");
	            else if (chkey == ' ')
	                strcpy(buf, "Space");
	            else if (chkey == 9)
	                strcpy(buf, "Tab");
	            else if (chkey == 8)
	                strcpy(buf, "Backspace");
	            else if (chkey == 80)
	                strcpy(buf, "Down key");
	            else if (chkey == 72)
	                strcpy(buf, "Up key");
	            else if (chkey == 75)
	                strcpy(buf, "Left key");
	            else if (chkey == 77)
	                strcpy(buf, "Right key");
	            setfillstyle(1, 0);
	            bar(getmaxx() / 2 - 96, y, getmaxx() / 2 + 96, y + 20);
	            outtextxy(getmaxx() / 2, y + 5, buf);
	            if (keys.left == chkey) {
	                if (y != 100) {
	                    drawborder(y, 0);
	                    y = 100;
	                    drawborder(y, 1);
	                    goto error;
	                }
	            }
	            if (keys.right == chkey) {
	                if (y != 150) {
	                    drawborder(y, 0);
	                    y = 150;
	                    drawborder(y, 1);
	                    goto error;
	                }
	            }
	            if (keys.up == chkey) {
	                if (y != 200) {
	                    drawborder(y, 0);
	                    y = 200;
	                    drawborder(y, 1);
	                    goto error;
	                }
	            }
	            if (keys.shoot == chkey) {
	                if (y != 250) {
	                    drawborder(y, 0);
	                    y = 250;
	                    drawborder(y, 1);
	                    goto error;
	                }
	            }
	        }
	    }
	}
	void password()
	{
	    cleardevice();
	    border();
	    thgtxt(170, 80, "PASSWORD");
	    delay(400);
	    outtextxy(getmaxx() / 2, 200, "Enter the password...");
	    char key, in[100] = "";
	    int i = 0, x = getmaxx() / 2 - 100, y = 300;
	    setfillstyle(1, WHITE);
	    setcolor(WHITE);
	    while (1) {
	        key = getch();
	        if (key == 8 && i > 0) {
	            setcolor(BLACK);
	            setfillstyle(1, BLACK);
	            bar(x - 20, y - 10, x, y + 10);
	            x -= 15;
	            setcolor(WHITE);
	            setfillstyle(1, WHITE);
	        }
	        if (key != 8 && i >= 0) {
	            outtextxy(x, y, "*");
	            x += 15;
	        }
	        if (isalnum(key)) {
	            in[i] = key;
	            in[i + 1] = '\0';
	            i++;
	        }
	        else if (key == 13)
	            break;
	        if (key == 8 && i > 0)
	            i--;
	    }
	    if (strcmpi(in, "one") == 0) {
	        stage = 0;
	        level = 1;
	        outtextxy(210, 350, "Password OK");
	        getch();
	    }
	    else if (strcmpi(in, "two") == 0) {
	        stage = 1;
	        level = 2;
	        outtextxy(210, 350, "Password OK");
	        getch();
	    }
	    else if (strcmpi(in, "three") == 0) {
	        stage = 3;
	        level = 4;
	        outtextxy(210, 350, "Password OK");
	        getch();
	    }
	    else if (strcmpi(in, "four") == 0) {
	        stage = 4;
	        level = 6;
	        outtextxy(210, 350, "Password OK");
	        getch();
	    }
	    else if (strcmpi(in, "five") == 0) {
	        stage = 5;
	        level = 7;
	        outtextxy(210, 350, "Password OK");
	        getch();
	    }
	    else
	        outtextxy(210, 350, "Wrong Password");
	    getch();
	}
	void success(int a)
	{
	    cleardevice();
	    border();
	    settextstyle(1, 0, 4);
	    setcolor(WHITE);
	    outtextxy(getmaxx() / 2, getmaxy() / 2, "CONGRATULATIONS");
	    setcolor(WHITE);
	    char buf[50] = "YOU HAVE SUCCESSFULLY COMPLETED LEVEL ";
	    buf[38] = a + 49;
	    buf[39] = '\0';
	    settextstyle(1, 0, 2);
	    if (stage == 5)
	        outtextxy(getmaxx() / 2, getmaxy() / 2 + 100, "YOU WON THE GAME");
	    else
	        outtextxy(getmaxx() / 2, getmaxy() / 2 + 100, buf);
	    delay(2000);
	    cleardevice();
	}
	void highscore()
	{
	    cleardevice();
	    border();
	    settextstyle(1, 0, 4);
	    settextstyle(1, 0, 4);
	    ifstream fin(filedir, ios::binary);
	    thg_score tmp[7], t;
	    int i = 0;
	    if (!fin) {
	        outtextxy(200, 200, "File NOT found!!");
	        getch();
	        fin.close();
	        return;
	    }
	    while (fin.read((char*)&tmp[i], sizeof(tmp[0]))) {
	        i++;
	        if (i >= 7)
	            break;
	    }
	    for (int k = 0; k < i - 1; k++)
	        for (int j = 0; j < i - k - 1; j++)
	            if (tmp[j].score < tmp[j + 1].score) {
	                t = tmp[j];
	                tmp[j] = tmp[j + 1];
	                tmp[j + 1] = t;
	            }
	    thgtxt(170, 100, "HIGH SCORES");
	    setcolor(WHITE);
	    thgtxt(100, 200, "NINJA");
	    thgtxt(400, 200, "SCORE");
	    int y = 210;
	    setcolor(7);
	    for (k = 0; k < i; k++) {
	        thgtxt(100, y += 35, tmp[k].name);
	        char buff[5];
	        sprintf(buff, "%i", tmp[k].score);
	        thgtxt(400, y, buff);
	    }
	    fin.close();
	    getch();
	    cleardevice();
	}
	//////////////////////////////////////////////////////////////
	///////////////HELP////////////////////////////////////////////
	void help()
	{
	    cleardevice();
	    border();
	    char a[20][100] = { "HELP", "Collect all the items present in each level ",
	        "to proceed to the next level", "kill all the enemys to gain extra po ints",
	        "CONTROLS", "Move Left : LEFT ARROW", "Move Right : RIGHT ARROW",
	        "Jump : UP ARROW", "Shoot : SPACE BAR", "QUIT : Q", "ALL THE BEST" };
	    settextjustify(1, 1);
	    settextstyle(1, 0, 4);
	    setcolor(7);
	    thgtxt(260, 100, a[0]);
	    settextstyle(1, 0, 2);
	    setcolor(GREEN);
	    outtextxy(getmaxx() / 2, 100, a[1]);
	    delay(100);
	    outtextxy(getmaxx() / 2, 130, a[2]);
	    delay(50);
	    outtextxy(getmaxx() / 2, 160, a[3]);
	    delay(200);
	    settextstyle(1, 0, 4);
	    setcolor(7);
	    thgtxt(240, 270, a[4]);
	    setcolor(GREEN);
	    settextstyle(1, 0, 2);
	    if (controllval(keys.left)) {
	        strcpy(a[5], "Move left : ");
	        strcat(a[5], controllval(keys.left));
	    }
	    else {
	        a[5][12] = keys.left;
	        a[5][13] = '\0';
	    }
	    if (controllval(keys.right)) {
	        strcpy(a[6], "Move right : ");
	        strcat(a[6], controllval(keys.right));
	    }
	    else {
	        a[6][13] = keys.right;
	        a[6][14] = '\0';
	    }
	    if (controllval(keys.up)) {
	        strcpy(a[7], "jump : ");
	        strcat(a[7], controllval(keys.up));
	    }
	    else {
	        a[7][7] = keys.up;
	        a[7][8] = '\0';
	    }
	    if (controllval(keys.shoot)) {
	        strcpy(a[8], "shoot : ");
	        strcat(a[8], controllval(keys.shoot));
	    }
	    else {
	        a[8][8] = keys.shoot;
	        a[8][9] = '\0';
	    }
	    outtextxy(getmaxx() / 2, 270, a[5]);
	    delay(50); //left
	    outtextxy(getmaxx() / 2, 300, a[6]);
	    delay(50); //right
	    outtextxy(getmaxx() / 2, 330, a[7]);
	    delay(50); //jump
	    outtextxy(getmaxx() / 2, 360, a[8]);
	    delay(50); //shoot
	    outtextxy(getmaxx() / 2, 390, a[9]);
	    delay(50); //quit
	    settextstyle(1, 0, 1);
	    setcolor(3);
	    thgtxt(150 + 220, 450, a[10]);
	    getch();
	}
	/////////////////////////////////////////////////////////
	////////////////////CREDITS////////////////////////////////////
	void loadninja()
	{
	    cleardevice();
	    border();
	    ifstream fin(filedir, ios::binary);
	    settextstyle(1, 0, 4);
	    if (!fin) {
	        outtextxy(200, 200, "File NOT found!!");
	        getch();
	        fin.close();
	        return;
	    }
	    thg_score tmp;
	    int i = 0, y = 150;
	    char buff[15];
	    setcolor(WHITE);
	    thgtxt(200, 110, "Loading NinJa");
	    setcolor(7);
	    while (fin.read((char*)&tmp, sizeof(tmp))) {
	        i++;
	        sprintf(buff, "%i. %s  Level : %i", i, tmp.name, tmp.stage + 1);
	        thgtxt(50, y += 30, buff);
	    }
	    setcolor(WHITE);
	    thgtxt(30, getmaxy(), "Enter the record number : ");
	    setcolor(7);
	    char ch = getch();
	    buff[0] = ch;
	    buff[1] = '\0';
	    outtextxy(530, getmaxy() - 50, buff);
	    recordno = ch - 48;
	    fin.clear();
	    if (recordno < 1 || recordno > i || !isdigit(ch)) {
	        setcolor(RED);
	        thgtxt(50, getmaxy() - 40, "Sorry...Invalid input!!");
	        getch();
	        return;
	    }
	    fin.seekg((int)((recordno - 1) * sizeof(score)));
	    fin.read((char*)&score, sizeof(score));
	    sprintf(buff, "Successfully loaded ninja %s", score.name);
	    setcolor(GREEN);
	    thgtxt(50, getmaxy() - 40, buff);
	    level = score.level;
	    stage = score.stage;
	    fin.close();
	    getch();
	    gameloaded = 1;
	}
	void save()
	{
	    fflush(stdin);
	    char ch;
	    cleardevice();
	    thgtxt(50, 100, "Press Enter");
	    do {
	        ch = getch();
	    } while (ch != 13);
	    cleardevice();
	    border();
	    settextstyle(1, 0, 4);
	    thgtxt(50, 200, "You want to save your game ?");
	    ch = getch();
	    ofstream fout(filedir, ios::binary | ios::ate);
	    fout.clear();
	    score.stage = stage;
	    score.level = level;
	    if (ch == 'y' || ch == 'Y') {
	        outtextxy(200, 250, "Y");
	        if (gameloaded)
	            fout.seekp((int)((recordno - 1) * sizeof(score)));
	        else
	            fout.seekp(0, ios::end);
	        fout.write((char*)&score, sizeof(score));
	        cleardevice();
	        border();
	        outtextxy(200, 200, "Saved successfully");
	    }
	    else
	        outtextxy(200, 250, "N");
	    getch();
	    fout.close();
	}

