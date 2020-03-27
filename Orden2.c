/*
Autor: josecano
Compilador: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
Compilado: gcc Orden2.c -o Orden2
Fecha: Thu Mar 26 19:09:26 UTC 2020
Librerias: stdio
Resumen: Este programa creará un vector cuyas componentes serán dadas por el usuario. A continuación, el programa pasará a ordenar el vector de forma ascendente.
Entrada:  x
Salida:  vec
*/


#include <stdio.h>

int main()
{
	int Vec[5]; //Declaramos la variable de nuestro vector
	int i, j, k; //Declaramos 3 variables que serán utilizadas en varios loops diferentes

	printf("Por favor, ingrese 5 números enteros para su Vector\n"); //Pedimos al usuario que ingrese los números de su vector, sin un orden particular.

	for(i = 0; i < 5; i++) //Este loop nos permite escanear 5 cantidades distintas en lugar de asignarle valores a cada número del array independientemente.
	{
		scanf("%i", &Vec[i]); 
	}


	printf("\nSu vector, ordenado de forma ascendente, es el siguiente:\n"); //Texto para ayudar a orientar al usuario.


	for(i = 0; i < 5; i++) //Comenzamos el loop de ordenamiento con un índice ascendiente i.
	{
		for(j = i + 1; j < 5; j++) //El índice i irá de la mano con otro índice j, ascendiente también, pero que va una casilla adelante de i.
		{
			if(Vec[i] > Vec[j]) //Procedemos a comparar i con j. Lo ideal es que el valor de i siempre sea menor al de j, pero en caso de no ser así, tenemos este if.
			{
				k = Vec[i]; //Usamos la variable k como almacenamiento temporal. Si el valor de i es mayor que el de j, el valor de i pasa a ser almacenada en k.
				Vec[i] = Vec[j]; //A continuación, el valor de j pasa a ser almacenado en la casilla de i.
				Vec[j] = k; //Por último, el valor de i (antes almacenado en k) pasa a la casilla de j. De esta manera, logramos intercambiar los valores. Ahora el valor de i es menor que el de j.
			}
		}
	}


	for(i = 0; i < 5; i++) //Realizamos otro loop for, para imprimir el vector ordenado.
	{
		printf("%i\n", Vec[i]); //Nos aseguramos de imprimir una nueva línea con cada componente, para que se vea más limpio.
	}




return 0;

}

