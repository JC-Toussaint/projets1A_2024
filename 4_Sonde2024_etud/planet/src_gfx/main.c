#include "sonde.h"

/* variable globale pour l'affichage */
int display=0;
                 
int main()
{
Astre astre[10];
InitAstreDB(astre);
InitGraph(WIDTH);

    int year, month, day, hour, mins;
printf( "year	:" ); scanf("%d", &year);
printf( "month  :" ); scanf("%d", &month);
printf( "day	:" ); scanf("%d", &day);
printf( "hour	:" ); scanf("%d", &hour);
printf( "minute :" ); scanf("%d", &mins);

    // compute day number for date/time
    double d = DayNumber( year, month, day, hour, mins );
          
    // compute location of objects
    for (int p = 0; p<10; p++) {  
        Astre *obj=&astre[p];
        GetHelioCoord(d, obj);
	printf("%12s %10.5lf %10.5lf %10.5lf\n", obj->name, obj->pos.x, obj->pos.y, obj->pos.z); 

        gfx_color(0, 0, 255);
        int ixpos = (obj->pos.x+L_OBS)/(2.*L_OBS)*WIDTH;
        int iypos = (obj->pos.y+L_OBS)/(2.*L_OBS)*WIDTH;
        gfx_filled_circle(ixpos, iypos, RADIUS); 
        gfx_color(255, 0, 0);
        gfx_draw_string(ixpos, iypos, obj->name);
        gfx_flush();
        gfx_swap_buffers();
        }
    printf("\n");

gfx_wait();
gfx_wait();

/*
    for(;;) {
        double x, y;
        unsigned int button;
     
        g2_query_pointer(display, &x, &y, &button);
	if ((button & 0xFF00)) {
           printf("Position : %lf \t %lf D=%lf\n", x, y, sqrt(x*x+y*y));
	   }
    }
*/
}

