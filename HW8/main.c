// Universidad de los Andes
// Andrés Felipe García Albarracín
// Andrea Rozo Méndez
// Tarea 8

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <functions.h>

int main(int argc, char **argv)
{
	if(arcg != 8)
	{
		printf ("Numero de parametros incorrecto");
		exit(1);
	}

	int	 i;
	int	 j;
	double x0 = atof(argv[1]);
	double xf = atof(argv[2]);
	double t0 = atof(argv[3]);
	double tf = atof(argv[4]);
	double dt = atof(argv[5]);
	double dx = atof(argv[6]);
	int condIni = atoi(argv[7]);

	int n_points_t = (tf-t0)/dt;
	int n_points_x = (xf-x0)/dx;

	double a = dt/(dx*dx);  // alpha
	
	if (a > 0.5)
	{
		printf ("No existe estabilidad en el método. Escoja otro valor de dt y dx");
		exit(1);
	}

	double *t = malloc(n_points_t*sizeof(double));
	double *x = malloc(n_points_x*sizeof(double));
	double *u_new = malloc(n_points_x*sizeof(double));
	double *u_old = malloc(n_points_x*sizeof(double));
	double *u_init = malloc(n_points_x*sizeof(double));

	if (!t || !x || !u_new || !u_old || !u_init)
	{
		printf ("Error al crear los arreglos");
		exit(1);
	}

	// Creación de los vectores de posición
	for (i = 0; i < n_points_x; i++)
	{
		x[i] = x0 + i*dx;
	}

	if (condIni = 1)
	{
		f1(n_points_x, x, u_init);
	}
	
	else if (condIni = 2)
	{
		f2(n_points_x, x, u_init);
	}
	
	else
	{
		printf ("Condición inicial no válida");
		exit(1);
	}

	// Iteraciones - condición inicial
	for (i = 0; i < n_points_x; i++)
	{
		u_old[i] = u_init[i];
	}

	//condiciones de frontera
	u_new [0] = 0.0;
	u_new [n_points-1] = 0.0;
	u_old [0] = 0.0;
	u_old [n_points-1] = 0.0;
	for (j = 0; j < n_points_t; j++)
	{
		
		for (i = 1; i < n_points_x-1; i++)
		{
			u_new[i] = a*u_old[i+1] + (1-2*a)*u_old[i] + a*u_old[i-1];
		}
		for (i = 1; i < n_points_x-1; i++)
		{
			u_old[i] = u_new[i];
		}
		if (j%(n_points_t/10) == 0)
		{
			FILE *out;
			char nombreArchivo[256] = "Grafica";
			char num[5];
			sprintf(num,"%f",t[j]);
			strcat(nombreArchivo,num);
			strcat(nombreArchivo,"_CondicionInicial");
			sprintf(num,"%d",condIni);
			strcat(nombreArchivo,num);
			strcat(nombreArchivo,".txt");
			out = fopen(nombreArchivo,'w');

			for (i = 1; i < n_points_x-1; i++)
			{
				fprintf(out,"%f		%f\n",x[i],u_new[i]);
			}
			
			fclose(out);
		}			

	}

	

