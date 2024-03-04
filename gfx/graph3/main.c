#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include <X11/Xlib.h>
#include <X11/extensions/Xdbe.h>

#include <unistd.h>

#define FPS 50
#define RECT_WIDTH 300
#define RECT_HEIGHT 300

#include "main.h"
#include "gfx.h"

int main(void)
{
// creation de la fenetre graphique
    InitGraph(L);  

    Draw();

    Animate();

    Rebound();

// fermeture de la fenetre graphique
    gfx_quit();

    return 0;
}
