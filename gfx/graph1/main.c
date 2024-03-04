#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include <gfx.h>
#include <time.h>
#include <errno.h>    
 
/* fenetre graphique */
#define L 600
#define FPS 50
#define RECT_WIDTH 300
#define RECT_HEIGHT 300
  
void InitGraph(int taille);
void Draw();
void Animate();

void InitGraph(int taille)
{
/* cree une fenetre graphique carree taille =  nombre de pixels */
gfx_open(L, L,"graph1");
}

void Draw() {
/* efface la fenetre graphique couleur blanc */
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


void Animate() {
int N=100;
double Rayon=L/10.;
int n;

for (n=0; n<N; n++) {
    int x=(int)((double)n/(double)N * L);
    int y=x;

/* efface la fenetre graphique couleur blanc */
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

int main(){
    InitGraph(L);  
    Draw();
    Animate();
    gfx_quit();
}

