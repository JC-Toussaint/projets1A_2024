#include "main.h"

void Rebound() {

	int rect_x = 10;
	int rect_y = 10;

	int rect_dx = -3;
	int rect_dy = -2;

	int quit = 0;
	while (!quit) {

		/* OBLIGATOIRE : capture des evenements */
		quit=gfx_event_waiting();
		gfx_color(255, 255, 255);
		gfx_clear();

		gfx_color(0xff, 0x0, 0x0);
		gfx_filled_rectangle(rect_x, rect_y, RECT_WIDTH, RECT_HEIGHT);
		gfx_swap_buffers();

		gfx_color(0x0, 0x0, 0xff);
		gfx_filled_rectangle(L-RECT_WIDTH-rect_x, rect_y, RECT_WIDTH, RECT_HEIGHT);
		gfx_swap_buffers();

		gfx_color(0, 255, 0);
		gfx_filled_circle(rect_x, rect_y, L/4);
		gfx_swap_buffers();

		int rect_nx = rect_x + rect_dx;
		if (rect_nx <= 0 || rect_nx + RECT_WIDTH >= L) {
			rect_dx *= -1;
		} else {
			rect_x = rect_nx;
		}

		int rect_ny = rect_y + rect_dy;
		if (rect_ny <= 0 || rect_ny + RECT_HEIGHT >= L) {
			rect_dy *= -1;
		} else {
			rect_y = rect_ny;
		}

		usleep(1000*1000/FPS);
	}

}

