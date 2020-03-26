/*
Autor: josecano
Compilador: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
Compilado: gcc Factoriales.c -o Factoriales
Fecha: Mon Mar 23 20:27:22 UTC 2020
Librerias: stdio, otras librerias
Resumen: Este programa calcula el resultado de cuatro sumatorias distintas, desde un número inicial, hasta un número final dado por el usuario.
Entrada:  num
Salida:  suma, sumb, sumc, sumd
*/

#include <stdio.h>
#include <math.h>




double Sumac (int n)
	
{

	if(n==1)
	{
		return 1;
	}

	else
	{
		return ( pow(5, -0.5)*(pow(0.5,n)*( (pow(1+sqrt(5),n) - (pow(1-sqrt(5),n)))) + pow(0.5, n - 1)*(pow(1 + sqrt(5), n-1) - pow(1-sqrt(5), n-1))));
	}

}




double main()

{

	int num;
	double suma, sumb, sumc, sumd;


	printf("Por favor, ingrese un entero positivo.\n");
	scanf("%d", &num);



	while(num < 0)
	{
		printf("El número que ingresó no es válido\n\nPor favor, ingrese un número.\n");
		scanf("%d", &num);
	}



	//PRIMERA SUMATORIA
	
	if(num <=3)
	{
		printf("\nLa Primera Sumatoria no es Válida en este número\n");
	}

	else
	{
		suma = 0;

		for(int k = 4; k <= num; k++)
		{
			suma = suma + pow(k, 2)*(k - 3);
		}

		printf("\nResultado de la Primera Sumatoria: %f\n", suma);
	}





	//SEGUNDA SUMATORIA

	if(num == 1)
	{
		printf("\nLa Segunda Sumatoria tiende a Infinito\n");
	}
	
	else
	{
		sumb = 0;

		for(int k = 2; k <= num; k++)
		{
			sumb = sumb + 3*pow(k - 1, -1);
		}


		printf("\nResultado de la Segunda Sumatoria: %f\n", sumb);
	}



	//TERCERA SUMATORIA
	sumc =  Sumac(num);

	printf("\nResultado de la Tercera Sumatoria: %f\n", sumc);



	//CUARTA SUMATORIA
	
	if(num==1)
	{
		printf("\nLa Cuarta Sumatoria no es válida en este número.\n");
	}

	else
	{
		sumd = 0;

		for(int k = 2; k <= num; k++)
		{
			sumd = sumd + 0.1*(3*pow(2,k-2) + 4);
		}

		printf("\nResultado de la Cuarta Sumatoria: %f\n", sumd);
	}



return 0;

}


