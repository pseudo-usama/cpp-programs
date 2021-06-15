/*
 *  Developed in Turbo C++
 */

/*  buttusamaiftikhar@gmail.com
 *  https://twitter.com/UsamaIftikharB1
 *  https://www.instagram.com/buttusamaiftikhar/ 
 *  https://www.linkedin.com/in/usama-iftikhar-butt-b8203614a/
 *  https://github.com/buttusamaiftikhar
 *  For more Programs and Projects email me
 */

#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <stdlib.h>

//defining boolean possibilities
#define true  1
#define false 0
typedef int bool;

int X, Y;	//For getmaxx() and getmaxy()
const int Mrgn = 5;
const int Pdng = 11;

void Set_XY(int x, int y) {
	X = x;
	Y = y;
}//End Set_XY Fn

bool SURE(int a);	//Calls on restart and exit

enum Parts { Nothing, Head, Tail, Body };	//Defines Body Parts
enum Status { Up, Down, Right, Left };		//Snake Direction

struct snake {		//Its an Linked List and uses to store each Snake body Parts...
public:
	int X;		//Saves X Point in Screen
	int Y;		//Saves Y Point in Screen
	int BodyPart;	//Which Part of Body [like Head, Tail]
	int Direction;	//Direction of that Node

	snake *Snake_Head;	//Points to Head of Snake
	snake *Prev;

private:
	snake *Snake_Tail;	//Points to last Body Part

public:
	void Set_Default();		//Set the Default Snake
	void Make_New();		//Makes new node when snake eat food
	void Dispose();			//Delete all the Linked List
	bool Is_Exist(int x, int y);	//Use to check weather there exist any Snake Part
};//End class snake

class Snake {
private:
	//These used for Backend Proceses
	snake Data;	//Saves Data of Snake
	struct food {
	public:
		int X;
		int Y;
	};
	food Food;
	int Score;
	int Feeds;

public:
	void Controler();				//Controls all the Game
	bool Set_Next_and_NotHit(int IsChangeDirection);	//Set the next Position of Snake in Data [Array]
	void Draw();					//Draw the Snake
	void BackGround();				//Create BackGround Graphics

	Snake();	//Constructor
};//End Snake [class]

void main() {
	int gdriver = DETECT,gmode;
	initgraph(&gdriver,&gmode,"C:\\TC\\BGI");

	Set_XY(getmaxx(), getmaxy());

	Snake Ob;

	Ob.Controler();
}//End main Fn

///////////////////////////////////////////////////////////////////////
////////////////////////Functions for Snake class//////////////////////
///////////////////////////////////////////////////////////////////////

void Snake::Controler() {	//Contools all the Game
	Data.Set_Default();
	this->BackGround();

	int IsChangeDirection = -1;
	bool Not_Paused = true;	//Use in Pausing
	bool Not_Loss = true;	//Use in Lossing

	while(true) {
		if(kbhit()) {
			switch(int(getch())) {
				case 'p':	//Pause
//				case 'P':
					if(Not_Loss) {
						Not_Paused = false;
						setfillstyle(1, 8);
						settextstyle(6, 0, 1);
						bar(3*X/4+20, Mrgn+Pdng+160, 3*X/4+20+100, Mrgn+Pdng+160+25);
						outtextxy(3*X/4+20, Mrgn+Pdng+160, "Unpause: U");
					}
				break;

				case 'u':	//Resume
				case 'U':
					Not_Paused = true;

					settextstyle(6, 0, 1);
					setfillstyle(1, 8);
					bar(3*X/4+20, Mrgn+Pdng+160, 3*X/4+20+100, Mrgn+Pdng+160+25);
					outtextxy(3*X/4+20, Mrgn+Pdng+160, "Pause:   P");
				break;

				case 72:	//Up button
					if(Data.Snake_Head->Direction == Right || Data.Snake_Head->Direction == Left)
						IsChangeDirection = Up;
				break;

				case 80:	//Down button
					if(Data.Snake_Head->Direction == Right || Data.Snake_Head->Direction == Left)
						IsChangeDirection = Down;
				break;

				case 77:	//Right button
					if(Data.Snake_Head->Direction == Up || Data.Snake_Head->Direction == Down)
						IsChangeDirection = Right;
				break;

				case 75:	//Left button
					if(Data.Snake_Head->Direction == Up || Data.Snake_Head->Direction == Down)
						IsChangeDirection = Left;
				break;

				case 'r':
				case 'R':
					if(SURE(1)) {
						Data.Dispose();
						Data.Set_Default();
						Not_Loss = true;
						Feeds = 0;
						Score = 0;
					}
				break;

				case 'e':	//exit
				case 'E':
					SURE(2);
				break;
			} //End switch
		} //End if

		if(Not_Paused && Not_Loss) {
			setfillstyle(1, BLACK);
			bar(Mrgn+1, Mrgn+1, 3*X/4-Mrgn-1, Y-Mrgn-1);

			this->Draw();
			Not_Loss = this->Set_Next_and_NotHit(IsChangeDirection);

			delay(100);
			IsChangeDirection = -1;
		}//End if
		else if(Not_Loss == false){
			setfillstyle(1, BLACK);
			bar(Mrgn+1, Mrgn+1, 3*X/4-Mrgn-1, Y-Mrgn-1);

			this->Draw();

			delay(700);

			setfillstyle(1, BLACK);
			bar(Mrgn+1, Mrgn+1, 3*X/4-Mrgn-1, Y-Mrgn-1);

			delay(700);
		}//End else if
	}//End while Loop
}//End Controler Fn

/*  buttusamaiftikhar@gmail.com
 *  https://twitter.com/UsamaIftikharB1
 *  https://www.instagram.com/buttusamaiftikhar/
 *  https://www.linkedin.com/in/usama-iftikhar-butt-b8203614a/
 *  https://github.com/buttusamaiftikhar
 *  For more Programs and Projects email me
 */

bool Snake::Set_Next_and_NotHit(int IsChangeDirection) {
	snake *temp;
	int x_get, x_set, y_get, y_set, direction_get, direction_set;

	if(IsChangeDirection > -1 && IsChangeDirection < 4) {//Check request for changing snake direction
		Data.Snake_Head->Direction = IsChangeDirection;
		return(true);
	}//End if
	else if(IsChangeDirection != -1)
		cout<<"Change Direction  Error";

	switch(Data.Snake_Head->Direction) {
		case Up:
			if(Data.Is_Exist(Data.Snake_Head->X, (Data.Snake_Head->Y-1+33)%33))
				return(false);

			x_set = Data.Snake_Head->X;
			y_set = Data.Snake_Head->Y;
			direction_set = Data.Snake_Head->Direction;

			Data.Snake_Head->Y = (Data.Snake_Head->Y-1+33)%33;
		break;//breaking Up

		case Down:
			if(Data.Is_Exist(Data.Snake_Head->X, (Data.Snake_Head->Y+1)%33))
				return(false);

			x_set = Data.Snake_Head->X;
			y_set = Data.Snake_Head->Y;
			direction_set = Data.Snake_Head->Direction;

			Data.Snake_Head->Y = (Data.Snake_Head->Y+1)%33;
		break;//breaking Down

		case Right:
			if(Data.Is_Exist((Data.Snake_Head->X+1)%33, Data.Snake_Head->Y))
				return(false);

			x_set = Data.Snake_Head->X;
			y_set = Data.Snake_Head->Y;
			direction_set = Data.Snake_Head->Direction;

			Data.Snake_Head->X = (Data.Snake_Head->X+1)%33;
		break;//breaking Right

		default://Left
			if(Data.Is_Exist((Data.Snake_Head->X-1+33)%33, Data.Snake_Head->Y))
				return(false);

			x_set = Data.Snake_Head->X;
			y_set = Data.Snake_Head->Y;
			direction_set = Data.Snake_Head->Direction;

			Data.Snake_Head->X = (Data.Snake_Head->X-1+33)%33;
		break;//breaking default - left
	}//End switch

	temp = Data.Snake_Head->Prev;

	while(temp != NULL) {
		//Getting values of Snake after Snake_Head
		x_get = temp->X;
		y_get = temp->Y;
		direction_get = temp->Direction;

		temp->X = x_set;
		temp->Y = y_set;
		temp->Direction = direction_set;

		x_set = x_get;
		y_set = y_get;
		direction_set = direction_get;

		temp = temp->Prev;
	}

	if(Data.Snake_Head->X == Food.X && Data.Snake_Head->Y == Food.Y) {
		//Set Location of Food
		Food.X = rand() % 33;
		Food.Y = rand() % 33;

		Feeds++;
		Score += 10;

		Data.Make_New();
	}//End if

	return(true);
}//End Set_Next_and_IsHit Fn

void Snake::Draw() {	//Draw Snake on Screen
	snake *temp = Data.Snake_Head;

	int i, j;

	while(temp != NULL) {
		i = temp->X;
		j = temp->Y;

		setcolor(WHITE);

		switch(temp->BodyPart) {
			case Head:
				switch(temp->Direction) {
					case Up:
						circle  (Mrgn+Pdng+14*i  , Mrgn+Pdng+14*j  , 7);	//Circle
						putpixel(Mrgn+Pdng+14*i-3, Mrgn+Pdng+14*j-3, 0);	//Left pixel
						putpixel(Mrgn+Pdng+14*i+3, Mrgn+Pdng+14*j-3, 0);	//Right pixel
						line    (Mrgn+Pdng+14*i-3, Mrgn+Pdng+14*j-7,
							 Mrgn+Pdng+14*i-7, Mrgn+Pdng+14*j-10 );	//Left Line
						line    (Mrgn+Pdng+14*i+3, Mrgn+Pdng+14*j-7,
							 Mrgn+Pdng+14*i+7, Mrgn+Pdng+14*j-10 );	//Right Line
					break;

					case Down:
						circle  (Mrgn+Pdng+14*i  , Mrgn+Pdng+14*j  , 7);	//Circle
						putpixel(Mrgn+Pdng+14*i-3, Mrgn+Pdng+14*j+3, 0);	//Left pixel
						putpixel(Mrgn+Pdng+14*i+3, Mrgn+Pdng+14*j+3, 0);	//Right pixel
						line    (Mrgn+Pdng+14*i-3, Mrgn+Pdng+14*j+7,
							 Mrgn+Pdng+14*i-7, Mrgn+Pdng+14*j+10);	//Left Line
						line    (Mrgn+Pdng+14*i+7, Mrgn+Pdng+14*j+10,
							 Mrgn+Pdng+14*i+3, Mrgn+Pdng+14*j+7 );	//Right Line
					break;

					case Right:
						circle  (Mrgn+Pdng+14*i   , Mrgn+Pdng+14*j  , 7);	//circle
						putpixel(Mrgn+Pdng+14*i+3 , Mrgn+Pdng+14*j-3, 0);	//Upper pixel
						putpixel(Mrgn+Pdng+14*i+3 , Mrgn+Pdng+14*j+3, 0);	//Buttom pixel
						line    (Mrgn+Pdng+14*i+7 , Mrgn+Pdng+14*j-3,
							 Mrgn+Pdng+14*i+10, Mrgn+Pdng+14*j-7  );	//Upper Line
						line    (Mrgn+Pdng+14*i+7 , Mrgn+Pdng+14*j+3,
							 Mrgn+Pdng+14*i+10, Mrgn+Pdng+14*j+7  );	//Bottom Line
					break;

					default://Left
						circle  (Mrgn+Pdng+14*i   , Mrgn+Pdng+14*j  , 7);	//circle
						putpixel(Mrgn+Pdng+14*i-3 , Mrgn+Pdng+14*j-3, 0);	//Upper pixel
						putpixel(Mrgn+Pdng+14*i-3 , Mrgn+Pdng+14*j+3, 0);	//Buttom pixel
						line    (Mrgn+Pdng+14*i-7 , Mrgn+Pdng+14*j-3,
							 Mrgn+Pdng+14*i-10, Mrgn+Pdng+14*j-7  );	//Upper Line
						line    (Mrgn+Pdng+14*i-7 , Mrgn+Pdng+14*j+3,
							 Mrgn+Pdng+14*i-10, Mrgn+Pdng+14*j+7  );	//Bottom Line
					break;
				}//End inner switch [Head case of outer switch]
			break;	//breaking outer switch Head case

			case Body:
				switch(temp->Direction) {
					case Up:
						ellipse(Mrgn+Pdng+14*i, Mrgn+Pdng+14*j, 0, 360, 6, 7);	//Big ellipse
						ellipse(Mrgn+Pdng+14*i, Mrgn+Pdng+14*j, 90, 270, 3, 7);	//Small Left ellipse
					break;

					case Down:
						ellipse(Mrgn+Pdng+14*i, Mrgn+Pdng+14*j, 0, 360, 6, 7);	//Big ellipse
						ellipse(Mrgn+Pdng+14*i, Mrgn+Pdng+14*j, 270, 450, 3, 7);//Small Left ellipse
					break;

					case Right:
						ellipse(Mrgn+Pdng+14*i, Mrgn+Pdng+14*j, 0, 360, 7, 6);	//Big ellipse
						ellipse(Mrgn+Pdng+14*i, Mrgn+Pdng+14*j, 0, 180, 7, 3);	//Small Upper ellipse
					break;

					default://Left
						ellipse(Mrgn+Pdng+14*i, Mrgn+Pdng+14*j, 0, 360, 7, 6);	//Big ellipse
						ellipse(Mrgn+Pdng+14*i, Mrgn+Pdng+14*j, 180, 360, 7, 3);//Small bottom ellipse
					break;
				}//End inner switch [Body case of outer switch]
			break;//breaking outer switch Body case

			case Tail:
				switch(temp->Direction) {
					case Up:
						ellipse(Mrgn+Pdng+14*i, Mrgn+Pdng+14*j, 0, 360, 5, 6);
					break;

					case Down:
						ellipse(Mrgn+Pdng+14*i, Mrgn+Pdng+14*j, 0, 360, 5, 6);
					break;

					case Right:
						ellipse(Mrgn+Pdng+14*i, Mrgn+Pdng+14*j, 0, 360, 6, 5);
					break;

					default://Left
						ellipse(Mrgn+Pdng+14*i, Mrgn+Pdng+14*j, 0, 360, 6, 5);
					break;
				}//End inner switch [Tail case of outer switch]
			break;//breaking outer switch Tail case

			case Nothing:
			break;

			default:
				cout<<"Error";
			break;
		}//End outer switch

		temp = temp->Prev;	//Set Previous Node
	}//End while Loop

	//Draw Food
	circle(Mrgn+Pdng+Food.X*14, Mrgn+Pdng+Food.Y*14, 5);
	setfillstyle(1, WHITE);
	floodfill(Mrgn+Pdng+Food.X*14, Mrgn+Pdng+Food.Y*14, WHITE);

	window(72, 9, 73, 10);
	cout<<Score;

	window(72, 10, 73, 10);
	cout<<Feeds;
}//End Draw Fn

void Snake::BackGround() {
	setfillstyle(1, BLACK);
	bar(0, 0, 3*X/4, Y);	//Game Panel

	setfillstyle(1, 8);
	bar(3*X/4, 0, X, Y);	//Controll Panel

	//Border Lines for Game Panel
	rectangle(Mrgn-2, Mrgn-2, 3*X/4 - Mrgn+2, Y-Mrgn+2);
	rectangle(Mrgn, Mrgn, 3*X/4 - Mrgn, Y-Mrgn);

	//Border Lines for Control Panel
	rectangle(3*X/4+Mrgn-2, Mrgn-2, X-Mrgn+2, Y-Mrgn+2);
	rectangle(3*X/4+Mrgn, Mrgn, X-Mrgn, Y-Mrgn);

	settextstyle(4, 0, 5);
	outtextxy(3*X/4+30, 7, "Snake");
	line(3*X/4+30, 55, 3*X/4+128, 55);

	settextstyle(6, 0, 1);

	outtextxy(3*X/4+20, Mrgn+Pdng+100, "Score  : ");
	outtextxy(3*X/4+20, Mrgn+Pdng+120, "Feeds  : ");

	outtextxy(3*X/4+20, Mrgn+Pdng+160, "Pause  : P");
	outtextxy(3*X/4+20, Mrgn+Pdng+180, "Restart : R");
	outtextxy(3*X/4+20, Mrgn+Pdng+200, "Exit     : E");

	outtextxy(3*X/4+Mrgn+Pdng, Y-Mrgn-Pdng-100, "Conrolls:");

	const int S = 15;		//Size of button S by S
	rectangle(3*X/4+Mrgn+Pdng+25-S          , Y-Mrgn-Pdng-15-S, 3*X/4+Mrgn+Pdng+25+S          , Y-Mrgn-Pdng-15+S);	//Left botton
	rectangle(3*X/4+Mrgn+Pdng+25+S+25-S     , Y-Mrgn-Pdng-15-S, 3*X/4+Mrgn+Pdng+25+S+25+S     , Y-Mrgn-Pdng-15+S);	//Down botton
	rectangle(3*X/4+Mrgn+Pdng+25+S+25+S+25-S, Y-Mrgn-Pdng-15-S, 3*X/4+Mrgn+Pdng+25+S+25+S+25+S, Y-Mrgn-Pdng-15+S);	//Right botton
	rectangle(3*X/4+Mrgn+Pdng+25+S+25-S     , Y-Mrgn-Pdng-70  , 3*X/4+Mrgn+Pdng+25+S+25+S     , Y-Mrgn-Pdng-40  );	//Up botton

	settextstyle(0, 0, 0);

	outtextxy(3*X/4+Mrgn+Pdng+23 , Y-Mrgn-Pdng-18, "<");	//Left
	outtextxy(3*X/4+Mrgn+Pdng+62 , Y-Mrgn-Pdng-18, "v");	//Down
	outtextxy(3*X/4+Mrgn+Pdng+101, Y-Mrgn-Pdng-18,  ">");	//Right
	outtextxy(3*X/4+Mrgn+Pdng+62 , Y-Mrgn-Pdng-55, "^");	//Up
}//End BackGound Fn

Snake::Snake() {
	Food.X = rand() % 33;
	Food.Y = rand() % 33;

	Feeds = 0;
	Score = 0;
}//End Snake (Constructor)

///////////////////////////////////////////////////////////////////////
////////////////////////Functions for snake class//////////////////////
///////////////////////////////////////////////////////////////////////

/*  buttusamaiftikhar@gmail.com
 *  https://twitter.com/UsamaIftikharB1
 *  https://www.instagram.com/buttusamaiftikhar/ 
 *  https://www.linkedin.com/in/usama-iftikhar-butt-b8203614a/
 *  https://github.com/buttusamaiftikhar
 *  For more Programs and Projects email me
 */

void snake::Make_New() {
	snake *NewNode = new snake;			//Making new Node
	NewNode->Direction = Snake_Tail->Direction;	//Set direction
	NewNode->Prev = NULL;				//Setting the Last Node Prev as NULL
	NewNode->BodyPart = Tail;			//Setting bodyPart as Tail
	Snake_Tail->BodyPart = Body;			//Set old Tail as Body
	Snake_Tail->Prev = NewNode;			//Create Link

	switch(NewNode->Direction) {	//Set the Location
		case Up:
			NewNode->X = Snake_Tail->X;
			NewNode->Y = (Snake_Tail->Y+1)%33;
		break;

		case Down:
			NewNode->X = Snake_Tail->X;
			NewNode->Y = (Snake_Tail->Y+33-1)%33;
		break;

		case Right:
			NewNode->X = (Snake_Tail->X+33-1)%33;
			NewNode->Y = Snake_Tail->Y;
		break;

		default://Left
			NewNode->X = (Snake_Tail->X+1)%33;
			NewNode->Y = Snake_Tail->Y;
		break;
	}//End switch
	Snake_Tail = NewNode;	//Updating the Tail
}//End Make_New Fn

void snake::Set_Default() {//Set the Default Snake
	snake *NewNode = new snake;
	NewNode->X = 15;
	NewNode->Y = 15;
	NewNode->BodyPart = Tail;
	NewNode->Direction = Right;
	NewNode->Prev = NULL;

	Snake_Tail = new snake;
	Snake_Tail->X = 16;
	Snake_Tail->Y = 15;
	Snake_Tail->BodyPart = Body;
	Snake_Tail->Direction = Right;
	Snake_Tail->Prev = NewNode;

	Snake_Head = new snake;
	Snake_Head->X = 17;
	Snake_Head->Y = 15;
	Snake_Head->BodyPart = Head;
	Snake_Head->Direction = Right;
	Snake_Head->Prev = Snake_Tail;
}//End Set_Default Fn

bool snake::Is_Exist(int x, int y) {
	snake *temp = Snake_Head->Prev;

	while(temp != NULL) {
		if(temp->X == x && temp->Y == y)
			return(true);
		temp = temp->Prev;
	}//End while Loop
	return(false);
}//End Is_Exist Fn

void snake::Dispose() {	//Clear all the Linked List
	snake *temp, *del = Snake_Head;

	while(temp != NULL) {
		temp = del->Prev;
		delete(del);
		del = temp;
	}//End while Loop
}//End Dispose Fn

///////////////////////////////////////////////////////////////////////
/////////////////////////////Globel Functions//////////////////////////
///////////////////////////////////////////////////////////////////////

/*  buttusamaiftikhar@gmail.com
 *  https://twitter.com/UsamaIftikharB1
 *  https://www.instagram.com/buttusamaiftikhar/ 
 *  https://www.linkedin.com/in/usama-iftikhar-butt-b8203614a/
 *  https://github.com/buttusamaiftikhar
 *  For more Programs and Projects email me
 */

bool SURE(int a) {	//Pop up message
	if(a == 1 || a == 2) {
		settextstyle(0, 0, 0);

		setfillstyle(1, 7);
		bar(X/2-120, Y/2-50, X/2+120-2, Y/2+50-2);	//back ground bar

		setfillstyle(1, BLACK);
		for(int i=0; i<98; i+=4)
			for(int j=0; j<238; j+=4)
				bar(X/2-120+j, Y/2-50+i, X/2-120+j+2, Y/2-50+i+2);	//Small Boxes

		setfillstyle(1, 7);
		bar(X/2-105, Y/2-35, X/2+105, Y/2+35);	//Small inner bar

		setcolor(BLACK);
		outtextxy(X/2-10, Y/2+10, "Y/N");

		if(a == 1) {
			outtextxy(X/2-95, Y/2-8, "Are you sure to Restart.");

			while(true) {
				switch(getch()) {
					case 'Y':	//Yes
					case 'y':
						return(true);

					case 'N':	//No
					case 'n':
						return(false);
				}//End switch
			}//End while Loop
		}//End inner if
		else {
			outtextxy(X/2-85, Y/2-8, "Are you sure to Exit.");

			while(true) {
				switch(getch()) {
					case 'Y':	//Yes
					case 'y':
						exit(0);
					break;

					case 'N':	//No
					case 'n':
						return(false);
				}//End switch
			}//End while Loop
		}//End else
	}//End outer if
}//End SURE Fn


/*  buttusamaiftikhar@gmail.com
 *  https://twitter.com/UsamaIftikharB1
 *  https://www.instagram.com/buttusamaiftikhar/ 
 *  https://www.linkedin.com/in/usama-iftikhar-butt-b8203614a/
 *  https://github.com/buttusamaiftikhar
 *  For more Programs and Projects email me
 */