#include <stdio.h>
#include <stdlib.h>
#include "array2D.h"

int** array2D(int nrl, int nrh, int ncl, int nch)
/* array allocation t[nrl..nrh][ncl..nch]*/
{
	int nrow=nrh-nrl+1;
	int ncol=nch-ncl+1;
	int  **t;

	t=(int**)malloc(nrow*sizeof (int*));
	if (!t)
		{
   		fprintf(stderr, "Error : memory allocation aborted\n");
	   	exit(1);
	   	}
	t -= nrl;

	for (int i=nrl; i<=nrh; i++)
   	{
	t[i]=(int*) malloc(ncol*sizeof(int));
	if (!t[i])
		{
	   	fprintf(stderr, "Error : memory allocation aborted\n");
	   	exit(1);
	   	}
	t[i] -= ncl;
	}

return t;
}

void initArray2D(int **t, int nrl, int nrh, int ncl, int nch)
{
for (int i=nrl; i<=nrh; i++)
for (int j=ncl; j<=nch; j++)
	{
	t[i][j]=0;
	}
}

void freeArray2D(int **t, int nrl, int nrh, int ncl, int nch)
{
for (int i=nrl; i<=nrh; i++)
    {
    free(t[i]+ncl);
    }

free(t+nrl);
}

