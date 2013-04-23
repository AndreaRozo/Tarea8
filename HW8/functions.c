// Universidad de los Andes
// Andrés Felipe García Albarracín
// Andrea Rozo Méndez

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>

double f1(int size; double *x, double *u_in)
{
	int j;
	for (j = 0; j<size; j++)
	{
		u_in[j] = 4*x[j]*(1-x[j]));
	}
}

double f2(int size; double *x, double *u_in)
{
	int j;
	for (j = 0; j<size; j++)
	{
		u_in[j] = exp(-x[j]*x[j]);
	}
}
