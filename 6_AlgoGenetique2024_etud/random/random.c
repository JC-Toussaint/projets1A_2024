#include <stdio.h>
#include <math.h>

#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

gsl_rng *r=NULL;  			/* déclaration globale du generateur */
unsigned long int seed = 1564431;	/* nombre source du generateur */

main ()
{
int i;
int Ntirages=10000;			/* nb de tirages */
int Nintervalles=50;			/* nb d'intervalles de l'histogramme */

const gsl_rng_type * T=NULL;	   /* type de générateur */

gsl_rng_env_setup();

T = gsl_rng_default;
r = gsl_rng_alloc (T);
printf("generator type : %s\n", gsl_rng_name (r));

/* initialisation du generateur avec le nombre source */
gsl_rng_set(r, seed);

for (i=0; i<Ntirages; i++)
    {
/*  tirage d'un nb aleatoire distrib uniforme */
    double x=gsl_rng_uniform (r);  
    printf("%lf\n", x);

    }

getchar();
}
