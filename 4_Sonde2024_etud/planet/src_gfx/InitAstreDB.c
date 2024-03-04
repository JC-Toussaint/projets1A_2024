#include "sonde.h"

/* 
Initialisation des parametres des astres du systeme solaire
et des elements orbitaux des planetes reference J2000 
*/

void InitAstreDB(Astre *astre)
{
// Sun
Astre *Sun=&(astre[0]); 	// Sun alias de astre[0]
strcpy(Sun->name, "Sun");
Sun->mass=1.989e+30;
	{
	OrbitalElement *orbit=&(Sun->orbitJ2000);	// orbit alias de astre[0].orbit
	orbit->a=0.;
	orbit->e=0.;
	orbit->i=0.;
	orbit->O=0.;
	orbit->w=0.;
	orbit->L=0.;

	OrbitalElement *rate=&(Sun->rateJ2000);
	rate->a=0.;
	rate->e=0.;
	rate->i=0.;
	rate->O=0.;
	rate->w=0.;
	rate->L=0.;
	}
	
// Mercury
Astre *Mercury=&(astre[1]); 	// Mercury alias de astre[1]
strcpy(Mercury->name, "Mercury");
Mercury->mass=3.303e+23;
	{
	OrbitalElement *orbit=&(Mercury->orbitJ2000);	// orbit alias de astre[1].orbit
	orbit->a=0.38709893;
	orbit->e=0.20563069;
	orbit->i=7.00487 ;
	orbit->O=48.33167;
	orbit->w=77.45645;
	orbit->L=252.25084 ;

	OrbitalElement *rate=&(Mercury->rateJ2000);
	rate->a=+0.00000066;
	rate->e=+0.00002527;
	rate->i=-23.51;
	rate->O=-446.30;
	rate->w=+573.57;
	rate->L=+538101628.29;
	}

Astre *Venus=&(astre[2]); 	// Venus alias de astre[2]
strcpy(Venus->name, "Venus");
Venus->mass=4.869e+24;
	{
	OrbitalElement *orbit=&(Venus->orbitJ2000);	// orbit alias de astre[2].orbit
	orbit->a=+0.72333199;
	orbit->e=+0.00677323;
	orbit->i=+3.39471;
	orbit->O=+76.68069;
	orbit->w=+131.53298;
	orbit->L=+181.97973 ;

	OrbitalElement *rate=&(Venus->rateJ2000);
	rate->a=+0.00000092;
	rate->e=-0.00004938;
	rate->i=-2.86;
	rate->O=-996.89;
	rate->w=-108.80;
	rate->L=+210664136.06;
	}

Astre *Earth=&(astre[3]); 	// Earth alias de astre[3]
strcpy(Earth->name, "Earth");
Earth->mass=5.976e+24;
	{
	OrbitalElement *orbit=&(Earth->orbitJ2000);	// orbit alias de astre[3].orbit
	orbit->a=+1.00000011;
	orbit->e=+0.01671022;
	orbit->i=+0.00005; 
	orbit->O=-11.26064; 
	orbit->w=+102.94719; 
	orbit->L=+100.46435; 

	OrbitalElement *rate=&(Earth->rateJ2000);
	rate->a=-0.00000005;
	rate->e=-0.00003804;
	rate->i=-46.94;
	rate->O=-18228.25;
	rate->w=+1198.28;
	rate->L=+129597740.63;
	}

Astre *Mars=&(astre[4]); 	// Earth alias de astre[4]
strcpy(Mars->name, "Mars");
Mars->mass=6.421e+23;
	{
	OrbitalElement *orbit=&(Mars->orbitJ2000);	// orbit alias de astre[4].orbit
	orbit->a=+1.52366231; 
	orbit->e=+0.09341233; 
	orbit->i=+1.85061;    
	orbit->O=+49.57854;   
	orbit->w=+336.04084;  
	orbit->L=+355.45332;  

	OrbitalElement *rate=&(Mars->rateJ2000);
	rate->a=-0.00007221; 
	rate->e=+0.00011902; 
	rate->i=-25.47;	   
	rate->O=-1020.19;    
	rate->w=+1560.78;    
	rate->L=+68905103.78;
	}

Astre *Jupiter=&(astre[5]); 	// Jupiter alias de astre[5]
strcpy(Jupiter->name, "Jupiter");
Jupiter->mass=1.900e+27;
	{
	OrbitalElement *orbit=&(Jupiter->orbitJ2000);	// orbit alias de astre[5].orbit
	orbit->a=+5.20336301; 
	orbit->e=+0.04839266; 
	orbit->i=+1.30530;   
	orbit->O=+100.55615;   
	orbit->w=+14.75385;  
	orbit->L=+34.40438;  

	OrbitalElement *rate=&(Jupiter->rateJ2000);
	rate->a=+0.00060737; 
	rate->e=-0.00012880; 
	rate->i=-4.15;	   
	rate->O=+1217.17;    
	rate->w=+839.93;     
	rate->L=+10925078.35;
	}

Astre *Saturn=&(astre[6]); 	// Saturn alias de astre[6]
strcpy(Saturn->name,"Saturn");
Saturn->mass=5.688e+26;
	{
	OrbitalElement *orbit=&(Saturn->orbitJ2000);	// orbit alias de astre[6].orbit
	orbit->a=+9.53707032;  
	orbit->e=+0.05415060;  
	orbit->i=+2.48446;    
	orbit->O=+113.71504;    
	orbit->w=+92.43194;   
	orbit->L=+49.94432;   

	OrbitalElement *rate=&(Saturn->rateJ2000);
	rate->a=-0.00301530;
	rate->e=-0.00036762;
	rate->i=+6.11;	  
	rate->O=-1591.05;   
	rate->w=-1948.89;   
	rate->L=+4401052.95;
	}

Astre *Uranus=&(astre[7]); 	// Uranus alias de astre[7]
strcpy(Uranus->name,"Uranus");
Uranus->mass=8.686e+25;
	{
	OrbitalElement *orbit=&(Uranus->orbitJ2000);	// orbit alias de astre[7].orbit
	orbit->a=+19.19126393;  
	orbit->e=+0.04716771;   
	orbit->i=+0.76986;     
	orbit->O=+74.22988;      
	orbit->w=+170.96424;   
	orbit->L=+313.23218;   

	OrbitalElement *rate=&(Uranus->rateJ2000);
	rate->a=+0.00152025;   
	rate->e=-0.00019150;   
	rate->i=-2.09;	     
	rate->O=-1681.40;      
	rate->w=+1312.56;      
	rate->L=+1542547.79;   
	}

Astre *Neptune=&(astre[8]); 	// Neptune alias de astre[8]
strcpy(Neptune->name,"Neptune");
Neptune->mass=1.024e+26;
	{
	OrbitalElement *orbit=&(Neptune->orbitJ2000);	// orbit alias de astre[8].orbit
	orbit->a=+30.06896348; 
	orbit->e=+0.00858587;  
	orbit->i=+1.76917;    
	orbit->O=+131.72169;    
	orbit->w=+44.97135;   
	orbit->L=+304.88003;  

	OrbitalElement *rate=&(Neptune->rateJ2000);
	rate->a=-0.00125196;  
	rate->e=+0.00002510;  
	rate->i=-3.64; 	   
	rate->O=-151.25;	    
	rate->w=-844.43;	    
	rate->L=+786449.21;   
	}

Astre *Pluto=&(astre[9]); 	// Pluto alias de astre[9]
strcpy(Pluto->name,"Pluto");
Pluto->mass=1.27e+22;
	{
	OrbitalElement *orbit=&(Pluto->orbitJ2000);	// orbit alias de astre[9].orbit
	orbit->a=+39.48168677;
	orbit->e=+0.24880766; 
	orbit->i=+17.14175;   
	orbit->O=+110.30347;   
	orbit->w=+224.06676;  
	orbit->L=+238.92881;  

	OrbitalElement *rate=&(Pluto->rateJ2000);
	rate->a=-0.00076912;
	rate->e=+0.00006465;
	rate->i=+11.07;
	rate->O=-37.33;
	rate->w=-132.25;
	rate->L=+522747.90;    
	}
}
