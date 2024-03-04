#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <errno.h>  

#include <gfx.h>
 
void InitGraph(int taille);
void Draw();
void Animate();
void Rebound();

/* fenetre graphique */
#define L 600
#define FPS 50
#define RECT_WIDTH 300
#define RECT_HEIGHT 300
#endif
 




