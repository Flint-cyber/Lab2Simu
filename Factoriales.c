/*
Autor: josecano
Compilador: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
Compilado: gcc Factoriales.c -o Factoriales
Fecha: Mon Mar 23 20:27:22 UTC 2020
Librerias: stdio, otras librerias
Resumen: Este programa calcula el factorial de un número dado por el usuario
Entrada:  num
Salida:  factorial
*/

//Incluir librerias
#include <stdio.h>


long FunFac(int i)

{

	if(i==0)
	{
		return 1;
	}

	else
	{
		return (i*FunFac(i-1));
	}

}




int main()

{

	int num;
	long fac;

	printf("Por favor, ingrese un entero positivo.\n");
	scanf("%d", &num);

	while(num < 0)
	{
		printf("El número que ingresó no es válido\n\nPor favor, ingrese un número.\n");
		scanf("%d", &num);
	}

	
	fac = FunFac(num);

	printf("El factorial de %d es: %ld.\n", num, fac);

return 0;

}


