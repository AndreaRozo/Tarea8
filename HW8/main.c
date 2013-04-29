// Universidad de los Andes
// Andrés Felipe García Albarracín
// Andrea Rozo Méndez
// Tarea 8

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "functions.h"


int main(int argc, char **argv)
{
	if(argc != 8)
	{
		printf ("Número de parametros incorrecto \n");
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

	FILE *fileout;

	printf("puntos t: %d\n", n_points_t);
	printf("puntos x: %d\n", n_points_x);
	printf("CondIni: %d\n", condIni);

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

	// Creación del vector de tiempo
	for (i = 0; i < n_points_t; i++)
	{
		t[i] = t0 + i*dt;
	}	
	
	// Creación de los vectores de posición
	char nombre[256] = "VectorX_CondIn";
	char numb[5];
	sprintf(numb,"%d",condIni);
	strcat(nombre,numb);
	strcat(nombre,".txt");
	fileout = fopen(nombre,"w");
	for (i = 0; i < n_points_x; i++)
	{
		x[i] = x0 + i*dx;
		fprintf(fileout,"%f\n",x[i]);
	}
	fclose(fileout);

	if (condIni == 1)
	{
		f1(n_points_x, x, u_init);
	}
	
	else if (condIni == 2)
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
	u_new [n_points_x-1] = 0.0;
	u_old [0] = 0.0;
	u_old [n_points_x-1] = 0.0;
	printf("CondIni: %d\n", condIni);

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
			char nombreArchivo[256] = "Graf";
			char num[5];
			sprintf(num,"%d",j/(n_points_t/10));
			strcat(nombreArchivo,num);
			strcat(nombreArchivo,"_CondIn");
			sprintf(num,"%d",condIni);
			strcat(nombreArchivo,num);
			strcat(nombreArchivo,".txt");
			fileout = fopen(nombreArchivo,"w");
			for (i = 0; i < n_points_x; i++)
			{
				fprintf(fileout,"%f\n",u_new[i]);
			}
			fclose(fileout);
		}			

	}
	return 0;
}

