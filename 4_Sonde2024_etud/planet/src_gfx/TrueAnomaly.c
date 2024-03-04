#include "sonde.h"

// compute the true anomaly from mean anomaly using iteration
//  M - mean anomaly in radians
//  e - orbit eccentricity

double TrueAnomaly( double M, double e)
  {  
    double V, E, E1;

    // initial approximation of eccentric anomaly
    E = M + e*sin(M)*(1.0 + e*cos(M));

    // iterate to improve accuracy
    do {
        E1 = E;
        E  = E1 - (E1 - e*sin(E1) - M)/(1 - e*cos(E1));
	}
    while (fabs( E - E1 ) >= eps);

    // convert eccentric anomaly to true anomaly
    V = 2*atan(sqrt((1. + e)/(1. - e))*tan(0.5*E));

    // modulo 2pi
    if (V < 0) {
        V = V + 2*M_PI; 
        }
    
    return V;
}
