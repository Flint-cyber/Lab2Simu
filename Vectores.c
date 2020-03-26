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

//Incluir librerias
#include <stdio.h>
#include <math.h>

float main ()

{
	float Mag1, Mag2, Prod, Punto, Cruz; //Variables de salida
	float Suma = 0;//Una variable de control para realizar nuestras operaciones, las cuales requieren cierto grado de recursividad.
	float Vec1[4]; //El array del primer vector
	float Vec2[4]; //El array del segundo vector


//Comenzamos escaneando las componentes de cada vector

	printf("Por favor, ingrese las coordenadas del Vector 1.\n");
	
	scanf("%f", &Vec1[1]);
	scanf("%f", &Vec1[2]);
	scanf("%f", &Vec1[3]);

	printf("\nPor favor, ingrese las coordenadas del Vector 2.\n");

	scanf("%f", &Vec2[1]);
	scanf("%f", &Vec2[2]);
	scanf("%f", &Vec2[3]);



	
			//PROBLEMA UNO: MAGNITUDES

	for (int i = 1; i <= 3; i++)
	{
	
//Con este loop, multiplicamos cada componente consigo misma de manera ordenada, y las vamos sumando poco a poco.

		Prod = Vec1[i]*Vec1[i];

//La variable Suma empieza en cero para que nuestro for comience con el cuadrado de la primera componente, y luego vaya sumando más cuadrados hasta llegar a la tercera componente.

		Suma = Suma + Prod;
	}

//Saliendo del loop for, procedemos a sacar raíz cuadrada y asignamos ese valor a la variable Mag1, declarada anteriormente. 

		Mag1 = sqrt(Suma);

//Imprimimos la Magnitud.

	printf("\nNorma del Vector 1: %f\n", Mag1);
		
		Suma = 0; //Reseteamos Suma, para utilizarla en el siguiente loop.


//Repetimos exactamente el mismo procedimiento, pero ahora usando Vec2.

	for (int i = 1; i <= 3; i++)
	{
		Prod = Vec2[i]*Vec2[i];
		Suma = Suma + Prod;
	}
		
		Mag2 = sqrt(Suma);

	printf("Norma del Vector 2: %f\n", Mag2);

		Suma = 0;



		//PROBLEMA DOS: SUMA VECTORIAL

	printf("\nResultado de la Suma Vectorial:\n");

//Hacemos uso de un loop for que va a imprimir la suma de dos números que pertenezcan a la misma componente, desde la componente uno, hasta la tres.

	for(int i = 1; i <= 3; i++)
	{
		Suma = Vec1[i] + Vec2[i];

		printf("%f\n", Suma);
	}
		Suma = 0;
		


		//PROBLEMA TRES: PRODUCTO ESCALAR

	for (int i = 1; i <= 3; i++)
	{

//Aquí, haremos el mismo procedimiento que con la norma, multiplicando componente con componente, pero de distintos vectores.

		Prod = Vec1[i]*Vec2[i];

//Luego, sumamos los resultados de las multiplicaciones. Aségurandonos de que SUma ya ha sido reseteado para la fluidez de la recursividad.

		Suma = Suma + Prod;
	}

//Por último, imprimimos, y reseteamos Suma.

	printf("\nResultado del Producto Punto: %f\n", Suma);

		Suma = 0;
		

	
		//PROBLEMA CUATRO: PRODUCTO VECTORIAL
		
//Este es el problema más difícil de realizar, debido a lo laborioso que resulta el cálculo del producto vectorial.

//Definimos nuestro tercer vector.
		
	float Vec3[4];
	
//A continuación, le asignamos valores a cada componente de Vec3, basándonos en la fórmula para encontrar el producto cruz.

	Vec3[1] = Vec1[2]*Vec2[3] - Vec1[3]*Vec2[2];
	Vec3[2] = Vec1[3]*Vec2[1] - Vec1[1]*Vec2[3];
	Vec3[3] = Vec1[1]*Vec2[2] - Vec1[2]*Vec2[1];


//Imprimimos el enunciado para el usuario.
	printf ("\nResultado del Producto Cruz: \n");

//Con un for loop, imprimimos las componentes del nuevo Vector.

	for (int i = 1; i <= 3; i++)
	{
		printf("%f\n", Vec3[i]);
	}



	
return 0;

}
