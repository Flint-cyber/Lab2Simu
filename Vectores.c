/*
Autor: josecano
Compilador: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
Compilado: gcc Vectores.c -o Vectores
Fecha: Mon Mar 23 20:48:05 UTC 2020
Librerias: stdio, otras librerias
Resumen: Este archivo tomará 2 vectores cuyas componentes serán especificadas por el usuario, y realizará varias operaciones con ellos: magnitud, suma, producto punto y producto cruz.
Entrada:  x1, x2, y1, y2, z1, z2
Salida:  Mag, Sum, Punto, Cruz
*/

#include <stdio.h>
#include <math.h>

float main ()

{
	float Mag1, Mag2, Prod, Punto, Cruz; //Variables de salida
	float Suma = 0;//Una variable de control para realizar nuestras operaciones, las cuales requieren cierto grado de recursividad.
	float Vec1[3]; //El array del primer vector
	float Vec2[3]; //El array del segundo vector
	int i; //Variable de control para ciclos for

//Comenzamos escaneando las componentes de cada vector

	printf("Por favor, ingrese las coordenadas del Vector 1.\n"); //Escameamos con un ciclo for, ya que es más conveniente que ir componente por componente.
	
	for(i = 0; i < 3; i++)
	{
		scanf("%f", &Vec1[i]); //Iremos escaneando y asignando el valor a la i-ésima componente del vector, desde la cero-ésima hasta la segunda.
	}



	printf("\nPor favor, ingrese las coordenadas del Vector 2.\n");

	for(i = 0; i < 3; i++)
	{
		scanf("%f", &Vec2[i]); //Hacemos exactamente lo mismo que con el vector 1.
	}


	
			//PROBLEMA UNO: MAGNITUDES

	for (int i = 0; i < 3; i++) //Con el loop, vamos analizando ordenadamente cada componente, y realizando la operación que corresponde.
	{
		Prod = Vec1[i]*Vec1[i]; //Multiplicamos componente con componente.

		//La variable Suma empieza en cero, y luego va añadiendo el cuadrado de cada componente.

		Suma = Suma + Prod; //La variable suma ahora tomará el valor de ella misma, más el nuevo resultado del producto.
	}

		Mag1 = sqrt(Suma); //Saliendo del loop for, procedemos a sacar raíz cuadrada y asignamos ese valor a la variable Mag1, declarada anteriormente. 

	printf("\nNorma del Vector 1: %f\n", Mag1); //Imprimimos la Magnitud.

		
		Suma = 0; //Reseteamos Suma, para utilizarla en el siguiente loop.


//Repetimos exactamente el mismo procedimiento, pero ahora usando Vec2.

	for (int i = 0; i < 3; i++)
	{
		Prod = Vec2[i]*Vec2[i]; //Multiplicamos componente con componente.
		Suma = Suma + Prod; //Suma toma el valor de ella misma en la iteración anterior, más el valor del producto.
	}
		
		Mag2 = sqrt(Suma); //Sacamos raíz cuadrada.

	printf("Norma del Vector 2: %f\n", Mag2); //Imprimimos.

		Suma = 0; //Reseteamos el valor de Suma.



		//PROBLEMA DOS: SUMA VECTORIAL

	printf("\nResultado de la Suma Vectorial:\n"); //Imprimimos el encabezado
	
	for(int i = 0; i < 3; i++) //Creamos otro loop for.
	{
		Suma = Vec1[i] + Vec2[i]; //En cada iteración, sumamos componente con componente, del vector1 y el vector2.

		printf("%f\n", Suma); //Impriimos cada una de las sumas independientemente, pues son componentes ortogonales del vector nuevo.
	}
		Suma = 0; //Reseteamos la variable Suma.		

	

		//PROBLEMA TRES: PRODUCTO ESCALAR

//Aquí, haremos el mismo procedimiento que con la norma, multiplicando componente con componente, pero de distintos vectores.

	for (int i = 0; i < 3; i++) //Hacemos un loop for para el proceso iterativo.
	{
		Prod = Vec1[i]*Vec2[i]; //En cada iteración, multiplicamos la i-ésima componente del vector1, con la del vector2.

		Suma = Suma + Prod; //Suma toma el valor de ella misma en la iteración pasada, y le suma el valor del producto.
	}

		//Por último, imprimimos el resultado, y reseteamos Suma.

	printf("\nResultado del Producto Punto: %f\n", Suma);

		Suma = 0;
		

	
		//PROBLEMA CUATRO: PRODUCTO VECTORIAL
		
//Este es el problema más difícil de realizar, debido a lo laborioso que resulta el cálculo del producto vectorial.

	float Vec3[3]; //Definimos nuestro tercer vector.
	
//A continuación, le asignamos valores a cada componente de Vec3, basándonos en la fórmula para encontrar el producto cruz, la cual usa el determinante de una matriz de tres por tres.

	Vec3[0] = Vec1[1]*Vec2[2] - Vec1[2]*Vec2[1];
	Vec3[1] = Vec1[2]*Vec2[0] - Vec1[0]*Vec2[2];
	Vec3[2] = Vec1[0]*Vec2[1] - Vec1[1]*Vec2[0];

	printf ("\nResultado del Producto Cruz: \n"); //Imprimimos el enunciado para el usuario.

	for (int i = 0; i < 3; i++) //Con un for loop, imprimimos las componentes del nuevo Vector, una por una.
	{
		printf("%f\n", Vec3[i]);
	}

return 0;

}
