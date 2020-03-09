/*
Autor: josecano
Compilador: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
Compilado: gcc Primos2.c -o Primos2
Fecha: Mon Mar 9 21:33:22 UTC 2020
Librerias: stdio, otras librerias
Resumen: Este arvhico muestra todos los números primos que eas superior e inferior, proveídas por el usuario.
Entrada:  sup, inf
Salida:  primos
*/

//Incluir librerias
#include <stdio.h>
//Declarar variables globales

//Iniciamos nuestra función

int main()
{

	int sup, inf;//Declaramos dos variables que serivirán para delimitar el proceso iterativo: las cotas superior e inferior.
	
//Escaneamos la cota inferior, para darle a nuestro proceso, un número a partir del cuál empezar a calcular.
	printf("Por favor, ingrese una cota inferior\n");
	scanf("%d", &inf); 

	while(inf<=1)//No queremos ni el uno, ni el cero, ni números negativos en el programa, y con este WHILE nos aseguramos de que el usuario solo ingrese positivos mayores a uno.
	{
		printf("El número que ingresó no es válido.\n\nPor favor, ingrese una cota inferior\n");
		scanf("%d", &inf);//Seguirá escaneando hasta que el valor sea mayor a uno.
	}


//Ahora es el turno de escanear una cota superior que nos diga cuándo terminar el proceso.
	printf("Por favor, ingrese una cota superior\n"); 
	scanf("%d", &sup);

	while(sup<=inf)//No tiene sentido hablar de una cota Superior que sea menor a la Inferior, así que en caso de que se ingrese algo así, se pedirá al usuario que ingrese un dato distinto.
	{	
		if(sup==inf)//También evitamos que las dos cotas sean iguales, pues en dado caso, el programa ya no tiene chiste.
		{
			printf("Las cotas superior e inferior no pueden ser las mismas.\n\nPor favor, ingrese una cota superior\n");
		}
	
		else if(sup<=1)//En caso de que el número cero, uno, o negativo, se notificará que el número no es válido.
		{
			printf("El número que ingresó no es válido.\n\nPor favor, ingrese una cota superior.\n");
		}

		else //Por último, tampoco podemos permitir que la cota superior sea menor a la inferior.
		{
			printf("La cota superior no puede ser menor a la inferior.\n\nPor favor, ingrese una cota superior\n");
		}


		scanf("%d", &sup);//Seguimos escaneando la cota superior hasta que se cumplan los requisitos.
	}


//Imprimimos un pequeño texto para que el usuario distinga la respuesta.
	printf("\nLos números primos en el intervalo [%d,%d] son:\n", inf, sup);


//Terminadas nuestras condicionales para los datos ingresados por el usuario, ya podemos comenzar el proceso.


	while(inf <= sup) //Iremos analizando cada número desde la cota inferior hasta la superior, pero como el intervalo es cerrado, también debemos incluir las dos cotas en la lista.

	{
		int Divisible = 0; //Nuestra flag para el ciclo FOR.

		for(int x = 2; x < inf; x++)//La verificación empieza, por supuesto, desde el número dos, pero debe terminar en la cota inferior para verificar si es primo o no.
		{
			if(inf%x ==0)
			{
				Divisible = 1;
			}
		}

		if(Divisible == 0) 
		{
			printf("%d\n", inf);
		}
	
		inf++; //Si no es divisible, entonces el número será añadido a la lista, y el ciclo WHILE pasará a analizar el siguiente número en la sucesión, hasta llegar a la cota superior.
	}
	



return 0;
}


