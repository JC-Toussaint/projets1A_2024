#include "sonde.h"

/* 
reference J2000 
calcul des elements orbitaux pour astre donne
*/

void GetOrbitalElements(double d, Astre *astre)
{
double cy = d / 36525.;          // centuries since J2000

OrbitalElement *orbit=&(astre->orbitJ2000);		
OrbitalElement *rate =&(astre->rateJ2000);
OrbitalElement *orb  =&(astre->orbit);

orb->a = orbit->a + rate->a*cy;
orb->e = orbit->e + rate->e*cy;
orb->i =(orbit->i - rate->i*cy/3600)*deg2rad;
orb->O =(orbit->O - rate->O*cy/3600)*deg2rad;
orb->w =(orbit->w + rate->w*cy/3600)*deg2rad;
orb->L = mod2pi((orbit->L + rate->L*cy/3600)*deg2rad);
}
