#include "fir.h"

#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

FILE *OutFile=NULL;
gsl_rng *r=NULL;  			/* declaration globale du generateur */
unsigned long int seed = 1564431;	/* nombre source du generateur */

int display; /* variable globale */

/* round robin lowband fir filter */
#define NBSAMPLES 1000

double rr_fir_filter0(double newsample) {
	static double samples[NBSAMPLES];
	static uint32_t numsample=0;
	static double slidingsum=0;
	slidingsum-= samples[numsample];
	samples[numsample]= newsample;
	slidingsum+= samples[numsample];
	numsample++;
	numsample%=NBSAMPLES;
	return slidingsum/NBSAMPLES;
}

double rr_fir_filter(uint8_t ch, double newsample) {
	if (ch>2) return 0;
	static double samples[2][NBSAMPLES]={0};
	static uint32_t numsample[2]={0};
	static double slidingsum[2]={0};
	uint32_t ns = numsample[ch];
	slidingsum[ch] -= samples[ch][ns];
	samples[ch][ns]= newsample;
	slidingsum[ch]+= samples[ch][ns];
	numsample[ch]++;
	numsample[ch]%=NBSAMPLES;
	return slidingsum[ch]/NBSAMPLES;
}

void OpenGnuplot()
{
/* ouverture du tube (pipe) vers gnuplot */

OutFile=popen("gnuplot","w");
fprintf(OutFile,"set grid\n");
fprintf(OutFile,"plot 0,0\n");
}

void CloseGnuplot()
{
/* fermeture du tube vers gnuplot */
pclose(OutFile);
}

void DrawGnuplot()
{
fprintf(OutFile,"  set yrange [-1:1]\n");
fprintf(OutFile,"  plot 'data' using 3 w l lt rgb '#FF0000'\n");
fprintf(OutFile,"replot 'data' using 2 lt rgb '#0000FF'\n");
fflush(OutFile);
}

void evol(uint64_t Nsteps){

FILE *f=fopen("data", "w");
if (!f) exit(1);

OpenGnuplot();

for (uint64_t nstep=1; nstep<Nsteps; nstep++){    
    double a=gsl_rng_uniform (r);
    
    double aFir  = rr_fir_filter(0, a);
   
    printf("step %lu r %lf rFir %lf\n", nstep, a, aFir);   
    fprintf(f, "%lu %lf %lf\n", nstep, a, aFir);
    fflush(f);
    DrawGnuplot();
    if (! (nstep % (NBSAMPLES))) {
       rewind(f);  // rembobinage du fichier
       }
    }
CloseGnuplot();
}


int main()
{
const gsl_rng_type * T=NULL;	   /* type de generateur */
gsl_rng_env_setup();

T = gsl_rng_default;
r = gsl_rng_alloc (T);
printf("generator type : %s\n", gsl_rng_name (r));

/* initialisation du generateur avec le nombre source */
gsl_rng_set(r, seed);

evol(1000000000);
}

