#include <main.h>
  
void Draw() {
gfx_color(255, 255, 255);
gfx_clear();

/* carre en rouge */
gfx_color(255, 0, 0);
gfx_filled_rectangle(0, 0, L/2, L/2); 

/* carre plein en bleu */
gfx_color(0, 0, 255);
gfx_filled_rectangle(L/2, L/2, L/2, L/2);

/* disque en vert */
gfx_color(0, 255, 0);
double Rayon=L/10.;
gfx_filled_circle(L/2, L/2, Rayon); 

/* affichage */
gfx_swap_buffers();

printf("Appuyer sur la touche q\n");
for(;;) {
	char c = gfx_wait();
	if(c=='q') break;
	}
} 

