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

#include <stdio.h>


int main()
{
	int par[10] = {4, 2, 14, 6, 20, 10, 18, 12, 8, 16}; //El orden de las cantidades fue decidido por un programa de ordenamiento pseudo-aleatorio.
	char x; //La variable para decidir si se ingresó el dato correcto del 'menú'
	int j, i, k; //Las variables a utilizar en los ciclos for y while

	printf("Este programa contiene un arreglo de 10 números pares.\n"); //Inicializamos el Menú
	printf("Presione 'a' para verlos de forma ascendente.\n"); //Opción 1
	printf("Presione 'd' para verlos de forma descendente.\n"); //Opción 2


	scanf("%c", &x); //Escaneamos lo que elija presionar el usuario.

	while(x != 'a' && x != 'd') //Queremos que el usuario presione ya sea 'a', o 'b'. NADA MÁS 
				//Si lo que el usuario presiona no es NI 'a' NI 'b', entones seguiremos escaneando hasta que haga lo correcto.		
	{
		printf("\nEl caracter que ingresó no es válido.\n\nPresione 'a' para verlos de forma ascendente.\nPresione 'd' para verlos de forma descendente.\n");
		scanf("%c", &x); //Notificamos y seguimos escaneando.
	}

	//Si se presiona un valor aceptado, salimos del loop while, y pasamos a imprimir el vector ordenado.
	
	
	if(x == 'a') //Si se elije la opción 1, lo ordenamos de forma ascendente.
	{
		printf("\nNúmeros ordenados de forma Ascendente: \n"); //Enunciado para orientar al usuario
		
			for(i = 0; i < 10; i++) //Primer loop, que usa una variable i que inicia en la posición cero.
			{
				for(j = i + 1; j < 10; j++)//Segundo loop, usa una variable j que inicia una posición adelante de i.
				{
					//Comparamos i con j
					//Lo ideal es que i sea menor que j. De ser así, dejamos a i solo y pasamos al siguiente puesto.
					if(par[i] >  par[j]) //Si i es mayor que j, tenemos que intercambiar lugares.
					{
						x = par[i]; //La variable provisional x toma el valor de i
						par[i] = par[j]; //i toma el valor de j
						par[j] = x; //j toma el valor de la variable provisional x
						//Ya cambiamos de lugar a i con j.
					}
				}
			}

			//Ahora, pasamos a imprimir el vector ordenado.
			for(i = 0; i < 10; i++)  //Vamos imprimiendo cada una de las componentes desde la 0 hasta la 9.
			{
				printf("%i\n", par[i]); //Imprimimos, junto con una nueva línea, para distinguir las componentes.
			}
	}

	if(x == 'd') //Si el usuario elige la opción 2, lo ordenamos en forma descendente.
	{
		printf("\nNúmeros ordenados de forma Descendente: \n"); //Enunciado para notificar al usuario.

		for(i = 0; i <= 9; i++) //Primer loop, que usa una variable i que empieza en 0 y termina en 0
		{
			for(j = i + 1; j <= 9; j++) //Segundo loop, que usa una variable j que empieza una posición por arriba de i y termina en 9.
			{
				//Comparamos i con j
				//Lo ideal es que i sea mayor que j. De ser así, dejamos a i solo y pasamos al siguiente puesto.
				if(par[i] < par[j]) //Si i es menor que j, tenemos que intercambiar lugares.
				{
					x = par[i]; //El valor de i pasa a la variable provisional x
					par[i] = par[j]; //El valor de j pasa a estar en la posición i
					par[j] = x; //El valor de la variable provisional x pasa a estar en j
				}
			}
		}

		//Ahora toca imprimir el vector ordenado.
		for(i = 0; i < 10; i++) //Imprimimos cada una de las componentes desde 0 hasta 9
		{
			printf("%i\n", par[i]); //Junto con ello, imprimimos una nueva línea para que puedan distinguirse las componentes.
		}
	}

	
	return 0;
}
