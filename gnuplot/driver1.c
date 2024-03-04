#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

FILE *OutFile;

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
double t, y, arg;

FILE *f=fopen("data", "w");
if (!f) exit(1);

OpenGnuplot();

t=0;
for(;;)
   {
   arg=t*M_PI;
   y = cos(arg);
   fprintf(f, "%lf %lf\n", t, y);
   fflush(f);
   DrawGnuplot();
   t += 0.01;
   }

CloseGnuplot();
}
