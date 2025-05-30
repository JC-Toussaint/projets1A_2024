#include <stdio.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_linalg.h>
#include "gsl_matrix_ext.h"

int main()
{
    gsl_matrix *A = gsl_matrix_alloc(3, 3); 
    if (!A) exit(1);
    gsl_vector *x = gsl_vector_alloc(3);
    if (!x) exit(1);
    gsl_vector *b = gsl_vector_alloc(3);
    if (!b) exit(1);

    gsl_matrix_set(A, 0, 0, 1.0);
    gsl_matrix_set(A, 0, 1, 1.0);
    gsl_matrix_set(A, 0, 2, 0.0);

    gsl_matrix_set(A, 1, 0, 0.0);
    gsl_matrix_set(A, 1, 1, 1.0);
    gsl_matrix_set(A, 1, 2, 0.0);

    gsl_matrix_set(A, 2, 0, 0.0);
    gsl_matrix_set(A, 2, 1, 1.0);
    gsl_matrix_set(A, 2, 2, 1.0);
    
    gsl_vector_set(b, 0, 6.0);
    gsl_vector_set(b, 1, 20.0);
    gsl_vector_set(b, 2, 29.0);

    // allocate memory for the permutation matrix
    gsl_permutation* p = gsl_permutation_alloc(3);

    // perform LU decomposition of matrix A with permutation matrix p
    int signum;
    gsl_linalg_LU_decomp(A, p, &signum);

    // solve the linear system of equations
    gsl_linalg_LU_solve(A, p, b, x);
    
    printf("Solution:\n");
    printf("x = %g\n", gsl_vector_get(x, 0));
    printf("y = %g\n", gsl_vector_get(x, 1));
    printf("z = %g\n", gsl_vector_get(x, 2));
    
    gsl_blas_dgemv(CblasNoTrans, 1.0, A, x, -1.0, b);
    
    printf("Remainder:\n");
    printf("%g\n", gsl_vector_get(b, 0));
    printf("%g\n", gsl_vector_get(b, 1));
    printf("%g\n", gsl_vector_get(b, 2));
      
    gsl_matrix_free(A);
    gsl_vector_free(x);
    gsl_vector_free(b);

    return 0;
}


