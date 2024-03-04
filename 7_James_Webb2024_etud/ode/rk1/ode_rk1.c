/* Pour compiler le programme ode.c
	gcc -I /usr/extralib/include/ ode_rk1.c -o ode -lg2 -lm

   Pour l’exécuter
	./ode
*/

#include <stdio.h>
#include <math.h>

enum status { SUCCESS, ERROR };

/* DIM dimension du systeme d'equations */
#define DIM 4

/* ecriture du systeme d'equations differentielles du 1er ordre  */
/* eq du ressort en 2D sous la forme dyvec/dt = fvec	*/

int fonction (double t, const double *yvec, double *fvec, void *params)
{
  double x =yvec[0];
  double y =yvec[1];
  double vx=yvec[2];
  double vy=yvec[3];

  fvec[0] = vx;		
  fvec[1] = vy;
  
  fvec[2] = -x;
  fvec[3] = -y;
  
  return SUCCESS;
}

int evolve_rk1(double *t, double h, double *yvec){
double fvec[DIM];
int status=fonction(*t, yvec, fvec, NULL);
if (status) return status;

for (int i=0; i<DIM; i++){
    yvec[i] += h*fvec[i];
    }
*t += h;
return SUCCESS;
}

int main()
{
/* temps initial et temps final */
  double t = 0.0, tfin = 10.0;

/* pas fixe d'integration des equations diff */  
  double h = 0.01;
  
/* conditions initiales {x0 y0 x0' y0'} */  
  double y[DIM] = { 1.0, 1.0, 0., 0. };

  for (;;)
    {
    int status = evolve_rk1 (&t, h, y);
    if (status != SUCCESS) break;
      
    printf("%lf \t %lf \t %lf \t %lf\n", t, h, y[0], y[1]);
    if (t>=tfin) break;  
    }

}
