#include <stdio.h>
  #include <conio.h>
  #include <graphics.h>
  #include <dos.h>

  int main() {
        /* request auto detection */
        int gdriver = DETECT, gmode, err;
        int i, x1, y1, x2, y2, midx, midy;

        /* initialize graphic mode */
	initgraph(&gdriver, &gmode, "C:/TC/BGI");
        err = graphresult();

        if (err != grOk) {
                /* error occurred */
                printf("Graphics Error: %s\n",
                                grapherrormsg(err));
                return 0;
        }

        /* mid positions in x and y axis */
        midx = getmaxx() / 2;
        midy = getmaxy() / 2;

        /* drawing the tank */
        setcolor(DARKGRAY);
        setlinestyle(SOLID_LINE, 1, 3);
        rectangle(100, midy - 5, getmaxx() - 100, midy + 200);
        setcolor(BLACK);
        line(99, midy - 5, getmaxx() - 99, midy - 5);

        /* water from pipe to tank */
        setcolor(BLUE);
        setlinestyle(DOTTED_LINE, 1, 3);
        arc(0, midy, 0, 90, 150);
        arc(0, midy, 0, 90, 147);
        arc(0, midy, 0, 90, 144);
        setlinestyle(SOLID_LINE, 1, 3);
        line(144, midy, 144, midy + 198);
        line(146, midy, 146, midy + 198);
        line(148, midy, 148, midy + 198);
        line(149, midy, 149, midy + 198);

        /* drawing the pipe */
        setcolor(WHITE);
        setlinestyle(SOLID_LINE, 1, 1);
        setfillstyle(SOLID_FILL, WHITE);
        rectangle(0, midy - 156, 30, midy - 137);
        floodfill(1, midy - 155, WHITE);

        /* set the color of water */
        setcolor(BLUE);
        setlinestyle(SOLID_LINE, 1, 3);

        x1 = 103, y1 = midy + 195;
        x2 = getmaxx() - 103, y2 = midy + 197;

        /* fill the tank with water */
        while (y1 > midy) {
                setfillstyle(SOLID_FILL, BLUE);
                rectangle(x1, y1, x2, y2);
                floodfill(x1, y1, BLUE);
                y1 = y1 - 2;
                y2 = y2 - 2;
                delay(100);
        }

        /* stop water from pipe to tank */
        setcolor(BLACK);
        setlinestyle(SOLID_LINE, 1, 3);
        arc(0, midy, 0, 90, 150);
        arc(0, midy, 0, 90, 147);
        arc(0, midy, 0, 90, 144);

        /* redraw the white pipe */
        setcolor(WHITE);
        setlinestyle(SOLID_LINE, 1, 1);
        setfillstyle(SOLID_FILL, WHITE);
        rectangle(0, midy - 156, 30, midy - 137);
        floodfill(28, midy - 139, WHITE);

        getch();

        /* deallocate memory allocated for graphic screen */
        closegraph();

        return 0;
  }
