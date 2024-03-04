#include "sonde.h"

// return an angle in the range 0 to 2pi
double mod2pi( double x )  // radians
{    
    /*
    double b = x / (2.*M_PI);
    double a = (2*M_PI)*(b - (int)(b));
    
    if (a < 0) 
        a = (2*M_PI) + a; 
    */
    double a=fmod(x, 2*M_PI);
    return a;
}
