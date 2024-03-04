#ifndef __main__
#define __main__
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include <gfx.h>
#include <time.h>
#include <errno.h>    
#endif
 
/* fenetre graphique */
#define L 600
#define FPS 50
#define RECT_WIDTH 300
#define RECT_HEIGHT 300

int msleep(long msec);
void InitGraph(int taille);
void Draw();
void Animate();

extern int display; /* variable globale */

