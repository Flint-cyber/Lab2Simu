/*
Autor: josecano
Compilador: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
Compilado: gcc Factoriales.c -o Factoriales
Fecha: Mon Mar 23 20:27:22 UTC 2020
Librerias: stdio
Resumen: Este programa calcula el factorial de un número dado por el usuario
Entrada:  num
Salida:  fac
*/

#include <stdio.h>


long FunFac(int i) //Inicializamos nuestra función recursiva.
{
	if(i==0) //Cero factorial es igual a uno, así que a partir de este valor base, podemos construir la recursividad.
		//Si el valor de i es cero, solo retornará uno.
	{
		return 1;
	}

	else //Si el valor de i NO es cero, entonces procederá a multiplicar i por la función valuada en i menos uno.
		//Irá así, sucesivamente, hasta toparse con que i es igual a cero. 
		//Retornará uno, y se irá en reversa, multiplicándolo por los siguientes números hasta llegar al i original.
	{
		return (i*FunFac(i-1)); //Retornamos el valor de i factorial.
	}

}




int main() 

{

	int num; //Declaramos variable de entrada
	long fac; //Declaramos variable de salida.

	printf("Por favor, ingrese un entero positivo.\n"); //Pedimos al usuario que ingrese el número cuyo factorial quiere saber.
	scanf("%d", &num); //Escaneamos el dato ingresado.

	while(num < 0) //Queremos solo factoriales de números mayores o iguales a cero.
			//Esto debido a que los factoriales de enteros negativos tienden a infinito y menos infinito.
			//Así que usamos este while para asegurarnos de que solo se ingresen números mayores o iguales a cero.
	{
		printf("El número que ingresó no es válido\n\nPor favor, ingrese un número.\n"); //Notificamos al usuario de su error.
		scanf("%d", &num); //Seguimos escaneando hasta que se cumpla con el criterio.
	}

	
	fac = FunFac(num); //Igualamos nuestra variable de salida a lo que nos regrese la función FunFac valuada en num.

	printf("El factorial de %d es: %ld.\n", num, fac); //Imprimimos el factorial.

return 0;

}


