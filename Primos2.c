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
	scanf("%d", &inf); //Escaneamos el valor, y se lo asignamos a la variable inferior.

	while(inf<=1)//No queremos ni el uno, ni el cero, ni números negativos en el programa, y con este WHILE,
			//nos aseguramos de que el usuario solo ingrese positivos mayores a uno.
	{
		printf("El número que ingresó no es válido.\n\nPor favor, ingrese una cota inferior\n");
		scanf("%d", &inf);//Seguirá escaneando hasta que el valor sea mayor a uno.
	}


//Ahora es el turno de escanear una cota superior que nos diga dónde terminar el proceso.
	printf("Por favor, ingrese una cota superior\n"); 
	scanf("%d", &sup); //Escaneamos el valor, y se lo asignamos a la variable superior.

	while(sup<=inf)//No tiene sentido hablar de una cota Superior que sea menor a la Inferior, 
			//así que en caso de que se ingrese algo así, se pedirá al usuario que ingrese un dato distinto.
	{	
		if(sup==inf)//Aquí evitamos que las dos cotas sean iguales, pues en dado caso, el programa ya no tiene chiste.
		{
			printf("Las cotas superior e inferior no pueden ser las mismas.\n\nPor favor, ingrese una cota superior\n");
		}
	
		else if(sup<=1)//Aquí, evitamosque el número cero, uno, o negativo.
		{
			printf("El número que ingresó no es válido.\n\nPor favor, ingrese una cota superior.\n");
		}

		else //Por último, aqúi, en cualquier otro caso, solo impedimos que la cota superior sea menor a la inferior.
		{
			printf("La cota superior no puede ser menor a la inferior.\n\nPor favor, ingrese una cota superior\n");
		}


		scanf("%d", &sup);//Seguimos escaneando la cota superior hasta que se cumplan todos los requisitos.
	}


//Imprimimos un pequeño texto y generamos una nueva línea, para que el usuario distinga la respuesta más fácilmente
	printf("\nLos números primos en el intervalo [%d,%d] son:\n", inf, sup);
	
//Escribimos [] para dar a entender que las cotas inferior y superiro, de ser primas, irán incluidas en la lista.
//Esto ya que es un intervalo cerrado.


//Terminadas nuestras condicionales para los datos ingresados por el usuario, ya podemos comenzar el proceso.


	while(inf <= sup) 
//Iremos analizando cada número desde la cota inferior hasta la superior, pero como el intervalo es cerrado, 
//también debemos incluir las dos cotas en la lista.

	{
		int Divisible = 0; //Nuestra flag para el ciclo FOR, la divisibilidad del número, empieza en cero.
				   //Esto porque comenzamos asumiendo que el número es primo.

		//Dentro del While, metemos el proceso de verificación de primos que habíamos realizado previamente: Primos1.c
		
		for(int x = 2; x < inf; x++) //Comenzamos el conteo en 2 pues todos los números son divisibles en 1.

		{
			if(inf%x ==0) //Verificamos si el residuo es cero.
			{
				Divisible = 1; //Si al menos uno de ellos es cero, se activa la Flag que indica que es divisible.
			}
		}

		if(Divisible == 0) 
		{
			printf("%d\n", inf); //Si en ningún momento existe divisibilidad, entonces el número analizado será impreso.
					     //En caso contrario, si hay divisibilidad, será ignorado.
		}
	
		inf++; //Luego de haber analizado la divisibilidad y luego de haberse impreso o ignorado el número,
			//la cota inferior aumentará en uno, nuestro ciclo WHILE pasará a analizar el siguiente número en la sucesión, 
			//y seguirá así hasta llegar a la cota superior.
	}
	
return 0;
}


