#include <stdio.h>
  #include <conio.h>
  #include <math.h>
  #include <graphics.h>
  #include <dos.h>

  int main() {
        /* request auto detection */
        int gdriver = DETECT, gmode, err;
        int i = 0, fq, amp;
        double x, y;

        /* initialize graphic mode */
	initgraph(&gdriver, &gmode, "C:/TC/BGI");
        err = graphresult();

        if (err != grOk) {
                /* error occurred */
                printf("Graphics Error: %s\n",
                                grapherrormsg(err));
                return 0;
        }

        /* initialize the variables */
        x = 0;

        /* frequency is 2 here */
        fq = 2;

        /* setting amplitute to 100 */
        amp = 100;

        line(0, getmaxy() / 2, getmaxx(), getmaxy() / 2);

        /* generate a sine wave */
        while (x < getmaxx()) {
                setcolor(i % 15 ? i % 15 : 1);

                /* calculate y value given x */
                y = amp * sin((3.14 * fq * x) / 180);
                y = y + getmaxy() / 2;

                /* plot a pixel at the given position */
                putpixel(x, y, 15);

                /* draw a line using the above manipulated pts */
                line(x, y, x, y - 12);
                line(x, y, x, y + 12);

                /* sleep for 100 micro seconds */
                delay(100);

                /* increment x */
                x = x + 5;
                i++;
        }

        getch();

        /* deallocate memory allocated for graphics screen */
        closegraph();

        return 0;
  }