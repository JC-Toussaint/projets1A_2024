#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

FILE *OutFile;

void delay(time_t duration){
time_t stop_time = time(NULL) + duration;
for(;;) {
   time_t current_time = time(NULL);
   if (current_time>stop_time){
      break;
      }
   }
}

void OpenGnuplot()
{
/* ouverture du tube (pipe) vers gnuplot */

OutFile=popen("gnuplot","w");
fprintf(OutFile,"set grid\n");
}

void CloseGnuplot()
{
/* fermeture du tube vers gnuplot */
pclose(OutFile);
}

void DrawGnuplot()
{
fprintf(OutFile,"plot 'data' using 1:2 with lines\n");
fflush(OutFile);
}

int main()
{
double t, y;
time_t duration=1;

FILE *f=fopen("data", "w");
if (!f) exit(1);

OpenGnuplot();

t=0;
for(;;)
   {
   delay(duration);
   time_t current_time = time(NULL);
   printf("%ld \n", current_time);

   y = cos(M_PI*t);
   fprintf(f, "%lf %lf\n", t, y);
   fflush(f);
   DrawGnuplot();
   t += 0.01;
   }

CloseGnuplot();
}
