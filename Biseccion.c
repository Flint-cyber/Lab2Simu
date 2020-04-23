/*
Autor: josec
Compilador: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
Compilado: gcc bis.c -o bis
Fecha: Wed Apr 22 09:47:03 CST 2020
Librerias: stdio, math
Resumen: Este programa calcula la raíz de una función matemática a través del método iterativo de bisección
Entrada:  
Salida: raíz
*/


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float a, b, root;
int i;

float bis (float na, float nb);


float main()
{
	
	printf("La Función es: y = (sin(x)/x)\n");
	printf("\nEl intervalo seleccionado es: [1,5]\n");
	
	a = 1;
	b = 5;

	root = bis(a, b);

	printf("\nLa raíz de esta función es:\t");
	printf("%.5f\n", root);




	//IMPRESIÓN DE LA GRÁFICA
	

	FILE * pun;

	pun = fopen("plot2.gp", "w");

	fprintf(pun, "plot [-10:10][-0.5:1.2] sin(x)/x lw 4, 0 lw 4;");

	fclose(pun);

	system("gnuplot -p plot2.gp");

	remove ("plot2.gp");



	return 0;

}




float bis (float na, float nb)
{
	float np, xp, xa, res;


	for(i = 0; i < 20; i++)
	{
		np = (na + nb)/2;
		
		xp = (sin(np)/np);
		xa = (sin(na)/na);
		res = xp*xa;

		if(res > 0)
		{
			na = np;
		}

		else if(res < 0)
		{
			nb = np;
		}


	}

		return np;


}




