#include "main.h"
   
void Animate() {
int N=100;
double Rayon=L/10.;
int n;

for (n=0; n<N; n++) {
    int x=(int)((double)n/(double)N * L);
    int y=x;

    gfx_color(255, 255, 255);
    gfx_clear();

/* OBLIGATOIRE : capture des evenements */
    int quit=gfx_event_waiting();

/* disque en vert */
    gfx_color(0, 255, 0);
    gfx_filled_circle(x, y, Rayon);   
    gfx_swap_buffers(); 
    usleep(1000*1000/FPS);
    }

printf("Appuyer encore sur la touche q\n");
for(;;) {
	char c = gfx_wait();
	if(c=='q') break;
	}
} 


