/*
Autor: josecano
Compilador: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
Compilado: gcc Orden1.c -o Orden1
Fecha: Thu Mar 26 17:43:27 UTC 2020
Librerias: stdio, otras librerias
Resumen: Este archivo guarda un arreglo de 10 números pares del 2 al 20. Se le dará la elección al usuario de verlos en forma ascendente o descendente. El proceso de ordenamiento irá inscrito en el código.
Entrada:  x
Salida:  nums
*/

//Incluir librerias
#include <stdio.h>


int main()
{
	int par[10] = {4, 2, 8, 6, 12, 10, 18, 20, 14, 16};
	char x;
	int j, i, k;

	printf("Este programa contiene un arreglo de 10 números pares.\n");
	printf("Presione 'a' para verlos de forma ascendente.\n");
	printf("Presione 'd' para verlos de forma descendente.\n");


	scanf("%c", &x);

	while(x != 'a' && x != 'd')
		
	{
		printf("\nEl caracter que ingresó no es válido.\n\nPresione 'a' para verlos de forma ascendente.\nPresione 'd' para verlos de forma descendente.\n");
		scanf("%c", &x);
	}

	
	if(x == 'a')
	{
		printf("\nNúmeros ordenados de forma Ascendente: \n");
		
			for(i = 0; i < 10; i++)
			{
				for(j = i + 1; j < 10; j++)
				{

					if(par[i] >  par[j])
					{
						x = par[i];
						par[i] = par[j];
						par[j] = x;	
					}
				}
			}


			for(i = 0; i < 10; i++)
			{
				printf("%i\n", par[i]);
			}
	}






	if(x == 'd')
	{
		printf("\nNúmeros ordenados de forma Descendente: \n");

		for(i = 9; i >= 0; i--)
		{
			for(j = i - 1; j >= 0; j--)
			{
				if(par[i] > par[j])
				{
					x = par[i];
					par[i] = par[j];
					par[j] = x;
				}
			}
		}


		for(i = 0; i < 10; i++)
		{
			printf("%i\n", par[i]);
		}



	}





	return 0;
}
