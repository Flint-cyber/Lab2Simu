/*
Autor: josecano
Compilador: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
Compilado: gcc Orden2.c -o Orden2
Fecha: Thu Mar 26 19:09:26 UTC 2020
Librerias: stdio, otras librerias
Resumen: Este programa creará un vector cuyas componentes serán dadas por el usuario. A continuación, el programa pasará a ordenar el vector de forma ascendente.
Entrada:  x
Salida:  vec
*/

//Incluir librerias
#include <stdio.h>

int main()
{
	int Vec[5];
	int i, j, k;

	printf("Por favor, ingrese 5 números enteros para su Vector\n");

	for(i = 0; i < 5; i++)
	{
		scanf("%i", &Vec[i]);
	}


	printf("\nSu vector, ordenado de forma ascendente, es el siguiente:\n");


	for(i = 0; i < 5; i++)
	{
		for(j = i + 1; j < 5; j++)
		{
			if(Vec[i] > Vec[j])
			{
				k = Vec[i];
				Vec[i] = Vec[j];
				Vec[j] = k;
			}
		}
	}


	for(i = 0; i < 5; i++)
	{
		printf("%i\n", Vec[i]);
	}




return 0;

}

