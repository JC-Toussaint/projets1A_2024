#include <stdio.h>
#include <math.h>

#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_histogram.h>

gsl_rng *r=NULL;  			/* declaration globale du generateur */
unsigned long int seed = 1564431;	/* nombre source du generateur */

main ()
{
int i;
int Ntirages=10000;			/* nb de tirages */
int Nintervalles=50;			/* nb d'intervalles de l'histogramme */

const gsl_rng_type * T=NULL;	   /* type de generateur */
gsl_histogram * h=NULL;			      /* histogramme */

gsl_rng_env_setup();

T = gsl_rng_default;
r = gsl_rng_alloc (T);
printf("generator type : %s\n", gsl_rng_name (r));

/* initialisation du generateur avec le nombre source */
gsl_rng_set(r, seed);


h = gsl_histogram_alloc (Nintervalles);

/* domaine de stockage [-10, 10] */
gsl_histogram_set_ranges_uniform (h, -10, 10);

for (i=0; i<Ntirages; i++)
    {
/*  tirage d'un nb aleatoire distrib uniforme */
/*  double x=gsl_rng_uniform (r);  */

/* tirage d'un nb aleatoire distrib gaussienne */
    double x=gsl_ran_gaussian (r, 1.);	
    gsl_histogram_increment(h, x);
    }

for (i=0; i<Nintervalles; i++)
    {
    printf("%d\t%lf\t%lf\n", i, 0.5*(h->range[i]+h->range[i+1]),  h->bin[i]);
    }
    
gsl_histogram_free (h);
getchar();
}
