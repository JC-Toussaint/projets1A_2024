#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "array2D.h"

int main()
{
double r;

int N=10;    
int **t=array2D(0, N, 0, N);
initArray2D (t, 0, N, 0, N); 

for (int i=1; i<N; i++) {
    for (int j=1; j<N; j++) {
        printf("%d ", t[i][j]);
    }
printf("\n");
}
                
freeArray2D(t, 0, N, 0, N);        
}
