#include "gsl_matrix_ext.h"

void gsl_matrix_add_value(gsl_matrix * m, int i, int j, double value)
{
double z=gsl_matrix_get(m, i, j);
z+=value;
gsl_matrix_set(m, i, j, z);
}

