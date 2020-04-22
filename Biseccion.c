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

//Incluir librerias
#include <stdio.h>
#include <math.h>

float p1, p, a, b;
float X;
int i, j;
float bis (float np, float na, float nb);


float main()
{
	
	printf("La Función es: y = (sin(x)/x)\n");
	printf("\nEl intervalo seleccionado es: [1,5]\n");
	
	float root = bis(3, 1, 5);

	printf("\nLa raíz de esta función es:\t");
	printf("%.5f\n", root);


	return 0;

}




float bis (float np, float na, float nb)
{
	float xp, xa, res, ret;


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




