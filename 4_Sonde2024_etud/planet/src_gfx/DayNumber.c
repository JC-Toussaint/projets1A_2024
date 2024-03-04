#include "sonde.h"

// day number to/from J2000 (Jan 1.5, 2000)
double DayNumber( int y, int m, int d, int hour, int mins)
{
    double rv;
    double h  = hour + mins / 60;
           
    rv = 367*y - 7*(y + (m + 9) / 12) / 4
       + 275*m / 9 + d - 730531.5 + h / 24;
 
    return rv;
}    
    
