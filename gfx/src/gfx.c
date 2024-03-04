/*
Version 4, 11/01/2022 by JC Toussaint Phelma
adds additional functions for drawing circle, rectangle and text
adds double buffering

A simple graphics library for CSE 20211 by Douglas Thain
For complete documentation, see:
http://www.nd.edu/~dthain/courses/cse20211/fall2011/gfx
Version 3, 11/07/2012 - Now much faster at changing colors rapidly.
Version 2, 9/23/2011 - Fixes a bug that could result in jerky animation.
*/

#include "gfx.h"

/*
gfx_open creates several X11 objects, and stores them in globals
for use by the other functions in the library.
*/

static Display *gfx_display=0;
static Window  gfx_window=0;
static GC      gfx_gc=0;
static XdbeBackBuffer gfx_back_buffer=0;
static Colormap gfx_colormap;
static int      gfx_fast_color_mode = 0;
static int gfx_window_width=0;
static int gfx_window_height=0;
static Atom wm_delete_window;

/* These values are saved by gfx_wait then retrieved later by gfx_xpos and gfx_ypos. */
static int saved_xpos = 0;
static int saved_ypos = 0;

void gfx_open( int width, int height, const char *title ){
	gfx_display = XOpenDisplay(0);
	if(!gfx_display) {
		fprintf(stderr,"gfx_open: unable to open the graphics window.\n");
		exit(1);
	}

	Visual *visual = DefaultVisual(gfx_display,0);
	if(visual && visual->class==TrueColor) {
		gfx_fast_color_mode = 1;
	} else {
		gfx_fast_color_mode = 0;
	}

	int blackColor = BlackPixel(gfx_display, DefaultScreen(gfx_display));
	int whiteColor = WhitePixel(gfx_display, DefaultScreen(gfx_display));

	gfx_window = XCreateSimpleWindow(gfx_display, DefaultRootWindow(gfx_display), 0, 0, width, height, 0, blackColor, blackColor);
    gfx_window_width=width;
    gfx_window_height=height;

	XSetWindowAttributes attr;
	attr.backing_store = Always;

	XChangeWindowAttributes(gfx_display,gfx_window,CWBackingStore,&attr);

    int major_version_return, minor_version_return;
    if(XdbeQueryExtension(gfx_display, &major_version_return, &minor_version_return)) {
        printf("XDBE version %d.%d\n", major_version_return, minor_version_return);
    } else {
        fprintf(stderr, "XDBE is not supported!!!1\n");
        exit(1);
    }

    gfx_gc = XCreateGC(gfx_display, gfx_window, 0, NULL);
    gfx_back_buffer = XdbeAllocateBackBufferName(gfx_display, gfx_window, 0);

    XStoreName(gfx_display, gfx_window, title);

    wm_delete_window = XInternAtom(gfx_display, "WM_DELETE_WINDOW", False);
    XSetWMProtocols(gfx_display, gfx_window, &wm_delete_window, 1);

    XSelectInput(gfx_display, gfx_window, StructureNotifyMask|KeyPressMask|ButtonPressMask);
//    XSelectInput(gfx_display, gfx_window, KeyPressMask|ButtonPressMask);

    XMapWindow(gfx_display, gfx_window);

	gfx_colormap = DefaultColormap(gfx_display,0);

	XSetForeground(gfx_display, gfx_gc, whiteColor);

	// Wait for the MapNotify event
	for(;;) {
		XEvent e;
		XNextEvent(gfx_display, &e);
		if (e.type == MapNotify)
			break;
	}
}

/* Change the current drawing color. */
void gfx_color( int r, int g, int b ){
	XColor color;

	if(gfx_fast_color_mode) {
		/* If this is a truecolor display, we can just pick the color directly. */
		color.pixel = ((b&0xff) | ((g&0xff)<<8) | ((r&0xff)<<16) );
	} else {
		/* Otherwise, we have to allocate it from the colormap of the display. */
		color.pixel = 0;
		color.red = r<<8;
		color.green = g<<8;
		color.blue = b<<8;
		XAllocColor(gfx_display, gfx_colormap, &color);
	}

	XSetForeground(gfx_display, gfx_gc, color.pixel);
}
void gfx_clear(){
 //   XSetForeground(gfx_display, gfx_gc, 0xFFFFFF);  
    XFillRectangle(gfx_display, gfx_back_buffer, gfx_gc, 0, 0, gfx_window_width, gfx_window_height);
}

/* Draw a single point at (x,y) */
void gfx_point( int x, int y ){
  XDrawPoint(gfx_display, gfx_back_buffer, gfx_gc, x, y);
}

/* Draw a line from (x1,y1) to (x2,y2) */
void gfx_line( int x1, int y1, int x2, int y2 ){
  XDrawLine(gfx_display, gfx_back_buffer, gfx_gc, x1, y1, x2, y2);
}

/* Draw a circle of radius R whose center is located at xc, yc */
void gfx_circle( int xc, int yc, int R){
  XDrawArc(gfx_display, gfx_back_buffer, gfx_gc, xc-R, yc-R, 2*R, 2*R, 0, 360*64);
}

/* Draw a filled circle of radius R whose center is located at xc, yc */
void gfx_filled_circle( int xc, int yc, int R){
  XFillArc(gfx_display, gfx_back_buffer, gfx_gc, xc-R, yc-R, 2*R, 2*R, 0, 360*64);
}

/* Draw a rectangle whose the upper-left corner is located at x, y */
void gfx_rectangle( int x, int y, int width, int height){
  XDrawRectangle(gfx_display, gfx_back_buffer, gfx_gc, x, y, width, height);
}

/* Draw a filled rectangle whose the upper-left corner is located at x, y */
void gfx_filled_rectangle( int x, int y, int width, int height)
{
  XFillRectangle(gfx_display, gfx_back_buffer, gfx_gc, x, y, width, height);
}

/* Draw a string at x,y */
void gfx_draw_string( int x, int y, char* text){
  XDrawString(gfx_display, gfx_back_buffer, gfx_gc, x, y, text, strlen(text));
}

/* swap buffers */
void gfx_swap_buffers(){
    XdbeSwapInfo swap_info;
    swap_info.swap_window = gfx_window;
    swap_info.swap_action = 0;
    XdbeSwapBuffers(gfx_display, &swap_info, 1);
}


int gfx_event_waiting(){
        while (XPending(gfx_display) > 0) {
            XEvent event = {0};
            XNextEvent(gfx_display, &event);
            switch (event.type) {
                case KeyPress: {
                    switch (XLookupKeysym(&event.xkey, 0)) {
                        case 'q':
                            return 1;
                            break;
                        default:
                            {}
                        }
                    } break;
                case ClientMessage: {
                    if ((Atom) event.xclient.data.l[0] == wm_delete_window) {
                        return 1;
                    }
                    break;
                }
            break;
            }
        }
        return 0;
}

/* Return the X and Y coordinates of the last event. */
int gfx_xpos(){
   return saved_xpos;
}

int gfx_ypos(){
  return saved_ypos;
}


/* Flush all previous output to the window. */
void gfx_flush(){
	XFlush(gfx_display);
}

/* Wait for the user to press a key or mouse button. */
char gfx_wait(){
	XEvent event;
	gfx_flush();
	while(1) {
		XNextEvent(gfx_display,&event);
		if(event.type==KeyPress) {
			saved_xpos = event.xkey.x;
			saved_ypos = event.xkey.y;
			return XLookupKeysym(&event.xkey,0);
		} else if(event.type==ButtonPress) {
			saved_xpos = event.xkey.x;
			saved_ypos = event.xkey.y;
			return event.xbutton.button;
		}
	}
}

void gfx_quit(){
    XCloseDisplay(gfx_display);
}

