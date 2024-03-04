#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include <gsl/gsl_errno.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_odeiv.h>
#include <gsl/gsl_ieee_utils.h>
#include <gsl/gsl_const_mksa.h>

#include "gfx.h"

#ifndef __SONDE__
#define __SONDE__ 

#define DIM 4

/* largeur en pixels de la fenetre graphique */
#define WIDTH 600
#define L_OBS (35.0) /* en UA */
#define RADIUS 4

#define  pi M_PI
#define  rad2deg (180./M_PI)
#define  deg2rad (M_PI/180.)
#define  day2sec (24.*3600.)
#define  sec2day (1./(24.*3600.));
#define  eps 1e-12

typedef 
struct OrbitalElement {	// orbital parameters (J2000 epoch)		// deviation rates  
double a; 		// semi-major axis [AU]				// semi-major axis [AU/Cy]
double e; 		// eccentricity of orbit			// eccentricity of orbit [/Cy]
double i; 		// inclination of orbit [deg] 			// inclination of orbit [Seconds/Cy]
double O; 		// longitude of the ascending node [deg]	// longitude of the ascending node [Seconds/Cy]
double w; 		// longitude of perihelion [deg]		// longitude of perihelion [Seconds/Cy]
double L; 		// mean longitude [deg]				// mean longitude [Seconds/Cy]
}
OrbitalElement;

typedef
struct HelioCoord {
       double x, y, z;
       }
HelioCoord;

typedef
struct Astre
{
char name[256];
double mass;
OrbitalElement orbitJ2000; 	// orbital parameters (J2000 epoch)
OrbitalElement rateJ2000;	// deviation rates
OrbitalElement orbit;		
HelioCoord pos;
}
Astre; 

                                                                                
/* prototypes */
double DayNumber( int y, int m, int d, int hour, int mins);
void InitAstreDB(Astre *astre);
void GetHelioCoord(double d, Astre *astre);
void GetOrbitalElements(double d, Astre *astre);
double TrueAnomaly( double M, double e);

void InitGraph(int taille); 
double mod2pi( double x );  // radians

#endif
