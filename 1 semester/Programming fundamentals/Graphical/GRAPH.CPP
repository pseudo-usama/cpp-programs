#include <iostream.h>
#include <graphics.h>
#include <conio.h>

void main() {
	int gdriver = DETECT,gmode;
	initgraph(&gdriver, &gmode, "C:\\TC\\BGI");

	start:

	cleardevice();

	int x=getmaxx()/2, y=getmaxy()/2;

	line(x-230, y    , x+230, y    );	//x-axis line
	line(x    , y-230, x    , y+230);	//y-axis line





	int i, j, constant, decider = 1, x1, x2, y1, y2;

	cout << "Enter the x Coefficient        =   ";
	cin >> i;

	cout << "Enter the y Coefficient        =   ";
	cin >> j;

	cout << "Enter the constant             =   ";
	cin >> constant;

	cout << "           " << i << "x";
	if (j > 0) { cout << " + "; }
	cout << j << "y" << " = " << constant << endl;

	cout << "This is the equation." << endl;



	for (int a = 239; a >= -239; a--)
	{
		for (int b = -319; b <= 319; b++)
		{
			if(decider != 1 && i * a + j * b == constant) {
				x2=b;
				y2=a;
			}
			else if (decider && i * a + j * b == constant) {
				x1=b;
				y1=a;
				decider=0;
			}
		}
	}

	if (decider)
	{
		cout << "There is no line in this range of graph." << endl;
		cout << "Enter an equation of limited range.";
	}
	else{
//		line(x1+230+409/2, y1+230+249/2, x2+230+409/2, y2+230+249/2);
		line(x1+319, y1+239, x2+319, y2+239);
//		line(x1, y1, x2, x2);
	}


	if(getch()=='z') { goto start; }


}