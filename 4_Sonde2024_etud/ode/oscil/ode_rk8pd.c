/* Pour compiler le programme ode.c
	gcc -I /usr/extralib/include/ ode.c -o ode -lgsl -lgslcblas -lm

   Pour l’exécuter
	Export LD_LIBRARY_PATH = $HOME/extralib:$LD_LIBRARY_PATH
	./ode
*/

#include <stdio.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_odeiv.h>
#include <gsl/gsl_ieee_utils.h>

/* DIM dimension du systeme d'equations */
#define DIM 4

/* limite supérieure du pas d’intégration */
const double hmax=0.01 ;

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
  
  return GSL_SUCCESS;
}

int main()
{
  const gsl_odeiv_step_type * T = gsl_odeiv_step_rk8pd;
  gsl_odeiv_step * s = gsl_odeiv_step_alloc (T, DIM);	

/* controle de la precision de calcul */  
  gsl_odeiv_control * c = gsl_odeiv_control_y_new (0., 1.e-6);
  gsl_odeiv_evolve * e  = gsl_odeiv_evolve_alloc (DIM); 
  gsl_odeiv_system sys = {fonction, NULL, DIM, NULL};

/* temps initial et temps final */
  double t = 0.0, tfin = 10.0;
/* pas initial d'integration des equations diff */  
  double h = hmax;
  
/* conditions initiales {x0 y0 x0' y0'} */  
  double y[DIM] = { 1.0, 1.0, 0., 0. };

  gsl_ieee_env_setup();

  for (;;)
    {
    int status = gsl_odeiv_evolve_apply (e, c, s,
                                         &sys, 
                                         &t, tfin,
                                         &h, y);

    if (status != GSL_SUCCESS) break;
      
/* ---- limite sup du pas d'integration fixee par l'utilisateur */  
   
    if (h>hmax) h=hmax;

/* ------*/    
  
    printf("%lf \t %lf \t %lf \t %lf\n", t, h, y[0], y[1]);
    if (t>=tfin) break;  
    }

  gsl_odeiv_evolve_free(e);
  gsl_odeiv_control_free(c);
  gsl_odeiv_step_free(s);
}
