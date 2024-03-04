/*
A simple example of using the gfx library.
CSE 20211
9/7/2011
by Prof. Thain
*/

#include <stdio.h>
#include "gfx.h"
#include <unistd.h>

int main()
{
	int ysize = 600;
	int xsize = 600;

	char c;

	// Open a new window for drawing.
	gfx_open(xsize,ysize,"Example Graphics Program");

	// Set the current drawing color to green.
	gfx_color(0,200,100);

	// Draw a triangle on the screen.
	gfx_line(100,100,200,100);
	gfx_line(200,100,150,150);
	gfx_line(150,150,400,400);

    gfx_flush();
    sleep(3);

    gfx_clear();

	// Set the current drawing color to red.
	gfx_color(200, 0, 0);

	// Draw a triangle on the screen.
	gfx_line(100,100,200,100);
	gfx_line(200,100,150,150);
	gfx_line(150,150,400,400);

    gfx_line(0, 0, xsize-1, ysize-1);
    gfx_circle( xsize/2, ysize/2, xsize/2);

	// Set the current drawing color to blue.
	gfx_color(0, 0, 200);
    gfx_filled_circle( xsize/4, ysize/4, xsize/4);

	gfx_color(200, 200, 200);
    gfx_draw_string( xsize/4, ysize/4, "text");


	// Set the current drawing color to red.
	gfx_color(200, 0, 0);
    gfx_filled_circle( xsize/4, 3*ysize/4, xsize/4);

	gfx_color(200, 200, 200);
    gfx_draw_string( xsize/4, 3*ysize/4, "text");
	while(1) {
		// Wait for the user to press a character.
		c = gfx_wait();

		// Quit if it is the letter q.
		if(c=='q') break;
	}

	return 0;
}

