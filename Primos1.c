/*
Autor: josecano
Compilador: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
Compilado: gcc Primos1.c -o Primos1
Fecha: Sun Mar 8 21:52:11 UTC 2020
Librerias: stdio, otras librerias
Resumen: Este programa busca verificar si el numero ingresado es primo o no
Entrada:  primo
Salida:  res
*/

//Incluir librerias
#include <stdio.h> 
//Declarar variables globales


//Iniciamos nuestra función

int main()
{
	//Declaramos Variables
	int primo; //Esta será la variable que ingresará el usuario
	int Divisible=0;//Esta será nuestra FLAG para el ciclo FOR
	
	printf("Por favor, ingrese un número.\n"); 
	//Comenzamos pidiéndole un valor  al usuario

	scanf("%d", &primo); 
	//Leemos el número y le asignamos su valor a nuestra variable 


//Este primer ciclo WHILE nos permitirá descartar los números no deseados: los negativos, el cero, y el uno.
	
	while(primo<=1)
	{
		printf("El número %d no es válido.\n\nPor favor, ingrese un número.\n", primo);
	scanf("%d", &primo);
	}

	
//Haremos un método interativo, sacando el residuo de la variable con todos los números que vayan antes de él, exceptuando al uno, y a él mismo, pues esos dos son los únicos divisores de un primo, y de excluirlos, todos los números quedarían excluidos. Por ello empezamos en dos y terminamos justo antes de la variable primo.


	for (int x = 2; x < primo; x++) //Comenzamos el conteo
	{


		if(primo%x == 0) 
		//Sacamos los residuos correspondientes para cada iteración
		{
			Divisible=1; 
		//Si todos los residuos son cero, entonces desde el vamos         		sabemos que NO es primo.
		}
	}

	if(Divisible==0) 
	//Una pequeña condicional para imprimir los resultados basándonos en los	 resultados obtenidos a través del método interativo.
	{
		printf("El número %d es PRIMO.\n", primo);
	}
	
	else if (Divisible==1)
	{
		printf("El número %d es COMPUESTO.\n", primo);
	}
	
//Procedemos, finalmente, a imprimir los resultados para el usuario.

return 0;
}
