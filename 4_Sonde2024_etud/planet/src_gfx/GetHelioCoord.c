#include "sonde.h"

/*
calcul des coordonnees heliocentriques a partir des elements orbitaux
*/

void GetHelioCoord(double d, Astre *astre)
{

GetOrbitalElements(d, astre);

if (strcmp(astre->name, "Earth")==0) {
    double ae = astre->orbit.a;
    double ee = astre->orbit.e;
    double ie = astre->orbit.i;
    double oe = astre->orbit.O;
    double pe = astre->orbit.w;
    double le = astre->orbit.L;
    
     // position of Earth in its orbit
    double me = mod2pi(le - pe);
    double ve = TrueAnomaly(me, ee);
    double re = ae*(1 - ee*ee) / (1 + ee*cos(ve));

    // heliocentric rectangular coordinates of Earth
    double xe = re*cos(ve + pe);
    double ye = re*sin(ve + pe);
    double ze = 0;
    
    astre->pos.x=xe;
    astre->pos.y=ye;
    astre->pos.z=ze;
    }
else {
    double ap = astre->orbit.a;
    double ep = astre->orbit.e;
    double ip = astre->orbit.i;
    double op = astre->orbit.O;
    double pp = astre->orbit.w;
    double lp = astre->orbit.L;

    // position of planet in its orbit
    double mp = mod2pi(lp - pp);
    double vp = TrueAnomaly(mp, ep);
    double rp = ap*(1 - ep*ep) / (1 + ep*cos(vp));
    
    // heliocentric rectangular coordinates of planet
    double xh = rp*(cos(op)*cos(vp + pp - op) - sin(op)*sin(vp + pp - op)*cos(ip));
    double yh = rp*(sin(op)*cos(vp + pp - op) + cos(op)*sin(vp + pp - op)*cos(ip));
    double zh = rp*(sin(vp + pp - op)*sin(ip));

    astre->pos.x=xh;
    astre->pos.y=yh;
    astre->pos.z=zh;	
    }
}
